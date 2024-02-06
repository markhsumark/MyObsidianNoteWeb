---
date created: 2022-09-24 16:02
date updated: 2022-12-27 20:07
---

# page Buffering 機制

> **現況（緣由）**：OS選完victim page且此page is modified，現行流程

1. 將victim page _write back_
2. 才能載入miss page
3. then, process才可恢復執行

=>process 可_恢復時間拖很久(I/O time 兩次_)，希望改善之。~~page fault影響太大~~

## [法一]

~~用事先空出來的frame作為暫時miss page存放的地方，錯開整理時間~~

> （只會找page table裡的）先用私房錢，等有時間再還。當下處理page fault只用一次I/O time

**將frame 分成**

- Resident frames => 分配給process
- Free frames pool =>OS keep ~~私房錢~~

**用途**
提供free frame~~(私房錢)~~，讓miss page先行載入

**使用流程**

1. OS選完victim page且為modified
2. OS先自 _Free frames pool_ 中先提供一 free frame，供miss page載入
3. 載入完，process先恢復執行
4. OS稍後再將 victim page 寫回Disk，然後歸還 free frame

## [法二]

~~不常用的做記號~~

OS會keep 一條 _Modification list_ ，記載著==[Modification Bit](Modification%20Bit.md)值= 1 之所有page No.
OS會_等Disk比較空間_的時候==，將此list 中_一些pages write back to Dick_, and clear thier m.bit為0，如此一來==可增加選出的victim pages是 unmodified之機率==

## [法三]

> 把free frame pool看作cache，要找東西之前==先看F.F.P(free frame pool)==

以**[法一]**為基礎 ~~差在此法會檢查free frame pool並直接用裡面的page~~
OS在針對 free frames pool中==每個 free frame _紀錄此頁匡裡頭放的是哪一個process之哪個page_==，因為這些_free frame pool中 free frame 內放的內容一定是最新的_。

**使用流程**

1. OS選完victim且modified
2. OS先到free frame pool中找有沒有miss pool存在
3. 若有，直接用。若沒有，**[法一]**後續流程
4. OS等Disk有空，將victim page寫回Disk，再歸還free frame
