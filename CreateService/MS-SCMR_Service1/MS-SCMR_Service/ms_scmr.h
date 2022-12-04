

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ms_scmr.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=ARM64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#pragma once
#include <ntstatus.h>
#define WIN32_NO_STATUS
#define SECURITY_WIN32
#define CINTERFACE
#define COBJMACROS
#include <windows.h>
#include <sspi.h>
#include <sddl.h>
#include <wincred.h>
#include <ntsecapi.h>
#include <ntsecpkg.h>
#include <stdio.h>
#include <wchar.h>

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __ms_scmr_h__
#define __ms_scmr_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "ms-dtyp.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __svcctl_INTERFACE_DEFINED__
#define __svcctl_INTERFACE_DEFINED__

/* interface svcctl */
/* [unique][ms_union][version][uuid] */ 

#define	MAX_SERVICE_NAME_LENGTH	( 256 )

#define	SC_MAX_DEPEND_SIZE	( ( 4 * 1024 )  )

#define	SC_MAX_NAME_LENGTH	( ( MAX_SERVICE_NAME_LENGTH + 1 )  )

#define	SC_MAX_PATH_LENGTH	( ( 32 * 1024 )  )

#define	SC_MAX_PWD_SIZE	( 514 )

#define	SC_MAX_COMPUTER_NAME_LENGTH	( 1024 )

#define	SC_MAX_ACCOUNT_NAME_LENGTH	( ( 2 * 1024 )  )

#define	SC_MAX_COMMENT_LENGTH	( 128 )

#define	SC_MAX_ARGUMENT_LENGTH	( 1024 )

#define	SC_MAX_ARGUMENTS	( 1024 )

typedef /* [handle] */ wchar_t *SVCCTL_HANDLEW;

typedef /* [handle] */ LPSTR SVCCTL_HANDLEA;

typedef /* [context_handle] */ PVOID SC_RPC_HANDLE;

typedef /* [context_handle] */ PVOID SC_RPC_LOCK;

typedef /* [context_handle] */ PVOID SC_NOTIFY_RPC_HANDLE;

typedef SC_RPC_HANDLE *LPSC_RPC_HANDLE;

typedef SC_RPC_LOCK *LPSC_RPC_LOCK;

typedef SC_NOTIFY_RPC_HANDLE *LPSC_NOTIFY_RPC_HANDLE;

typedef struct _STRING_PTRSA
    {
    /* [range][string] */ LPSTR StringPtr;
    } 	STRING_PTRSA;

typedef struct _STRING_PTRSA *PSTRING_PTRSA;

typedef struct _STRING_PTRSA *LPSTRING_PTRSA;

typedef struct _STRING_PTRSW
    {
    /* [range][string] */ wchar_t *StringPtr;
    } 	STRING_PTRSW;

typedef struct _STRING_PTRSW *PSTRING_PTRSW;

typedef struct _STRING_PTRSW *LPSTRING_PTRSW;

typedef /* [range] */ DWORD BOUNDED_DWORD_4K;

typedef BOUNDED_DWORD_4K *LPBOUNDED_DWORD_4K;

typedef /* [range] */ DWORD BOUNDED_DWORD_8K;

typedef BOUNDED_DWORD_8K *LPBOUNDED_DWORD_8K;

typedef /* [range] */ DWORD BOUNDED_DWORD_256K;

typedef BOUNDED_DWORD_256K *LPBOUNDED_DWORD_256K;

//typedef CONST UNICODE_STRING* PCUNICODE_STRING;

extern VOID WINAPI RtlInitUnicodeString(OUT PUNICODE_STRING DestinationString, IN PCWSTR SourceString);
//extern BOOLEAN WINAPI RtlEqualUnicodeString(IN PCUNICODE_STRING String1, IN PCUNICODE_STRING String2, IN BOOLEAN CaseInSensitive);

//typedef /* [public][public][public][public][public] */ struct __MIDL_svcctl_0001
//    {
//    DWORD dwServiceType;
//    DWORD dwCurrentState;
//    DWORD dwControlsAccepted;
//    DWORD dwWin32ExitCode;
//    DWORD dwServiceSpecificExitCode;
//    DWORD dwCheckPoint;
//    DWORD dwWaitHint;
//    } 	SERVICE_STATUS;

//typedef struct __MIDL_svcctl_0001 *LPSERVICE_STATUS;

//typedef /* [public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public] */ struct __MIDL_svcctl_0002
//    {
//    DWORD dwServiceType;
//    DWORD dwCurrentState;
//    DWORD dwControlsAccepted;
//    DWORD dwWin32ExitCode;
//    DWORD dwServiceSpecificExitCode;
//    DWORD dwCheckPoint;
//    DWORD dwWaitHint;
//    DWORD dwProcessId;
//    DWORD dwServiceFlags;
//    } 	SERVICE_STATUS_PROCESS;

//typedef struct __MIDL_svcctl_0002 *LPSERVICE_STATUS_PROCESS;

//typedef struct _QUERY_SERVICE_CONFIGW
//    {
//    DWORD dwServiceType;
//    DWORD dwStartType;
//    DWORD dwErrorControl;
//    /* [range][string] */ LPWSTR lpBinaryPathName;
//    /* [range][string] */ LPWSTR lpLoadOrderGroup;
//    DWORD dwTagId;
//    /* [range][string] */ LPWSTR lpDependencies;
//    /* [range][string] */ LPWSTR lpServiceStartName;
//    /* [range][string] */ LPWSTR lpDisplayName;
//    } 	QUERY_SERVICE_CONFIGW;

