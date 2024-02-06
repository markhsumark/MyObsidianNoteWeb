---
date created: 2022-09-14 13:53
date updated: 2023-01-12 19:26
---

```ad-hint
page table發生的事情
- size不夠-> VMemory
- page fault!!處理
- EMAT
- 速度？
```

# Ch8 Virtual Memory

## 主要目的及附帶好處 #⭐️

> 允許process size 在超過physical memory free space size 之下，仍能執行。

logical memory size 不會受到physical memory size 之限制

> 觀念：即是=="Partial" loading process部分內容, process 即可執行==(even 不載入也可執行）
>
> - 早期：[dynamic loading](../CH7%20Memory%20Management/Dynamic%20loading.md)（ＯＳ無額外支持）
> - 現代：OS提供VM特性
>
> 其他附帶好處
>
> 1. 若process只載入一部分即可執行
>
> ->==同時間內可載入的process數量變多==
> ->CPU utilization 相對高
> `NOTE:Thrash 情況除外`
> 2. less I/O Time(因為量少)
> 3. ==Memory utilization相對較高==
> 4. ==programmer無須煩惱 process size太大的問題，只需專心把程式寫正確==
> 5. ~~Copy-on-write技術~~

## Demand Paging 技術 #⭐️

~~需要有一個機制區分哪些pages不再memory中~~

> 定義：架構在前面的[Page Memory  Management](../CH7%20Memory%20Management/page.md) 基礎。差別：process執行之前，無須事先載入所有的Pages，而是載入部分所需（demand）之Pages即可執行
> 
> 若是資料結構具有locality，則Demand paging效果較好
> 
> ==NOTE:也可以不載入任何page即可執行，此為_pure demand paging_。
> 若事先載入猜測的pages叫做[prepaging](prepaging.md)==


==NOTE:[CH7] valid & invalid paged==

圖示：

![](../img/截圖%202022-09-14%20下午2.40.59.jpg)

## Page fault 之處理 #⭐️⭐️⭐️

> 兩次I/O time

Steps:

1. MMU 送出一個中段通知OS
2. OS收到中斷後，暫停目前process之執行且保存此process之status(eg. p.c. registers value...etc)
3. OS依此存取位址判斷是否是合法存取。
   若非法則終止此process。
   合法則判定是page fault引起
4. Then, OS去Memory中找尋可用頁匡，若沒有，則需執行，以空出一個free frame
5. Then, OS再到Disk確認lost page所在位置，啟動Disk I/O運作[Page Replacement](Page%20Replacement.md)載入lost page 到free frame。
6. Then, OS修改page table標示錯lost page的frame No.並將Invalid改為Valid值
7. OS恢復原本中斷前之process之執行

![400](../img/714FFDCB-0BEE-4E15-98A9-D80DCB2E49CB.jpeg)

==NOTE: p.245是more steps==

## EMAT計算 #⭐️⭐️⭐️⭐️

~~平均memory access處理時間~~
==單位是時間==

> = `(1-p){Memory Access Time} + P  {Page fault 處理時間}` 其中P : page fault ratio
> =`{memory access時間}*{memory access 頻率}+ {Page fault處理時間}*{Page fault 頻率}`

```ad-example
~~~
Memory access time: 100ns
page fault processing time: 5ms
~~~
---
(1)若page faultratio = 20%
求EMAT?
   Ans:(1-0.2)*100ns+0.2*5ms = 80ns + 1ms = 1000080ns
---
(2)若EMAT不超過10𝜇s 則page fault應< ?
   Ans:
   (1-p)*100ns+p*5ms < 10𝜇s
   100 - 100p + 5000000p < 10000
   499900p < 9900
   => p< 99/4999 ~= 1/500
```

> 小結：提及VM效能，即是要降低EMAT，而關鍵點：_要降低page fault ratio_

## 影響page fault ratio 因素

- Page Replacement法則之選擇
- Frame 數分配多寡之影響
- Page size影響
- program structures影響

## Working Set

 >概念：利用locality 來預測一段時間內所需的frame數量，藉此降低thrashing 的機率

```ad-question
title:解釋Working Set 是如何處理Thrashing 問題的？
利用Working set 確認process總共所需的frame數量，若此數字高於physical frames number，就降低multiprogramming degree。
```

## 加速page replacement的各種方法

### Page Replacement法則 #⭐️⭐️⭐️⭐️⭐️

[Page Replacement](Page%20Replacement.md)

==NOTE:在所有replacement法則中，沒有最差的==

1. **[FIFO](FIFO.md)**
2. **[OPT](OPT.md)**  ~~看向未來~~
3. **[LRU](LRU.md)**    ~~過去（包含pages外的）很久沒使用的~~
4. **LRU近似**
   1. [Additional Reference Bit](Additional%20Reference%20Bit.md) Usage
   2. [Second chance](Second%20chance.md)(or clock)  ~~依據值R.bit~~
   3. [Enhanced Second chance](Enhanced%20Second%20chance.md) ~~兩個依據值R.bit&M.bit~~
5. **Counting Algo..

> 定義：以page的_累計參考次數_作為選擇victim page的依據（值相同也是以FIFO為準）

1. LFU：過去參考次數最少為victim page ~~pages中過去使用**次數**最少的~~
2. MFU：過去參考次數最多為victim page  ~~pages中過去使用**次數**最多的的~~

分析：

- **page fault ratio相當高**
- 製做成本高，需硬體支持
- _**有[Belady Anomaly](Belady%20Anomaly.md)**_

### [Page Buffer機制](Page%20Buffer機制.md)

舉例
![450](../img/截圖%202022-09-24%20下午3.41.17.jpg)

## Modification(Dirty)Bit, Belady Anomaly, stack property #⭐️⭐️⭐️⭐️

[Modification Bit](Modification%20Bit.md)
[Belady Anomaly](Belady%20Anomaly.md)

## Frame數目分配多寡之影響 #⭐️⭐

- 一般而言，process分配的頁匡數增加->page fault ratio應下降
- OS再分配process 頁匡數時，需滿足 _最多&最少數目限制_(由HW決定，非OS)
  - 最多數目：phy. memory size
  - 最少數目：需能讓 _CPU機器指令_ 順利完成，週期中 _可能之最多memory access數_，否則無法完成。_**（需讓機器指令一次存取完整）**_
- 在滿足最少&最多數目_區間_才是_OS可以決定_的範圍

## Thrashing #⭐️⭐️⭐️⭐️⭐️

```ad-question
title:What is Thrashing?
collapse:none
process花在page fault 的時間遠大於正常處理時間，造成CPU利用率急速下降，I/O Disk異常忙碌。
原因：
process分配到的frame不夠而造成page fault 
OS分配page給此process後可能會造成另一個process page fault 不斷這樣惡性循環
```

> 定義：若某些_Process==分配到的頁匡數不足==_，則process經常page fault 且page replacement，若OS採用[Global replacement policy](Global%20replacement%20policy.md)，則可能會_誤選其他processes之page為victim page_.，造成其他processes page fault.，同理。
> =>大家搶成一團，都在page fault，都在等待pages I/O完成
> => ready queue空了，CPU utilization下降，sys.引入更多process。
> =>如此循環下去會呈現：
>
> - CPU utilization 急速下降
> - paging Disk 異常忙碌
> - page fault time 遠大於 正常執行時間
>
> 稱之Thrashing

![300](../img/截圖%202022-09-24%20下午4.55.27.jpg)

### Thrashing 解決/預防

**[法一]**
當Thrashing已發生=>降低Multiprogramming degree
**[法二]**
利用 _[page fault frequence control](page%20fault%20frequence%20control.md)_ 機制，來防止Thrashing ~~控制頁匡數~~
**[法三]**
利用 _[Working Set Model](Working%20Set%20Model.md)_ 技術預估processes在不同執行時期需要的頁匡
**[法四]**
- 增加main memory size
- 規定不能使用global 

```ad-question
下列cases，若增加Multiprogramming degree是否可以提高CPU利用度?what actions will you do?
CPU utilization/ paging Disk
A. 3%/90%
B. 87%/10%
C. 3%/10%
ANS:
A. 明顯在Thrashing。應該要降低degree
B. 幫助有限。不要動，幫助有限
C. 都很空閒，要增加M.Degree

```

```ad-example
title:p.296. 66
```

## Page size 之影響 #⭐️⭐️⭐️

若page size _越小_則

1. Page fault ratio: 增加
2. Page Table size: 變大
3. I/O次數: 增加
4. 內部碎裂: 輕微
5. I/O Transfer time: 較小
6. [locality](Locality%20Model.md): 較佳

> 1~~3缺點，4~~5優點
> _趨勢朝向“大”的page size_

```ad-danger
title:p.258
```

## program structure 影響 #⭐️⭐️⭐️

1. Program 中所使用之data structures 指令, algo.等，_應符合[locality model](Locality%20Model.md)則_有助於降低page fault對V.M is _Good_，反之則BAD
2. Program 中對於Array 元素之處理順序，最好符合Array 元素在memory中之存放順序，以降低page fault ratio

```ad-example
A:[1..128, 1..128]of int;
每個int 佔1 byte
page size = 128 bytes
A以Row-major存放元素
給予3個frames（且Code已置入第一個frame，其餘為空）採[FIFO](FIFO)/[LRU](LRU)，求page fault 次數
~~~C
(i)
for i= 1 to 128
	for j= 1 to 128 
		A[i, j]=0;
~~~
~~~C
(ii)
for j= 1 to 128
	for i= 1 to 128 
		A[i, j]=0;
~~~
**Ans:**
![300x200](../../img/截圖%202022-09-26%20下午10.32.13.jpg)

(i)每清一列一次page fault  => 128*1次
(ii)每清一行元素發生128次 page fault => 128*128次

```

## copy-on-write技術 #⭐️⭐️⭐️

主要是在探討3種fork():

### fork() without copy-on-write

~~直接複製~~

> 定義：當Parent process生出child process，OS會替child process _配置 New frames 給 child_
> (即 Parent, child 佔用不同空間)且OS也須 Copy parent 的內容給 child。

**缺點**：

1. 每生出child process，OS_及要配置 New Frames_ 給 child => ==_大幅佔用 memory_==
2. process _creation 速度慢_，因為需要Copy parent 內容給 child

### fork() with copy-on-write

~~先不複製，做記號，需要改動再複製~~

> 定義：Parent 建立 child process。 Initially, child _先共享 parent 之 memory space，不先配置child process New frames_ 。
> 直到parent or child process ==需更改重要內容，先進行完整的copy，再去修改。==

- 有可能write之pages需mark "copy-on-write" pages
- 不會modified pages(eg. read-only Code)不需 mark

優點

1. minimizing the need of Memory
2. speed up the process creation

### vfork()

> 定義：也是讓child 出生時==暫時共享==parent's frames，但是不提供copy-on-write
> 任一方該更改，另一方會受影響
>
> 適用於child出生後 ==馬上execlp()==

p.261

## TLB Reach #⭐️⭐️

```ad-note
title:量度TLB的兩個metrix
1. TLB Hit ratio
2. TLB Reach
```

> 定義：經由TLB所能存取到的memory size，即
> `TLB Reach = TLB entry數*Page size`
> 希望TLB Reach 越大越好
>
> 理想中，process的working set存放在TLB中。如果不是，那可能要花很多精力處理page fault。

增大TLB的方法：

1. 增加TLB entry 數目
   - 優點:增大TLB Reach/Hit-ratio
   - 缺點:
     1. 成本高
     2. 也可能無法涵蓋Process的working set
2. 加大Page size:
   - 優點：
     1. 加大TLB Reach
     2. page fault ration & page table size 下降
   - 缺點：
     1. 內部碎裂嚴重
        > [!NOTE] 解法
        > 提供多種page size=> 在TLB中_增加一個page size欄位_。
        > 此外，很多機器是由OS來管理TLB（以前是HW管理）

p.263
