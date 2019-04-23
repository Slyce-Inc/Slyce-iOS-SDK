
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN
__attribute__((objc_subclassing_restricted))
@interface SlyceTheme : NSObject

+ (SlyceTheme *)shared;


/*!
 *  @method
 *
 *  @brief Resets all properties to their defaults.
 *
 *  @discussion Use this method to reset all properties to the default values.
 *
 */
+ (void)resetToDefaults;


/*!
 *  @method
 *
 *  @brief Sets a float value for the provided property name.
 *
 *  @discussion Use this method to set a float value for a property defined in Slyce Theming Guide.
 *
 *  @param value The CGFloat value to be used for the provided property name.
 *  @param propertyName The property name defined by the Slyce Theming Guide.
 *
 */
- (void)setFloat:(CGFloat)value forPropertyName:(NSString *)propertyName;

/*!
 *  @method
 *
 *  @brief Sets a string on the SlyceTheme for the provided property name.
 *
 *  @discussion Use this method to set one-off strings in the SDK. This will override any string set via the localization file.
 *
 *  @param string The string to be used for the provided property name.
 *  @param propertyName The property name defined by the Slyce Theming Guide.
 *
 */
- (void)setString:(NSString *)string forPropertyName:(NSString *)propertyName;

/*!
 *  @method
 *
 *  @brief Sets a UIImage on the SlyceTheme for the provided property name.
 *
 *  @discussion Use this method to set custom images. Provided images must be propery instantiated and ready to use.
 *
 *  @param image The image to be used for the provided property name.
 *  @param propertyName The property name defined by the Slyce Theming Guide.
 *
 */
- (void)setImage:(UIImage *)image forPropertyName:(NSString *)propertyName;

/*!
 *  @method
 *
 *  @brief Sets an NSString on the SlyceTheme that represents a font for the provided property name.
 *
 *  @discussion Setting a font name will tell the SDK which font so use for the provided font name. The SDK manages font weight and size internally. If a font name is unavailable, a system font will be used.
 *
 *  @param fontName The fontName to be used for the provided property name.
 *  @param propertyName The property name defined by the Slyce Theming Guide.
 *
 */
- (void)setFontName:(NSString *)fontName forPropertyName:(NSString *)propertyName;

/*!
 *  @method
 *
 *  @brief Sets a UIColor on the SlyceTheme for the provided property name.
 *
 *  @discussion Use this method to set custom colors.
 *
 *  @param color The color to be used for the provided property name.
 *  @param propertyName The property name defined by the Slyce Theming Guide.
 *
 */
- (void)setColor:(UIColor *)color forPropertyName:(NSString *)propertyName;

/*!
 *  @method
 *
 *  @brief Sets an appearance stlye on the SlyceTheme for the provided property name.
 *
 *  @discussion Use this method to adjust appearanace settings such as header types and other visibility properties.
 *
 *  @param style The appearanceStyle to be used for the provided property name.
 *  @param propertyName The property name defined by the Slyce Theming Guide.
 *
 */
- (void)setAppearanceStyle:(NSUInteger)style forPropertyName:(NSString *)propertyName;

@end
NS_ASSUME_NONNULL_END