typedef struct _QUERY_SERVICE_CONFIGW *LPQUERY_SERVICE_CONFIGW;

//typedef struct _QUERY_SERVICE_LOCK_STATUSW
//    {
//    DWORD fIsLocked;
//    /* [range][string] */ LPWSTR lpLockOwner;
//    DWORD dwLockDuration;
//    } 	QUERY_SERVICE_LOCK_STATUSW;

typedef struct _QUERY_SERVICE_LOCK_STATUSW *LPQUERY_SERVICE_LOCK_STATUSW;

//typedef struct _QUERY_SERVICE_CONFIGA
//    {
//    DWORD dwServiceType;
//    DWORD dwStartType;
//    DWORD dwErrorControl;
//    /* [range][string] */ LPSTR lpBinaryPathName;
//    /* [range][string] */ LPSTR lpLoadOrderGroup;
//    DWORD dwTagId;
//    /* [range][string] */ LPSTR lpDependencies;
//    /* [range][string] */ LPSTR lpServiceStartName;
//    /* [range][string] */ LPSTR lpDisplayName;
//    } 	QUERY_SERVICE_CONFIGA;

typedef struct _QUERY_SERVICE_CONFIGA *LPQUERY_SERVICE_CONFIGA;

//typedef /* [public] */ struct __MIDL_svcctl_0003
//    {
//    DWORD fIsLocked;
//    /* [range][string] */ unsigned char *lpLockOwner;
//    DWORD dwLockDuration;
//    } 	QUERY_SERVICE_LOCK_STATUSA;

//typedef struct __MIDL_svcctl_0003 *LPQUERY_SERVICE_LOCK_STATUSA;

//typedef struct _SERVICE_DESCRIPTIONA
//    {
//    /* [range][string] */ LPSTR lpDescription;
//    } 	SERVICE_DESCRIPTIONA;

typedef struct _SERVICE_DESCRIPTIONA *LPSERVICE_DESCRIPTIONA;

//typedef /* [v1_enum] */ 
//enum _SC_ACTION_TYPE
//    {
//        SC_ACTION_NONE	= 0,
//        SC_ACTION_RESTART	= 1,
//        SC_ACTION_REBOOT	= 2,
//        SC_ACTION_RUN_COMMAND	= 3
//    } 	SC_ACTION_TYPE;

//typedef /* [public][public][public][public][public][public][public][public][public][public] */ struct __MIDL_svcctl_0004
//    {
//    SC_ACTION_TYPE Type;
//    DWORD Delay;
//    } 	SC_ACTION;

//typedef struct __MIDL_svcctl_0004 *LPSC_ACTION;

//typedef struct _SERVICE_FAILURE_ACTIONSA
//    {
//    DWORD dwResetPeriod;
//    /* [range][string] */ LPSTR lpRebootMsg;
//    /* [range][string] */ LPSTR lpCommand;
//    /* [range] */ DWORD cActions;
//    /* [size_is] */ SC_ACTION *lpsaActions;
//    } 	SERVICE_FAILURE_ACTIONSA;

typedef struct _SERVICE_FAILURE_ACTIONSA *LPSERVICE_FAILURE_ACTIONSA;

//typedef struct _SERVICE_DELAYED_AUTO_START_INFO
//    {
//    BOOL fDelayedAutostart;
//    } 	SERVICE_DELAYED_AUTO_START_INFO;

typedef struct _SERVICE_DELAYED_AUTO_START_INFO *LPSERVICE_DELAYED_AUTO_START_INFO;

//typedef struct _SERVICE_FAILURE_ACTIONS_FLAG
//    {
//    BOOL fFailureActionsOnNonCrashFailures;
//    } 	SERVICE_FAILURE_ACTIONS_FLAG;

typedef struct _SERVICE_FAILURE_ACTIONS_FLAG *LPSERVICE_FAILURE_ACTIONS_FLAG;

//typedef struct _SERVICE_SID_INFO
//    {
//    DWORD dwServiceSidType;
//    } 	SERVICE_SID_INFO;

typedef struct _SERVICE_SID_INFO *LPSERVICE_SID_INFO;
//
//typedef struct _SERVICE_PRESHUTDOWN_INFO
//    {
//    DWORD dwPreshutdownTimeout;
//    } 	SERVICE_PRESHUTDOWN_INFO;

typedef struct _SERVICE_PRESHUTDOWN_INFO *LPSERVICE_PRESHUTDOWN_INFO;

//typedef struct _SERVICE_DESCRIPTIONW
//    {
//    /* [range][string] */ LPWSTR lpDescription;
//    } 	SERVICE_DESCRIPTIONW;

typedef struct _SERVICE_DESCRIPTIONW *LPSERVICE_DESCRIPTIONW;

//typedef struct _SERVICE_FAILURE_ACTIONSW
//    {
//    DWORD dwResetPeriod;
//    /* [range][string] */ LPWSTR lpRebootMsg;
//    /* [range][string] */ LPWSTR lpCommand;
//    /* [range] */ DWORD cActions;
//    /* [size_is] */ SC_ACTION *lpsaActions;
//    } 	SERVICE_FAILURE_ACTIONSW;

typedef struct _SERVICE_FAILURE_ACTIONSW *LPSERVICE_FAILURE_ACTIONSW;

//typedef /* [public][public][v1_enum] */ 
//enum __MIDL_svcctl_0005
//    {
//        SC_STATUS_PROCESS_INFO	= 0
//    } 	SC_STATUS_TYPE;

