#ifndef SlyceTitleBarStyle_h
#define SlyceTitleBarStyle_h

typedef NS_ENUM(NSUInteger, SlyceTitleBarStyle) {
    SlyceTitleBarStyleBackStripImageSettings, // back button, strip image, settings button (SDK-844)
    SlyceTitleBarStyleStripImage, // only strip image (SDK-847)
    SlyceTitlebarStyleSettings, // only settings button (SDK-846)
    SlyceTitlebarStyleStripImageSettings, // strip image, settings button (SDK-845)
    SlyceTitlebarStyleBackTitleSettings, // title, settings, back (SDK-848)
    SlyceTitlebarStyleTitleSettings, // title, settings (SDK-849)
};

#endif /* SlyceTitleBarStyle_h */
