---
date created: 2022-11-02 18:27
date updated: 2023-01-30 16:37
---

```ad-question
title:為什麼OS需要block儲存在Disk的相關資訊
Ans:需要知道File在Disk裡是怎麼儲存，藉以應用最適合的disk scheduling

原問題：
`Give the reasons why the operating system might require accurate information on how blocks are stored on a disk. How could the operating system improve file system performance with this knowledge? Briefly justify your answers.`
```

# Disk system 組成 #⭐️

- 由多片Disks組成
- 每片Disk通常雙面可存Data
- 每面劃分成多個同心圓軌道，叫做 _Track_(磁軌)
- 每條Track在畫分為多個 _sector_(磁區)
- _sector_ 是 Dick controller 可 read, write, 控制之基本單位
- 不同面之相同 Track No 之集合稱為 _cylinder_(磁柱)

# Disk Access Time組成 #⭐️⭐️⭐️

> 由三個部分組成

1. seek Time：將Head移動到存取的Track上方所花之時間
2. Latency Time：將域存取的sector「轉」到讀寫頭下方所花的時間
3. Transfer Time：Data在Disk和Memory之間的傳輸時間

`Disk Access Time = seek time + Latency time + Transfer time`

```txt
Avg Disk Accsee Time (假設讀取XBlock)
= {avg seek time}+{avg Latency time=轉一圈的時間/2}+{傳輸XBlock的時間}`
```

> [!NOTE] 通常以seek Time為主

==rpm(rotation per minute)==

```ad-example
title:Disk 轉速7200 rpm，球avg. Latency Time
-> 一秒120圈
-> 轉一圈花1/120秒
故平均 = 1/120/2 (s)
```

```ad-example
title:求Transfer rate（每秒可以傳輸多少Data）
Disk 有10 片disks
雙面可存
每面有2048條track
每條track有4096個sector
每個secto可存16Kb
轉速6000rpm
求Transfer rate（每秒可以傳輸多少Data）
---
Ans:
6000rpm = 100圈/s
轉一圈 = 讀取一整個磁柱
而一條cylinder容量 = 20條Tracks = `20*4096*16Kb`

`100*20*4096*16(Kb/s)`
`= 128000MB/sec`
```

```ad-example
title:承上題
假設Disk平均seek time = 10ms
今天要read a File , File size = 4MB
需花?ms
---
Ans:
Disk Access Time 
= seek time(Avg.) + latency time(Avg.) + Transfer time
= `10ms + 1/2 *1/100 + 4MB/128000(MB/s)`

