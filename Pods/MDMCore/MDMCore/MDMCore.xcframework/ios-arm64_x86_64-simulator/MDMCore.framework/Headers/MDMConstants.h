//
//  MDMConstants.h
//  MDMCore
//
//  Created by Robson Moreira on 15/02/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#ifndef MDMConstants_h
#define MDMConstants_h

#define DEVICE_MANUFACTURER @"Apple Inc."
#define DEVICE_PLATFORM @"IOS"

// MDM Bundle Identifier Core
#define MDM_CORE_BUNDLE_ID @"br.com.hands.mdm.libs.ios.core"

// Queue identifier
#define BLOCK_QUEUE @"block-queue"

// Modules ID
#define MODULE_AD @"mdm-ad"
#define MODULE_APP @"mdm-appbehavior"
#define MODULE_BUNDLE @"mdm-bundle"
#define MODULE_CORE @"mdm-core"
#define MODULE_CONFIG @"mdm-config"
#define MODULE_DATA @"mdm-databehavior"
#define MODULE_DEVICE @"mdm-devicebehavior"
#define MODULE_GEO @"mdm-geobehavior"
#define MODULE_NOTIFICATION @"mdm-notification"
#define MODULE_INBOX @"mdm-inbox"

// Modules Name
#define MODULE_AD_NAME @"MDMAd"
#define MODULE_APP_NAME @"MDMAppbehavior"
#define MODULE_BUNDLE_NAME @"MDMBundle"
#define MODULE_CORE_NAME @"MDMCore"
#define MODULE_CONFIG_NAME @"MDMConfig"
#define MODULE_DEVICE_NAME @"MDMDeviceBehavior"
#define MODULE_GEO_NAME @"MDMGeoBehavior"
#define MODULE_NOTIFICATION_NAME @"MDMNotification"
#define MODULE_INBOX_NAME @"MDMInbox"

// Keys for dictionary
#define KEY_EU_ID @"euid"
#define KEY_AP_ID @"apid"
#define KEY_MDM_APP_BUNDLE @"MDM_APP_BUNDLE"
#define KEY_BACKGROUND_MODES @"UIBackgroundModes"
#define KEY_APP_ID @"appId"
#define KEY_ADVERTISING_ID @"advertisingId"
#define KEY_PLATFORM @"platform"
#define KEY_SDK_VERSION @"sdkVersion"
#define KEY_HOST @"host"
#define KEY_LEVEL @"level"
#define KEY_MESSAGE @"message"
#define KEY_DATE_TIME @"dateTime"
#define KEY_STACK_TRACE @"stackTrace"
#define KEY_MODULE_NAME @"moduleName"
#define KEY_SYSTEM_VERSION @"systemVersion"
#define KEY_DEVICE_MANUFACTURER @"deviceManufacturer"
#define KEY_DEVICE_MODEL @"deviceModel"
#define KEY_DEVICE_CODENAME @"deviceCodename"
#define KEY_APP_PACKAGE_NAME @"appPackageName"
#define KEY_APP_VERSION @"appVersion"
#define KEY_APP_VERSION_NAME @"appVersionName"
#define KEY_APP_VERSION_BUILD @"appVersionBuild"
#define KEY_IS_JAILBREAK @"isJailbreak"
#define KEY_STORAGE_PERCENTAGE_FREE @"storagePercentageFree"
#define KEY_MEMORY_PERCENTAGE_FREE @"memoryPercentageFree"
#define KEY_BATTERY_CHARGING @"batteryCharging"
#define KEY_BATTERY_PERCENTAGE @"batteryPercentage"
#define KEY_BATTERY_TEMPERATURE @"batteryTemperature"

// Key for plist
#define TYPE_PLIST @"plist"
#define KEY_APPS_SCHEMES @"LSApplicationQueriesSchemes"
#define KEY_MOTION_USAGE @"NSMotionUsageDescription"
#define HANDS_MDM_CONFIG @"MDMConfig"
#define HANDS_AD_SERVER @"MDMAdServerConfig"
#define KEY_MDM_AD_PUBLISHER_ID @"MDM_AD_PUBLISHER_ID"
#define KEY_MDM_ADSERVER_BASE @"MDM_ADSERVER_BASE"
#define KEY_MDM_AD_FORMATS @"MDM_AD_FORMATS"
#define KEY_MDM_AD_SCREENS @"MDM_AD_SCREENS"
#define ERROR_GET_APP @"App Behavior Exception"
#define ERROR_GET_APP_MESSAGE @"This app tried to check url schemes without a usage description. The application Info.plist must contain the \"LSApplicationQueriesSchemes\" key with the url schemas to query."

