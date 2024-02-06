---
date created: 2022-12-14 20:17
date updated: 2022-12-26 21:13
---

# Process Communication 兩大方式

Interprocess Communication (IPC)

## Shared memory

> 定義：
> Processes之間，透過向OS申請一個shared memory space ，在這space 上可宣告一些shared memory,processes 可藉由write/read這些共想變數，達到溝通

特點:

- ==OS不需提供額外支援在溝通==，只提供shared memory 
- Programmer 責任重大，亦即撰寫額外控制碼來確保”No” [Race condition](Race%20condition.md)
- 適用於==大量的資訊溝通==
- 通訊速度快
- ==不需kernel 介入==
- ==需要少量的sys. call(用於create shared memory  space)==
- 不適於分散式系統

## Message passing

> 定義：兩個processes溝通要遵守以下規定
>
> - 建立雙方的communication link
> - Message 可互相傳輸
> - 溝通完，釋放communication link

特點（與shared memory 相反）

- ==OS提供額外支援（建立、回收link ; 傳送、接受message）==
- Programmer無啥負擔
- 適用於==少量資訊溝通==
- 通訊速度慢（==需要用kernel==)
- 較適合分散式系統

# Race condition 兩大策略

[Race condition](Race%20condition.md)

| Disable interrupt | spin lock                                               |
| ----------------- | ------------------------------------------------------- |
| 適合uniprocesser  | 適合multiprocesser、Real-time system、multiple computer |
| 方便簡易實施      | 較為複雜                                                |

## Disable interrupt

~~我在用的時候，其他人不准搶走我的CPU!~~

> 定義：process 執行共享變數存取前，先disable interrupt，完成存取後，才enable interrupt，如此，可保證process在存取共享變數期間cpu不會被preempted，故可防治

**優**
The critical section problem could be solved in simply in a single-core environment if we could prevent interrupt form occurring while a shared variable was being modified.

- Simple
- ==適用於uniprocesser(單cpu)==

**缺**

- 不適合用於Multiprocessors之環境
  1. 若我們只disable a core 之interrupt，無法防止其他core interrupt.  所以只能disable**所有**cpu之中斷，啊disable 其餘cpu，導致==效能就差==
  2. 傳遞訊息需大量時間
- 風險高`一般只開放給OS的開發者，防治kernel data’s race condition`

  ```ad-hint
    - 若放任user process可以disable interrupt, 則對其極度信任，不能讓其為所欲為（不enable interrupt ->CPU never return）  
      
      
    
    Kernel 的data structure 也有race condition 的問題
    
    1.  Non-preemptive kernal: **不會有race condition 的議題**。
    2.  Preemptive kernal: more responsive, more suitable for real-time programming.**但是OS developers 需對kernal data structure 提供防止race condition 之機制**
  ```

## Critical section design(or spin lock)

~~工作台一次只能一個人用~~

> 定義：在每個C.S前後，programmer必須撰寫額外code,稱Entry section（進入區）及Exit section（離開區）
>
> - Reminder section定義： 除了C.S以外之code區間，process不會存取共享變數
> - Critical section 定義：在此code 區間process會存取共享變數

**優**
==適用於Muliprocesser==

### Busy waiting技巧

> 定義：\
> 在entry section 設計當中經常遇到利用此技術來迫使process waiting，無法往下執行。

```C
P𝒾  
if (條件式）then  
{  
	add Pi to waiting Queue;  
	Block(Pi); // sys.call 
	Pi自running->wait  
}  
Pj
if (送達） then  
{  
	remove Pi from waiting Queue  
	Wakeup(Pi);  
}
```
```ad-hint
**此技巧利用決定是否要將process switch到waiting Queue，來避免不需要的loop等待**
```
```ad-hint
~~沒有範例程式碼ＱＱ~~
此技巧是利用迴圈（loop） 相關敘述來完成。  
例：while…do “no operation”  
若條件式保持true->保持迴圈->等待效果  
```



**優缺**：與spinlock 相反

| 與non-busy waiting相比                                                                     | -                                                                 |
| -------------------------------------------------------------------------------------- | ----------------------------------------------------------------- |
| busy waiting 缺點                                                                                      | busy waiting 優點                                                                 |
| 若process平均waitingt之時間很久則spin lock不利，因為其他waiting process仍要與其他process爭奪CPU用在無意義的looping上 | 若process平均皆可在極短的時間內（< context switching）離開loop往下執行，在spin lock十分有利 |
| `也就是說process的C.S 長度決定使用哪一種策略`                                                          |                                                                   |

