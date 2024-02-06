---
date created: 2022-12-20 16:15
date updated: 2022-12-29 17:42
---

# System call #⭐️

> 作為user processes 和 kernel 溝通之==介面==，代表OS可以提供的服務項目
> 例如：讀取檔案、拷貝、

## 種類

1. 處理程序控制
2. 檔案的運用
3. 裝置的運用

## 步驟

參數放到stack, system call's code放到暫存器, trap kernel, 

1. Push parameters on stack.  
2. Invoke the system call.  
3. Put code for system call on register.  
4. Trap to the kernel  
5. Since a number is associated with each system call, system call interface invokes/dispatch intended system call in OS kernel and return status of the system call and any return value.  
6. Increment stack pointer.

![](../../img/截圖%202023-01-22%20下午4.05.12.jpg)

## 參數傳遞方式 #⭐️⭐

### 利用Registers

**優點：**
簡單、快速

**缺點：**
不適用在大量參數

### 利用memory

> 以memory 中一個Block保存這些參數，然後將Block's address記在register中給OS用

**優點：**
適用於大量參數

**缺點：**
存取速度慢

### 利用stack

> 參數push進，OS再pop以取得

**優點：**
適用大量參數，且比memory簡單

**缺點：**
stack size大小應該要很大（以免溢出）

# policy and mechanism #⭐️⭐

| Policy(策略)             | Mechanism(想法)     |
| ------------------------ | ------------------- |
| =="What" will be done?== | =="How" to do it?== |
| 經常改變                 | 通常不會改          |
`「賦予等級」及「確切數字」等實體含義的即為”policy”`

例：

- 使用priority 做CPUscheduling -> Mechanism
- 優先權大小定義-> Policy

# OS structure

## Simple

## More Complex than Simple

## Layered approach

## Microkernel #⭐️⭐️⭐️⭐️

```ad-question
title:什麼是Microkernel
移除kernel中不必要的service並將其移至user-level以sys. library方式提供。(ex: iOS and Android)
```

> 起源：_CMU_(卡內基美隆大學)最早提出此概念，為_簡化UNIX_發展出==MachOS==
> 定義：將==kernel 中一些 非必要的服務自 kernel 中移除==，改成在user site 以 system software/library 方式提供服務，==以便得到一個較小的kernel==
>
> 一般而言提供：
>
> - Process management
> - Memory management
> - Process Communication
> 
> 應用例子：iOS and Android

**優點：**

1. 更容易擴充microkernel：
   很多服務在user site，不需要kernel  大幅配合修改
2. 更容易將OS移植到新的硬體架構
3. 更可靠和安全
   若service fail，因為running 在user site ，所以不影響其他process and kerenl。

**缺點：**
Performance變差：
user site & kernel 之間大量message處理＆傳輸之負擔

## Monolithic #⭐️⭐️⭐️⭐️

```ad-question
title:什是Monolithic
將子系統整合成一大塊程序放進kernel的簡化架構，可以直接用sys. calls呼叫kernel services.
```

> 定義：
> 與Microkernel 相反。所有的kernel services 皆Run在kernel mode
> 將子系統整合成一大塊程序放進kernel的簡化架構，可以直接用sys. calls呼叫kernel services.
> 
> 例(大部分OS)：UNIX, Linux, Windows, Apple OS

**優缺**
與Microkernel 相反

## Modules

## Hybrid system

# Virtual Machine

**相關名詞：**

- Host：underlying HW system
- _Virtual Machine Manager(VMM)_ or Hypervisor：
  ==Create== and ==Run== VM by providing interface that is identical to the host
- Guest：
  process provided with ==virtual copy of the host== ~~通常是OS~~

## VMM 種類 #⭐️⭐

### Type 0

### Type 1

- OS-like-Software：只提供virtaulization 功能
- general-purpose OS 但是是在kernel mode提供VMM

### Type 2

> Applications that run on standard OS but provides VMM功能

e.g Virtual Box, Parallel Desktop

## Virtualization之變形 #⭐️

## 優點與應用 #⭐️

好處

1. 作為一個測試發展中的OS的良好==負載平台==
2. 降低成本
3. 安全
4. 雲端服務&商業
   1. 備份
   2. 整合sys. ~~多個sys.在同一台機器~~
   3. 轉移能力
   4. templating

缺點

1. 不好開發
2. 效能比real HW差

---

# Icloud computing

- Public cloud
- Private cloud
- Hybrid cloud
- Software as a service (SaaS):在網路上提供的APP
- Platform as a service (PaaS):API功能提供。e.g database server
- Intrastructure as a service (IaaS):備份運算
