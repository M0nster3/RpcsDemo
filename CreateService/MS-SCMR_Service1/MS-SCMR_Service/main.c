#include <windows.h>
#include <stdio.h>
#include "ms_scmr.h"
#pragma comment(lib, "rpcrt4.lib")

#if !defined(NT_SUCCESS)
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#endif

const RPC_WSTR UUI = L"8a885d04-1ceb-11c9-9fe8-08002b104860";
#define SERVICE_ALL_ACCESS  0xF01FF 
#define SC_MANAGER_ALL_ACCESS  0xF003F
#define SERVICE_WIN32_OWN_PROCESS  0x00000010 
#define SERVICE_DEMAND_START  0x00000003
#define SERVICE_ERROR_IGNORE  0x00000000
#define SERVICE_DRIVER  0x00000010

//extern VOID WINAPI RtlInitUnicodeString(OUT PUNICODE_STRING DestinationString, IN PCWSTR SourceString);
LPSC_RPC_HANDLE lpServiceHandle;
NTSTATUS status;
void __RPC_FAR* __RPC_USER midl_user_allocate(size_t cBytes)
{
	return((void __RPC_FAR*) malloc(cBytes));
}

void __RPC_USER midl_user_free(void __RPC_FAR* p)
{
	free(p);
}

handle_t __RPC_USER
SVCCTL_HANDLEA_bind(SVCCTL_HANDLEA szMachineName)
{
	handle_t hBinding = NULL;
	UCHAR* pszStringBinding;
	RPC_STATUS status;

	wprintf(L"[*] SVCCTL_HANDLEA_bind() called\n");

	status = RpcStringBindingComposeA(NULL,
		(UCHAR*)"ncacn_np",
		(UCHAR*)szMachineName,
		(UCHAR*)"\\pipe\\ntsvcs",
		NULL,
		(UCHAR**)&pszStringBinding);
	if (status != RPC_S_OK)
	{
		wprintf(L"[*] RpcStringBindingCompose returned 0x%x\n", status);
		return NULL;
	}

	/* Set the binding handle that will be used to bind to the server. */
	status = RpcBindingFromStringBindingA(pszStringBinding,
		&hBinding);
	if (status != RPC_S_OK)
	{
		wprintf(L"[*] RpcBindingFromStringBinding returned 0x%x\n", status);
	}

	status = RpcStringFreeA(&pszStringBinding);
	if (status != RPC_S_OK)
	{
		wprintf(L"[*] RpcStringFree returned 0x%x\n", status);
	}

	return hBinding;
}


void __RPC_USER
SVCCTL_HANDLEA_unbind(SVCCTL_HANDLEA szMachineName,
	handle_t hBinding)
{
	RPC_STATUS status;

	wprintf(L"[*] SVCCTL_HANDLEA_unbind() called\n");

	status = RpcBindingFree(&hBinding);
	if (status != RPC_S_OK)
	{
		wprintf(L"[*] RpcBindingFree returned 0x%x\n", status);
	}
}


handle_t __RPC_USER
SVCCTL_HANDLEW_bind(SVCCTL_HANDLEW szMachineName)
{
	handle_t hBinding = NULL;
	LPWSTR pszStringBinding;
	RPC_STATUS status;

	wprintf(L"[*] SVCCTL_HANDLEW_bind called\n");

	status = RpcStringBindingComposeW(NULL,
		L"ncacn_np",
		szMachineName,
		L"\\pipe\\ntsvcs",
		NULL,
		&pszStringBinding);
	if (status != RPC_S_OK)
	{
		wprintf(L"[*] RpcStringBindingCompose returned 0x%x\n", status);
		return NULL;
	}

	/* Set the binding handle that will be used to bind to the server. */
	status = RpcBindingFromStringBindingW(pszStringBinding,
		&hBinding);
	if (status != RPC_S_OK)
	{
		wprintf(L"[*] RpcBindingFromStringBinding returned 0x%x\n", status);
	}

	status = RpcStringFreeW(&pszStringBinding);
	if (status != RPC_S_OK)
	{
		wprintf(L"[*] RpcStringFree returned 0x%x\n", status);
	}

	return hBinding;
}


void __RPC_USER
SVCCTL_HANDLEW_unbind(SVCCTL_HANDLEW szMachineName,
	handle_t hBinding)
{
	RPC_STATUS status;

	wprintf(L"[*] SVCCTL_HANDLEW_unbind called\n");

	status = RpcBindingFree(&hBinding);
	if (status != RPC_S_OK)
	{
		wprintf(L"[*] RpcBindingFree returned 0x%x\n", status);
	}
}

CLIENT_CALL_RETURN RPC_VAR_ENTRY
NdrClientCall3(
	MIDL_STUBLESS_PROXY_INFO* pProxyInfo,
	unsigned long               nProcNum,
	void* pReturnValue,
	...
);

Delete() {
	wprintf(L"[*] Sleeping for 3s to Deletion Service\n");
	//Sleep(30000);
	Sleep(30000);
	wprintf(L"[*] start Deleting service.\n");
	status = RDeleteService(lpServiceHandle);
	if (status != 0)
	{
		wprintf(L"[!] Unable to delete service. Status code returned:0x%ld\n",status);
	}
	else
	{
		wprintf(L"[*] Successfully deleted the service.");
	}
}

int __RPC_USER
main() {
	LPSC_RPC_HANDLE lpScHandle;
	LPSTR lpServiceName = "tests";
	LPSTR lpBinaryPathName = "C:/Windows/srvany.exe";

	DWORD OpenSCManag = ROpenSCManagerA("127.0.0.1", NULL, SC_MANAGER_ALL_ACCESS, &lpScHandle);
	/*wprintf(L"%ld", OpenSCManag);*/
	if (OpenSCManag == 0) {
		status = RCreateServiceA(
			lpScHandle,
			lpServiceName,
			lpServiceName,
			SERVICE_ALL_ACCESS,
			SERVICE_DRIVER,
			SERVICE_DEMAND_START,
			SERVICE_ERROR_IGNORE,
			lpBinaryPathName,
			NULL,
			NULL,
			NULL,
			0,
			NULL,
			NULL,
			0,
			&lpServiceHandle
		);
		//wprintf(L"%ld", status);
		if (status != 0)
		{
			if (status == 1073)
				wprintf(L"[!] Unable to create service. The specified service already exists\n");
			else if (status == 1053)
				wprintf(L"[!] Unable to create service. The service did not respond to a start or control request in a timely manner Status code returned: 0x%ld\n", status);
			else
				wprintf(L"[!] Unable to create service. Status code returned: 0x%ld\n", status);
		}
		else
		{
			LPCWSTR* lpServiceArgVectors = NULL;
			wprintf(L"[*] Successfully created service .\n");
			wprintf(L"[*] Starting service.\n");
			status = RStartServiceA(lpServiceHandle, 0, lpServiceArgVectors);
			if (status != 0)
			{
				if (status == 1053) {
					wprintf(L"[!] Unable to start service, The service did not respond to the start or control request in a timely fashion 0x%ld\n", status);
					Delete();
				}
				else {
					wprintf(L"[!] Unable to start service 0x%ld\n", status);
					Delete();
				}
			}
			else {
				wprintf(L"[*] Service is started.\n");
				exit(0);
			}
		}
	}
	else
	{
		wprintf(L"ROpenSCManagerA Wrong");
	}
	

	
}