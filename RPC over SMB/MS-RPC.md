https://www.hackingarticles.in/active-directory-enumeration-rpcclient/

MS-RPC服务还可以通过不同的传输协议访问，其中通过SMB传输的RPC服务可以通过命名管道访问，可以对某些机器进行SMB空会话连接的话（比较少见）还可以使用更多RPC接口搜集信息，这也导致了可以利用这个特点进行一些信息的探测。

常见的情况是如果红队人员在目标内网有一个落脚点以及得到一份域凭据就可以使用这种方式连接DC进行一些RPC接口调用，从而探测有价值的域信息；使用该种方法比执行一些NET类收集命令有更好的规避性。

rpcclient可以执行MS-RPC（kali）

### 1、连接

```
rpcclient -U "Domamin/user" ip
```

### 2、查询域信息

```
querydominfo
```

### 3、枚举域用户

```
enumdomusers
```

### 4、枚举域组

```
enumdomgroups
```

### 5、组查询

(0x200是枚举域组中得到的内容)

```
querygroup 0x200
```

### 6、查询用户

```
queryuser Administrator
```

### 7、枚举权限

```
queryprivs
```

### 8、获取域密码信息

```
getdompwinfo
```

### 9、获取用户域密码信息

(列举了 RID 为 0x1f4 的用户的密码属性。)

```
getusrdompwinfo 0x1f4
```

### 10、从 LSA 枚举 SID

```
lsaenumsid
lookupsids sid号
```

### 11、创建域用户

```
createdomuser hacker
setuserinfo2 hacker Password@1
enumdomusers
```

### 12、查找名称(获取用户sid)

```
lookupnames user
```

### 13、枚举别名组

(它枚举域上的别名组。别名是可用于引用对象或元素的替代名称。当与内置参数一起使用时，它会按别名显示所有内置组，如下所示。)

```
enumalsgroups builtin
```

### 14、删除域用户

```
deletedomuser user
```

### 15、枚举共享

```
netshareenum 
netshareenumall
```

### 16、查看枚举共享的详细信息

```
netsharegetinfo Confidential
```

### 17、枚举域

```
enumdomains
```

### 18、枚举域组

```
enumdomgroups 
enumdomusers 
queryusersgroups 0x44f 
querygroupmem 0x201
```

### 19、域的用户以及 RID

```
querydispinfo
```

### 20、更改用户密码

```
chgpasswd raj oldpass newpass
```

### 21、创建域组

```
createdomgroup newgroup
enumdomgroups
```

### 22、删除域组

```
deletedomgroup newgroup
enumdomgroups
```

### 23、域查找

```
lookupdomain domains
```

### 24、SAM 查找

```
samlookupnames domain raj 
samlookuprids domain 0x44f
```

25、**LSA 查询**

```
lsaquery 
dsroledominfo
```

26、**LSA 创建帐户**

```
lookupnames Monster0
lsacreateaccount S-1-5-21-3232368669-2512470540-2741904768-1103
```

27、**枚举 LSA 组特权**

```
lsaenumsid
lookupsids S-1-1-0
lsaenumprivsavvount S-1-1-0
lsaenumacctrights S-1-1-0

也可以操纵该 SID 的权限，使其容易受到特定权限的攻击或完全删除用户的权限。为了证明这一点，攻击者首先使用 lsaaddpriv 命令将 SeCreateTokenPrivielge 添加到 SID，然后使用 lsadelpriv 命令从该组中删除该特权。所有这些都可以在 lsaenumprivaccount 命令的使用中观察到。

lsaaddpriv S-1-1-0 SeCreateTokenPrivilege 
lsaenumprivsaccount S-1-1-0 
lsadelpriv S-1-1-0 SeCreateTokenPrivilege 
lsaenumprivsaccount S-1-1-0
```

28、**枚举 LSA 帐户权限**

在之前的演示中，攻击者能够为组提供和删除权限。也可以为特定用户添加和删除权限。lsaaddacctrights 命令可用于根据用户的 SID 向用户添加权限。SID 是使用lookupnames 命令检索的。在验证使用 lsaenumprivaccount 命令添加了权限后，我们使用 lsaremoveacctrights 命令删除了用户的权限。

```
lookupnames raj 
lsaaddacctrights S-1-5-21-3232368669-2512470540-2741904768-1103 SeCreateTokenPrivilege 
lsaenumprivsaccount S-1-5-21-3232368669-2512470540-2741904768-1103 
lsaremoveacctrights S-1-5-21-3232368669-2512470540-2741904768- 1103 SeCreateTokenPrivilege 
lsaenumprivsaccount S-1-5-21-3232368669-2512470540-2741904768-1103

在处理不同用户和组的权限后，可以使用 lsalookupprivvalue 命令为特定用户枚举这些特定权限的值。
lsalookupprivvalue SeCreateTokenPrivielge
```

29、**LSA 查询安全对象**

```
lsaquerysecobj
```

