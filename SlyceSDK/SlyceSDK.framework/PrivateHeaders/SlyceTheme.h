#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SlyceHeaderStyles.h"

NS_ASSUME_NONNULL_BEGIN
@interface SlyceTheme : NSObject

+ (SlyceTheme *)shared;

+ (void)resetToDefaults;

// MARK: - camera header configs
@property (nonatomic, readwrite) SlyceHeaderLeftStyle headerLeftNavigation;
@property (nonatomic, readwrite) SlyceHeaderCenterStyle headerCenter;
@property (nonatomic, readwrite) SlyceHeaderRightStyle headerRightNavigation;

// MARK: - error handling
// MARK: strings
@property (nonatomic, readwrite, copy, nullable) NSString *error_string_type_image_headline;
@property (nonatomic, readwrite, copy, nullable) NSString *error_string_type_image_subtitle;
@property (nonatomic, readwrite, copy, nullable) NSString *error_string_type_system_headline;
@property (nonatomic, readwrite, copy, nullable) NSString *error_string_type_system_subtitle;

// MARK: images
@property (nonatomic, readwrite, copy, nullable) UIImage *error_image_type_image;
@property (nonatomic, readwrite, copy, nullable) UIImage *error_image_type_system;

// MARK: colors
@property (nonatomic, readwrite, copy, nullable) UIColor *error_color_no_internet;
@property (nonatomic, readwrite, copy, nullable) UIColor *error_color_low_internet;
@property (nonatomic, readwrite, copy, nullable) UIColor *error_color_connected_internet;

// MARK: - fonts
// MARK: global
@property (nonatomic, readwrite, copy, nullable) NSString *global_headline_font;
@property (nonatomic, readwrite, copy, nullable) NSString *global_title_font;
@property (nonatomic, readwrite, copy, nullable) NSString *global_primary_font;
@property (nonatomic, readwrite, copy, nullable) NSString *global_secondary_font;

// convenience UIFont getters; these simply abstract UIFont fontWithName:size:
- (UIFont *)global_headline_font:(CGFloat)fontSize;
- (UIFont *)global_title_font:(CGFloat)fontSize;
- (UIFont *)global_primary_font:(CGFloat)fontSize;
- (UIFont *)global_secondary_font:(CGFloat)fontSize;

// MARK: - colors
// MARK: global
@property (nonatomic, readwrite, copy, nullable) UIColor *global_accent_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *global_error_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *global_primaryBackground_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *global_secondaryBackground_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *global_primaryForeground_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *global_secondaryForeground_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *bg_processingIndicator_tint;
// MARK: lens
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_background_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_tint_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_background_selection_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_selection_tint_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_status_background_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_status_background_selection_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_status_tint_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_status_selection_tint_color;

@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_active_tint_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_active_selection_tint_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_active_background_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_active_background_selection_color;

@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_picker_tint_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_picker_selection_tint_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_picker_background_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_picker_background_selection_color;

// MARK: settings
@property (nonatomic, readwrite, copy, nullable) UIColor *settings_btn_tint_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *settings_btn_color;

// MARK: - strings
// MARK: global
@property (nonatomic, readwrite, copy, nullable) NSString *string_appTitle;
// MARK: lens
@property (nonatomic, readwrite, copy, nullable) NSString *string_lens_visualSearch;
@property (nonatomic, readwrite, copy, nullable) NSString *string_lens_barcode;
@property (nonatomic, readwrite, copy, nullable) NSString *string_lens_imageMatch;
// MARK: coaching tips
@property (nonatomic, readwrite, copy, nullable) NSString *string_coachingTip_headline_universal;
@property (nonatomic, readwrite, copy, nullable) NSString *string_coachingTip_body_universal;
@property (nonatomic, readwrite, copy, nullable) NSString *string_coachingTip_headline_visualSearch;
@property (nonatomic, readwrite, copy, nullable) NSString *string_coachingTip_body_visualSearch;
@property (nonatomic, readwrite, copy, nullable) NSString *string_coachingTip_headline_barcode;
@property (nonatomic, readwrite, copy, nullable) NSString *string_coachingTip_body_barcode;
@property (nonatomic, readwrite, copy, nullable) NSString *string_coachingTip_headline_imageMatch;
@property (nonatomic, readwrite, copy, nullable) NSString *string_coachingTip_body_imageMatch;
// MARK: settings
@property (nonatomic, readwrite, copy, nullable) NSString *string_settingsTitle;
// MARK: search history
@property (nonatomic, readwrite, copy, nullable) NSString *string_searchHistoryTitle;
@property (nonatomic, readwrite, copy, nullable) NSString *string_emptyContent_headline;
@property (nonatomic, readwrite, copy, nullable) NSString *string_emptyContent_body;

// MARK: - icons
// MARK: camera
@property (nonatomic, readwrite, copy, nullable) UIImage *bg_nav_stripImage;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_back;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_settings;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_close;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_visualSearch;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_barcode;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_imageMatch;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_photoGallery;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_searchHistory;
@property (nonatomic, readwrite, copy, nullable) NSArray<UIImage *> *bg_processingIndicator;
// MARK: global
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_global_done_small;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_global_done_large;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_global_alert_small;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_global_alert_large;
// MARK: search history
@property (nonatomic, readwrite, copy, nullable) UIImage *bg_searchHistory_nullContent;
@property (nonatomic, readwrite, copy, nullable) UIImage *bg_emptyContentImage;
// MARK: coaching tips
@property (nonatomic, readwrite, copy, nullable) UIImage *bg_coachingTip_universalLens;
@property (nonatomic, readwrite, copy, nullable) UIImage *bg_coachingTip_visualSearch;
@property (nonatomic, readwrite, copy, nullable) UIImage *bg_coachingTip_barcode;
@property (nonatomic, readwrite, copy, nullable) UIImage *bg_coachingTip_imageMatch;

@end
NS_ASSUME_NONNULL_END