```

# Disk Free space Management方法

基礎：Disk 之配置、存取單位是 **Block**

|       | [Bit vector](Bit%20vector.md) | [Link list](Link%20list.md) | [Grouping](Grouping.md)                                   | [Counting](Counting.md)                             |
| ----- | ----------------------------- | --------------------------- | --------------------------------------------------------- | --------------------------------------------------- |
| 簡述    | 紀錄每一個block是否free              | free block link 起來          | 每個free block存很多free block No.的[Link list](Link%20list.md) | 每個free block不但存了下一個free block，還存從自己開始的連續free block數 |
| 分析與比較 | 適用small disk、適合找連續的Block      | 適合大Disk、不適合找連續Block、加入刪除方便  | 迅速找到下量free Block                                          | 適用於"連續配置"                                           |

Grouping, Counting 都是link list的變形

![400](../../資料結構/img/截圖%202022-11-02%20下午7.52.40.jpg)

# File Allocation Methods #⭐️⭐️⭐️⭐️⭐️

```ad-question
title:為什麼需要明確的file資訊
Ans:
需要知道file的儲存方式和address，並利用此資訊實施最好的disk algorithm
```

```ad-question
title:哪一個File Allocation Method在operation多為"append", "truncate"最適合？
Indexed Allocation
```

~~Contiguous & linked 特性相反~~

| -                                                   | [Contiguous Allocation](Contiguous%20Allocation) | [Linked Allocation](Linked%20Allocation.md) | [Index Allocation](Index%20Allocation.md) |
| --------------------------------------------------- | ------------------------------------------------ | ------------------------------------------- | ----------------------------------------- |
| 簡述                                                  | ~~A到B是你的空間喔~~                                    | ~~A跳到D跳到...到B都是你的空間~~                       | ~~用額外空間紀錄每一個Block的指標~~                    |
| 外部碎裂                                                | 有 (Repack 解決)                                    | 無                                           | 無                                         |
| 可靠度                                                 | ==最好==                                           | 差                                           | 差                                         |
| seek Time                                           | ==最快==                                           | 長                                           |                                           |
| 擴充                                                  | 不便                                               | 容易                                          | 容易（且不需事先宣告）                               |
| [Random(Direct) Access](Random(Direct)%20Access.md) | 可支援                                              | 無法支援（不方便                                    | 可支援                                       |
| 循序存取速度                                              | 快（連續Blocks）                                      | 慢                                           |                                           |
| 佔用空間                                                | 最小                                               | 第二小（需要pointer）                              | 最大（需要index block space）                   |

- [FAT](FAT) ~~把指標存在一起的linked allocation（追蹤只要讀pointer不用整個block）~~
- UNIX的[I-Node](I-Node.md)

# [Disk scheduling Algorithm](Disk%20scheduling%20Algorithm.md) #⭐️⭐️⭐️⭐️⭐️

# 其他名詞解釋

## formatting(格式化) #⭐️

- [physical formatting(low-level formatting)](physical%20formatting(low-level%20formatting).md)
- [logical formatting(high-level formatting)](logical%20formatting(high-level%20formatting).md)

## Raw-I/O

~~如字面上的意思~~

> 將磁碟當作「大型的陣列」來用，沒有任何File sys支援服務

優點：快
缺點：不方便使用

## Bootstrap loader #⭐️⭐️⭐️

> 定義：此loader只有一個目的
>
> 1. 開機時，用來將object code從Disk 載入到RAM

**[早期]：**
Bootstrap loader存在ROM裏面，開機時首先執行載入OS。
缺點

1. Bootstrap loader不容易修改（ROM是燒進去的）
2. ROM大小有限->Bootstrap loader無法過大

**[現代]：**
~~ROM裡面存Bootstrap的位址，Bootstrap存在Disk~~
Bootstrap loader（or Bootstrap records)存在ROM裏面，開機時透過Bootstrap loader找出「在磁碟內完整的Bootstrap loader」，抓到RAM，再透過完整的Bootstrap loader載入OS。
此外，Bootstrap loader放在Disk中「固定」的Blocks中，稱為_Boot Block_ ;擁有_Boot Block_的Disk叫做_Boot Disk_ or _system Disk_

## BAD sectors 處理方法

為何會壞？

- 工廠生產過程就壞了
- 使用一段時間才壞

處理方法

1. Mark BAD sectors,以後不使用（IDE disk controller採用）
2. 使用spare sectors來代替（SCSI disk controller採用）
   ```
   spare sectors：low-formatting就以配置、OS看不到、只有SCSI disk controller可用
   ```

缺點：這樣轉向可能會破壞掉原本 Disk scheduling 的效能
（解法：spare sector分散/安插在track上，再利用平移讓BAD sector旁邊是空的）

## SWAP space Management #⭐️

Disk除了一般儲存Files Data外，也有負責暫存SWAP out 的process（沒有kernel的） image or pages，尤其是[CH8 Virtual Memory](../CH8%20Virtual%20Memory/CH8%20Virtual%20Memory.md)機制

**使用此技術會:**

- ==降低系統performance==
- ==提升Virtual memory size==

SWAP space

- 也_可以單獨利用其他Disks來保_存，不跟kernel儲存的Disk混用
- 通常是_預留空間_，space size宜大不宜小，雖有space浪費，但至少安全

**Management方法**

1. 使用File system以File system以File 形式存放SWAP out之process image or pages
   優點：
   - 容易製作
   缺點：
   - ==效能不佳==
   - 外部碎裂問題（通常用[Contiguous Allocation](Contiguous%20Allocation.md))
2. 使用獨立的Partition 存放。Raw-I/O
   優點：效能佳
   缺點：萬一partition size不夠大，必須重新re-partition

## Disk #⭐️⭐

### Access Performance

提升技術：[Data striping](Data%20striping.md)

### Reliablility

1. [Mirror](Mirror.md)
2. [parity-check](parity-check.md)

## RAID 介紹 #⭐️⭐️⭐️

（Redundant Array of Independent Disks)

### Redundant

> 用多個小的Disk替代一個大的Disk
> 目的:提升disk 的throughput、reliability

| RAID-0                                   | RAID-1              | RAID-2                | RAID-3                                               | RAID-4                                                 | RAID-5                   | RAID-6       | RAID-01, RAID-10                               |
| ---------------------------------------- | ------------------- | --------------------- | ---------------------------------------------------- | ------------------------------------------------------ | ------------------------ | ------------ | ---------------------------------------------- |
| Block-level striping&No reliability tech | [Mirror](Mirror.md) | error-checking Code技術 | Bit-level striping & [parity-check](parity-check.md) | Block-level striping & [parity-check](parity-check.md) | parity blocks分散存放的RAID-4 | Reed-Solomon | [Mirror](Mirror.md) & Block level striping(組合) |
| `N`個Disk                                 | `2N`                | `2N+1`                | `N+1`                                                | `N+1`                                                  | `N`                      |              | `2N`                                           |
|                     non-redundant striping                     |                     | 無實際產品                 |                                                      |                                                        |                          | 無實際產品、成本太高   |                                                |

1. RAID-0
   > 即是Block-level striping 且==沒有任何reliability提升技術==，如[mirror](Mirror.md) or parity-check
   > 適用於_高效能存取_要求且_可靠度不甚重要_之應用場合

2. RAID-1
   > 即是==[mirror](Mirror.md) only==
   > 缺點同[mirror](Mirror.md)

3. RAID-2（無實際產品）
   > 採用memory 之 ECC(error-checking Code)技術，Disks數需`2N-1`
   >
   > - 成本降低有限
   > - 可靠度根RAID-3一樣但成本高於RAID-3

4. RAID-3
   > 採用_Bit-Level striping_ 及 _parity-check_技術
   >
   > - `N+1`部Disks

5. RAID-4
   > 採_Block-Level striping_ 及 _parity-check_技術
   >
   > - `N+1`部Disks

6. RAID-5
   > 採用_Block-Level striping_及 _parity-check_技術，但差別在於==parity blocks是分散於Disks中==，並非集中存於單一Disk中
   >
   > - 目的：避免單一Disk過度使用
   > - `N`部Disks（每個disk要額外容納parity的資訊）~~（也就是只允許一步Disk出錯)~~

7. RAID-6（無實際產品）
   > 採用Reed-Solomon技術，可允許兩部Disks同時出錯。但是成本太高。

8. RAID-0 & RAID-1組合

   > _高效能存取_與_高可靠度_皆要求之場合

   分為:

   1. RAID 0+1:先striping 再整體[mirror](Mirror.md)
      ![](../img/截圖%202022-12-14%20下午6.27.40.jpg)
   2. RAID1+0:先個別[mirror](Mirror.md) 再交錯(striping)
      ![](../img/截圖%202022-12-14%20下午6.27.54.jpg)

## RAM Disk

> 定義：將RAM切割一塊space作為一個logical Disk使用

優點

- 速度極快

缺點：

- 容量小
- power-off後，data不見。
