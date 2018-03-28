#import <Foundation/Foundation.h>

// TODO: directly access LensConfiguration for this information? or just move this to Lens and make it LensType? or check class instead of using this at all? BaseLens is private type, lens is fileprivate, etc, so the architecture needs to be reviewed; also, should this have an "undecided" value that replaces menuHidden?
typedef NS_ENUM(NSUInteger, SlyceLensType) {
    SlyceLensTypeUniversal NS_SWIFT_NAME(universal),
    SlyceLensType3D NS_SWIFT_NAME(threeD),
    SlyceLensType2D NS_SWIFT_NAME(twoD),
    SlyceLensTypeBarcode NS_SWIFT_NAME(barcode),
    SlyceLensTypeCustom NS_SWIFT_NAME(custom),
};
