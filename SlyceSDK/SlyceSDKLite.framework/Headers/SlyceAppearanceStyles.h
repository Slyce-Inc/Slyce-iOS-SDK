#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, SlyceActiveSearchesStyle)
{
    SlyceActiveSearchesStyleHidden,
    SlyceActiveSearchesStyleVisible
};

typedef NS_ENUM(NSUInteger, SlyceHeaderStyleLeft)
{
    SlyceHeaderStyleLeftHidden,
    SlyceHeaderStyleLeftBackButton
};

typedef NS_ENUM(NSUInteger, SlyceHeaderStyleCenter)
{
    SlyceHeaderStyleCenterHidden,
    SlyceHeaderStyleCenterTitle,
    SlyceHeaderStyleCenterImage
};

typedef NS_ENUM(NSUInteger, SlyceHeaderStyleRight)
{
    SlyceHeaderStyleRightHidden,
    SlyceHeaderStyleRightHelp
};

typedef NS_ENUM(NSUInteger, SlyceSearchResultsListType)
{
    SlyceSearchResultsGrid,
    SlyceSearchResultsList
};
