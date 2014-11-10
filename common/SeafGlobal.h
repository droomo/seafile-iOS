//
//  SeafGlobal.h
//  seafilePro
//
//  Created by Wang Wei on 11/9/14.
//  Copyright (c) 2014 Seafile. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <AssetsLibrary/AssetsLibrary.h>
#import "SeafConnection.h"

@interface SeafGlobal : NSObject


@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;

@property (readonly) ALAssetsLibrary *assetsLibrary;

@property (retain) NSMutableArray *conns;
@property (readwrite) SeafConnection *connection;


+ (SeafGlobal *)sharedObject;

- (void)loadAccounts;
- (void)saveAccounts;
- (SeafConnection *)getConnection:(NSString *)url username:(NSString *)username;

- (void)startTimer;

- (void)saveContext;
- (void)deleteAllObjects: (NSString *) entityDescription;

- (void)incDownloadnum;
- (void)decDownloadnum;
- (void)incUploadnum;
- (int)uploadingnum;
- (int)downloadingnum;

- (void)finishDownload:(id<SeafDownloadDelegate>) file result:(BOOL)result;
- (void)finishUpload:(SeafUploadFile *) file result:(BOOL)result;

- (void)backgroundUpload:(SeafUploadFile *)file;
- (void)backgroundDownload:(id<SeafDownloadDelegate>)file;
- (void)removeBackgroundUpload:(SeafUploadFile *)file;


@end
