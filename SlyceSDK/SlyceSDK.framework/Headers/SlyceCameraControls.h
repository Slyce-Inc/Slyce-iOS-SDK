
NS_ASSUME_NONNULL_BEGIN
@protocol SlyceCameraControls <NSObject>

@property (nonatomic, readonly) BOOL paused;

- (void)start;
- (BOOL)startAndReturnError:(NSError * _Nullable __autoreleasing *)error;

- (void)stop;

- (void)pause;

- (void)resume;
- (BOOL)resumeAndReturnError:(NSError * _Nullable __autoreleasing *)error;

@end
NS_ASSUME_NONNULL_END