//typedef /* [public][public][public][v1_enum] */ 
//enum __MIDL_svcctl_0006
//    {
//        SC_ENUM_PROCESS_INFO	= 0
//    } 	SC_ENUM_TYPE;

//typedef struct _SERVICE_PREFERRED_NODE_INFO
//    {
//    USHORT usPreferredNode;
//    BOOLEAN fDelete;
//    } 	SERVICE_PREFERRED_NODE_INFO;

typedef struct _SERVICE_PREFERRED_NODE_INFO *LPSERVICE_PREFERRED_NODE_INFO;

//typedef struct _SERVICE_TRIGGER_SPECIFIC_DATA_ITEM
//    {
//    DWORD dwDataType;
//    /* [range] */ DWORD cbData;
//    /* [size_is] */ PBYTE pData;
//    } 	SERVICE_TRIGGER_SPECIFIC_DATA_ITEM;

typedef struct _SERVICE_TRIGGER_SPECIFIC_DATA_ITEM *PSERVICE_TRIGGER_SPECIFIC_DATA_ITEM;
//
//typedef struct _SERVICE_TRIGGER
//    {
//    DWORD dwTriggerType;
//    DWORD dwAction;
//    GUID *pTriggerSubtype;
//    /* [range] */ DWORD cDataItems;
//    /* [size_is] */ PSERVICE_TRIGGER_SPECIFIC_DATA_ITEM pDataItems;
//    } 	SERVICE_TRIGGER;

typedef struct _SERVICE_TRIGGER *PSERVICE_TRIGGER;

//typedef struct _SERVICE_TRIGGER_INFO
//    {
//    /* [range] */ DWORD cTriggers;
//    /* [size_is] */ PSERVICE_TRIGGER pTriggers;
//    PBYTE pReserved;
//    } 	SERVICE_TRIGGER_INFO;

typedef struct _SERVICE_TRIGGER_INFO *PSERVICE_TRIGGER_INFO;

typedef ULONG SECURITY_INFORMATION;

typedef ULONG *PSECURITY_INFORMATION;

//typedef struct _ENUM_SERVICE_STATUSA
//    {
//    LPSTR lpServiceName;
//    LPSTR lpDisplayName;
//    SERVICE_STATUS ServiceStatus;
//    } 	ENUM_SERVICE_STATUSA;

typedef struct _ENUM_SERVICE_STATUSA *LPENUM_SERVICE_STATUSA;

//typedef struct _ENUM_SERVICE_STATUSW
//    {
//    LPWSTR lpServiceName;
//    LPWSTR lpDisplayName;
//    SERVICE_STATUS ServiceStatus;
//    } 	ENUM_SERVICE_STATUSW;

typedef struct _ENUM_SERVICE_STATUSW *LPENUM_SERVICE_STATUSW;

//typedef struct _ENUM_SERVICE_STATUS_PROCESSA
//    {
//    LPSTR lpServiceName;
//    LPSTR lpDisplayName;
//    SERVICE_STATUS_PROCESS ServiceStatusProcess;
//    } 	ENUM_SERVICE_STATUS_PROCESSA;

typedef struct _ENUM_SERVICE_STATUS_PROCESSA *LPENUM_SERVICE_STATUS_PROCESSA;

//typedef struct _ENUM_SERVICE_STATUS_PROCESSW
//    {
//    LPWSTR lpServiceName;
//    LPWSTR lpDisplayName;
//    SERVICE_STATUS_PROCESS ServiceStatusProcess;
//    } 	ENUM_SERVICE_STATUS_PROCESSW;

typedef struct _ENUM_SERVICE_STATUS_PROCESSW *LPENUM_SERVICE_STATUS_PROCESSW;

typedef struct _SERVICE_DESCRIPTION_WOW64
    {
    DWORD dwDescriptionOffset;
    } 	SERVICE_DESCRIPTION_WOW64;

typedef struct _SERVICE_DESCRIPTION_WOW64 *LPSERVICE_DESCRIPTION_WOW64;

typedef struct _SERVICE_FAILURE_ACTIONS_WOW64
    {
    DWORD dwResetPeriod;
    DWORD dwRebootMsgOffset;
    DWORD dwCommandOffset;
    DWORD cActions;
    DWORD dwsaActionsOffset;
    } 	SERVICE_FAILURE_ACTIONS_WOW64;

typedef struct _SERVICE_FAILURE_ACTIONS_WOW64 *LPSERVICE_FAILURE_ACTIONS_WOW64;

typedef struct _SERVICE_REQUIRED_PRIVILEGES_INFO_WOW64
    {
    DWORD dwRequiredPrivilegesOffset;
    } 	SERVICE_REQUIRED_PRIVILEGES_INFO_WOW64;

typedef struct _SERVICE_REQUIRED_PRIVILEGES_INFO_WOW64 *LPSERVICE_REQUIRED_PRIVILEGES_INFO_WOW64;

DWORD RCloseServiceHandle( 
    /* [out][in] */ LPSC_RPC_HANDLE hSCObject);

DWORD RControlService( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ DWORD dwControl,
    /* [out] */ LPSERVICE_STATUS lpServiceStatus);

DWORD RDeleteService( 
    /* [in] */ SC_RPC_HANDLE hService);

DWORD RLockServiceDatabase( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [out] */ LPSC_RPC_LOCK lpLock);

DWORD RQueryServiceObjectSecurity( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ SECURITY_INFORMATION dwSecurityInformation,
    /* [size_is][out] */ LPBYTE lpSecurityDescriptor,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_256K pcbBytesNeeded);

