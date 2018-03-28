#import <Foundation/Foundation.h>

@interface SlyceSearchResult : NSObject

@property(nonatomic, copy) NSString *type;
@property(nonatomic, copy) NSString *mappingID;
@property(nonatomic, copy) NSString *cursor;
@property(nonatomic, strong) NSArray <NSDictionary *> *items;

@end
