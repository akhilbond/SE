/**
 * Copyright 2012-2015 Amazon.com, Inc. or its affiliates. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You may not use this file except in compliance with the License. A copy
 * of the License is located at
 *
 * http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
 */

#import <Foundation/Foundation.h>

#pragma mark - Error domains

/**
  Login With Amazon error domain for NSErrors
 */
FOUNDATION_EXPORT NSString *const AIErrorDomain;

#pragma mark - Error codes

/**
  No error, initial value.
*/
extern const NSUInteger kAINoError;

/**
  A valid refresh token was not found.

  The refresh token stored in the SDK is invalid, expired, revoked, does not match
  the redirection URI used in the authorization request, does not have the required scopes, or was issued to another
  client. `[AIMobileLib getProfile:]` and `[getAccessTokenForScopes:withOverrideParams:delegate:]` can return this
  error.

  Generally with this type of error, the app can call `[AIMobileLib authorizeUserForScopes:delegate:]` to request
  authorization, or call `[AIMobileLib clearAuthorizationState:]` to logout the user.
*/
extern const NSUInteger kAIApplicationNotAuthorized;

/**
  An error occurred on the server.

  The server encountered an error while completing the request, or the SDK received an unknown response from the server.
  `[AIMobileLib getProfile:]`, `[AIMobileLib getAccessTokenForScopes:withOverrideParams:delegate:]`, and
  `[AIMobileLib authorizeUserForScopes:delegate:]` can return this error.

  Generally with this type of error, the app can allow the user to retry the last action.
*/
extern const NSUInteger kAIServerError;

/**
  The user dismissed the page.

  The user pressed cancel while on an Amazon-provided page, such as login or consent.
  `[AIMobileLib authorizeUserForScopes:delegate:]` can return this error.

  Generally with this type of error, the app can allow the user to perform the requested operation again.
*/
extern const NSUInteger kAIErrorUserInterrupted;

/**
  The resource owner or authorization server denied the request.

  The user declined to authorize the app on the consent page. `[AIMobileLib authorizeUserForScopes:delegate:]` can
  return this error.

  Generally with this type of error, the app can call `[AIMobileLib authorizeUserForScopes:delegate:]` to
  request authorization.
*/
extern const NSUInteger kAIAccessDenied;

/**
  The SDK encountered an error on the device.

  The SDK returns this when there is a problem with the Keychain. `[AIMobileLib getProfile:]`,
  `[AIMobileLib getAccessTokenForScopes:withOverrideParams:delegate:]`, and
  `[AIMobileLib authorizeUserForScopes:delegate:]` can return this error.

  Generally with this type of error, the app can call `[AIMobileLib clearAuthorizationState:]` to reset the Keychain.
*/
extern const NSUInteger kAIDeviceError;

/**
  One of the API parameters is invalid.

  The request is missing a required parameter, includes an invalid parameter value, includes a parameter more than once,
  or is otherwise malformed.

  Check your method parameters and try again. All APIs can return this error.
*/
extern const NSUInteger kAIInvalidInput;

/**
  A network error occurred, possibly due to the user being offline.

 `[AIMobileLib getProfile:]`, `[AIMobileLib getAccessTokenForScopes:withOverrideParams:delegate:]`, and
 `[AIMobileLib authorizeUserForScopes:delegate:]` can return this error.

  Generally with this type of error, the app can ask the user to check their network connections.
*/
extern const NSUInteger kAINetworkError;

/**
  The client is not authorized to request an authorization code using this method.

  The app is not authorized to make this call. Make sure the registered Bundle identifier matches your app, and that you
  have a valid APIKey property in the app property list.
  `[AIMobileLib getAccessTokenForScopes:withOverrideParams:delegate:]`, and
  `[AIMobileLib authorizeUserForScopes:delegate:]` can return this error.
*/
extern const NSUInteger kAIUnauthorizedClient;

/**
  An internal error occurred in the SDK.

 `[AIMobileLib getProfile:]`, `[AIMobileLib getAccessTokenForScopes:withOverrideParams:delegate:]`, and
 `[AIMobileLib authorizeUserForScopes:delegate:]` can return this error.

 Generally these errors cannot be handled by app. Please contact us to report recurring internal errors.
*/
extern const NSUInteger kAIInternalError;

/**
 An version error occurred while the SDK version is not supported for LWA SSO.
 Only `[AIMobileLib authorizeUserForScopes:delegate:]` can return this error.
 */
extern const NSUInteger kAIVersionDenied;

#pragma mark - AIError

/**
  This class encapsulates the error information generated by the SDK. An AIError object includes the error code and a
  meaningful error message. The error code constants are available in the header file.
*/
@interface AIError : NSObject

/**
  The error code for the error encountered by the API.

  @since 1.0
*/
@property NSUInteger code;

/**
  The readable message corresponding to the error code.

  @since 1.0
*/
@property (copy) NSString *message;

@end
