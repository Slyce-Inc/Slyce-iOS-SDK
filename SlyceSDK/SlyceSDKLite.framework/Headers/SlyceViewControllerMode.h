
typedef NS_ENUM(NSUInteger, SlyceViewControllerMode) {
    /*! @brief Sets "universal" lens mode. You must have a universal lens configured for your Slyce account. */
    SlyceViewControllerModeUniversal NS_SWIFT_NAME(universal),
    
    /*! @brief Set "picker" lens mode. This allows the user to choose between all configured lenses, except universal lens. */
    SlyceViewControllerModePicker NS_SWIFT_NAME(picker),
};
