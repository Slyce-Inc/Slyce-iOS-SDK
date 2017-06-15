//
// Created by Leo Lemesev on 06/06/2017.
// Copyright (c) 2017 BuyCode. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SFSyncDelegate <NSObject>


- (void)syncStarted;

- (void)syncFinished;

- (void)syncFailedWithMessage:(NSString *)failMesage;

- (void)syncedCatalogs:(NSInteger)count from:(NSInteger)total;


@end