DWORD RSetServiceObjectSecurity( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ SECURITY_INFORMATION dwSecurityInformation,
    /* [size_is][in] */ LPBYTE lpSecurityDescriptor,
    /* [in] */ DWORD cbBufSize);

DWORD RQueryServiceStatus( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [out] */ LPSERVICE_STATUS lpServiceStatus);

DWORD RSetServiceStatus( 
    /* [in] */ SC_RPC_HANDLE hServiceStatus,
    /* [in] */ LPSERVICE_STATUS lpServiceStatus);

DWORD RUnlockServiceDatabase( 
    /* [out][in] */ LPSC_RPC_LOCK Lock);

DWORD RNotifyBootConfigStatus( 
    /* [range][unique][string][in] */ SVCCTL_HANDLEW lpMachineName,
    /* [in] */ DWORD BootAcceptable);

void Opnum10NotUsedOnWire( 
    /* [in] */ handle_t IDL_handle);

DWORD RChangeServiceConfigW( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ DWORD dwServiceType,
    /* [in] */ DWORD dwStartType,
    /* [in] */ DWORD dwErrorControl,
    /* [range][unique][string][in] */ wchar_t *lpBinaryPathName,
    /* [range][unique][string][in] */ wchar_t *lpLoadOrderGroup,
    /* [unique][out][in] */ LPDWORD lpdwTagId,
    /* [size_is][unique][in] */ LPBYTE lpDependencies,
    /* [range][in] */ DWORD dwDependSize,
    /* [range][unique][string][in] */ wchar_t *lpServiceStartName,
    /* [size_is][unique][in] */ LPBYTE lpPassword,
    /* [range][in] */ DWORD dwPwSize,
    /* [range][unique][string][in] */ wchar_t *lpDisplayName);

DWORD RCreateServiceW( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [range][string][in] */ wchar_t *lpServiceName,
    /* [range][unique][string][in] */ wchar_t *lpDisplayName,
    /* [in] */ DWORD dwDesiredAccess,
    /* [in] */ DWORD dwServiceType,
    /* [in] */ DWORD dwStartType,
    /* [in] */ DWORD dwErrorControl,
    /* [range][string][in] */ wchar_t *lpBinaryPathName,
    /* [range][unique][string][in] */ wchar_t *lpLoadOrderGroup,
    /* [unique][out][in] */ LPDWORD lpdwTagId,
    /* [size_is][unique][in] */ LPBYTE lpDependencies,
    /* [range][in] */ DWORD dwDependSize,
    /* [range][unique][string][in] */ wchar_t *lpServiceStartName,
    /* [size_is][unique][in] */ LPBYTE lpPassword,
    /* [range][in] */ DWORD dwPwSize,
    /* [out] */ LPSC_RPC_HANDLE lpServiceHandle);

DWORD REnumDependentServicesW( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ DWORD dwServiceState,
    /* [size_is][out] */ LPBYTE lpServices,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_256K pcbBytesNeeded,
    /* [out] */ LPBOUNDED_DWORD_256K lpServicesReturned);

DWORD REnumServicesStatusW( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [in] */ DWORD dwServiceType,
    /* [in] */ DWORD dwServiceState,
    /* [size_is][out] */ LPBYTE lpBuffer,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_256K pcbBytesNeeded,
    /* [out] */ LPBOUNDED_DWORD_256K lpServicesReturned,
    /* [unique][out][in] */ LPBOUNDED_DWORD_256K lpResumeIndex);

DWORD ROpenSCManagerW( 
    /* [range][unique][string][in] */ SVCCTL_HANDLEW lpMachineName,
    /* [range][unique][string][in] */ wchar_t *lpDatabaseName,
    /* [in] */ DWORD dwDesiredAccess,
    /* [out] */ LPSC_RPC_HANDLE lpScHandle);

DWORD ROpenServiceW( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [range][string][in] */ wchar_t *lpServiceName,
    /* [in] */ DWORD dwDesiredAccess,
    /* [out] */ LPSC_RPC_HANDLE lpServiceHandle);

DWORD RQueryServiceConfigW( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [out] */ LPQUERY_SERVICE_CONFIGW lpServiceConfig,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_8K pcbBytesNeeded);

DWORD RQueryServiceLockStatusW( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [out] */ LPQUERY_SERVICE_LOCK_STATUSW lpLockStatus,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_4K pcbBytesNeeded);

DWORD RStartServiceW( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [range][in] */ DWORD argc,
    /* [size_is][unique][in] */ LPSTRING_PTRSW argv);

DWORD RGetServiceDisplayNameW( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [range][string][in] */ wchar_t *lpServiceName,
    /* [size_is][range][string][out] */ wchar_t *lpDisplayName,
    /* [out][in] */ DWORD *lpcchBuffer);

DWORD RGetServiceKeyNameW( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [range][string][in] */ wchar_t *lpDisplayName,
    /* [size_is][range][string][out] */ wchar_t *lpServiceName,
    /* [out][in] */ DWORD *lpcchBuffer);

void Opnum22NotUsedOnWire( 
    /* [in] */ handle_t IDL_handle);

DWORD RChangeServiceConfigA( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ DWORD dwServiceType,
    /* [in] */ DWORD dwStartType,
    /* [in] */ DWORD dwErrorControl,
    /* [range][unique][string][in] */ LPSTR lpBinaryPathName,
    /* [range][unique][string][in] */ LPSTR lpLoadOrderGroup,
    /* [unique][out][in] */ LPDWORD lpdwTagId,
    /* [size_is][unique][in] */ LPBYTE lpDependencies,
    /* [range][in] */ DWORD dwDependSize,
    /* [range][unique][string][in] */ LPSTR lpServiceStartName,
    /* [size_is][unique][in] */ LPBYTE lpPassword,
    /* [range][in] */ DWORD dwPwSize,
    /* [range][unique][string][in] */ LPSTR lpDisplayName);

