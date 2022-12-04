#include <stdio.h>
#include <Windows.h>
#include "SchRPC.h"


#pragma comment(lib, "rpcrt4.lib")

const RPC_WSTR UUI = L"86D35949-83C9-4044-B424-DB363231FD0C";
const RPC_WSTR InterfaceAddress = (RPC_WSTR)L"\\pipe\\atsvc";

#define TASK_CREATE 2
#define TASK_LOGON_NONE 0
RPC_STATUS status;
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)

//
//typedef RPC_STATUS(WINAPI* MyRpcStringBindingComposeW)(
//	RPC_WSTR ObjUuid,
//	RPC_WSTR ProtSeq,
//	RPC_WSTR NetworkAddr,
//	RPC_WSTR Endpoint,
//	RPC_WSTR Options,
//	RPC_WSTR* StringBinding
//	);
//typedef RPC_STATUS(WINAPI* MyRpcBindingFromStringBindingW)(
//	RPC_WSTR           StringBinding,
//	RPC_BINDING_HANDLE* Binding
//	);
//typedef RPC_STATUS(WINAPI* MyRpcBindingSetAuthInfoExA)(
//	RPC_BINDING_HANDLE       Binding,
//	RPC_CSTR                 ServerPrincName,
//	unsigned long            AuthnLevel,
//	unsigned long            AuthnSvc,
//	RPC_AUTH_IDENTITY_HANDLE AuthIdentity,
//	unsigned long            AuthzSvc,
//	RPC_SECURITY_QOS* SecurityQos
//	);
//typedef RPC_STATUS(WINAPI* MyRpcStringFreeW)(
//	RPC_WSTR* String
//	);
//
//MyRpcStringBindingComposeW nRpcStringBindingComposeW;
//MyRpcBindingFromStringBindingW nRpcBindingFromStringBindingW;
//MyRpcBindingSetAuthInfoExA nRpcBindingSetAuthInfoExA;
//MyRpcStringFreeW nRpcStringFreeW;

//10 min
static const wchar_t* xml =
L"<?xml version=\"1.0\" encoding=\"UTF-16\"?>\n"
L"<Task version=\"1.2\" xmlns=\"http://schemas.microsoft.com/windows/2004/02/mit/task\">\n"
L"  <RegistrationInfo>\n"
L"    <Author>Microsoft Corporation</Author>\n"
L"    <Description>test</Description>\n"
L"    <URI>\teas</URI>\n"
L"  </RegistrationInfo>\n"
L"  <Triggers>\n"
L"    <TimeTrigger id=\"Trigger1\">\n"
L"      <Repetition>\n"
L"        <Interval>PT10M</Interval>\n"
L"        <StopAtDurationEnd>false</StopAtDurationEnd>\n"
L"      </Repetition>\n"
L"      <StartBoundary>2005-01-01T12:05:00</StartBoundary>\n"
L"      <Enabled>true</Enabled>\n"
L"    </TimeTrigger>\n"
L"  </Triggers>\n"
L"  <Principals>\n"
L"    <Principal id=\"LocalSystem\">\n"
L"      <RunLevel>HighestAvailable</RunLevel>\n"
L"      <UserId>S-1-5-18</UserId>\n"
L"    </Principal>\n"
L"  </Principals>\n"
L"  <Settings>\n"
L"    <MultipleInstancesPolicy>IgnoreNew</MultipleInstancesPolicy>\n"
L"    <DisallowStartIfOnBatteries>true</DisallowStartIfOnBatteries>\n"
L"    <StopIfGoingOnBatteries>true</StopIfGoingOnBatteries>\n"
L"    <AllowHardTerminate>true</AllowHardTerminate>\n"
L"    <StartWhenAvailable>true</StartWhenAvailable>\n"
L"    <RunOnlyIfNetworkAvailable>false</RunOnlyIfNetworkAvailable>\n"
L"    <IdleSettings>\n"
L"      <Duration>PT10M</Duration>\n"
L"      <WaitTimeout>PT1H</WaitTimeout>\n"
L"      <StopOnIdleEnd>true</StopOnIdleEnd>\n"
L"      <RestartOnIdle>false</RestartOnIdle>\n"
L"    </IdleSettings>\n"
L"    <AllowStartOnDemand>true</AllowStartOnDemand>\n"
L"    <Enabled>true</Enabled>\n"
L"    <Hidden>false</Hidden>\n"
L"    <RunOnlyIfIdle>false</RunOnlyIfIdle>\n"
L"    <WakeToRun>false</WakeToRun>\n"
L"    <ExecutionTimeLimit>PT72H</ExecutionTimeLimit>\n"
L"    <Priority>7</Priority>\n"
L"  </Settings>\n"
L"  <Actions Context=\"LocalSystem\">\n"
L"    <Exec>\n"
L"      <Command>%s</Command>\n"
L"    </Exec>\n"
L"  </Actions>\n"
L"</Task>\n";