# C.S 必須滿足的三個性質（需皆滿足）： #⭐️⭐️⭐️⭐️⭐️

## mutual exclusion

~~一次一個process在C.S中~~

> 定義：任何時間點，全部的（每個process中）C.S中，最多只有一個可以在其區間內活動

## Progress

~~不會被迫停止~~

> 定義：
>
> 1. 不想進入C.S之process,不可阻礙或參與其他想進的process。\
>    ==「不要無故阻礙別人」==
> 2. 若一堆process想進入C.S，必須在有限的時間決定誰可進入。「不可造成所有process接近不了」
>    ==「no deadlock」==

## Bounded waiting

~~process排C.S的隊不可以排過久~~

> 定義：==process提出欲進入C.S之申請後，需在有限時間內進入C.S==。若有n個process想進入，任一process最多等n-1次就可進入  **_  要公平，no [starvation](../CH4%20Process%20Management%20&%20Tread%20Management/starvation.md)_**

# C.S design 方法（防止race condition)

## Software solution

> 定義：沒有依靠Hardware and OS支持，存粹程式設計

- [兩個process之C.S design](兩個process之C.S%20design.md)

- ｎ個process之C.S design
  - Algo4: Peterson's n個processes solution
  - Bakery's Algo.

缺點：都必須配合Hardware才能，否則compiler可能會竄改順序導致錯誤

## Hardware support

- [Memory barrier(or memory Fence)](Memory%20barrier(or%20memory%20Fence).md) ~~確保順序正確~~
- [Hardware instructions](Hardware%20instructions.md) ~~不可被中斷的機器指令，保證“atomiclly” executed.~~
- [Atomic value](Atomic%20value.md) 

## [mutex lock](mutex%20lock.md)

## [Semaphore](Semaphore.md)

# 著名的同步問題之解決

## [Producer-Consumer Problem](Producer-Consumer%20Problem.md)

## [Reader/Writer problem](Reader,Writer%20problem.md)

## [The sleeping Barber problem "理髮師睡覺問題"](The%20sleeping%20Barber%20problem%20"理髮師睡覺問題".md)

## [The Dinning-philosophers problem](The%20Dinning-philosophers%20problem.md)

# Monitor

==基本上就是一個類別(Class)==

> **定義**
> 用一種**用於解決synchronization problem** 之Abstract Data type.\
> =>類比於"class"
>
> 組成：
>
> 1. shared variables
> 2. a set of functions
> 3. initialization code
>
> ```C
> struct monitor monitor-name  
> { 
>   shared variables 宣告;  
> 	function P1(參數){...body...}  
> 	...  
> 	function Pn(參數){...body...}  
> 	initialization code(){...}  
>  }
> ```
>
> 特性
>
> 1. 在Monitor內所宣告的共享變數只可以被Monitor內的functions 直接存取，但外界不可
> 2. 本身以**保障mutual exclusion 性質**
>
> 優點：
>
> - Monitor內之共享變數值不會race condition(than semephore)
> - programmer不需去煩惱共享變數之R.C & 同步問題，只需專心處理sync. problem

## Condition variables

> 定義：
> 在Monitor內，提供此特殊型態，及Condition type的變數，提供給programmer 解sync. problem之用途

每個condition有兩個operation
(Condition x;)

- [x.wait](x.wait.md)~~「沒位子了！排隊吧！」~~
- [x.signal](x.signal.md) ~~「下一位！請進」！~~

Note:"Not active"

- process呼叫的function已執行完畢（離開Monitor）
- process執行x.wait()被block

## 應用例子

[Monitor應用例子](Monitor應用例子.md)

## conditional wait