DWORD RCreateServiceA( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [range][string][in] */ LPSTR lpServiceName,
    /* [range][unique][string][in] */ LPSTR lpDisplayName,
    /* [in] */ DWORD dwDesiredAccess,
    /* [in] */ DWORD dwServiceType,
    /* [in] */ DWORD dwStartType,
    /* [in] */ DWORD dwErrorControl,
    /* [range][string][in] */ LPSTR lpBinaryPathName,
    /* [range][unique][string][in] */ LPSTR lpLoadOrderGroup,
    /* [unique][out][in] */ LPDWORD lpdwTagId,
    /* [size_is][unique][in] */ LPBYTE lpDependencies,
    /* [range][in] */ DWORD dwDependSize,
    /* [range][unique][string][in] */ LPSTR lpServiceStartName,
    /* [size_is][unique][in] */ LPBYTE lpPassword,
    /* [range][in] */ DWORD dwPwSize,
    /* [out] */ LPSC_RPC_HANDLE lpServiceHandle);

DWORD REnumDependentServicesA( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ DWORD dwServiceState,
    /* [size_is][out] */ LPBYTE lpServices,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_256K pcbBytesNeeded,
    /* [out] */ LPBOUNDED_DWORD_256K lpServicesReturned);

DWORD REnumServicesStatusA( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [in] */ DWORD dwServiceType,
    /* [in] */ DWORD dwServiceState,
    /* [size_is][out] */ LPBYTE lpBuffer,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_256K pcbBytesNeeded,
    /* [out] */ LPBOUNDED_DWORD_256K lpServicesReturned,
    /* [unique][out][in] */ LPBOUNDED_DWORD_256K lpResumeIndex);

DWORD ROpenSCManagerA( 
    /* [range][unique][string][in] */ SVCCTL_HANDLEA lpMachineName,
    /* [range][unique][string][in] */ LPSTR lpDatabaseName,
    /* [in] */ DWORD dwDesiredAccess,
    /* [out] */ LPSC_RPC_HANDLE lpScHandle);

DWORD ROpenServiceA( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [range][string][in] */ LPSTR lpServiceName,
    /* [in] */ DWORD dwDesiredAccess,
    /* [out] */ LPSC_RPC_HANDLE lpServiceHandle);

DWORD RQueryServiceConfigA( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [out] */ LPQUERY_SERVICE_CONFIGA lpServiceConfig,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_8K pcbBytesNeeded);

DWORD RQueryServiceLockStatusA( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [out] */ LPQUERY_SERVICE_LOCK_STATUSA lpLockStatus,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_4K pcbBytesNeeded);

DWORD RStartServiceA( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [range][in] */ DWORD argc,
    /* [size_is][unique][in] */ LPSTRING_PTRSA argv);

DWORD RGetServiceDisplayNameA( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [range][string][in] */ LPSTR lpServiceName,
    /* [size_is][string][out] */ LPSTR lpDisplayName,
    /* [out][in] */ LPBOUNDED_DWORD_4K lpcchBuffer);

DWORD RGetServiceKeyNameA( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [range][string][in] */ LPSTR lpDisplayName,
    /* [size_is][string][out] */ LPSTR lpKeyName,
    /* [out][in] */ LPBOUNDED_DWORD_4K lpcchBuffer);

void Opnum34NotUsedOnWire( 
    /* [in] */ handle_t IDL_handle);

DWORD REnumServiceGroupW( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [in] */ DWORD dwServiceType,
    /* [in] */ DWORD dwServiceState,
    /* [size_is][out] */ LPBYTE lpBuffer,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_256K pcbBytesNeeded,
    /* [out] */ LPBOUNDED_DWORD_256K lpServicesReturned,
    /* [unique][out][in] */ LPBOUNDED_DWORD_256K lpResumeIndex,
    /* [range][unique][string][in] */ LPCWSTR pszGroupName);

typedef struct _SERVICE_RPC_REQUIRED_PRIVILEGES_INFO
    {
    /* [range] */ DWORD cbRequiredPrivileges;
    /* [size_is] */ PBYTE pRequiredPrivileges;
    } 	SERVICE_RPC_REQUIRED_PRIVILEGES_INFO;

typedef struct _SERVICE_RPC_REQUIRED_PRIVILEGES_INFO *LPSERVICE_RPC_REQUIRED_PRIVILEGES_INFO;

typedef struct _SC_RPC_CONFIG_INFOA
    {
    DWORD dwInfoLevel;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ LPSERVICE_DESCRIPTIONA psd;
        /* [case()] */ LPSERVICE_FAILURE_ACTIONSA psfa;
        /* [case()] */ LPSERVICE_DELAYED_AUTO_START_INFO psda;
        /* [case()] */ LPSERVICE_FAILURE_ACTIONS_FLAG psfaf;
        /* [case()] */ LPSERVICE_SID_INFO pssid;
        /* [case()] */ LPSERVICE_RPC_REQUIRED_PRIVILEGES_INFO psrp;
        /* [case()] */ LPSERVICE_PRESHUTDOWN_INFO psps;
        /* [case()] */ PSERVICE_TRIGGER_INFO psti;
        /* [case()] */ LPSERVICE_PREFERRED_NODE_INFO pspn;
        } 	;
    } 	SC_RPC_CONFIG_INFOA;

