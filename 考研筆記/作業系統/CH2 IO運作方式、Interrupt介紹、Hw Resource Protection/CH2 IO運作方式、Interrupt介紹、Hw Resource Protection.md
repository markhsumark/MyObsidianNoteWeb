---
date created: 2022-12-12 22:24
date updated: 2023-01-11 23:25
---

# I/O

## Polling I/O

> 定義：又叫 ==Busy-waiting I/O== or ==Programmed I/O==

**steps:**

1. 執行中的process發出I/O request 給OS, 希望OS提供某種I/O服務
2. OS收到請求，（可能）會先Block process
3. OS中的_I/O subsystem_會處理此請求
4. I/O subsystem 會pass 需求給==device driver==
5. ==device driver==會依此請求設定相關_I/O-Commands_ 到_device controller_
6. _device controller_會指揮_I/O device_運作
7. 此時CPU可能idle，OS可能會將CPU分給其他process用
8. CPU會不斷地去polling I/O-Device controller上之相關register值，確定是否完工

![](../img/截圖%202022-12-08%20下午11.00.10.jpg)

**缺點：**

CPU並未將全部的時間用於process exec.上，而是大部分時間去polling I/O-Deviec controllers
-> CPU利用度不高，且process throughput 偏低

## Interrupt I/O

**steps:**(1~7同Polling I/O)
8. 當I/O工作完成，I/O-Device Controller 會發出一個"==I/O completed=="interrupt 通知CPU(OS)~~對kernel level process~~
9. OS收到中斷通知後，可能會==暫停目前執行的process==
10. OS依照Interrupt ID(No)查詢==Interrupt vector==，找到對應的==ISR==(服務處理程式)
11. Jump to ISR並執行ISR
12. ISR完成，控制權交回kernel I/O-subsystem，通知process I/O-completed 以及其結果。
13. OS==恢復==之前中斷的process 或交給CPU scheduler決定
![](../img/截圖%202022-12-12%20下午11.04.58.jpg)

**優點：**
CPU無須花時間用於polling，而是全心用於Process execution。所以CPU utilization和throughput較高
**缺點：**

1. Interrupt之處理需耗費時間(CPU time)
   `Note:I/O很快的話，pollinh也許比interrupt 還有效率`
2. 若Interrupt頻率高->CPU utiliztion會很差`時間都用在處理Interrupt`
3. CPU仍需花時間處理memory之間的Data-transfer

## DMA(direct memory access)

> 定義：_DMA controller_負責_I/O-Device_ and _memory_ 之間的==_Data-transfer工作_==。~~解決Interrupt I/O的缺點3~~
>
> **所以（優點）：**
>
> 1. CPU有更多時間可以花在process上
> 2. 適合用*"Block"-Transfer oriented I/O-Device*, ex: Disk。
>
> **缺點：**
>
> 1. 增加硬體設計之複雜度
> 2. 因為，DMA會和CPU爭奪memory 和Bus之使用權->硬體協調設計（通常是DMA高優先）

**Cycle stealing(interleaving**

> CPU 和 DMA爭奪memory的使用權時，通常DMA有較高的優先權，所以CPU可能會被迫暫停。
> 
> 當週邊設備要求進行主記憶體存取時，它中斷中央處理器， 它用不著儲存中央處理器狀態，並使==中央處理器延遲一個記 憶體週期(Memory Cycle)，週邊設備利用這極短的時間 ，至主記憶體內存取一或二個位元組(Bytes)==。

```ad-question
title:CPU怎麼使用DMA
CPU 將數值寫入DMA能夠access的特殊register中，DMA收到命令後就會開始操作
```

```ad-question
title:CPU怎麼知道DMA是否結束？
DMA完成工作後，會interrupt CPU
```



![](../img/截圖%202022-12-12%20下午11.20.24.jpg)

# Interrupt

> 定義：系統中*硬體*產生的變化
> 
> kernel所在的memory area 中會存有一個"==Interrupt vector=="表，內放各式==interrupt ID== & ==ISRs之位址==。此外也會存這一些==ISRs 的 Binary code==

## Interrupt 處理

**OS之處理steps:**

1. OS收到後，**若要**立即處理->展停目前執行的process且保存其status
2. OS查interrupt vector  based on interrupt ID，辨別何種中斷發生且找出ISR之位置
3. Jump to ISR位置並執行
4. 完成ISR，然後交回kernel控制
5. 恢復之前被中斷的process(或是依照CPU scheduler)

![400](../img/截圖%202022-12-20%20下午4.03.05.jpg)

## Interrupt種類

**[分類一]**

1. External interrupt:CPU之外的元件發出的。~~I/O-completed, I/O error, machine-check~~
2. Internal interrupt:CPU執行process時遇到重大error引起。~~divide zero~~
3. Software interrupt:process執行時，若需OS提供某種服務，會發出此類型的中斷，通知OS [CH3 system call](../CH3%20OS%20structure%20and%20Development/CH3%20OS%20structure%20and%20Development.md#System%20call%20⭐️)

**[分類二]** ~~常用這個~~ 

| -  | trap                                               | hardware interrupt                   |
| -- | -------------------------------------------------- | ------------------------------------ |
| 定義 | 軟體產生的中斷                                            | 硬體產生的中斷                              |
| 目的 | catch the arithmatic interrupt, software interrupt | I/O通知OS事件，像是I/O complete, I/O error等 |

1. Interrupt:硬體產生的中斷
2. Trap:軟體產生的中斷。catch the arithmatic interrupt, software interrupt

**[分類三]**
Interrupt之間應該有優先權

1. Non-maskable-Interrupt:需立即處理
2. Maskable-interrupt:此中斷發生可以delay或是忽略

## Blocking I/O, Non Block I/O, Asynchoronous-I/O

![](../img/截圖%202022-12-12%20下午11.55.28.jpg)
![250](../img/截圖%202022-12-12%20下午11.55.36.jpg)

# Hw Resource Protection

## 基礎建設

### Dual mode

![](../img/截圖%202022-12-12%20下午11.56.57.jpg)
![](../../img/截圖%202022-12-29%20下午4.57.15.jpg)
```ad-question
title:dual mode operation is provided by OS or CPU
Both. dual mode同時需要硬體以及軟體的支援。CPU中的mode bit。OS需要定義privilege instructions
```
```ad-question
title:什麼情況下會讓mode從user mode switch 到kernel mode?
system call, interrupt, divides by zero, illegel memory access, ...
```
```ad-question
title:OS可以run在user mode嗎？
不可，這樣就無法達到dual mode的目的
```

### Privilege instruction

![](../../img/截圖%202022-12-29%20下午4.57.26.jpg)

## I/O protection

~~使用特權指令~~
![](../../img/截圖%202022-12-29%20下午4.57.35.jpg)

## Memory Protection

~~register 限制上下界~~

![](../../img/截圖%202022-12-29%20下午4.58.19.jpg)

## CPU protection

~~Max-Time-Quantum~~
![](../img/截圖%202022-12-12%20下午11.57.24.jpg)
