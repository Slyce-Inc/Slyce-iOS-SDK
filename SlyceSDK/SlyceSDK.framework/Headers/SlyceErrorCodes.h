
extern NSString * _Nonnull const SlyceErrorDomain;

NS_ERROR_ENUM(SlyceErrorDomain)
{
    SlyceErrorUnknown = -1,
    
    // General
    
    SlyceErrorOperationCouldNotBeCompleted = -101,
    SlyceErrorBadCredentials = -102,
    SlyceErrorMissingCredentials = -103,
    SlyceErrorNotAuthenticated = -104,
    SlyceErrorNotOpen = -105,
    SlyceErrorOperationCancelled = -106,

    // Networking

    SlyceErrorUnexpectedStatusCode = -201,
    SlyceErrorInvalidConfig = -202,
    SlyceErrorWorkflowOperationMessage = -203,
    SlyceErrorNetworkTimeout = -204,
    SlyceErrorUnexpectedConnectionType = -205,
    SlyceErrorUnexpectedResponseType = -206,
    SlyceErrorWebSocketConnection = -207,
    SlyceErrorConfigurationService = -208,
    
    // Parsing Error
    
    SlyceErrorJSONParsing = -301,
    
    // Lenses
    
    SlyceErrorInvalidLens = -401,
    
    // Camera
    
    SlyceErrorCaptureDeviceUnavailable = -501,
    SlyceErrorCaptureSessionUnavailable = -502,
    SlyceErrorCameraNotStarted = -503,
    SlyceErrorCaptureStillImage = -504,
    SlyceErrorImageProcessing = -505,
    SlyceErrorCouldNotAddOutput = -506,
    
    // Workflow
    
    SlyceErrorWorkflowOperationFailed = -601,
    SlyceErrorWorkflowOperationNoResults = -602,
    
    // Search History
    
    SlyceErrorSearchHistoryManager = -701,
    SlyceErrorCoreData = -702,
    
    // Feature Matching
    
    SlyceErrorFeatureMatchCatalog = -801,
    
    // GDPR
    
    SlyceErrorUserNotGDPRCompliant = -901,
    SlyceErrorUserIdentifierNotSet = -902
};