typedef struct _SC_RPC_CONFIG_INFOW
    {
    DWORD dwInfoLevel;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ LPSERVICE_DESCRIPTIONW psd;
        /* [case()] */ LPSERVICE_FAILURE_ACTIONSW psfa;
        /* [case()] */ LPSERVICE_DELAYED_AUTO_START_INFO psda;
        /* [case()] */ LPSERVICE_FAILURE_ACTIONS_FLAG psfaf;
        /* [case()] */ LPSERVICE_SID_INFO pssid;
        /* [case()] */ LPSERVICE_RPC_REQUIRED_PRIVILEGES_INFO psrp;
        /* [case()] */ LPSERVICE_PRESHUTDOWN_INFO psps;
        /* [case()] */ PSERVICE_TRIGGER_INFO psti;
        /* [case()] */ LPSERVICE_PREFERRED_NODE_INFO pspn;
        } 	;
    } 	SC_RPC_CONFIG_INFOW;

DWORD RChangeServiceConfig2A( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ SC_RPC_CONFIG_INFOA Info);

DWORD RChangeServiceConfig2W( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ SC_RPC_CONFIG_INFOW Info);

DWORD RQueryServiceConfig2A( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ DWORD dwInfoLevel,
    /* [size_is][out] */ LPBYTE lpBuffer,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_8K pcbBytesNeeded);

DWORD RQueryServiceConfig2W( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ DWORD dwInfoLevel,
    /* [size_is][out] */ LPBYTE lpBuffer,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_8K pcbBytesNeeded);

DWORD RQueryServiceStatusEx( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ SC_STATUS_TYPE InfoLevel,
    /* [size_is][out] */ LPBYTE lpBuffer,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_8K pcbBytesNeeded);

DWORD REnumServicesStatusExA( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [in] */ SC_ENUM_TYPE InfoLevel,
    /* [in] */ DWORD dwServiceType,
    /* [in] */ DWORD dwServiceState,
    /* [size_is][out] */ LPBYTE lpBuffer,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_256K pcbBytesNeeded,
    /* [out] */ LPBOUNDED_DWORD_256K lpServicesReturned,
    /* [unique][out][in] */ LPBOUNDED_DWORD_256K lpResumeIndex,
    /* [range][unique][string][in] */ LPCSTR pszGroupName);

DWORD REnumServicesStatusExW( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [in] */ SC_ENUM_TYPE InfoLevel,
    /* [in] */ DWORD dwServiceType,
    /* [in] */ DWORD dwServiceState,
    /* [size_is][out] */ LPBYTE lpBuffer,
    /* [range][in] */ DWORD cbBufSize,
    /* [out] */ LPBOUNDED_DWORD_256K pcbBytesNeeded,
    /* [out] */ LPBOUNDED_DWORD_256K lpServicesReturned,
    /* [unique][out][in] */ LPBOUNDED_DWORD_256K lpResumeIndex,
    /* [range][unique][string][in] */ LPCWSTR pszGroupName);

void Opnum43NotUsedOnWire( 
    /* [in] */ handle_t IDL_handle);

DWORD RCreateServiceWOW64A( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [range][string][in] */ LPSTR lpServiceName,
    /* [range][unique][string][in] */ LPSTR lpDisplayName,
    /* [in] */ DWORD dwDesiredAccess,
    /* [in] */ DWORD dwServiceType,
    /* [in] */ DWORD dwStartType,
    /* [in] */ DWORD dwErrorControl,
    /* [range][string][in] */ LPSTR lpBinaryPathName,
    /* [range][unique][string][in] */ LPSTR lpLoadOrderGroup,
    /* [unique][out][in] */ LPDWORD lpdwTagId,
    /* [size_is][unique][in] */ LPBYTE lpDependencies,
    /* [range][in] */ DWORD dwDependSize,
    /* [range][unique][string][in] */ LPSTR lpServiceStartName,
    /* [size_is][unique][in] */ LPBYTE lpPassword,
    /* [range][in] */ DWORD dwPwSize,
    /* [out] */ LPSC_RPC_HANDLE lpServiceHandle);

DWORD RCreateServiceWOW64W( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [range][string][in] */ wchar_t *lpServiceName,
    /* [range][unique][string][in] */ wchar_t *lpDisplayName,
    /* [in] */ DWORD dwDesiredAccess,
    /* [in] */ DWORD dwServiceType,
    /* [in] */ DWORD dwStartType,
    /* [in] */ DWORD dwErrorControl,
    /* [range][string][in] */ wchar_t *lpBinaryPathName,
    /* [range][unique][string][in] */ wchar_t *lpLoadOrderGroup,
    /* [unique][out][in] */ LPDWORD lpdwTagId,
    /* [size_is][unique][in] */ LPBYTE lpDependencies,
    /* [range][in] */ DWORD dwDependSize,
    /* [range][unique][string][in] */ wchar_t *lpServiceStartName,
    /* [size_is][unique][in] */ LPBYTE lpPassword,
    /* [range][in] */ DWORD dwPwSize,
    /* [out] */ LPSC_RPC_HANDLE lpServiceHandle);

void Opnum46NotUsedOnWire( 
    /* [in] */ handle_t IDL_handle);

typedef struct _SERVICE_NOTIFY_STATUS_CHANGE_PARAMS_1
    {
    ULONGLONG ullThreadId;
    DWORD dwNotifyMask;
    UCHAR CallbackAddressArray[ 16 ];
    UCHAR CallbackParamAddressArray[ 16 ];
    SERVICE_STATUS_PROCESS ServiceStatus;
    DWORD dwNotificationStatus;
    DWORD dwSequence;
    } 	SERVICE_NOTIFY_STATUS_CHANGE_PARAMS_1;

