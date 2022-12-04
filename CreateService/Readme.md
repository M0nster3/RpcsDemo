不是所有程序都可以作为服务的方式运行，因为作为服务运行需要能返回运行情况等信息，所以有的程序添加后会

出现以下提示：

Windows无法启动 XXX 服务（位于 本地计算机上）。错误1053:服务没有及时响应启动或者控制请求。

微软有一个srvany.exe可以解决此问题，首先创建一个服务，但是执行文件要选择srvany.exe

sc create ServiceName binPath= "C:\Windows\srvany.exe" start= auto

reg add HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\ServiceName\Parameters /v AppDirectory /t REG_SZ /d "c:\" /f

reg add HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\ServiceName\Parameters /v Application /t REG_SZ /d "c:\xxx.exe" /f

reg add HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\ServiceName\Parameters /v AppParameters /t REG_SZ /d "如果程序需要参数则填在这里，如果不需要，清空这段文字或者整行" /f