//VOID GetFunction() {
//
//	HMODULE handle = LoadLibraryA("rpcrt4.dll");
//	nRpcStringBindingComposeW = (MyRpcStringBindingComposeW)GetProcAddress(handle, "RpcStringBindingComposeW");
//	nRpcBindingFromStringBindingW = (MyRpcBindingFromStringBindingW)GetProcAddress(handle, "RpcBindingFromStringBindingW");
//	nRpcBindingSetAuthInfoExA = (MyRpcBindingSetAuthInfoExA)GetProcAddress(handle, "RpcBindingSetAuthInfoExA");
//	nRpcStringFreeW = (MyRpcStringFreeW)GetProcAddress(handle, "RpcStringFreeW");
//}

handle_t BindtoRpc()
{
	wchar_t buffer[100];
	RPC_WSTR StringBinding;
	handle_t BindingHandle;
	RPC_SECURITY_QOS SecurityQOS = { 0 };

	RpcStringBindingComposeW(UUI, (RPC_WSTR)L"ncacn_np", (RPC_WSTR)L"localhost", InterfaceAddress, NULL, &StringBinding);
	RpcBindingFromStringBindingW(StringBinding, &BindingHandle);

	SecurityQOS.Version = 1;
	SecurityQOS.ImpersonationType = RPC_C_IMP_LEVEL_IMPERSONATE;
	SecurityQOS.Capabilities = RPC_C_QOS_CAPABILITIES_DEFAULT;
	SecurityQOS.IdentityTracking = RPC_C_QOS_IDENTITY_STATIC;
	RpcBindingSetAuthInfoExA(BindingHandle, 0, RPC_C_AUTHN_LEVEL_PKT_PRIVACY, 0xA, 0, RPC_C_AUTHZ_NONE, &SecurityQOS);

	RpcStringFreeW(&StringBinding);

	return(BindingHandle);
}


BOOL CreateTask(handle_t handle, wchar_t* ProgramPath, wchar_t* wszProgramArgs) {

	wchar_t xmlBuffer[4096];
	wchar_t* actualPath = NULL;
	TASK_XML_ERROR_INFO* errorInfo = NULL;

	swprintf(xmlBuffer, 4096, xml, ProgramPath);

	HRESULT status = SchRpcRegisterTask(handle, L"\\MicroSoft Corp", xmlBuffer, TASK_CREATE, NULL, 0, 0, NULL, &actualPath, &errorInfo);

	if (status == S_OK)
	{
		return TRUE;
	}
	return FALSE;
}

int wmain(int argc, wchar_t* argv[]) {

	//GetFunction();
	handle_t handle = BindtoRpc();

	BOOL isSuccess = CreateTask(handle, argv[1], NULL);

	if (isSuccess == TRUE)
	{
		printf("add success");
	}
	else {
		printf("false");
	}

	return 0;
}


void __RPC_FAR* __RPC_USER midl_user_allocate(size_t cBytes)
{
	return((void __RPC_FAR*) malloc(cBytes));
}

void __RPC_USER midl_user_free(void __RPC_FAR* p)
{
	free(p);
}