typedef struct _SERVICE_NOTIFY_STATUS_CHANGE_PARAMS_1 *PSERVICE_NOTIFY_STATUS_CHANGE_PARAMS_1;

typedef struct _SERVICE_NOTIFY_STATUS_CHANGE_PARAMS_2
    {
    ULONGLONG ullThreadId;
    DWORD dwNotifyMask;
    UCHAR CallbackAddressArray[ 16 ];
    UCHAR CallbackParamAddressArray[ 16 ];
    SERVICE_STATUS_PROCESS ServiceStatus;
    DWORD dwNotificationStatus;
    DWORD dwSequence;
    DWORD dwNotificationTriggered;
    /* [range][string] */ PWSTR pszServiceNames;
    } 	SERVICE_NOTIFY_STATUS_CHANGE_PARAMS_2;

typedef struct _SERVICE_NOTIFY_STATUS_CHANGE_PARAMS_2 *PSERVICE_NOTIFY_STATUS_CHANGE_PARAMS_2;

typedef SERVICE_NOTIFY_STATUS_CHANGE_PARAMS_2 SERVICE_NOTIFY_STATUS_CHANGE_PARAMS;

typedef SERVICE_NOTIFY_STATUS_CHANGE_PARAMS_2 *PSERVICE_NOTIFY_STATUS_CHANGE_PARAMS;

typedef struct _SC_RPC_NOTIFY_PARAMS
    {
    DWORD dwInfoLevel;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ PSERVICE_NOTIFY_STATUS_CHANGE_PARAMS_1 pStatusChangeParam1;
        /* [case()] */ PSERVICE_NOTIFY_STATUS_CHANGE_PARAMS_2 pStatusChangeParams;
        } 	;
    } 	SC_RPC_NOTIFY_PARAMS;

typedef struct _SC_RPC_NOTIFY_PARAMS_LIST
    {
    BOUNDED_DWORD_4K cElements;
    /* [size_is] */ SC_RPC_NOTIFY_PARAMS NotifyParamsArray[ 1 ];
    } 	SC_RPC_NOTIFY_PARAMS_LIST;

typedef struct _SC_RPC_NOTIFY_PARAMS_LIST *PSC_RPC_NOTIFY_PARAMS_LIST;

DWORD RNotifyServiceStatusChange( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ SC_RPC_NOTIFY_PARAMS NotifyParams,
    /* [in] */ GUID *pClientProcessGuid,
    /* [out] */ GUID *pSCMProcessGuid,
    /* [out] */ PBOOL pfCreateRemoteQueue,
    /* [out] */ LPSC_NOTIFY_RPC_HANDLE phNotify);

error_status_t RGetNotifyResults( 
    /* [in] */ SC_NOTIFY_RPC_HANDLE hNotify,
    /* [out] */ PSC_RPC_NOTIFY_PARAMS_LIST *ppNotifyParams);

DWORD RCloseNotifyHandle( 
    /* [out][in] */ LPSC_NOTIFY_RPC_HANDLE phNotify,
    /* [out] */ PBOOL pfApcFired);

typedef struct _SERVICE_CONTROL_STATUS_REASON_IN_PARAMSA
    {
    DWORD dwReason;
    /* [range][string] */ LPSTR pszComment;
    } 	SERVICE_CONTROL_STATUS_REASON_IN_PARAMSA;

typedef struct _SERVICE_CONTROL_STATUS_REASON_IN_PARAMSA *PSERVICE_CONTROL_STATUS_REASON_IN_PARAMSA;

typedef struct _SERVICE_CONTROL_STATUS_REASON_OUT_PARAMS
    {
    SERVICE_STATUS_PROCESS ServiceStatus;
    } 	SERVICE_CONTROL_STATUS_REASON_OUT_PARAMS;

typedef struct _SERVICE_CONTROL_STATUS_REASON_OUT_PARAMS *PSERVICE_CONTROL_STATUS_REASON_OUT_PARAMS;

typedef /* [switch_type] */ union _SC_RPC_SERVICE_CONTROL_IN_PARAMSA
    {
    /* [case()] */ PSERVICE_CONTROL_STATUS_REASON_IN_PARAMSA psrInParams;
    } 	SC_RPC_SERVICE_CONTROL_IN_PARAMSA;

typedef /* [switch_type] */ union _SC_RPC_SERVICE_CONTROL_IN_PARAMSA *PSC_RPC_SERVICE_CONTROL_IN_PARAMSA;

typedef /* [switch_type] */ union _SC_RPC_SERVICE_CONTROL_OUT_PARAMSA
    {
    /* [case()] */ PSERVICE_CONTROL_STATUS_REASON_OUT_PARAMS psrOutParams;
    } 	SC_RPC_SERVICE_CONTROL_OUT_PARAMSA;

typedef /* [switch_type] */ union _SC_RPC_SERVICE_CONTROL_OUT_PARAMSA *PSC_RPC_SERVICE_CONTROL_OUT_PARAMSA;

DWORD RControlServiceExA( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ DWORD dwControl,
    /* [in] */ DWORD dwInfoLevel,
    /* [switch_is][in] */ PSC_RPC_SERVICE_CONTROL_IN_PARAMSA pControlInParams,
    /* [switch_is][out] */ PSC_RPC_SERVICE_CONTROL_OUT_PARAMSA pControlOutParams);

