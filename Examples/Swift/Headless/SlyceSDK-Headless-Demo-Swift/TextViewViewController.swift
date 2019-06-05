import UIKit
import SlyceSDK

class TextViewViewController: UIViewController
{
    let textView = UITextView()
    
    override func viewDidLoad()
    {
        super.viewDidLoad()

        // This view controller shows a UITextView, and implements a few
        // convenience methods that make it easy to add images and text
        // to the text view, and scroll to the bottom on each update.
        //
        // None of this code is necessary to run Slyce and
        // is only included to help navigate the example app.

        view.backgroundColor = UIColor.white
        
        textView.isEditable = false
        textView.isScrollEnabled = true
        textView.showsHorizontalScrollIndicator = false
        textView.alwaysBounceHorizontal = false
        textView.alwaysBounceVertical = true
        textView.isDirectionalLockEnabled = true
        textView.font = UIFont.systemFont(ofSize: 20)
        textView.textColor = UIColor.black
        textView.backgroundColor = UIColor.white
        textView.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(textView)
        
        textView.topAnchor.constraint(equalTo: view.topAnchor).isActive = true
        textView.leftAnchor.constraint(equalTo: view.leftAnchor).isActive = true
        textView.rightAnchor.constraint(equalTo: view.rightAnchor).isActive = true
        textView.bottomAnchor.constraint(equalTo: view.bottomAnchor).isActive = true
    }
    
    override var supportedInterfaceOrientations: UIInterfaceOrientationMask
    {
        return .portrait
    }
    
    func appendTaskToTextView(_ task: SlyceSearchTask, _ finished: Bool = false)
    {
        let stateString = finished ? "finished" : "created"
        let string = NSMutableAttributedString(string: "\nSlyceSearchTask "+stateString+":\n\t", attributes: [NSAttributedStringKey.font : UIFont.systemFont(ofSize: 18, weight: .bold)])
        appendAttributedStringToTextView(string)
        appendImageToTextView(task.request.image!)
    }
    
    func appendErrorsToTextView(_ errors: [Error])
    {
        let string = NSMutableAttributedString(string: "\nSlyceSearchTask errors:\n\t", attributes: [NSAttributedStringKey.font : UIFont.systemFont(ofSize: 18, weight: .bold)])
        
        for error in errors {
            string.append(NSAttributedString(string: error.localizedDescription.appending("\n")))
        }
        
        appendAttributedStringToTextView(string)
    }
    
    func appendUpdateToTextView(_ update: SlyceSearchResponseUpdate)
    {
        let string = NSMutableAttributedString(string: "\nSlyceSearchTask update:\n\t", attributes: [NSAttributedStringKey.font : UIFont.systemFont(ofSize: 18, weight: .bold)])
        
        string.append(NSAttributedString(string: "Type: ".appending(NSNumber(value: Int8(update.type.rawValue)).stringValue)))
        string.append(NSAttributedString(string: "\n\tValue: ".appending(update.value.debugDescription)))

        appendAttributedStringToTextView(string)
    }
    
    func appendResponseToTextView(_ response: SlyceSearchResponse)
    {
        let string = NSMutableAttributedString(string: "\nSlyceSearchTask response:\n\t", attributes: [NSAttributedStringKey.font : UIFont.systemFont(ofSize: 18, weight: .bold)])
        
        string.append(NSAttributedString(string: "Results: ".appending(response.results.debugDescription)))
        string.append(NSAttributedString(string: "\n\tTags: ".appending(response.tags.debugDescription)))
        
        appendAttributedStringToTextView(string)
    }
    
    func appendStringToTextView(_ string: String)
    {
        appendAttributedStringToTextView(NSAttributedString(string: string))
    }
    
    func appendImageToTextView(_ image: UIImage)
    {
        let imageAttachment = NSTextAttachment()

        OperationQueue.main.addOperation {
            // Resize image if too large to show elegantly in text view.
            let maxSize: CGFloat = self.view.frame.size.width - 50.0
            if image.size.height > maxSize || image.size.width > maxSize {
                let newWidth = maxSize
                let scale = newWidth / image.size.width
                let newHeight = image.size.height * scale
                UIGraphicsBeginImageContext(CGSize(width: newWidth, height: newHeight))
                image.draw(in: CGRect(x: 0, y: 0, width: newWidth, height: newHeight))
                let newImage = UIGraphicsGetImageFromCurrentImageContext()
                UIGraphicsEndImageContext()
                imageAttachment.image = newImage
            } else {
                imageAttachment.image = image
            }
        }

        appendAttributedStringToTextView(NSAttributedString(attachment: imageAttachment))
    }
    
    func appendAttributedStringToTextView(_ attributedString: NSAttributedString)
    {
        OperationQueue.main.addOperation {
            let appendingString = NSMutableAttributedString(attributedString: self.textView.attributedText)
            appendingString.append(attributedString)
            
            let endOfTextRange = NSRange(location: appendingString.string.count-1, length: 1)
            
            self.textView.attributedText = appendingString
            
            DispatchQueue.main.asyncAfter(deadline: DispatchTime.now() + 0.25, execute: {
                self.textView.scrollRangeToVisible(endOfTextRange)
            })
        }
    }
}
