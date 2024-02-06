---
date created: 2022-12-19 19:57
date updated: 2023-01-31 15:11
---

# Process vs Thread

| Process                              | Thread                           |
| ------------------------------------ | -------------------------------- |
| OS分配資源的單位                            | 分配CPU時間之單位                       |
| processes之間無共享內容                     | 有共享Code, Data,...                |
| Thread Blocked->Process Block!!      | 還有available thread -> process可以跑 |
| 效益低（creation, context-switch slower) | all faster and cost lower        |

# Stack vs Heap

**Stack**

> The stack is the memory set aside as scratch space ==for a thread of execution==.
> The stack is ==always reserved in a LIFO (last in first out)== order; the most recently reserved block is always the next block to be freed.
> ==無法輕易釋放stack的block==（大多都直接改成另一個pointer）

**Heap**

> here's no enforced pattern to the allocation and deallocation of blocks from the heap;
> ==you can allocate a block at any time and free it at any time==

## Thread 種類

- kernal thread
- user thread

# Process

> 執行中的程式
> 程式的基本執行實體
>
> 組成:
>
> 1. **Code section**: program code
> 2. **Data section**: 包含globle variables, static variable
> 3. **Heap**: 包含memory dynamically allocated during run time
> 4. **Program counter, other register**

# PCB #⭐️⭐️⭐️

> 當process被建立，kernel會在kernel memory area 新建一個表格（or Block)，記錄該process之所有**相關資訊**，稱之PCB
>
> 記錄項目(8個)
> `狀態x2, CPUx2, mem, id, pc, accounting(scheduling 相關)`
>
> 1. PID:唯一的
> 2. process state
> 3. CPU register（包含如stack top pointer, accumulator, index register）
> 4. CPU scheduling  info（process 優先權值, PCB pointer）
> 5. Memory management info（Base/ Limit register值, page table）
> 6. program counter
> 7. Accounting info（process使用CPU time 之最大值、目前用了多少cpu time）
> 8. I/O status

![](../img/截圖%202022-12-19%20下午8.08.39.jpg)

# Thread management

## Thread

> 定義：又稱"light weight process"
> 當process內之thread被建立後，每條thread有自己私有的組成內容：
>
> 1. Thread ID
> 2. Thread state
> 3. Programming Counter
> 4. CPU register
> 5. Stack
> 6. local variable
> 7. etc...

**好處：**

- Responsiveness
- Resource sharing
- Ecnomy
- Scalability(可擴展性)：process內每個thread 可在不同CPU內跑->充分利用multiprocessors 之利益

## Multithread Model

- Many-to many
- Many-to-one ~~效益最好~~
- One-to-one

![](../img/截圖%202022-12-21%20下午2.11.15.jpg)

# Process's STD

(process state diagram)

> 目的：描Process之life cycle

`分成5state和7state，差別在於有無處理memory不足的情況的state`
5 state STD

1. New(created) （process已建立、kernel 已配置PCB，但未配置memory）
2. Ready
3. Running
4. Waiting(Block)(Sleeping)
5. Terminated(exit)(zombie)

7 state STD

1. suspended/Ready （較不重要）
2. suspended/Block

![](../../img/截圖%202023-01-31%20下午3.10.36.jpg)
![](../img/截圖%202022-12-21%20下午1.23.40.jpg)

![](../img/截圖%202022-12-19%20下午8.06.18.jpg)
![](../img/截圖%202022-12-19%20下午8.06.32.jpg)
![](../img/截圖%202022-12-19%20下午8.06.43.jpg)
![](../../img/截圖%202023-01-31%20下午3.11.05.jpg)

# Scheduler  #⭐️⭐️

參與
new -> ready
ready <-> running

| Short-Term Scheduler     | Midium-Term Scheduler              | Long-Term Scheduler                             |
| ------------------------ | ---------------------------------- | ----------------------------------------------- |
| 處理process對CPU的使用權 | 處理memory 空間的利用(swap in/out) | 處理multiprogramming's degree, I/O or CPU bound |