> 先前condition 變數的waiting Queue is FIFO Queue，但在許多場合中，我們需要priority queue(優先權高先移除），才有Conditional wait

宣告 Condition x;
使用x.wait(C);//C表示process的priority number

## Monitor 種類

> 緣由：
> 若P執行了x.signal,此運作會讓Q resources execution 。
> 此時P &Q are active in the monitor但這會違反monitor的保障。所以，不可能。
> 故只能允許其中一個active
> ==選P還是Q先active分出monitor種類==

| -    | [Type1(Hoare monitor)](#Type1(Hoare%20monitor)) | [Type2](#Type2)                            | [Type3](#Type3)                                   |
| ---- | ----------------------------------------------- | ------------------------------------------ | ------------------------------------------------- |
| 描述 | P wait Q until Q finihed or Q is blocked again. | Q wait P until P finished or P is blocked. | P先離開 置於monitor 的 entry queue 的第一個位置） |
| 分析 | 保證Ｑ可以立即恢復執行、比3好                   | Q可能無法執行                              | 保證Ｑ可以立即恢復執行、比1差                     |
|      | Queue在外部                                     |                                            | Queue在monitor內                                  |




### Type1(Hoare monitor)

> P wait Q until Q finihed or Q is blocked again.

==會多一個"救命恩人"的queue，當P signal的時候，暫存Ｐ==

優點

- 保證Q一定可以立即恢復執行。
- more powerful than type[3]。

### Type2

> Q wait P until P finished or P is blocked.

缺點：不保證Q不會被拯救出來
（因為允許P繼續往下，很有可能改變了Q可以被恢復執行的條件。）

### Type3

> P exits monitor, let Q resume execution 直到Q finished or blocked ，P才進入monitor 。
> (P先離開 置於monitor 的 entry queue 的第一個位置）

例子：C/PASCAL語言
![](../../img/B7D02BA1-895A-4A0B-B762-8F43DF2159C4.png)

優點：保證Ｑ一定可以立即恢復執行
缺點：Not powerful than Type1 （理由：在P一進一出monitor期間）

### Type1, 3差異

P暫時儲存的Queue一個在外(monitor外的entry queue)，一個在內(monitor內的Hoare queue)

## 製作Monitor using Semaphore

（以Hoare Monitor為例）
**需求**

- 如何保障Monitor之mutual exclusion
- Hoare monitor性質
- 實作Condition type變數之[x.wait](x.wait.md)及[x.signal](x.signal.md)

**所需之共享變數**

- Semephore mutex = 1;
- monitor的互斥閥
- Semephore next = 0;
  卡救命恩人
- int next-count = 0;
  統計救命恩人個數，確認還有沒有救命恩人
- Semephore x-sem = 0;
  用以卡Q
- int x-count = 0;
  統計Q的個數

**製作碼**

```ad-note
title:Code
保障互斥
~~~C
//保障互斥
function P1(){
	wait(mutex);
	// Body //
	if(next-count > 0){
		signal(next);
	}else{
		siganl(mutex);
	}
}
~~~

Condition 變數
~~~C
x.wait:
x-count = x-count +1;
if(next-count > 0){
	signal(next);
}else{
	signal(mutex);
}
wait(x-sem);
x-count = x-count - 1;
~~~
~~~C
x.signal:
if(x-count > 0){
	next-count = next-count + 1;
	signal(x-sem);
	wait(next);
	// P 被救
	next-count = next-count - 1;
}
~~~
```

```ad-example
title:證明Monitor與semephore解決同步問題的能力是相當的
Ans:因為monitor與semephore是可以相互來製作的。
以[Hoare monitor](#Type1(Hoare%20monitor))為例
基本上就是一個類別(Class)
```

# Message Passing

用Message-Passing
解決[Producer-Consumer Problem](Producer-Consumer%20Problem.md)

## Direct v.s Indirect Communication

| -   | Direct(symmetric)            | Indirect                                        |
| --- | ---------------------------- | ----------------------------------------------- |
| 定義  | 需雙方相互指名對方PID                 | share mailbox建立連結                               |
| 建立後 | 專屬於溝通雙方，不可與他人共享              | link 是可以共享的                                     |
|     | 溝通雙方至多存在一條communication link | 溝通雙方是同時可有多條communication link存在，每條link都有mailbox |

Direct(Asymmetric)  ~~送方指名送訊息，收方不指名~~

## Send, receive 指令

> 表達出synchronization mode

**法一：**
使用[Link capacity](Link%20capacity.md)
**法二:：**
使用Blocking/Non-Blocking之send recevie

- Blocking Send ~~送方要等回信~~
- nonBlocking Send ~~一直送，不用等回信~~
- Blocking Receive ~~等信送來再做~~
- nonBlocking Receive ~~不用等信~~
