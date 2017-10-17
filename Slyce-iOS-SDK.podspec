Pod::Spec.new do |s|

s.name         							= "Slyce-iOS-SDK"
s.version      							= "4.5.9"
s.summary      							= "Slyce iOS SDK"
s.description  							= <<-DESC
									The Slyce iOS SDK makes it easy to add visual search capabilities to mobile apps.
			   					DESC
s.homepage     							= "https://github.com/Slyce-Inc/Slyce-iOS-SDK"
s.license      							= { :type => "BSD", :file => "LICENSE.md" }
s.author 	   								= { "Slyce Inc." => "avital@slyce.it" }
s.platform     							= :ios, "8.0"
s.source   	   							= { :git => "https://github.com/Slyce-Inc/Slyce-iOS-SDK.git", :tag => s.version }
s.requires_arc 							= true
s.preserve_paths 						= "SlyceSDK/SlyceSDK.framework"
s.libraries									= "icucore"
s.ios.vendored_frameworks 	= "SlyceSDK/SlyceSDK.framework"
s.xcconfig 									= { "OTHER_LDFLAGS" => "-ObjC", "FRAMEWORK_SEARCH_PATHS" => "$(inherited)" }

end
