https://mp.weixin.qq.com/s/VKi0UzFthMYKmA4Cq-0D1A

主要是利用`MS-TSCH`协议
https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-tsch/21e8e86e-ee5a-469d-917f-28a41f3c25a4

主要用了三个接口，主要关注第三个接口

![image-20221031002545297](/Users/Monster/Desktop/RedTeam/picture/image-20221031002545297.png)

根据解释说是可以使用XML自定义计划任务

![image-20221031002733825](/Users/Monster/Desktop/RedTeam/picture/image-20221031002733825.png)

![image-20221031003032428](/Users/Monster/Desktop/RedTeam/picture/image-20221031003032428.png)

但是在编写的时候查看源码发现多了一个参数，就是我们需要绑定的句柄

![image-20221031003133549](/Users/Monster/Desktop/RedTeam/picture/image-20221031003133549.png)

![image-20221031003154417](/Users/Monster/Desktop/RedTeam/picture/image-20221031003154417.png)

我们去搜一下这个是什么

https://learn.microsoft.com/en-us/windows/win32/rpc/rpc-binding-handle
![image-20221031004102217](/Users/Monster/Desktop/RedTeam/picture/image-20221031004102217.png)

https://learn.microsoft.com/zh-cn/windows/win32/rpc/primitive-and-custom-binding-handles

![image-20221031004130034](/Users/Monster/Desktop/RedTeam/picture/image-20221031004130034.png)

按照这个写就可以

其中的XML 可以参考微软官方的
https://docs.microsoft.com/en-us/windows/win32/taskschd/logon-trigger-example--xml-