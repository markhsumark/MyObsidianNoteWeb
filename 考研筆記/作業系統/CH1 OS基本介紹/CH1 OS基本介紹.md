---
date created: 2022-12-08 22:09
date updated: 2022-12-08 22:44
---

# Computer System structure

# OS structure

# OS之目的

# System types

## Multiprogramming system

![200](../img/截圖%202022-12-08%20下午9.59.08.jpg)

> 允許多個process in memory，同時進行（一段時間執行多個job）
> `若有process等待I/O，switch 到其他process -> 不讓process佔用CPU資源`

```ad-note
title:名詞解釋
1. Multiprogramming degree:待在系統中執行的process數目
```

## Time sharing system

![200](../img/截圖%202022-12-08%20下午9.59.22.jpg)

> 又稱multitasking ，It is a logical extension of Multiprogeamming sys
> (CPU switch jobs so frequently so that user can interact withneach job while it's running)
>
> - response time 要短，對每個user job 公平

**技術**

1. CPU schedluing 採用RR排程[ch4]
2. 有swapping 技術，及[virtual memory](../CH8%20Virtual%20Memory/CH8%20Virtual%20Memory.md) 技術
3. 有spooling 技術，讓每個user有自己 I/O-device 的感覺(同時也有Buffering 技術一併使用)

## Multiprocessors, Multicores system

> 又稱parallel, Tightly-Coupled system
> 主要特色：
>
> 1. 一部裝置內有多顆processors(or CPUs)，所有CPUs均共享machine 內的所有硬體
> 2. 通常都由同一個clock控制
> 3. 通常由==一個==OS管控所有CPUs
> 4. processors之間的溝通大多採 shared memory 方式

**Benefits:**

1. Increased througtput :
   同時處理多個job
2. Increased Reliability :
   萬一其中一個壞了，有其他的可以頂住
3. Economy of scale 運算能力規模擴充:
   共享bus, momory等其他資源

### ASMP(Asymmetric Multiprocessoes)

> 每一個processor提供的工作能力不同
> 通常是==Master-slave==

優點：

- 容易開發
- 便於從single-cpu OS修改而得

缺點：

- 效能較差：master-cpu是buttlenech
- 可靠度較差：Master-cpu壞了->停頓選新的Master

### SMP(Symmetric Multiprocessoes)

> 每一個Processor之工作能力皆相同，有對等權利、存取資源

優點缺點：
_**與ASMP相反**_

## Distributed system

~~彼此獨立，卻互相協助的一群機器~~

> 又叫Loosely-Coupled system
> 主要特色：
>
> 1. 多部Machine 以Network相互串連
> 2. 每一部machine內的cpu有自己的local momory, Bus, ...etc
> 3. 各CPU的clock不盡相同
> 4. 各CPU的OS不盡相同
> 5. processors之間的溝通採取"Message Passing"方式[ch6]

**構建理由或好處：**

1. throughput 增加
2. 可靠度提昇
3. Resource sharing -> cost down：因為他支持_client-server computinh enviroment_
4. remote communication（遠端通訊需求之滿足）

## Real time

可以分為2種

1. Hard real-time sys.
2. Soft real-time sys.

### Hard real-time system

> 定義："This system must ensure the critical task c==omplete on time!!=="
> 例如：軍事防衛系統、核能安控、汽車燃料控制、居家軟體控制、顯示系統

**系統設計考量**

- 任何可能影響處理時間之因素
- 可能造成處理時間過長 or 不可預期之設備，宜少用或不用（EX:Disk）
- 降低kernel 的干涉時間
- 用特殊的OS(or 不用OS)
- 不會與Time-sharing sys.並存

### Soft real-time system

> 定義："This system must ensure the real-time process has the ==highest priority== than the others and return this level of priority ==until it completed!=="
> 例：multimedia system , Virtual Reality, Science simulation

**系統設計考量**

1. CPU scheduling 而言：可插隊（preemption）、不提供Aging技術
2. 盡量降低kernel 之dispatch latency
3. ==現行的OS皆可支援==
4. 可支持virtual memory 之使用
5. 可以與Real-time 並存

## Mobile computing

> mobile device
> 硬體上的先天限制

| HW之先天限制                    | SW之設計限制                        |
| -------------------------- | ------------------------------ |
| slower processor(能耗大、散熱問題) | 運算不宜過度複雜                       |
| memory size 小              | 程式宜精。不用的memory space 立即release |
| display sceen 小            | 檢視之結果or內容有所裁剪                  |

## Batch system

> 定義：將一些非急迫性or 週期性之工作累積成堆，再批次送入系統處理，處理過程中不需雨user interaction
> 例：報稅、下載更新軟體

主要目的：想提高冷門時間之資源利用度
不適合用在user-interactive app & real-tiem app
