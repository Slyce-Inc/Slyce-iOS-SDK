
#ifdef SLYCE_SDK_INTERNAL
#import "SlyceTheme.h"
#import "SlyceAppearanceStyles.h"
#endif



@interface SlyceTheme ()

@property (nonatomic, readwrite) SlyceHeaderStyleLeft appearance_headerStyle_left;
@property (nonatomic, readwrite) SlyceHeaderStyleCenter appearance_headerStyle_center;
@property (nonatomic, readwrite) SlyceHeaderStyleRight appearance_headerStyle_right;
@property (nonatomic, readwrite) SlyceActiveSearchesStyle appearance_activeSearches;

// MARK: - strings
// MARK: - error handling
@property (nonatomic, readwrite, copy, nullable) NSString *error_string_type_image_headline;
@property (nonatomic, readwrite, copy, nullable) NSString *error_string_type_image_subtitle;
@property (nonatomic, readwrite, copy, nullable) NSString *error_string_type_system_headline;
@property (nonatomic, readwrite, copy, nullable) NSString *error_string_type_system_subtitle;

// MARK: global
@property (nonatomic, readwrite, copy, nullable) NSString *string_appTitle;
@property (nonatomic, readwrite, copy, nullable) NSString *string_alertOKString __deprecated_msg("Overide slyce_action_ok string instead.");

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

// MARK: search history
@property (nonatomic, readwrite, copy, nullable) NSString *string_searchHistoryTitle;
@property (nonatomic, readwrite, copy, nullable) NSString *string_emptyContent_headline;
@property (nonatomic, readwrite, copy, nullable) NSString *string_emptyContent_body;

// MARK: search results
@property (nonatomic, readwrite, copy, nullable) NSString *string_searchResultsTitle;
@property (nonatomic, readwrite) SlyceSearchResultsListType appearance_searchResultsType;

// MARK: - icons
@property (nonatomic, readwrite, copy, nullable) UIImage *btn_drawer_close;
@property (nonatomic, readwrite, copy, nullable) UIImage *btn_drawer_back;

@property (nonatomic, readwrite, copy, nullable) UIImage *ic_help;

// MARK: camera
@property (nonatomic, readwrite, copy, nullable) UIImage *bg_nav_stripImage;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_back;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_photoGallery;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_searchHistory;
@property (nonatomic, readwrite, copy, nullable) NSArray<UIImage *> *bg_processingIndicator;

// MARK: global
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_global_done_small;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_global_done_large;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_global_alert_small;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_global_alert_xlarge;

// MARK: search history
@property (nonatomic, readwrite, copy, nullable) UIImage *bg_emptyContentImage;

// MARK: coaching tips
@property (nonatomic, readwrite, copy, nullable) UIImage *bg_coachingTip_universalLens;
@property (nonatomic, readwrite, copy, nullable) UIImage *bg_coachingTip_visualSearch;
@property (nonatomic, readwrite, copy, nullable) UIImage *bg_coachingTip_barcode;
@property (nonatomic, readwrite, copy, nullable) UIImage *bg_coachingTip_imageMatch;

// MARK: error
@property (nonatomic, readwrite, copy, nullable) UIImage *error_image_type_system;
@property (nonatomic, readwrite, copy, nullable) UIColor *errorLayer_error_code_color;

// MARK: Fonts
@property (nonatomic, readwrite, copy, nullable) NSString *global_headline_font;
@property (nonatomic, readwrite, copy, nullable) NSString *global_secondary_font;
@property (nonatomic, readwrite, copy, nullable) NSString *global_title_font;
@property (nonatomic, readwrite, copy, nullable) NSString *global_primary_font;

// MARK: Corner radius
@property (nonatomic, readwrite, copy, nullable) NSNumber *userImage_global_cornerRadius;


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

@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_picker_tint_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_picker_selection_tint_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_picker_background_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *lens_btn_picker_background_selection_color;

// MARK: dots animation
@property (nonatomic, readwrite, copy, nullable) UIColor *dotDetection_primary;
@property (nonatomic, readwrite, copy, nullable) UIColor *dotDetection_secondary;

// MARK: settings
@property (nonatomic, readwrite, copy, nullable) UIColor *settings_btn_tint_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *settings_btn_color;

// MARK: web view
@property (nonatomic, readwrite, copy, nullable) UIColor *webview_btn_color;
@property (nonatomic, readwrite, copy, nullable) UIColor *webview_btn_tint_color;

// MARK: Lens Picker
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_open_unselected_barcode;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_open_selected_barcode;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_open_pressed_barcode;

@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_open_unselected_imageMatch;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_open_selected_imageMatch;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_open_pressed_imageMatch;

@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_open_unselected_visualSearch;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_open_selected_visualSearch;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_open_pressed_visualSearch;

@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_closed_selected_barcode;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_closed_pressed_barcode;

@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_closed_selected_imageMatch;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_closed_pressed_imageMatch;

@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_closed_selected_visualSearch;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_nav_lensPicker_closed_pressed_visualSearch;

@property (nonatomic, readwrite, copy, nullable) UIImage *ic_lensPicker_close;
@property (nonatomic, readwrite, copy, nullable) UIImage *ic_lensPicker_close_pressed;

@end
