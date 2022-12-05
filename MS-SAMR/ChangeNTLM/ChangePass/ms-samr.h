

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 21:14:07 2038
 */
 /* Compiler settings for ms-samr.idl:
     Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622
     protocol : dce , ms_ext, c_ext, robust
     error checks: allocation ref bounds_check enum stub_data
     VC __declspec() decoration level:
          __declspec(uuid()), __declspec(selectany), __declspec(novtable)
          DECLSPEC_UUID(), MIDL_INTERFACE()
 */
 /* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __ms2Dsamr_h__
#define __ms2Dsamr_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */

/* header files for imported files */
#include "ms-dtyp.h"

#ifdef __cplusplus
extern "C" {
#endif 


#ifndef __samr_INTERFACE_DEFINED__
#define __samr_INTERFACE_DEFINED__

    /* interface samr */
    /* [unique][ms_union][version][uuid] */

    typedef struct _RPC_STRING
    {
        unsigned short Length;
        unsigned short MaximumLength;
        /* [length_is][size_is] */ unsigned char* Buffer;
    } 	RPC_STRING;

    typedef struct _RPC_STRING* PRPC_STRING;

    typedef struct _OLD_LARGE_INTEGER
    {
        unsigned long LowPart;
        long HighPart;
    } 	OLD_LARGE_INTEGER;

    typedef struct _OLD_LARGE_INTEGER* POLD_LARGE_INTEGER;

    typedef /* [handle] */ wchar_t* PSAMPR_SERVER_NAME;

    typedef /* [context_handle] */ void* SAMPR_HANDLE;

    typedef struct _ENCRYPTED_LM_OWF_PASSWORD
    {
        unsigned char data[16];
    } 	ENCRYPTED_LM_OWF_PASSWORD;

    typedef struct _ENCRYPTED_LM_OWF_PASSWORD* PENCRYPTED_LM_OWF_PASSWORD;

    typedef struct _ENCRYPTED_LM_OWF_PASSWORD ENCRYPTED_NT_OWF_PASSWORD;

    typedef struct _ENCRYPTED_LM_OWF_PASSWORD* PENCRYPTED_NT_OWF_PASSWORD;

    typedef struct _SAMPR_ULONG_ARRAY
    {
        unsigned long Count;
        /* [size_is] */ unsigned long* Element;
    } 	SAMPR_ULONG_ARRAY;

    typedef struct _SAMPR_ULONG_ARRAY* PSAMPR_ULONG_ARRAY;

    typedef struct _SAMPR_SID_INFORMATION
    {
        PRPC_SID SidPointer;
    } 	SAMPR_SID_INFORMATION;

    typedef struct _SAMPR_SID_INFORMATION* PSAMPR_SID_INFORMATION;

    typedef struct _SAMPR_PSID_ARRAY
    {
        /* [range] */ unsigned long Count;
        /* [size_is] */ PSAMPR_SID_INFORMATION Sids;
    } 	SAMPR_PSID_ARRAY;

    typedef struct _SAMPR_PSID_ARRAY* PSAMPR_PSID_ARRAY;

    typedef struct _SAMPR_PSID_ARRAY_OUT
    {
        unsigned long Count;
        /* [size_is] */ PSAMPR_SID_INFORMATION Sids;
    } 	SAMPR_PSID_ARRAY_OUT;

    typedef struct _SAMPR_PSID_ARRAY_OUT* PSAMPR_PSID_ARRAY_OUT;

    typedef struct _SAMPR_RETURNED_USTRING_ARRAY
    {
        unsigned long Count;
        /* [size_is] */ PRPC_UNICODE_STRING Element;
    } 	SAMPR_RETURNED_USTRING_ARRAY;

    typedef struct _SAMPR_RETURNED_USTRING_ARRAY* PSAMPR_RETURNED_USTRING_ARRAY;

    /*
    typedef
        enum _SID_NAME_USE
    {
        SidTypeUser = 1,
        SidTypeGroup = (SidTypeUser + 1),
        SidTypeDomain = (SidTypeGroup + 1),
        SidTypeAlias = (SidTypeDomain + 1),
        SidTypeWellKnownGroup = (SidTypeAlias + 1),
        SidTypeDeletedAccount = (SidTypeWellKnownGroup + 1),
        SidTypeInvalid = (SidTypeDeletedAccount + 1),
        SidTypeUnknown = (SidTypeInvalid + 1),
        SidTypeComputer = (SidTypeUnknown + 1),
        SidTypeLabel = (SidTypeComputer + 1)
    } 	SID_NAME_USE;
    */

    typedef enum _SID_NAME_USE* PSID_NAME_USE;

    typedef struct _RPC_SHORT_BLOB
    {
        unsigned short Length;
        unsigned short MaximumLength;
        /* [length_is][size_is] */ unsigned short* Buffer;
    } 	RPC_SHORT_BLOB;

    typedef struct _RPC_SHORT_BLOB* PRPC_SHORT_BLOB;

    typedef struct _SAMPR_RID_ENUMERATION
    {
        unsigned long RelativeId;
        RPC_UNICODE_STRING Name;
    } 	SAMPR_RID_ENUMERATION;

    typedef struct _SAMPR_RID_ENUMERATION* PSAMPR_RID_ENUMERATION;

    typedef struct _SAMPR_ENUMERATION_BUFFER
    {
        unsigned long EntriesRead;
        /* [size_is] */ PSAMPR_RID_ENUMERATION Buffer;
    } 	SAMPR_ENUMERATION_BUFFER;

    typedef struct _SAMPR_ENUMERATION_BUFFER* PSAMPR_ENUMERATION_BUFFER;

    typedef struct _SAMPR_SR_SECURITY_DESCRIPTOR
    {
        /* [range] */ unsigned long Length;
        /* [size_is] */ unsigned char* SecurityDescriptor;
    } 	SAMPR_SR_SECURITY_DESCRIPTOR;

    typedef struct _SAMPR_SR_SECURITY_DESCRIPTOR* PSAMPR_SR_SECURITY_DESCRIPTOR;

    typedef struct _GROUP_MEMBERSHIP
    {
        unsigned long RelativeId;
        unsigned long Attributes;
    } 	GROUP_MEMBERSHIP;

    typedef struct _GROUP_MEMBERSHIP* PGROUP_MEMBERSHIP;

    typedef struct _SAMPR_GET_GROUPS_BUFFER
    {
        unsigned long MembershipCount;
        /* [size_is] */ PGROUP_MEMBERSHIP Groups;
    } 	SAMPR_GET_GROUPS_BUFFER;

    typedef struct _SAMPR_GET_GROUPS_BUFFER* PSAMPR_GET_GROUPS_BUFFER;

    typedef struct _SAMPR_GET_MEMBERS_BUFFER
    {
        unsigned long MemberCount;
        /* [size_is] */ unsigned long* Members;
        /* [size_is] */ unsigned long* Attributes;
    } 	SAMPR_GET_MEMBERS_BUFFER;

    typedef struct _SAMPR_GET_MEMBERS_BUFFER* PSAMPR_GET_MEMBERS_BUFFER;

    typedef struct _SAMPR_REVISION_INFO_V1
    {
        unsigned long Revision;
        unsigned long SupportedFeatures;
    } 	SAMPR_REVISION_INFO_V1;

    typedef struct _SAMPR_REVISION_INFO_V1* PSAMPR_REVISION_INFO_V1;

    typedef /* [public][public][public][switch_type] */ union __MIDL_samr_0001
    {
        /* [case()] */ SAMPR_REVISION_INFO_V1 V1;
    } 	SAMPR_REVISION_INFO;

    typedef /* [switch_type] */ union __MIDL_samr_0001* PSAMPR_REVISION_INFO;

    typedef struct _USER_DOMAIN_PASSWORD_INFORMATION
    {
        unsigned short MinPasswordLength;
        unsigned long PasswordProperties;
    } 	USER_DOMAIN_PASSWORD_INFORMATION;

    typedef struct _USER_DOMAIN_PASSWORD_INFORMATION* PUSER_DOMAIN_PASSWORD_INFORMATION;

    typedef
        enum _DOMAIN_SERVER_ENABLE_STATE
    {
        DomainServerEnabled = 1,
        DomainServerDisabled = (DomainServerEnabled + 1)
    } 	DOMAIN_SERVER_ENABLE_STATE;

    typedef enum _DOMAIN_SERVER_ENABLE_STATE* PDOMAIN_SERVER_ENABLE_STATE;

    typedef struct _DOMAIN_STATE_INFORMATION
    {
        DOMAIN_SERVER_ENABLE_STATE DomainServerState;
    } 	DOMAIN_STATE_INFORMATION;

    typedef struct _DOMAIN_STATE_INFORMATION* PDOMAIN_STATE_INFORMATION;

    typedef
        enum _DOMAIN_SERVER_ROLE
    {
        DomainServerRoleBackup = 2,
        DomainServerRolePrimary = 3
    } 	DOMAIN_SERVER_ROLE;

    typedef enum _DOMAIN_SERVER_ROLE* PDOMAIN_SERVER_ROLE;

    typedef struct _DOMAIN_PASSWORD_INFORMATION
    {
        unsigned short MinPasswordLength;
        unsigned short PasswordHistoryLength;
        unsigned long PasswordProperties;
        OLD_LARGE_INTEGER MaxPasswordAge;
        OLD_LARGE_INTEGER MinPasswordAge;
    } 	DOMAIN_PASSWORD_INFORMATION;

    typedef struct _DOMAIN_PASSWORD_INFORMATION* PDOMAIN_PASSWORD_INFORMATION;

    typedef struct _DOMAIN_LOGOFF_INFORMATION
    {
        OLD_LARGE_INTEGER ForceLogoff;
    } 	DOMAIN_LOGOFF_INFORMATION;

    typedef struct _DOMAIN_LOGOFF_INFORMATION* PDOMAIN_LOGOFF_INFORMATION;

    typedef struct _DOMAIN_SERVER_ROLE_INFORMATION
    {
        DOMAIN_SERVER_ROLE DomainServerRole;
    } 	DOMAIN_SERVER_ROLE_INFORMATION;

    typedef struct _DOMAIN_SERVER_ROLE_INFORMATION* PDOMAIN_SERVER_ROLE_INFORMATION;

    typedef struct _DOMAIN_MODIFIED_INFORMATION
    {
        OLD_LARGE_INTEGER DomainModifiedCount;
        OLD_LARGE_INTEGER CreationTime;
    } 	DOMAIN_MODIFIED_INFORMATION;

    typedef struct _DOMAIN_MODIFIED_INFORMATION* PDOMAIN_MODIFIED_INFORMATION;

    typedef struct _DOMAIN_MODIFIED_INFORMATION2
    {
        OLD_LARGE_INTEGER DomainModifiedCount;
        OLD_LARGE_INTEGER CreationTime;
        OLD_LARGE_INTEGER ModifiedCountAtLastPromotion;
    } 	DOMAIN_MODIFIED_INFORMATION2;

    typedef struct _DOMAIN_MODIFIED_INFORMATION2* PDOMAIN_MODIFIED_INFORMATION2;


#pragma pack(4)
    typedef struct _SAMPR_DOMAIN_GENERAL_INFORMATION
    {
        OLD_LARGE_INTEGER ForceLogoff;
        RPC_UNICODE_STRING OemInformation;
        RPC_UNICODE_STRING DomainName;
        RPC_UNICODE_STRING ReplicaSourceNodeName;
        OLD_LARGE_INTEGER DomainModifiedCount;
        unsigned long DomainServerState;
        unsigned long DomainServerRole;
        unsigned char UasCompatibilityRequired;
        unsigned long UserCount;
        unsigned long GroupCount;
        unsigned long AliasCount;
    } 	SAMPR_DOMAIN_GENERAL_INFORMATION;

    typedef struct _SAMPR_DOMAIN_GENERAL_INFORMATION* PSAMPR_DOMAIN_GENERAL_INFORMATION;


#pragma pack()

#pragma pack(4)
    typedef struct _SAMPR_DOMAIN_GENERAL_INFORMATION2
    {
        SAMPR_DOMAIN_GENERAL_INFORMATION I1;
        LARGE_INTEGER LockoutDuration;
        LARGE_INTEGER LockoutObservationWindow;
        unsigned short LockoutThreshold;
    } 	SAMPR_DOMAIN_GENERAL_INFORMATION2;

    typedef struct _SAMPR_DOMAIN_GENERAL_INFORMATION2* PSAMPR_DOMAIN_GENERAL_INFORMATION2;


#pragma pack()
    typedef struct _SAMPR_DOMAIN_OEM_INFORMATION
    {
        RPC_UNICODE_STRING OemInformation;
    } 	SAMPR_DOMAIN_OEM_INFORMATION;

    typedef struct _SAMPR_DOMAIN_OEM_INFORMATION* PSAMPR_DOMAIN_OEM_INFORMATION;

    typedef struct _SAMPR_DOMAIN_NAME_INFORMATION
    {
        RPC_UNICODE_STRING DomainName;
    } 	SAMPR_DOMAIN_NAME_INFORMATION;

    typedef struct _SAMPR_DOMAIN_NAME_INFORMATION* PSAMPR_DOMAIN_NAME_INFORMATION;

    typedef struct SAMPR_DOMAIN_REPLICATION_INFORMATION
    {
        RPC_UNICODE_STRING ReplicaSourceNodeName;
    } 	SAMPR_DOMAIN_REPLICATION_INFORMATION;

    typedef struct SAMPR_DOMAIN_REPLICATION_INFORMATION* PSAMPR_DOMAIN_REPLICATION_INFORMATION;

    typedef struct _SAMPR_DOMAIN_LOCKOUT_INFORMATION
    {
        LARGE_INTEGER LockoutDuration;
        LARGE_INTEGER LockoutObservationWindow;
        unsigned short LockoutThreshold;
    } 	SAMPR_DOMAIN_LOCKOUT_INFORMATION;

    typedef struct _SAMPR_DOMAIN_LOCKOUT_INFORMATION* PSAMPR_DOMAIN_LOCKOUT_INFORMATION;

    typedef
        enum _DOMAIN_INFORMATION_CLASS
    {
        DomainPasswordInformation = 1,
        DomainGeneralInformation = 2,
        DomainLogoffInformation = 3,
        DomainOemInformation = 4,
        DomainNameInformation = 5,
        DomainReplicationInformation = 6,
        DomainServerRoleInformation = 7,
        DomainModifiedInformation = 8,
        DomainStateInformation = 9,
        DomainGeneralInformation2 = 11,
        DomainLockoutInformation = 12,
        DomainModifiedInformation2 = 13
    } 	DOMAIN_INFORMATION_CLASS;

    typedef /* [switch_type] */ union _SAMPR_DOMAIN_INFO_BUFFER
    {
        /* [case()] */ DOMAIN_PASSWORD_INFORMATION Password;
        /* [case()] */ SAMPR_DOMAIN_GENERAL_INFORMATION General;
        /* [case()] */ DOMAIN_LOGOFF_INFORMATION Logoff;
        /* [case()] */ SAMPR_DOMAIN_OEM_INFORMATION Oem;
        /* [case()] */ SAMPR_DOMAIN_NAME_INFORMATION Name;
        /* [case()] */ DOMAIN_SERVER_ROLE_INFORMATION Role;
        /* [case()] */ SAMPR_DOMAIN_REPLICATION_INFORMATION Replication;
        /* [case()] */ DOMAIN_MODIFIED_INFORMATION Modified;
        /* [case()] */ DOMAIN_STATE_INFORMATION State;
        /* [case()] */ SAMPR_DOMAIN_GENERAL_INFORMATION2 General2;
        /* [case()] */ SAMPR_DOMAIN_LOCKOUT_INFORMATION Lockout;
        /* [case()] */ DOMAIN_MODIFIED_INFORMATION2 Modified2;
    } 	SAMPR_DOMAIN_INFO_BUFFER;

    typedef /* [switch_type] */ union _SAMPR_DOMAIN_INFO_BUFFER* PSAMPR_DOMAIN_INFO_BUFFER;

    typedef
        enum _DOMAIN_DISPLAY_INFORMATION
    {
        DomainDisplayUser = 1,
        DomainDisplayMachine = (DomainDisplayUser + 1),
        DomainDisplayGroup = (DomainDisplayMachine + 1),
        DomainDisplayOemUser = (DomainDisplayGroup + 1),
        DomainDisplayOemGroup = (DomainDisplayOemUser + 1)
    } 	DOMAIN_DISPLAY_INFORMATION;

    typedef enum _DOMAIN_DISPLAY_INFORMATION* PDOMAIN_DISPLAY_INFORMATION;

    typedef struct _SAMPR_DOMAIN_DISPLAY_USER
    {
        unsigned long Index;
        unsigned long Rid;
        unsigned long AccountControl;
        RPC_UNICODE_STRING AccountName;
        RPC_UNICODE_STRING AdminComment;
        RPC_UNICODE_STRING FullName;
    } 	SAMPR_DOMAIN_DISPLAY_USER;

    typedef struct _SAMPR_DOMAIN_DISPLAY_USER* PSAMPR_DOMAIN_DISPLAY_USER;

    typedef struct _SAMPR_DOMAIN_DISPLAY_MACHINE
    {
        unsigned long Index;
        unsigned long Rid;
        unsigned long AccountControl;
        RPC_UNICODE_STRING AccountName;
        RPC_UNICODE_STRING AdminComment;
    } 	SAMPR_DOMAIN_DISPLAY_MACHINE;

    typedef struct _SAMPR_DOMAIN_DISPLAY_MACHINE* PSAMPR_DOMAIN_DISPLAY_MACHINE;

    typedef struct _SAMPR_DOMAIN_DISPLAY_GROUP
    {
        unsigned long Index;
        unsigned long Rid;
        unsigned long Attributes;
        RPC_UNICODE_STRING AccountName;
        RPC_UNICODE_STRING AdminComment;
    } 	SAMPR_DOMAIN_DISPLAY_GROUP;

    typedef struct _SAMPR_DOMAIN_DISPLAY_GROUP* PSAMPR_DOMAIN_DISPLAY_GROUP;

    typedef struct _SAMPR_DOMAIN_DISPLAY_OEM_USER
    {
        unsigned long Index;
        RPC_STRING OemAccountName;
    } 	SAMPR_DOMAIN_DISPLAY_OEM_USER;

    typedef struct _SAMPR_DOMAIN_DISPLAY_OEM_USER* PSAMPR_DOMAIN_DISPLAY_OEM_USER;

    typedef struct _SAMPR_DOMAIN_DISPLAY_OEM_GROUP
    {
        unsigned long Index;
        RPC_STRING OemAccountName;
    } 	SAMPR_DOMAIN_DISPLAY_OEM_GROUP;

    typedef struct _SAMPR_DOMAIN_DISPLAY_OEM_GROUP* PSAMPR_DOMAIN_DISPLAY_OEM_GROUP;

    typedef struct _SAMPR_DOMAIN_DISPLAY_USER_BUFFER
    {
        unsigned long EntriesRead;
        /* [size_is] */ PSAMPR_DOMAIN_DISPLAY_USER Buffer;
    } 	SAMPR_DOMAIN_DISPLAY_USER_BUFFER;

    typedef struct _SAMPR_DOMAIN_DISPLAY_USER_BUFFER* PSAMPR_DOMAIN_DISPLAY_USER_BUFFER;

    typedef struct _SAMPR_DOMAIN_DISPLAY_MACHINE_BUFFER
    {
        unsigned long EntriesRead;
        /* [size_is] */ PSAMPR_DOMAIN_DISPLAY_MACHINE Buffer;
    } 	SAMPR_DOMAIN_DISPLAY_MACHINE_BUFFER;

    typedef struct _SAMPR_DOMAIN_DISPLAY_MACHINE_BUFFER* PSAMPR_DOMAIN_DISPLAY_MACHINE_BUFFER;

    typedef struct _SAMPR_DOMAIN_DISPLAY_GROUP_BUFFER
    {
        unsigned long EntriesRead;
        /* [size_is] */ PSAMPR_DOMAIN_DISPLAY_GROUP Buffer;
    } 	SAMPR_DOMAIN_DISPLAY_GROUP_BUFFER;

    typedef struct _SAMPR_DOMAIN_DISPLAY_GROUP_BUFFER* PSAMPR_DOMAIN_DISPLAY_GROUP_BUFFER;

    typedef struct _SAMPR_DOMAIN_DISPLAY_OEM_USER_BUFFER
    {
        unsigned long EntriesRead;
        /* [size_is] */ PSAMPR_DOMAIN_DISPLAY_OEM_USER Buffer;
    } 	SAMPR_DOMAIN_DISPLAY_OEM_USER_BUFFER;

    typedef struct _SAMPR_DOMAIN_DISPLAY_OEM_USER_BUFFER* PSAMPR_DOMAIN_DISPLAY_OEM_USER_BUFFER;

    typedef struct _SAMPR_DOMAIN_DISPLAY_OEM_GROUP_BUFFER
    {
        unsigned long EntriesRead;
        /* [size_is] */ PSAMPR_DOMAIN_DISPLAY_OEM_GROUP Buffer;
    } 	SAMPR_DOMAIN_DISPLAY_OEM_GROUP_BUFFER;

    typedef struct _SAMPR_DOMAIN_DISPLAY_OEM_GROUP_BUFFER* PSAMPR_DOMAIN_DISPLAY_OEM_GROUP_BUFFER;

    typedef /* [switch_type] */ union _SAMPR_DISPLAY_INFO_BUFFER
    {
        /* [case()] */ SAMPR_DOMAIN_DISPLAY_USER_BUFFER UserInformation;
        /* [case()] */ SAMPR_DOMAIN_DISPLAY_MACHINE_BUFFER MachineInformation;
        /* [case()] */ SAMPR_DOMAIN_DISPLAY_GROUP_BUFFER GroupInformation;
        /* [case()] */ SAMPR_DOMAIN_DISPLAY_OEM_USER_BUFFER OemUserInformation;
        /* [case()] */ SAMPR_DOMAIN_DISPLAY_OEM_GROUP_BUFFER OemGroupInformation;
    } 	SAMPR_DISPLAY_INFO_BUFFER;

    typedef /* [switch_type] */ union _SAMPR_DISPLAY_INFO_BUFFER* PSAMPR_DISPLAY_INFO_BUFFER;

    typedef struct _GROUP_ATTRIBUTE_INFORMATION
    {
        unsigned long Attributes;
    } 	GROUP_ATTRIBUTE_INFORMATION;

    typedef struct _GROUP_ATTRIBUTE_INFORMATION* PGROUP_ATTRIBUTE_INFORMATION;

    typedef struct _SAMPR_GROUP_GENERAL_INFORMATION
    {
        RPC_UNICODE_STRING Name;
        unsigned long Attributes;
        unsigned long MemberCount;
        RPC_UNICODE_STRING AdminComment;
    } 	SAMPR_GROUP_GENERAL_INFORMATION;

    typedef struct _SAMPR_GROUP_GENERAL_INFORMATION* PSAMPR_GROUP_GENERAL_INFORMATION;

    typedef struct _SAMPR_GROUP_NAME_INFORMATION
    {
        RPC_UNICODE_STRING Name;
    } 	SAMPR_GROUP_NAME_INFORMATION;

    typedef struct _SAMPR_GROUP_NAME_INFORMATION* PSAMPR_GROUP_NAME_INFORMATION;

    typedef struct _SAMPR_GROUP_ADM_COMMENT_INFORMATION
    {
        RPC_UNICODE_STRING AdminComment;
    } 	SAMPR_GROUP_ADM_COMMENT_INFORMATION;

    typedef struct _SAMPR_GROUP_ADM_COMMENT_INFORMATION* PSAMPR_GROUP_ADM_COMMENT_INFORMATION;

    typedef
        enum _GROUP_INFORMATION_CLASS
    {
        GroupGeneralInformation = 1,
        GroupNameInformation = (GroupGeneralInformation + 1),
        GroupAttributeInformation = (GroupNameInformation + 1),
        GroupAdminCommentInformation = (GroupAttributeInformation + 1),
        GroupReplicationInformation = (GroupAdminCommentInformation + 1)
    } 	GROUP_INFORMATION_CLASS;

    typedef /* [switch_type] */ union _SAMPR_GROUP_INFO_BUFFER
    {
        /* [case()] */ SAMPR_GROUP_GENERAL_INFORMATION General;
        /* [case()] */ SAMPR_GROUP_NAME_INFORMATION Name;
        /* [case()] */ GROUP_ATTRIBUTE_INFORMATION Attribute;
        /* [case()] */ SAMPR_GROUP_ADM_COMMENT_INFORMATION AdminComment;
        /* [case()] */ SAMPR_GROUP_GENERAL_INFORMATION DoNotUse;
    } 	SAMPR_GROUP_INFO_BUFFER;

    typedef /* [switch_type] */ union _SAMPR_GROUP_INFO_BUFFER* PSAMPR_GROUP_INFO_BUFFER;

    typedef struct _SAMPR_ALIAS_GENERAL_INFORMATION
    {
        RPC_UNICODE_STRING Name;
        unsigned long MemberCount;
        RPC_UNICODE_STRING AdminComment;
    } 	SAMPR_ALIAS_GENERAL_INFORMATION;

    typedef struct _SAMPR_ALIAS_GENERAL_INFORMATION* PSAMPR_ALIAS_GENERAL_INFORMATION;

    typedef struct _SAMPR_ALIAS_NAME_INFORMATION
    {
        RPC_UNICODE_STRING Name;
    } 	SAMPR_ALIAS_NAME_INFORMATION;

    typedef struct _SAMPR_ALIAS_NAME_INFORMATION* PSAMPR_ALIAS_NAME_INFORMATION;

    typedef struct _SAMPR_ALIAS_ADM_COMMENT_INFORMATION
    {
        RPC_UNICODE_STRING AdminComment;
    } 	SAMPR_ALIAS_ADM_COMMENT_INFORMATION;

    typedef struct _SAMPR_ALIAS_ADM_COMMENT_INFORMATION* PSAMPR_ALIAS_ADM_COMMENT_INFORMATION;

    typedef
        enum _ALIAS_INFORMATION_CLASS
    {
        AliasGeneralInformation = 1,
        AliasNameInformation = (AliasGeneralInformation + 1),
        AliasAdminCommentInformation = (AliasNameInformation + 1)
    } 	ALIAS_INFORMATION_CLASS;

    typedef /* [switch_type] */ union _SAMPR_ALIAS_INFO_BUFFER
    {
        /* [case()] */ SAMPR_ALIAS_GENERAL_INFORMATION General;
        /* [case()] */ SAMPR_ALIAS_NAME_INFORMATION Name;
        /* [case()] */ SAMPR_ALIAS_ADM_COMMENT_INFORMATION AdminComment;
    } 	SAMPR_ALIAS_INFO_BUFFER;

    typedef /* [switch_type] */ union _SAMPR_ALIAS_INFO_BUFFER* PSAMPR_ALIAS_INFO_BUFFER;

    typedef struct _SAMPR_ENCRYPTED_USER_PASSWORD
    {
        unsigned char Buffer[516];
    } 	SAMPR_ENCRYPTED_USER_PASSWORD;

    typedef struct _SAMPR_ENCRYPTED_USER_PASSWORD* PSAMPR_ENCRYPTED_USER_PASSWORD;

    typedef struct _SAMPR_ENCRYPTED_USER_PASSWORD_NEW
    {
        unsigned char Buffer[532];
    } 	SAMPR_ENCRYPTED_USER_PASSWORD_NEW;

    typedef struct _SAMPR_ENCRYPTED_USER_PASSWORD_NEW* PSAMPR_ENCRYPTED_USER_PASSWORD_NEW;

    typedef struct _USER_PRIMARY_GROUP_INFORMATION
    {
        unsigned long PrimaryGroupId;
    } 	USER_PRIMARY_GROUP_INFORMATION;

    typedef struct _USER_PRIMARY_GROUP_INFORMATION* PUSER_PRIMARY_GROUP_INFORMATION;

    typedef struct _USER_CONTROL_INFORMATION
    {
        unsigned long UserAccountControl;
    } 	USER_CONTROL_INFORMATION;

    typedef struct _USER_CONTROL_INFORMATION* PUSER_CONTROL_INFORMATION;

    typedef struct _USER_EXPIRES_INFORMATION
    {
        OLD_LARGE_INTEGER AccountExpires;
    } 	USER_EXPIRES_INFORMATION;

    typedef struct _USER_EXPIRES_INFORMATION* PUSER_EXPIRES_INFORMATION;

    typedef struct _SAMPR_LOGON_HOURS
    {
        unsigned short UnitsPerWeek;
        /* [length_is][size_is] */ unsigned char* LogonHours;
    } 	SAMPR_LOGON_HOURS;

    typedef struct _SAMPR_LOGON_HOURS* PSAMPR_LOGON_HOURS;

    typedef struct _SAMPR_USER_ALL_INFORMATION
    {
        OLD_LARGE_INTEGER LastLogon;
        OLD_LARGE_INTEGER LastLogoff;
        OLD_LARGE_INTEGER PasswordLastSet;
        OLD_LARGE_INTEGER AccountExpires;
        OLD_LARGE_INTEGER PasswordCanChange;
        OLD_LARGE_INTEGER PasswordMustChange;
        RPC_UNICODE_STRING UserName;
        RPC_UNICODE_STRING FullName;
        RPC_UNICODE_STRING HomeDirectory;
        RPC_UNICODE_STRING HomeDirectoryDrive;
        RPC_UNICODE_STRING ScriptPath;
        RPC_UNICODE_STRING ProfilePath;
        RPC_UNICODE_STRING AdminComment;
        RPC_UNICODE_STRING WorkStations;
        RPC_UNICODE_STRING UserComment;
        RPC_UNICODE_STRING Parameters;
        RPC_SHORT_BLOB LmOwfPassword;
        RPC_SHORT_BLOB NtOwfPassword;
        RPC_UNICODE_STRING PrivateData;
        SAMPR_SR_SECURITY_DESCRIPTOR SecurityDescriptor;
        unsigned long UserId;
        unsigned long PrimaryGroupId;
        unsigned long UserAccountControl;
        unsigned long WhichFields;
        SAMPR_LOGON_HOURS LogonHours;
        unsigned short BadPasswordCount;
        unsigned short LogonCount;
        unsigned short CountryCode;
        unsigned short CodePage;
        unsigned char LmPasswordPresent;
        unsigned char NtPasswordPresent;
        unsigned char PasswordExpired;
        unsigned char PrivateDataSensitive;
    } 	SAMPR_USER_ALL_INFORMATION;

    typedef struct _SAMPR_USER_ALL_INFORMATION* PSAMPR_USER_ALL_INFORMATION;

    typedef struct _SAMPR_USER_GENERAL_INFORMATION
    {
        RPC_UNICODE_STRING UserName;
        RPC_UNICODE_STRING FullName;
        unsigned long PrimaryGroupId;
        RPC_UNICODE_STRING AdminComment;
        RPC_UNICODE_STRING UserComment;
    } 	SAMPR_USER_GENERAL_INFORMATION;

    typedef struct _SAMPR_USER_GENERAL_INFORMATION* PSAMPR_USER_GENERAL_INFORMATION;

    typedef struct _SAMPR_USER_PREFERENCES_INFORMATION
    {
        RPC_UNICODE_STRING UserComment;
        RPC_UNICODE_STRING Reserved1;
        unsigned short CountryCode;
        unsigned short CodePage;
    } 	SAMPR_USER_PREFERENCES_INFORMATION;

    typedef struct _SAMPR_USER_PREFERENCES_INFORMATION* PSAMPR_USER_PREFERENCES_INFORMATION;

    typedef struct _SAMPR_USER_PARAMETERS_INFORMATION
    {
        RPC_UNICODE_STRING Parameters;
    } 	SAMPR_USER_PARAMETERS_INFORMATION;

    typedef struct _SAMPR_USER_PARAMETERS_INFORMATION* PSAMPR_USER_PARAMETERS_INFORMATION;

    typedef struct _SAMPR_USER_LOGON_INFORMATION
    {
        RPC_UNICODE_STRING UserName;
        RPC_UNICODE_STRING FullName;
        unsigned long UserId;
        unsigned long PrimaryGroupId;
        RPC_UNICODE_STRING HomeDirectory;
        RPC_UNICODE_STRING HomeDirectoryDrive;
        RPC_UNICODE_STRING ScriptPath;
        RPC_UNICODE_STRING ProfilePath;
        RPC_UNICODE_STRING WorkStations;
        OLD_LARGE_INTEGER LastLogon;
        OLD_LARGE_INTEGER LastLogoff;
        OLD_LARGE_INTEGER PasswordLastSet;
        OLD_LARGE_INTEGER PasswordCanChange;
        OLD_LARGE_INTEGER PasswordMustChange;
        SAMPR_LOGON_HOURS LogonHours;
        unsigned short BadPasswordCount;
        unsigned short LogonCount;
        unsigned long UserAccountControl;
    } 	SAMPR_USER_LOGON_INFORMATION;

    typedef struct _SAMPR_USER_LOGON_INFORMATION* PSAMPR_USER_LOGON_INFORMATION;

    typedef struct _SAMPR_USER_ACCOUNT_INFORMATION
    {
        RPC_UNICODE_STRING UserName;
        RPC_UNICODE_STRING FullName;
        unsigned long UserId;
        unsigned long PrimaryGroupId;
        RPC_UNICODE_STRING HomeDirectory;
        RPC_UNICODE_STRING HomeDirectoryDrive;
        RPC_UNICODE_STRING ScriptPath;
        RPC_UNICODE_STRING ProfilePath;
        RPC_UNICODE_STRING AdminComment;
        RPC_UNICODE_STRING WorkStations;
        OLD_LARGE_INTEGER LastLogon;
        OLD_LARGE_INTEGER LastLogoff;
        SAMPR_LOGON_HOURS LogonHours;
        unsigned short BadPasswordCount;
        unsigned short LogonCount;
        OLD_LARGE_INTEGER PasswordLastSet;
        OLD_LARGE_INTEGER AccountExpires;
        unsigned long UserAccountControl;
    } 	SAMPR_USER_ACCOUNT_INFORMATION;

    typedef struct _SAMPR_USER_ACCOUNT_INFORMATION* PSAMPR_USER_ACCOUNT_INFORMATION;

    typedef struct _SAMPR_USER_A_NAME_INFORMATION
    {
        RPC_UNICODE_STRING UserName;
    } 	SAMPR_USER_A_NAME_INFORMATION;

    typedef struct _SAMPR_USER_A_NAME_INFORMATION* PSAMPR_USER_A_NAME_INFORMATION;

    typedef struct _SAMPR_USER_F_NAME_INFORMATION
    {
        RPC_UNICODE_STRING FullName;
    } 	SAMPR_USER_F_NAME_INFORMATION;

    typedef struct _SAMPR_USER_F_NAME_INFORMATION* PSAMPR_USER_F_NAME_INFORMATION;

    typedef struct _SAMPR_USER_NAME_INFORMATION
    {
        RPC_UNICODE_STRING UserName;
        RPC_UNICODE_STRING FullName;
    } 	SAMPR_USER_NAME_INFORMATION;

    typedef struct _SAMPR_USER_NAME_INFORMATION* PSAMPR_USER_NAME_INFORMATION;

    typedef struct _SAMPR_USER_HOME_INFORMATION
    {
        RPC_UNICODE_STRING HomeDirectory;
        RPC_UNICODE_STRING HomeDirectoryDrive;
    } 	SAMPR_USER_HOME_INFORMATION;

    typedef struct _SAMPR_USER_HOME_INFORMATION* PSAMPR_USER_HOME_INFORMATION;

    typedef struct _SAMPR_USER_SCRIPT_INFORMATION
    {
        RPC_UNICODE_STRING ScriptPath;
    } 	SAMPR_USER_SCRIPT_INFORMATION;

    typedef struct _SAMPR_USER_SCRIPT_INFORMATION* PSAMPR_USER_SCRIPT_INFORMATION;

    typedef struct _SAMPR_USER_PROFILE_INFORMATION
    {
        RPC_UNICODE_STRING ProfilePath;
    } 	SAMPR_USER_PROFILE_INFORMATION;

    typedef struct _SAMPR_USER_PROFILE_INFORMATION* PSAMPR_USER_PROFILE_INFORMATION;

    typedef struct _SAMPR_USER_ADMIN_COMMENT_INFORMATION
    {
        RPC_UNICODE_STRING AdminComment;
    } 	SAMPR_USER_ADMIN_COMMENT_INFORMATION;

    typedef struct _SAMPR_USER_ADMIN_COMMENT_INFORMATION* PSAMPR_USER_ADMIN_COMMENT_INFORMATION;

    typedef struct _SAMPR_USER_WORKSTATIONS_INFORMATION
    {
        RPC_UNICODE_STRING WorkStations;
    } 	SAMPR_USER_WORKSTATIONS_INFORMATION;

    typedef struct _SAMPR_USER_WORKSTATIONS_INFORMATION* PSAMPR_USER_WORKSTATIONS_INFORMATION;

    typedef struct _SAMPR_USER_LOGON_HOURS_INFORMATION
    {
        SAMPR_LOGON_HOURS LogonHours;
    } 	SAMPR_USER_LOGON_HOURS_INFORMATION;

    typedef struct _SAMPR_USER_LOGON_HOURS_INFORMATION* PSAMPR_USER_LOGON_HOURS_INFORMATION;

    typedef struct _SAMPR_USER_INTERNAL1_INFORMATION
    {
        ENCRYPTED_NT_OWF_PASSWORD EncryptedNtOwfPassword;
        ENCRYPTED_LM_OWF_PASSWORD EncryptedLmOwfPassword;
        unsigned char NtPasswordPresent;
        unsigned char LmPasswordPresent;
        unsigned char PasswordExpired;
    } 	SAMPR_USER_INTERNAL1_INFORMATION;

    typedef struct _SAMPR_USER_INTERNAL1_INFORMATION* PSAMPR_USER_INTERNAL1_INFORMATION;

    typedef struct _SAMPR_USER_INTERNAL4_INFORMATION
    {
        SAMPR_USER_ALL_INFORMATION I1;
        SAMPR_ENCRYPTED_USER_PASSWORD UserPassword;
    } 	SAMPR_USER_INTERNAL4_INFORMATION;

    typedef struct _SAMPR_USER_INTERNAL4_INFORMATION* PSAMPR_USER_INTERNAL4_INFORMATION;

    typedef struct _SAMPR_USER_INTERNAL4_INFORMATION_NEW
    {
        SAMPR_USER_ALL_INFORMATION I1;
        SAMPR_ENCRYPTED_USER_PASSWORD_NEW UserPassword;
    } 	SAMPR_USER_INTERNAL4_INFORMATION_NEW;

    typedef struct _SAMPR_USER_INTERNAL4_INFORMATION_NEW* PSAMPR_USER_INTERNAL4_INFORMATION_NEW;

    typedef struct _SAMPR_USER_INTERNAL5_INFORMATION
    {
        SAMPR_ENCRYPTED_USER_PASSWORD UserPassword;
        unsigned char PasswordExpired;
    } 	SAMPR_USER_INTERNAL5_INFORMATION;

    typedef struct _SAMPR_USER_INTERNAL5_INFORMATION* PSAMPR_USER_INTERNAL5_INFORMATION;

    typedef struct _SAMPR_USER_INTERNAL5_INFORMATION_NEW
    {
        SAMPR_ENCRYPTED_USER_PASSWORD_NEW UserPassword;
        unsigned char PasswordExpired;
    } 	SAMPR_USER_INTERNAL5_INFORMATION_NEW;

    typedef struct _SAMPR_USER_INTERNAL5_INFORMATION_NEW* PSAMPR_USER_INTERNAL5_INFORMATION_NEW;

    typedef struct _SAMPR_ENCRYPTED_PASSWORD_AES
    {
        UCHAR AuthData[64];
        UCHAR Salt[16];
        ULONG cbCipher;
        /* [size_is] */ PUCHAR Cipher;
        ULONGLONG PBKDF2Iterations;
    } 	SAMPR_ENCRYPTED_PASSWORD_AES;

    typedef struct _SAMPR_ENCRYPTED_PASSWORD_AES* PSAMPR_ENCRYPTED_PASSWORD_AES;

    typedef struct _SAMPR_USER_INTERNAL7_INFORMATION
    {
        SAMPR_ENCRYPTED_PASSWORD_AES UserPassword;
        BOOLEAN PasswordExpired;
    } 	SAMPR_USER_INTERNAL7_INFORMATION;

    typedef struct _SAMPR_USER_INTERNAL7_INFORMATION* PSAMPR_USER_INTERNAL7_INFORMATION;

    typedef struct _SAMPR_USER_INTERNAL8_INFORMATION
    {
        SAMPR_USER_ALL_INFORMATION I1;
        SAMPR_ENCRYPTED_PASSWORD_AES UserPassword;
    } 	SAMPR_USER_INTERNAL8_INFORMATION;

    typedef struct _SAMPR_USER_INTERNAL8_INFORMATION* PSAMPR_USER_INTERNAL8_INFORMATION;

    typedef
        enum _USER_INFORMATION_CLASS
    {
        UserGeneralInformation = 1,
        UserPreferencesInformation = 2,
        UserLogonInformation = 3,
        UserLogonHoursInformation = 4,
        UserAccountInformation = 5,
        UserNameInformation = 6,
        UserAccountNameInformation = 7,
        UserFullNameInformation = 8,
        UserPrimaryGroupInformation = 9,
        UserHomeInformation = 10,
        UserScriptInformation = 11,
        UserProfileInformation = 12,
        UserAdminCommentInformation = 13,
        UserWorkStationsInformation = 14,
        UserControlInformation = 16,
        UserExpiresInformation = 17,
        UserInternal1Information = 18,
        UserParametersInformation = 20,
        UserAllInformation = 21,
        UserInternal4Information = 23,
        UserInternal5Information = 24,
        UserInternal4InformationNew = 25,
        UserInternal5InformationNew = 26,
        UserInternal7Information = 31,
        UserInternal8Information = 32
    } 	USER_INFORMATION_CLASS;

    typedef enum _USER_INFORMATION_CLASS* PUSER_INFORMATION_CLASS;

    typedef /* [switch_type] */ union _SAMPR_USER_INFO_BUFFER
    {
        /* [case()] */ SAMPR_USER_GENERAL_INFORMATION General;
        /* [case()] */ SAMPR_USER_PREFERENCES_INFORMATION Preferences;
        /* [case()] */ SAMPR_USER_LOGON_INFORMATION Logon;
        /* [case()] */ SAMPR_USER_LOGON_HOURS_INFORMATION LogonHours;
        /* [case()] */ SAMPR_USER_ACCOUNT_INFORMATION Account;
        /* [case()] */ SAMPR_USER_NAME_INFORMATION Name;
        /* [case()] */ SAMPR_USER_A_NAME_INFORMATION AccountName;
        /* [case()] */ SAMPR_USER_F_NAME_INFORMATION FullName;
        /* [case()] */ USER_PRIMARY_GROUP_INFORMATION PrimaryGroup;
        /* [case()] */ SAMPR_USER_HOME_INFORMATION Home;
        /* [case()] */ SAMPR_USER_SCRIPT_INFORMATION Script;
        /* [case()] */ SAMPR_USER_PROFILE_INFORMATION Profile;
        /* [case()] */ SAMPR_USER_ADMIN_COMMENT_INFORMATION AdminComment;
        /* [case()] */ SAMPR_USER_WORKSTATIONS_INFORMATION WorkStations;
        /* [case()] */ USER_CONTROL_INFORMATION Control;
        /* [case()] */ USER_EXPIRES_INFORMATION Expires;
        /* [case()] */ SAMPR_USER_INTERNAL1_INFORMATION Internal1;
        /* [case()] */ SAMPR_USER_PARAMETERS_INFORMATION Parameters;
        /* [case()] */ SAMPR_USER_ALL_INFORMATION All;
        /* [case()] */ SAMPR_USER_INTERNAL4_INFORMATION Internal4;
        /* [case()] */ SAMPR_USER_INTERNAL5_INFORMATION Internal5;
        /* [case()] */ SAMPR_USER_INTERNAL4_INFORMATION_NEW Internal4New;
        /* [case()] */ SAMPR_USER_INTERNAL5_INFORMATION_NEW Internal5New;
        /* [case()] */ SAMPR_USER_INTERNAL7_INFORMATION Internal7;
        /* [case()] */ SAMPR_USER_INTERNAL8_INFORMATION Internal8;
    } 	SAMPR_USER_INFO_BUFFER;

    typedef /* [switch_type] */ union _SAMPR_USER_INFO_BUFFER* PSAMPR_USER_INFO_BUFFER;

    typedef
        enum _PASSWORD_POLICY_VALIDATION_TYPE
    {
        SamValidateAuthentication = 1,
        SamValidatePasswordChange = (SamValidateAuthentication + 1),
        SamValidatePasswordReset = (SamValidatePasswordChange + 1)
    } 	PASSWORD_POLICY_VALIDATION_TYPE;

    typedef struct _SAM_VALIDATE_PASSWORD_HASH
    {
        unsigned long Length;
        /* [size_is][unique] */ unsigned char* Hash;
    } 	SAM_VALIDATE_PASSWORD_HASH;

    typedef struct _SAM_VALIDATE_PASSWORD_HASH* PSAM_VALIDATE_PASSWORD_HASH;

    typedef struct _SAM_VALIDATE_PERSISTED_FIELDS
    {
        unsigned long PresentFields;
        LARGE_INTEGER PasswordLastSet;
        LARGE_INTEGER BadPasswordTime;
        LARGE_INTEGER LockoutTime;
        unsigned long BadPasswordCount;
        unsigned long PasswordHistoryLength;
        /* [size_is][unique] */ PSAM_VALIDATE_PASSWORD_HASH PasswordHistory;
    } 	SAM_VALIDATE_PERSISTED_FIELDS;

    typedef struct _SAM_VALIDATE_PERSISTED_FIELDS* PSAM_VALIDATE_PERSISTED_FIELDS;

    typedef
        enum _SAM_VALIDATE_VALIDATION_STATUS
    {
        SamValidateSuccess = 0,
        SamValidatePasswordMustChange = (SamValidateSuccess + 1),
        SamValidateAccountLockedOut = (SamValidatePasswordMustChange + 1),
        SamValidatePasswordExpired = (SamValidateAccountLockedOut + 1),
        SamValidatePasswordIncorrect = (SamValidatePasswordExpired + 1),
        SamValidatePasswordIsInHistory = (SamValidatePasswordIncorrect + 1),
        SamValidatePasswordTooShort = (SamValidatePasswordIsInHistory + 1),
        SamValidatePasswordTooLong = (SamValidatePasswordTooShort + 1),
        SamValidatePasswordNotComplexEnough = (SamValidatePasswordTooLong + 1),
        SamValidatePasswordTooRecent = (SamValidatePasswordNotComplexEnough + 1),
        SamValidatePasswordFilterError = (SamValidatePasswordTooRecent + 1)
    } 	SAM_VALIDATE_VALIDATION_STATUS;

    typedef enum _SAM_VALIDATE_VALIDATION_STATUS* PSAM_VALIDATE_VALIDATION_STATUS;

    typedef struct _SAM_VALIDATE_STANDARD_OUTPUT_ARG
    {
        SAM_VALIDATE_PERSISTED_FIELDS ChangedPersistedFields;
        SAM_VALIDATE_VALIDATION_STATUS ValidationStatus;
    } 	SAM_VALIDATE_STANDARD_OUTPUT_ARG;

    typedef struct _SAM_VALIDATE_STANDARD_OUTPUT_ARG* PSAM_VALIDATE_STANDARD_OUTPUT_ARG;

    typedef struct _SAM_VALIDATE_AUTHENTICATION_INPUT_ARG
    {
        SAM_VALIDATE_PERSISTED_FIELDS InputPersistedFields;
        unsigned char PasswordMatched;
    } 	SAM_VALIDATE_AUTHENTICATION_INPUT_ARG;

    typedef struct _SAM_VALIDATE_AUTHENTICATION_INPUT_ARG* PSAM_VALIDATE_AUTHENTICATION_INPUT_ARG;

    typedef struct _SAM_VALIDATE_PASSWORD_CHANGE_INPUT_ARG
    {
        SAM_VALIDATE_PERSISTED_FIELDS InputPersistedFields;
        RPC_UNICODE_STRING ClearPassword;
        RPC_UNICODE_STRING UserAccountName;
        SAM_VALIDATE_PASSWORD_HASH HashedPassword;
        unsigned char PasswordMatch;
    } 	SAM_VALIDATE_PASSWORD_CHANGE_INPUT_ARG;

    typedef struct _SAM_VALIDATE_PASSWORD_CHANGE_INPUT_ARG* PSAM_VALIDATE_PASSWORD_CHANGE_INPUT_ARG;

    typedef struct _SAM_VALIDATE_PASSWORD_RESET_INPUT_ARG
    {
        SAM_VALIDATE_PERSISTED_FIELDS InputPersistedFields;
        RPC_UNICODE_STRING ClearPassword;
        RPC_UNICODE_STRING UserAccountName;
        SAM_VALIDATE_PASSWORD_HASH HashedPassword;
        unsigned char PasswordMustChangeAtNextLogon;
        unsigned char ClearLockout;
    } 	SAM_VALIDATE_PASSWORD_RESET_INPUT_ARG;

    typedef struct _SAM_VALIDATE_PASSWORD_RESET_INPUT_ARG* PSAM_VALIDATE_PASSWORD_RESET_INPUT_ARG;

    typedef /* [switch_type] */ union _SAM_VALIDATE_INPUT_ARG
    {
        /* [case()] */ SAM_VALIDATE_AUTHENTICATION_INPUT_ARG ValidateAuthenticationInput;
        /* [case()] */ SAM_VALIDATE_PASSWORD_CHANGE_INPUT_ARG ValidatePasswordChangeInput;
        /* [case()] */ SAM_VALIDATE_PASSWORD_RESET_INPUT_ARG ValidatePasswordResetInput;
    } 	SAM_VALIDATE_INPUT_ARG;

    typedef /* [switch_type] */ union _SAM_VALIDATE_INPUT_ARG* PSAM_VALIDATE_INPUT_ARG;

    typedef /* [switch_type] */ union _SAM_VALIDATE_OUTPUT_ARG
    {
        /* [case()] */ SAM_VALIDATE_STANDARD_OUTPUT_ARG ValidateAuthenticationOutput;
        /* [case()] */ SAM_VALIDATE_STANDARD_OUTPUT_ARG ValidatePasswordChangeOutput;
        /* [case()] */ SAM_VALIDATE_STANDARD_OUTPUT_ARG ValidatePasswordResetOutput;
    } 	SAM_VALIDATE_OUTPUT_ARG;

    typedef /* [switch_type] */ union _SAM_VALIDATE_OUTPUT_ARG* PSAM_VALIDATE_OUTPUT_ARG;

    long SamrConnect(
        /* [unique][in] */ PSAMPR_SERVER_NAME ServerName,
        /* [out] */ SAMPR_HANDLE* ServerHandle,
        /* [in] */ unsigned long DesiredAccess);

    long SamrCloseHandle(
        /* [out][in] */ SAMPR_HANDLE* SamHandle);

    long SamrSetSecurityObject(
        /* [in] */ SAMPR_HANDLE ObjectHandle,
        /* [in] */ SECURITY_INFORMATION SecurityInformation,
        /* [in] */ PSAMPR_SR_SECURITY_DESCRIPTOR SecurityDescriptor);

    long SamrQuerySecurityObject(
        /* [in] */ SAMPR_HANDLE ObjectHandle,
        /* [in] */ SECURITY_INFORMATION SecurityInformation,
        /* [out] */ PSAMPR_SR_SECURITY_DESCRIPTOR* SecurityDescriptor);

    void Opnum4NotUsedOnWire(
        /* [in] */ handle_t IDL_handle);

    long SamrLookupDomainInSamServer(
        /* [in] */ SAMPR_HANDLE ServerHandle,
        /* [in] */ PRPC_UNICODE_STRING Name,
        /* [out] */ PRPC_SID* DomainId);

    long SamrEnumerateDomainsInSamServer(
        /* [in] */ SAMPR_HANDLE ServerHandle,
        /* [out][in] */ unsigned long* EnumerationContext,
        /* [out] */ PSAMPR_ENUMERATION_BUFFER* Buffer,
        /* [in] */ unsigned long PreferedMaximumLength,
        /* [out] */ unsigned long* CountReturned);

    long SamrOpenDomain(
        /* [in] */ SAMPR_HANDLE ServerHandle,
        /* [in] */ unsigned long DesiredAccess,
        /* [in] */ PRPC_SID DomainId,
        /* [out] */ SAMPR_HANDLE* DomainHandle);

    long SamrQueryInformationDomain(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ DOMAIN_INFORMATION_CLASS DomainInformationClass,
        /* [switch_is][out] */ PSAMPR_DOMAIN_INFO_BUFFER* Buffer);

    long SamrSetInformationDomain(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ DOMAIN_INFORMATION_CLASS DomainInformationClass,
        /* [switch_is][in] */ PSAMPR_DOMAIN_INFO_BUFFER DomainInformation);

    long SamrCreateGroupInDomain(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ PRPC_UNICODE_STRING Name,
        /* [in] */ unsigned long DesiredAccess,
        /* [out] */ SAMPR_HANDLE* GroupHandle,
        /* [out] */ unsigned long* RelativeId);

    long SamrEnumerateGroupsInDomain(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [out][in] */ unsigned long* EnumerationContext,
        /* [out] */ PSAMPR_ENUMERATION_BUFFER* Buffer,
        /* [in] */ unsigned long PreferedMaximumLength,
        /* [out] */ unsigned long* CountReturned);

    long SamrCreateUserInDomain(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ PRPC_UNICODE_STRING Name,
        /* [in] */ unsigned long DesiredAccess,
        /* [out] */ SAMPR_HANDLE* UserHandle,
        /* [out] */ unsigned long* RelativeId);

    long SamrEnumerateUsersInDomain(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [out][in] */ unsigned long* EnumerationContext,
        /* [in] */ unsigned long UserAccountControl,
        /* [out] */ PSAMPR_ENUMERATION_BUFFER* Buffer,
        /* [in] */ unsigned long PreferedMaximumLength,
        /* [out] */ unsigned long* CountReturned);

    long SamrCreateAliasInDomain(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ PRPC_UNICODE_STRING AccountName,
        /* [in] */ unsigned long DesiredAccess,
        /* [out] */ SAMPR_HANDLE* AliasHandle,
        /* [out] */ unsigned long* RelativeId);

    long SamrEnumerateAliasesInDomain(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [out][in] */ unsigned long* EnumerationContext,
        /* [out] */ PSAMPR_ENUMERATION_BUFFER* Buffer,
        /* [in] */ unsigned long PreferedMaximumLength,
        /* [out] */ unsigned long* CountReturned);

    long SamrGetAliasMembership(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ PSAMPR_PSID_ARRAY SidArray,
        /* [out] */ PSAMPR_ULONG_ARRAY Membership);

    long SamrLookupNamesInDomain(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [range][in] */ unsigned long Count,
        /* [length_is][size_is][in] */ RPC_UNICODE_STRING Names[],
        /* [out] */ PSAMPR_ULONG_ARRAY RelativeIds,
        /* [out] */ PSAMPR_ULONG_ARRAY Use);

    long SamrLookupIdsInDomain(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [range][in] */ unsigned long Count,
        /* [length_is][size_is][in] */ unsigned long* RelativeIds,
        /* [out] */ PSAMPR_RETURNED_USTRING_ARRAY Names,
        /* [out] */ PSAMPR_ULONG_ARRAY Use);

    long SamrOpenGroup(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ unsigned long DesiredAccess,
        /* [in] */ unsigned long GroupId,
        /* [out] */ SAMPR_HANDLE* GroupHandle);

    long SamrQueryInformationGroup(
        /* [in] */ SAMPR_HANDLE GroupHandle,
        /* [in] */ GROUP_INFORMATION_CLASS GroupInformationClass,
        /* [switch_is][out] */ PSAMPR_GROUP_INFO_BUFFER* Buffer);

    long SamrSetInformationGroup(
        /* [in] */ SAMPR_HANDLE GroupHandle,
        /* [in] */ GROUP_INFORMATION_CLASS GroupInformationClass,
        /* [switch_is][in] */ PSAMPR_GROUP_INFO_BUFFER Buffer);

    long SamrAddMemberToGroup(
        /* [in] */ SAMPR_HANDLE GroupHandle,
        /* [in] */ unsigned long MemberId,
        /* [in] */ unsigned long Attributes);

    long SamrDeleteGroup(
        /* [out][in] */ SAMPR_HANDLE* GroupHandle);

    long SamrRemoveMemberFromGroup(
        /* [in] */ SAMPR_HANDLE GroupHandle,
        /* [in] */ unsigned long MemberId);

    long SamrGetMembersInGroup(
        /* [in] */ SAMPR_HANDLE GroupHandle,
        /* [out] */ PSAMPR_GET_MEMBERS_BUFFER* Members);

    long SamrSetMemberAttributesOfGroup(
        /* [in] */ SAMPR_HANDLE GroupHandle,
        /* [in] */ unsigned long MemberId,
        /* [in] */ unsigned long Attributes);

    long SamrOpenAlias(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ unsigned long DesiredAccess,
        /* [in] */ unsigned long AliasId,
        /* [out] */ SAMPR_HANDLE* AliasHandle);

    long SamrQueryInformationAlias(
        /* [in] */ SAMPR_HANDLE AliasHandle,
        /* [in] */ ALIAS_INFORMATION_CLASS AliasInformationClass,
        /* [switch_is][out] */ PSAMPR_ALIAS_INFO_BUFFER* Buffer);

    long SamrSetInformationAlias(
        /* [in] */ SAMPR_HANDLE AliasHandle,
        /* [in] */ ALIAS_INFORMATION_CLASS AliasInformationClass,
        /* [switch_is][in] */ PSAMPR_ALIAS_INFO_BUFFER Buffer);

    long SamrDeleteAlias(
        /* [out][in] */ SAMPR_HANDLE* AliasHandle);

    long SamrAddMemberToAlias(
        /* [in] */ SAMPR_HANDLE AliasHandle,
        /* [in] */ PRPC_SID MemberId);

    long SamrRemoveMemberFromAlias(
        /* [in] */ SAMPR_HANDLE AliasHandle,
        /* [in] */ PRPC_SID MemberId);

    long SamrGetMembersInAlias(
        /* [in] */ SAMPR_HANDLE AliasHandle,
        /* [out] */ PSAMPR_PSID_ARRAY_OUT Members);

    long SamrOpenUser(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ unsigned long DesiredAccess,
        /* [in] */ unsigned long UserId,
        /* [out] */ SAMPR_HANDLE* UserHandle);

    long SamrDeleteUser(
        /* [out][in] */ SAMPR_HANDLE* UserHandle);

    long SamrQueryInformationUser(
        /* [in] */ SAMPR_HANDLE UserHandle,
        /* [in] */ USER_INFORMATION_CLASS UserInformationClass,
        /* [switch_is][out] */ PSAMPR_USER_INFO_BUFFER* Buffer);

    long SamrSetInformationUser(
        /* [in] */ SAMPR_HANDLE UserHandle,
        /* [in] */ USER_INFORMATION_CLASS UserInformationClass,
        /* [switch_is][in] */ PSAMPR_USER_INFO_BUFFER Buffer);

    long SamrChangePasswordUser(
        /* [in] */ SAMPR_HANDLE UserHandle,
        /* [in] */ unsigned char LmPresent,
        /* [unique][in] */ PENCRYPTED_LM_OWF_PASSWORD OldLmEncryptedWithNewLm,
        /* [unique][in] */ PENCRYPTED_LM_OWF_PASSWORD NewLmEncryptedWithOldLm,
        /* [in] */ unsigned char NtPresent,
        /* [unique][in] */ PENCRYPTED_NT_OWF_PASSWORD OldNtEncryptedWithNewNt,
        /* [unique][in] */ PENCRYPTED_NT_OWF_PASSWORD NewNtEncryptedWithOldNt,
        /* [in] */ unsigned char NtCrossEncryptionPresent,
        /* [unique][in] */ PENCRYPTED_NT_OWF_PASSWORD NewNtEncryptedWithNewLm,
        /* [in] */ unsigned char LmCrossEncryptionPresent,
        /* [unique][in] */ PENCRYPTED_LM_OWF_PASSWORD NewLmEncryptedWithNewNt);

    long SamrGetGroupsForUser(
        /* [in] */ SAMPR_HANDLE UserHandle,
        /* [out] */ PSAMPR_GET_GROUPS_BUFFER* Groups);

    long SamrQueryDisplayInformation(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ DOMAIN_DISPLAY_INFORMATION DisplayInformationClass,
        /* [in] */ unsigned long Index,
        /* [in] */ unsigned long EntryCount,
        /* [in] */ unsigned long PreferredMaximumLength,
        /* [out] */ unsigned long* TotalAvailable,
        /* [out] */ unsigned long* TotalReturned,
        /* [switch_is][out] */ PSAMPR_DISPLAY_INFO_BUFFER Buffer);

    long SamrGetDisplayEnumerationIndex(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ DOMAIN_DISPLAY_INFORMATION DisplayInformationClass,
        /* [in] */ PRPC_UNICODE_STRING Prefix,
        /* [out] */ unsigned long* Index);

    void Opnum42NotUsedOnWire(
        /* [in] */ handle_t IDL_handle);

    void Opnum43NotUsedOnWire(
        /* [in] */ handle_t IDL_handle);

    long SamrGetUserDomainPasswordInformation(
        /* [in] */ SAMPR_HANDLE UserHandle,
        /* [out] */ PUSER_DOMAIN_PASSWORD_INFORMATION PasswordInformation);

    long SamrRemoveMemberFromForeignDomain(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ PRPC_SID MemberSid);

    long SamrQueryInformationDomain2(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ DOMAIN_INFORMATION_CLASS DomainInformationClass,
        /* [switch_is][out] */ PSAMPR_DOMAIN_INFO_BUFFER* Buffer);

    long SamrQueryInformationUser2(
        /* [in] */ SAMPR_HANDLE UserHandle,
        /* [in] */ USER_INFORMATION_CLASS UserInformationClass,
        /* [switch_is][out] */ PSAMPR_USER_INFO_BUFFER* Buffer);

    long SamrQueryDisplayInformation2(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ DOMAIN_DISPLAY_INFORMATION DisplayInformationClass,
        /* [in] */ unsigned long Index,
        /* [in] */ unsigned long EntryCount,
        /* [in] */ unsigned long PreferredMaximumLength,
        /* [out] */ unsigned long* TotalAvailable,
        /* [out] */ unsigned long* TotalReturned,
        /* [switch_is][out] */ PSAMPR_DISPLAY_INFO_BUFFER Buffer);

    long SamrGetDisplayEnumerationIndex2(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ DOMAIN_DISPLAY_INFORMATION DisplayInformationClass,
        /* [in] */ PRPC_UNICODE_STRING Prefix,
        /* [out] */ unsigned long* Index);

    long SamrCreateUser2InDomain(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ PRPC_UNICODE_STRING Name,
        /* [in] */ unsigned long AccountType,
        /* [in] */ unsigned long DesiredAccess,
        /* [out] */ SAMPR_HANDLE* UserHandle,
        /* [out] */ unsigned long* GrantedAccess,
        /* [out] */ unsigned long* RelativeId);

    long SamrQueryDisplayInformation3(
        /* [in] */ SAMPR_HANDLE DomainHandle,
        /* [in] */ DOMAIN_DISPLAY_INFORMATION DisplayInformationClass,
        /* [in] */ unsigned long Index,
        /* [in] */ unsigned long EntryCount,
        /* [in] */ unsigned long PreferredMaximumLength,
        /* [out] */ unsigned long* TotalAvailable,
        /* [out] */ unsigned long* TotalReturned,
        /* [switch_is][out] */ PSAMPR_DISPLAY_INFO_BUFFER Buffer);

    long SamrAddMultipleMembersToAlias(
        /* [in] */ SAMPR_HANDLE AliasHandle,
        /* [in] */ PSAMPR_PSID_ARRAY MembersBuffer);

    long SamrRemoveMultipleMembersFromAlias(
        /* [in] */ SAMPR_HANDLE AliasHandle,
        /* [in] */ PSAMPR_PSID_ARRAY MembersBuffer);

    long SamrOemChangePasswordUser2(
        /* [in] */ handle_t BindingHandle,
        /* [unique][in] */ PRPC_STRING ServerName,
        /* [in] */ PRPC_STRING UserName,
        /* [unique][in] */ PSAMPR_ENCRYPTED_USER_PASSWORD NewPasswordEncryptedWithOldLm,
        /* [unique][in] */ PENCRYPTED_LM_OWF_PASSWORD OldLmOwfPasswordEncryptedWithNewLm);

    long SamrUnicodeChangePasswordUser2(
        /* [in] */ handle_t BindingHandle,
        /* [unique][in] */ PRPC_UNICODE_STRING ServerName,
        /* [in] */ PRPC_UNICODE_STRING UserName,
        /* [unique][in] */ PSAMPR_ENCRYPTED_USER_PASSWORD NewPasswordEncryptedWithOldNt,
        /* [unique][in] */ PENCRYPTED_NT_OWF_PASSWORD OldNtOwfPasswordEncryptedWithNewNt,
        /* [in] */ unsigned char LmPresent,
        /* [unique][in] */ PSAMPR_ENCRYPTED_USER_PASSWORD NewPasswordEncryptedWithOldLm,
        /* [unique][in] */ PENCRYPTED_LM_OWF_PASSWORD OldLmOwfPasswordEncryptedWithNewNt);

    long SamrGetDomainPasswordInformation(
        /* [in] */ handle_t BindingHandle,
        /* [unique][in] */ PRPC_UNICODE_STRING Unused,
        /* [out] */ PUSER_DOMAIN_PASSWORD_INFORMATION PasswordInformation);

    long SamrConnect2(
        /* [string][unique][in] */ PSAMPR_SERVER_NAME ServerName,
        /* [out] */ SAMPR_HANDLE* ServerHandle,
        /* [in] */ unsigned long DesiredAccess);

    long SamrSetInformationUser2(
        /* [in] */ SAMPR_HANDLE UserHandle,
        /* [in] */ USER_INFORMATION_CLASS UserInformationClass,
        /* [switch_is][in] */ PSAMPR_USER_INFO_BUFFER Buffer);

    void Opnum59NotUsedOnWire(
        /* [in] */ handle_t IDL_handle);

    void Opnum60NotUsedOnWire(
        /* [in] */ handle_t IDL_handle);

    void Opnum61NotUsedOnWire(
        /* [in] */ handle_t IDL_handle);

    long SamrConnect4(
        /* [string][unique][in] */ PSAMPR_SERVER_NAME ServerName,
        /* [out] */ SAMPR_HANDLE* ServerHandle,
        /* [in] */ unsigned long ClientRevision,
        /* [in] */ unsigned long DesiredAccess);

    void Opnum63NotUsedOnWire(
        /* [in] */ handle_t IDL_handle);

    long SamrConnect5(
        /* [string][unique][in] */ PSAMPR_SERVER_NAME ServerName,
        /* [in] */ unsigned long DesiredAccess,
        /* [in] */ unsigned long InVersion,
        /* [switch_is][in] */ SAMPR_REVISION_INFO* InRevisionInfo,
        /* [out] */ unsigned long* OutVersion,
        /* [switch_is][out] */ SAMPR_REVISION_INFO* OutRevisionInfo,
        /* [out] */ SAMPR_HANDLE* ServerHandle);

    long SamrRidToSid(
        /* [in] */ SAMPR_HANDLE ObjectHandle,
        /* [in] */ unsigned long Rid,
        /* [out] */ PRPC_SID* Sid);

    long SamrSetDSRMPassword(
        /* [in] */ handle_t BindingHandle,
        /* [unique][in] */ PRPC_UNICODE_STRING Unused,
        /* [in] */ unsigned long UserId,
        /* [unique][in] */ PENCRYPTED_NT_OWF_PASSWORD EncryptedNtOwfPassword);

    long SamrValidatePassword(
        /* [in] */ handle_t Handle,
        /* [in] */ PASSWORD_POLICY_VALIDATION_TYPE ValidationType,
        /* [switch_is][in] */ PSAM_VALIDATE_INPUT_ARG InputArg,
        /* [switch_is][out] */ PSAM_VALIDATE_OUTPUT_ARG* OutputArg);

    void Opnum68NotUsedOnWire(
        /* [in] */ handle_t IDL_handle);

    void Opnum69NotUsedOnWire(
        /* [in] */ handle_t IDL_handle);

    void Opnum70NotUsedOnWire(
        /* [in] */ handle_t IDL_handle);

    void Opnum71NotUsedOnWire(
        /* [in] */ handle_t IDL_handle);

    void Opnum72NotUsedOnWire(
        /* [in] */ handle_t IDL_handle);

    NTSTATUS SamrUnicodeChangePasswordUser4(
        /* [in] */ handle_t BindingHandle,
        /* [unique][in] */ PRPC_UNICODE_STRING ServerName,
        /* [in] */ PRPC_UNICODE_STRING UserName,
        /* [in] */ PSAMPR_ENCRYPTED_PASSWORD_AES EncryptedPassword);



    extern RPC_IF_HANDLE samr_v1_0_c_ifspec;
    extern RPC_IF_HANDLE samr_v1_0_s_ifspec;
#endif /* __samr_INTERFACE_DEFINED__ */

    /* Additional Prototypes for ALL interfaces */

    handle_t __RPC_USER PSAMPR_SERVER_NAME_bind(PSAMPR_SERVER_NAME);
    void     __RPC_USER PSAMPR_SERVER_NAME_unbind(PSAMPR_SERVER_NAME, handle_t);

    void __RPC_USER SAMPR_HANDLE_rundown(SAMPR_HANDLE);

    /* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