## Long-Term Scheduler

> (Job scheduler)
>
> 根據==multiprogramming's degree, I/O, CPU bound比例==
> -> ==控制哪些process to ready==

**分析：**

1. 執行的頻率不高
2. 可以控制multiprogramming's degree
3. 可以調和I/O Bound 與CPU Bound Processes之適當比例組合
4. 在批次系統中常用。但在time-sharing sys., real-time sys.不用

## Short-Term Scheduler

> 又稱CPU scheduler, process scheduler
> 根據==優先級==->控制哪些process running

**分析：**

1. 不能調控multiprogramming's degree, I/O, CPU bound比例
2. Batch , Time-sharing, Real-time皆要使用
3. Time-sharing中常用CPU Time clicing(R-R)方法

## Medium-Term Scheduler

> (Job scheduler)
> 根據memory space, 優先級
> ->==控制swap(mem. & disk)==

# Context Switch #⭐️⭐️

> 定義：
> When CPU switch to another process , the system must ==save the state of the old process== and ==Load the saved state for the new process== via a "Context switch".
>
> - Context of process represented in the PCB
> - 是一種負擔
> - 降低Context Switch負擔:
>   1. Multiple Register Set:每個process有自己的（private) Register set, C.S時, ==kernel 只需切換指標==
>   2. Multithreading

# Dispatcher, Dispatch Latency #⭐️

> 定義：接手排班器出來的process，==並管理CPU的控制權==
> dispatch latency 越小越好

**功能：**

- Context Switch
- switch mode to user mode
- jump

# Process Control operation #⭐️⭐️⭐️

## Process Creation

> 任何process皆可建立processes
> 目的：要child process執行工作
> 可分為:
>
> - 與parent做一樣的事
> - 與parent做不一樣的事

## Child process所需的資源由誰供應

- OS
- parent 的 subset of 資源
- parent 的 all of 資源

## Parent & Child 之互動關係

1. 並行
2. 等待完成

## Process之終止

- process完成工作後會發出一個system call 請kernel 終止，收回其資源
- process可能異常終止
- parent基於以下理由，可能終止child
  - child已完成
  - child過度使用資源
  - parent被終止
    `有時候OS允許child存活，並由OS or grandparent（以上）提供資源`

---

## 以UNIX舉例

### fork()

> 建立child process，==獨立memory space==，資料copy by parent

傳回值：
成功-> 0給child ; child's pid給parent
失敗-> 負數給parent

### Exit()

> 用以終止process。process完成工作會發出此sys. call，請kernel 終止process & release resource
>
> - Exit(0)->正常結束
> - Exit(-1)->異常結束
>
> 若是child，kernel會通知parent

### Wait()

> 暫停process直到事件發生

### execlp()

> 此sys call 用以==載入特定的binary code(or machine code) file ==到memory 中執行
>
> 例：生出child後，要他執行「不同於parent的task」，則child可以用此指令。

### getpid()

> 取得pid

# 評估CPU scheduling 效能之依據 #⭐️⭐

1. CPU使用率：
   `{CPU花在process執行的time}/{CPU total time}`
2. 產能：
   `單位時間內完成的 “程序數目”`
3. 等待時間：
   `等待取得CPU 的時間之總和`
4. 完成Time(Turnaround)：
   `process到達 -> 完成 所經過的時長`
5. 回應時間：
   `user輸入data/command -> 產生第一次回應 的時長`

# 各種CPU scheduling algo. 計算及名詞

```ad-tip
title:preemptive
- preemptive是指在某一process執行時，有另一process打斷並搶走CPU使用權
```

小結:

| No [starvation](starvation.md) | Non-preemptive                     |
| ------------------------------ | ---------------------------------- |
| FCFS, RR, MFQs                 | FCFS, SJF, non-preemptive priority |

## FIFO Scheduling

~~乖乖排隊~~

![](../img/截圖%202022-12-20%20下午8.19.21.jpg)
特性：