typedef struct _SERVICE_CONTROL_STATUS_REASON_IN_PARAMSW
    {
    DWORD dwReason;
    /* [range][string] */ LPWSTR pszComment;
    } 	SERVICE_CONTROL_STATUS_REASON_IN_PARAMSW;

typedef struct _SERVICE_CONTROL_STATUS_REASON_IN_PARAMSW *PSERVICE_CONTROL_STATUS_REASON_IN_PARAMSW;

typedef /* [switch_type] */ union _SC_RPC_SERVICE_CONTROL_IN_PARAMSW
    {
    /* [case()] */ PSERVICE_CONTROL_STATUS_REASON_IN_PARAMSW psrInParams;
    } 	SC_RPC_SERVICE_CONTROL_IN_PARAMSW;

typedef /* [switch_type] */ union _SC_RPC_SERVICE_CONTROL_IN_PARAMSW *PSC_RPC_SERVICE_CONTROL_IN_PARAMSW;

typedef /* [switch_type] */ union _SC_RPC_SERVICE_CONTROL_OUT_PARAMSW
    {
    /* [case()] */ PSERVICE_CONTROL_STATUS_REASON_OUT_PARAMS psrOutParams;
    } 	SC_RPC_SERVICE_CONTROL_OUT_PARAMSW;

typedef /* [switch_type] */ union _SC_RPC_SERVICE_CONTROL_OUT_PARAMSW *PSC_RPC_SERVICE_CONTROL_OUT_PARAMSW;

DWORD RControlServiceExW( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ DWORD dwControl,
    /* [in] */ DWORD dwInfoLevel,
    /* [switch_is][in] */ PSC_RPC_SERVICE_CONTROL_IN_PARAMSW pControlInParams,
    /* [switch_is][out] */ PSC_RPC_SERVICE_CONTROL_OUT_PARAMSW pControlOutParams);

void Opnum52NotUsedOnWire( 
    /* [in] */ handle_t IDL_handle);

void Opnum53NotUsedOnWire( 
    /* [in] */ handle_t IDL_handle);

void Opnum54NotUsedOnWire( 
    /* [in] */ handle_t IDL_handle);

void Opnum55NotUsedOnWire( 
    /* [in] */ handle_t IDL_handle);

DWORD RQueryServiceConfigEx( 
    /* [in] */ SC_RPC_HANDLE hService,
    /* [in] */ DWORD dwInfoLevel,
    /* [out] */ SC_RPC_CONFIG_INFOW *pInfo);



extern RPC_IF_HANDLE svcctl_v2_0_c_ifspec;
extern RPC_IF_HANDLE svcctl_v2_0_s_ifspec;
#endif /* __svcctl_INTERFACE_DEFINED__ */

/* interface __MIDL_itf_ms_scmr_0000_0001 */
/* [local] */ 

void Opnum57NotUsedOnWire( void);

void Opnum58NotUsedOnWire( void);

void Opnum59NotUsedOnWire( void);

DWORD RCreateWowService( 
    /* [in] */ SC_RPC_HANDLE hSCManager,
    /* [range][string][in] */ wchar_t *lpServiceName,
    /* [range][unique][string][in] */ wchar_t *lpDisplayName,
    /* [in] */ DWORD dwDesiredAccess,
    /* [in] */ DWORD dwServiceType,
    /* [in] */ DWORD dwStartType,
    /* [in] */ DWORD dwErrorControl,
    /* [range][string][in] */ wchar_t *lpBinaryPathName,
    /* [range][unique][string][in] */ wchar_t *lpLoadOrderGroup,
    /* [unique][out][in] */ LPDWORD lpdwTagId,
    /* [size_is][unique][in] */ LPBYTE lpDependencies,
    /* [range][in] */ DWORD dwDependSize,
    /* [range][unique][string][in] */ wchar_t *lpServiceStartName,
    /* [size_is][unique][in] */ LPBYTE lpPassword,
    /* [range][in] */ DWORD dwPwSize,
    /* [in] */ USHORT dwServiceWowType,
    /* [out] */ LPSC_RPC_HANDLE lpServiceHandle);

void Opnum61NotUsedOnWire( void);

void Opnum62NotUsedOnWire( void);

void Opnum63NotUsedOnWire( void);

DWORD ROpenSCManager2( 
    /* [in] */ handle_t BindingHandle,
    /* [range][unique][string][in] */ wchar_t *DatabaseName,
    /* [in] */ DWORD DesiredAccess,
    /* [out] */ LPSC_RPC_HANDLE ScmHandle);



extern RPC_IF_HANDLE __MIDL_itf_ms_scmr_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ms_scmr_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

handle_t __RPC_USER SVCCTL_HANDLEW_bind ( SVCCTL_HANDLEW );
void     __RPC_USER SVCCTL_HANDLEW_unbind( SVCCTL_HANDLEW,  handle_t );
handle_t __RPC_USER SVCCTL_HANDLEW_bind ( SVCCTL_HANDLEW );
void     __RPC_USER SVCCTL_HANDLEW_unbind( SVCCTL_HANDLEW,  handle_t );
handle_t __RPC_USER SVCCTL_HANDLEA_bind ( SVCCTL_HANDLEA );
void     __RPC_USER SVCCTL_HANDLEA_unbind( SVCCTL_HANDLEA,  handle_t );

void __RPC_USER SC_RPC_HANDLE_rundown( SC_RPC_HANDLE );
void __RPC_USER SC_RPC_LOCK_rundown( SC_RPC_LOCK );
void __RPC_USER SC_NOTIFY_RPC_HANDLE_rundown( SC_NOTIFY_RPC_HANDLE );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


