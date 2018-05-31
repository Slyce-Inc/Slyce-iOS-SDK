XCODE_PROJ_PATH=SlyceSDK-Examples.xcworkspace
XCODE_SCHEME="Build All"
XCODE_DERIVED_DATA=./build

all: clean build

.PHONY: build
build:
	xcodebuild build -workspace $(XCODE_PROJ_PATH) -scheme $(XCODE_SCHEME) -sdk iphonesimulator -derivedDataPath $(XCODE_DERIVED_DATA)

clean:
	rm -rf $(XCODE_DERIVED_DATA)
	xcodebuild clean -workspace $(XCODE_PROJ_PATH) -scheme $(XCODE_SCHEME) -sdk iphonesimulator -derivedDataPath $(XCODE_DERIVED_DATA)