1. 簡易
2. 效能差
3. 可能遭遇“[護衛效應](護衛效應.md)”
4. 公平
5. no [starvation](starvation.md)
6. non-preemptive

## Preemptive Scheduling

~~搶走別人正在用的CPU~~

> 定義：process在執行時可能因為事件，而被迫放棄CPU，回到ready queue

優點：

- 完工時間不可預期
- context-switch相對多
- 較有可能race condition
- 排班效果較佳

缺點：

- 適合Real-time sys. , Time sharing sys.

## SJF Scheduling

shortest job first

> 定義：CPU burst time最小的process優先取得CPU。（若相同則以FCFS為準）
> _Non-preemptive_

![450](../img/截圖%202022-12-20%20下午8.32.35.jpg)
特性：

1. SJF排班效益最佳 （short job減少的wait time > Long Job 增加的waiting  -> ==平均wait time 最小==）
2. 不公平
3. 可能有[starvation](starvation.md) for long-bust time job
4. ==不能用在CPU scheduling（因為不知job長短。執行頻率太高間隔時間太短）==

## SRJF Scheduling

shortest remaining job first

> 及preemptive SJF
> 當process執行時==新到達的process之burst time < 正在執行的process之“剩餘”burst time==
> ->新到達的preempts目前process

![](../img/截圖%202022-12-20%20下午8.42.54.jpg)

## Priority Scheduling

> 定義：高優先度的優先取的CPU。（相同則以FCFS）
> 根據特性，實際上大部分排班規則都屬於Priority

特性：

1. 是一個可參數化之法則，給予不同priority 定義，可產生不同行為之排班
   ![](../img/截圖%202022-12-20%20下午8.47.09.jpg)
2. 不公平
3. [starvation](starvation.md) problem

## Round-Robin Scheduling(RR)

~~定期換班！！~~

若多個pointers指向同一個PCB，在RR中，該process可以獲得更多使用CPU的時間

`變化：multiple Quantum time`

![](../img/截圖%202022-12-21%20下午1.25.15.jpg)
![](../img/截圖%202022-12-21%20下午1.26.00.jpg)

## Multilevel Queue

~~多種排班疊再一起~~

![](../img/截圖%202022-12-21%20下午1.27.12.jpg)

## MultiLevel Feedback Queues(MFQs)

~~多層排班。但是！process可以使用[Aging](Aging.md)，可以上下層跑~~

> 定義：允許Multilevel queue's process moves between queues , & 可採用[Aging](Aging.md)

**特性：**

1. 可參數化項目眾多
2. 不公平
3. preemptive
4. No starvation

## Conbine of RR & Priority scheduling

~~用RR處理相同優先權的priority scheduling~~

> 定義：優先run高優先的process。但是！若是優先度一樣，則使用RR

# 特定sys. 排班設計考量 #⭐️

## Multiprogramming system

- ASMP
- SMP

## Processor Affinity

> 緣由：若process切換到其他的CPU處理，則cache的資料需要轉移->代價高
>
> 所以Affinity 期望process都待在同一個process完成

type of sys. call:`Linux 提供`

- soft affinity:盡量不移轉，但必要時可以轉
- hard affinity:絕對不移轉。

## Multi-Core CPU

**Meomry stall issue:**

**Solution:**
~~compute cycle & memory cycle 交錯~~
現今硬體製作"Multithreaded processing Cores"
->`>= 2`個hardware threads are assigned to each core
->`若一條hardware thread 發稱memory stall，the core can sitch to another thread and continue process`

## Real-time sys. scheduling #⭐️

### Hard real-time sys.

### hard real-time sys. 排班

![](../img/截圖%202022-12-21%20下午1.57.11.jpg)

### EDF法則

> 採取"Dynamic" priority 且preemptive
> ==規定Deadline越低，優先權越高==

![](../img/截圖%202022-12-21%20下午1.57.43.jpg)

# CPU utilization #⭐️⭐
