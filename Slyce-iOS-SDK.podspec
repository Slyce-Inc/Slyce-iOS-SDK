Pod::Spec.new do |s|

s.name                                  = "Slyce-iOS-SDK"
s.version                               = "5.1.0-rc2"
s.summary                               = "Slyce iOS SDK"
s.description                           = <<-DESC
The Slyce iOS SDK makes it easy to add visual search capabilities to mobile apps.
DESC
s.homepage                              = "https://github.com/Slyce-Inc/Slyce-iOS-SDK"
s.license                               = { :type => "BSD", :file => "LICENSE.md" }
s.author                                    = { "Slyce Inc." => "andy@slyce.it" }
s.platform                              = :ios, "9.0"
s.source                                = { :git => "https://github.com/Slyce-Inc/Slyce-iOS-SDK.git", :tag => "5.1.0-rc2" }
s.requires_arc                          = true
s.preserve_paths                        = "SlyceSDK/SlyceSDK.framework"
s.libraries                             = "icucore"
s.ios.vendored_frameworks               = "SlyceSDK/SlyceSDK.framework"
s.xcconfig                              = { "OTHER_LDFLAGS" => "-ObjC", "FRAMEWORK_SEARCH_PATHS" => "$(inherited)" }

end
