# RpcsDemo

## 1、前言

本项目主要编写了一些利用RPC协议在内网中的一些攻击面，有时候Byoass EDR等设备会有较好的效果，那么什么是RPC呢，RPC 代表“远程过程调用”，它不是 Windows 特定的概念。RPC 的第一个实现是在80年代在UNIX系统上实现的。这允许机器在网络上相互通信，它甚至被“用作网络文件系统（NFS）的基础”，其实简单的说就是它允许请求另一台计算机上的服务。

Demo大部分都是参考了impact工具，大家可以查看impacket源码，发现更多有趣的攻击面。

## 2、相关Demo的功能

| Demo                     | 注释                        |
| ------------------------ | --------------------------- |
| DumpLsass                | Dump lsass.exe              |
| MS-SAMR/AddUser          | 添加用户                    |
| MS-SAMR/ChangeNtlm       | 通过NTLM hash修改密码       |
| MS-TSCH_DESK             | 创建计划任务                |
| OXIDINterka_network_card | 探测内网多网卡              |
| RPC over SMB             | 通过SMB做信息探测（无Demo） |
| CreateService            | 创建服务                    |

### 3、后续打算出一篇相关相关Demo的原理

