import UIKit
import AVFoundation

class Camera: NSObject, AVCapturePhotoCaptureDelegate {
    public var cameraCaptureSession: AVCaptureSession?
    var cameraPreviewLayer: AVCaptureVideoPreviewLayer?
    
    func start() -> AVCaptureVideoPreviewLayer? {
        if nil == cameraCaptureSession {
            cameraCaptureSession = setupCaptureSession()
            
            if nil == cameraCaptureSession {
                print("Unable to create a camera capture session; this means the camera is unavailable or impossible to access and none of the SDK features will work!")
                return nil
            }
        }
        
        if nil == cameraPreviewLayer {
            let previewLayer = AVCaptureVideoPreviewLayer(session: cameraCaptureSession!)
            previewLayer.videoGravity = AVLayerVideoGravity.resizeAspectFill
            cameraPreviewLayer = previewLayer
            
            if nil == cameraPreviewLayer {
                print("Unable to create a camera preview layer; this means the camera will be invisible in the demo UI and it is unlikely that the SDK features will work!")
                return nil
            }
        }
        
        if cameraCaptureSession!.isRunning == false {
            cameraCaptureSession?.startRunning()
        }
        
        return cameraPreviewLayer
    }
    
    func getAvailableCamera() -> AVCaptureDevice? {
        return AVCaptureDevice.default(for: .video)
    }
    
    func prepareCamera(_ camera: AVCaptureDevice) {
        do {
            try camera.lockForConfiguration()
            camera.focusMode = .continuousAutoFocus
            camera.unlockForConfiguration()
        } catch let e {
            print(e)
        }
    }
    
    func setupCaptureSession() -> AVCaptureSession? {
        // create session
        let captureSession = AVCaptureSession()
        captureSession.sessionPreset = .high
        
        // create, setup camera
        guard let camera = getAvailableCamera() else {
            return nil
        }
        
        self.prepareCamera(camera)
        
        // add camera input to session
        var cameraInput: AVCaptureDeviceInput
        do {
            try cameraInput = AVCaptureDeviceInput(device: camera)
        } catch let e {
            print(e)
            return nil
        }
        
        if false == captureSession.canAddInput(cameraInput) {
            return nil
        }
        
        captureSession.addInput(cameraInput)
        return captureSession
    }
}
