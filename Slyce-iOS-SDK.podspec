Pod::Spec.new do |spec|

spec.name                    = "Slyce-iOS-SDK"
spec.version                 = "5.13.4"
spec.summary                 = "Slyce iOS SDK"
spec.description             = <<-DESC
The Slyce iOS SDK makes it easy to add visual search capabilities to mobile apps.
DESC
spec.homepage                = "https://github.com/Slyce-Inc/Slyce-iOS-SDK"
spec.license                 = { :type => "Commercial", :file => "LICENSE.md" }
spec.author                  = { "Slyce Inc." => "mobile@slyce.it" }
spec.platform                = :ios, "9.0"
spec.source                  = { :git => "https://github.com/Slyce-Inc/Slyce-iOS-SDK.git", :tag => "5.13.4" }
spec.requires_arc            = true
spec.preserve_paths          = "SlyceSDK/**"
spec.ios.vendored_frameworks = "SlyceSDK/SlyceSDK.framework"

end
