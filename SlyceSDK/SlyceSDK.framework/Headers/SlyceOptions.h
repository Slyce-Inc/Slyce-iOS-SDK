#import "SlyceBase.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString *const SlyceOptionKey NS_TYPED_EXTENSIBLE_ENUM;

SLYCE_SDK_EXPORT extern SlyceOptionKey SlyceOptionUniversalLensLocalDetectionModeKey NS_SWIFT_NAME(UniversalLensLocalDetectionMode);
SLYCE_SDK_EXPORT extern SlyceOptionKey SlyceOptionLensesKey NS_SWIFT_NAME(Lenses);


#pragma mark -

typedef NSString *const SlyceLensOptionKey NS_TYPED_EXTENSIBLE_ENUM;

SLYCE_SDK_EXPORT extern SlyceLensOptionKey SlyceLensOptionKeyCaptureMode;


#pragma mark -

typedef NSString *const SlyceLensCaptureMode NS_TYPED_EXTENSIBLE_ENUM;

SLYCE_SDK_EXPORT extern SlyceLensCaptureMode SlyceLensCaptureModeSingle;
SLYCE_SDK_EXPORT extern SlyceLensCaptureMode SlyceLensCaptureModeBatch;
SLYCE_SDK_EXPORT extern SlyceLensCaptureMode SlyceLensCaptureModeLegacyMulti;


#pragma mark -

SLYCE_SDK_EXPORT extern NSString *const kSlyceOptionUniversalLensLocalDetectionMode __deprecated_msg("Use SlyceOptionUniversalLensLocalDetectionModeKey instead");

SLYCE_SDK_EXPORT extern NSString *const SlyceOptionLensCaptureModeSingle __deprecated_msg("Use SlyceLensCaptureModeSingle instead");

SLYCE_SDK_EXPORT extern NSString *const SlyceOptionLensCaptureModeBatch __deprecated_msg("Use SlyceLensCaptureModeBatch instead");

SLYCE_SDK_EXPORT extern NSString *const SlyceOptionLensCaptureModeKey __deprecated_msg("Use SlyceLensOptionKeyCaptureMode instead");

NS_ASSUME_NONNULL_END