// Error Domain
#define ERROR_ADVERTISING_TRACKING @"Ad-Tracking is limited. User is limiting ad tracking in Settings/Privacy."

//// EndPoints MDM
//#define HANDS_ENDPOINT @"mdm-ad/app"
//#define HANDS_INSTALLED_APPS_ENDPOINT @"mdm-ad/app/installedapps"
//#define HANDS_APPS_ENDPOINT @"mdm-ad/appbehavior/conf" // Verificar se vai usar a lista do serviço ou plist
//#define HANDS_START_ENDPOINT @"init/"
//
//// EndPoints MBH
//#define GEOBEHAVIOR_API_ENDPOINT @"mbh-ad/v1/behavior"
//#define GEOLIVE_API_ENDPOINT @"mbh-ad/v1/live"
//#define GEOLOCATION_API_ENDPOINT @"mbh-ad/v2/latlng"
//#define REGISTER_TOKEN_API_ENDPOINT @"token"
//#define UNREGISTERTOKEN_API_ENDPOINT @"token"
//#define ACT_API_ENDPOINT @"mbh-ad/v2/act"
//#define UR_API_ENDPOINT @"mbh-ad/v2/ur"
//#define DOORBELL_API_ENDPOINT @"mbh-ad/doorbell"
//#define DEVICEBEHAVIOR_API_ENDPOINT @"behavior"
//
//// EndPoints PUSHER
//#define REPORT_NOTIFICATION_DELIVER_ENDPOINT @"deliver"
//#define REPORT_NOTIFICATION_INTERACTION_ENDPOINT @"interaction"
//#define REPORT_NOTIFICATION_OPEN_ENDPOINT @"open"
//
//
//// Graylog EndPoint
//#define GRAYLOG_ENDPOINT @"gelf"
//
//// Config EndPoint
//#define CONFIG_ENDPOINT @""
//
//#define KEY_MDM_PUBLISHER @"MDM_PUBLISHER"
//
//// Values for dictionary
//#define VALUE_OS_NAME @"ios"
//#define VALUE_COMEIN @"comein"
//#define VALUE_ACT @"act"
//#define VALUE_ADVERTISER_ID @"idfa"
//#define VALUE_DEVICE_MODEL @"device_model_id"
//
//#define VALUE_PUSH_C @"c"
//#define VALUE_PUSH_P @"p"
//
//#define VALUE_LOCATION_MODE @"location"
//
//#define KEY_CUSTOMER_ID @"cuid"
//#define KEY_DEVICE_ID @"duid"
//#define KEY_USER_EXTERNAL_ID @"exid"
//#define KEY_MDM_ID @"puid"
//
//#define KEY_CLIENT_ID @"clientId"
//#define KEY_PUBLISHER_ID @"publisherId"
//
//#define KEY_USER_ATTRIBUTES @"attributes"
//#define KEY_USER_AUDIENCES @"audiences"
//#define KEY_OS_NAME @"os"
//#define KEY_USER_EMAIL @"email"
//#define KEY_USER_CPF @"cpf"
//#define KEY_USER_PHONE @"phone"
//
//#define KEY_KEY @"key"
//#define KEY_VALUE @"value"
//#define KEY_ENCRYPTED @"encrypted"
//
//#define KEY_DEPARTURE_TIME @"dep"
//#define KEY_PRECISION @"p"
//#define KEY_BATTERY_STATE @"bst"
//#define KEY_BATTERY_LEVEL @"bl"
//#define KEY_TIME_CAPTURE @"time"
//#define KEY_LOCATION @"loc"
//#define KEY_ARRIVAL_TIME @"arr"
//#define KEY_OS_VERSION @"osv"
//#define KEY_DEVICE_MODEL @"dev"
//#define KEY_LOCATIONS @"locs"
//#define KEY_APPS_SCHEMES @"LSApplicationQueriesSchemes"
//#define KEY_INSTALLED_APPS @"installed_apps"
//#define KEY_TKN @"tkn"
//
//#define KEY_ADVERTISER_ID @"adid"
//
//#define KEY_PUSH_C @"c"
//#define KEY_PUSH_P @"p"
//#define KEY_PUSH_EU @"eu"
//#define KEY_PUSH_APP @"app"
//#define KEY_PUSH_PU @"pu"
//#define KEY_PUSH_T @"t"
//
//#define KEY_NOTIFICATION_TITLE @"aps.alert.title"
//#define KEY_NOTIFICATION_MDM @"mdm"
//#define KEY_NOTIFICATION_WC @"wc"

#endif /* MDMConstants_h */
