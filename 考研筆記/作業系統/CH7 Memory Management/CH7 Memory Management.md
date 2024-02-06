---
date created: 2022-12-27 00:07
date updated: 2023-01-12 17:47
---

```ad-hint
memory和Disk之間的銜接方式
- Binding
- loading
- linking （執行時間才會需要載入）

memory 
- contiguous allocation management

問題
- 內/外碎

page management
- logical -> physical
- page table種類
- page table size太大問題

segment

```

# [Binding](Binding.md) #⭐️

# [Dynamic loading](Dynamic%20loading.md) #⭐️

# [Dynamic linking](Dynamic%20linking.md) #⭐️

# Contiguous Allocation Management #⭐️⭐

> 1. process 載入到memory中執行, **他必須佔用一塊“連續的”Memory space**
> 2. 此process佔用的space也叫Partition
> 3. 通常Partition size是變動的，也叫"variable partition"
> 4. Partition 的數目即是Processes數目，也就是Multiprogramming Degree
> 5. Processes多次的配置予釋放後，會有一些空間是free稱為**hole**

- [First Fit](First%20Fit.md)
- [Best-Fit](Best-Fit.md)
- Worst-Fit

上述這些Contiguius Allocation methods 均遭遇一個共通問題，即[External Fragmentation(外部碎裂)](External%20Fragmentation(外部碎裂).md)

# Fragmentation #⭐️⭐️⭐️⭐️⭐️

分為：

- [External Fragmentation(外部碎裂)](External%20Fragmentation(外部碎裂).md) #⭐️⭐️⭐️⭐️⭐️
- [Internal Fragmentation (內部碎裂)](Internal%20Fragmentation%20(內部碎裂).md) #⭐️⭐️⭐️⭐️⭐️

| 碎裂問題                                         | Contiguous Allocation | Page | Segment | Paged Segment |
| -------------------------------------------- | --------------------- | ---- | ------- | ------------- |
| [內部碎裂](Internal%20Fragmentation%20(內部碎裂).md) | 無                     | 有    | 無       | 有             |
| [外部碎裂](External%20Fragmentation(外部碎裂).md)    | 有                     | 無    | 有       | 無             |

## 解決External 碎裂

兩種方式

- [Compaction 技術](Compaction%20技術.md) ~~移動執行中的process使其聚集形成一個連續的hole~~
- [page](page.md) ~~等分切割記憶體，process依照需求拿幾塊用->(不容易高好吃完n*page_size容量)~~

| [Compaction 技術](Compaction%20技術.md)        | [page](page.md)                                                                                             |
| ------------------------------------------ | ----------------------------------------------------------------------------------------------------------- |
| 解決外部碎裂                                     | 解決外部碎裂（但有內碎）                                                                                                |
| 必須是[Dynamic Binding](Dynamic%20Binding.md) | 支持Memory sharing & memory Protection之實施。支持[Dynamic loading](Dynamic%20loading.md) linking& Virtual memory實施 |

# Page Memeory Management #⭐️⭐️⭐️⭐️⭐️

```ad-attention
title:硬體才是提升paging效能的關鍵技術
```

[page](page.md)

## Logical address轉physical address過程

> CPU產生的logical address為單一量，自動拆解成[P|d]
> 其中
> P: page No.;
> d: page offset;

> MMU依P查詢Page table取得此page所在的frame No:f
> Then, [f|d]即為physical address. =>f*{page size}+ d

## Page table implementation

### [法一]使用register 保存page table中每個entry 內容

**優點：**

- 速度快(不用Memory Access)

**缺點：**

- 不適用在大型的process;
- 增加context switch Time （if register較多。在C.S.要一起跟著換）。

### [法二]使用Memory 保存page table：

> 1. ==PTBR(Page  Table Base Register)==:紀錄_Page table 在memory 之起始位址。_
> 2. ==PTLR(Page Table Length Register)==:紀錄_page table size_
>
> `NOTE:In PCB只記這兩個register即可`

**優點：**

1. 適用於大型的process
2. C.S Time較省（than[法ㄧ]）

**缺點：**

- 額外多一次Memory Access

### [法三]使用TLB

(Translation-Lookaside-Buffer)或叫Associative registers

> ==保存page table 中經常被存取的page No.及其frame No.==
>
> - **MMU會依P先到TLB search，若TLB Hit直接取得 f ，若TLB miss ，則MMU必須到memory去查詢page table取得 f** 
> - 之後，也會更新TLB不上miss的page No. 及 frame No.
> - 若TLB entry are full 則可以選擇一些entry 替換（LRU policy)

![](../../img/截圖%202022-12-27%20上午11.01.56.jpg)

```ad-note
title:硬體
-   Some TLBs 允許某些entries to be wire down ，代表這些entries 不可以被移出TLB。一般而言，TLB entries for key kernel code are wired down
-   有些TLB會多儲存Address-space identifier(ASID)(紀錄Process ID) in each TLB entry. 就可以存放多個process的TLB內容
```

## 相關計算

```txt
page table entry 數量
= page table使用的空間/page table entry size 
= process使用的frame數`
```

```ad-example
title:[型一]：使用TLB之EMAT求算
```

```ad-example
title:[型二]：Logical address 與physical address length(Bit 數) 計算
![](../../img/截圖%202022-12-27%20上午11.04.57.jpg)
```

```ad-example
title:[型三]：page table size相關計算

page size= 8KB
process size =1MB
page table entry size = 4bytes
求此process之page table size?
---
需要`1MB/8KB = 2^7`個pages
所以有2^7個entry
page table size = `2^7 \* 4B`
```

```ad-example
title:[型四]：[page table size 太大之解法的延伸運算](#page%20table%20size%20太大解法)
```

```ad-example
title:其他考題
![](../../img/截圖%202022-12-28%20下午5.38.44.jpg)
![](../../img/截圖%202022-12-28%20下午5.39.03.jpg)
![](../../img/截圖%202022-12-28%20下午5.39.21.jpg)
```

## page table size 太大解法

| [Hierarchical paging](#[法一]Hierarchical%20paging) | [Hashing Page Table](#[法二]Hashing%20Page%20Table) | [Inverted Page Table](#[法三]Inverted%20Page%20Table) |
| ------------------------------------------------- | ------------------------------------------------- | --------------------------------------------------- |
| 多層page table                                      | page table 用hash table實作                          | 每個frame標記上時所屬於的process ID                           |
| 空間小、慢(mem. access)、EMAT長                          |                                                   | linear search PID耗時、不能mem. sharing                  |

### [法一]Hierarchical paging

~~page table分層 -> 載入table總量減少、慢~~

> 不要一次將整個page table 抓到memory 中，而是將page table切成幾個小的pieces\
> process執行時，載入部分的所需之page table內容，以有效降低所需的memory size\
> 例：2-level page table

第一層page table找第一層page table
第二層指到physical address

![](../../img/截圖%202022-12-27%20下午2.38.22.jpg)
**優點：**
縮減所需要之space
**缺點：**
Memory Access次數增加，EMAT更長

### [法二]Hashing Page Table

> 將page table 視為hash table，具有相同的hash address 之page no. 及 frame no.會包裝成一個record，置入entry 中之link list 
> `NOTE:及每個entry採用chain方式處理overflow`

將來MMU logical  address轉physical address過程如下

![](../../img/截圖%202022-12-27%20下午2.40.20.jpg)

### [法三]Inverted Page Table  #⭐️⭐️⭐️ 

```ad-question
title:What is Inverted page table
A global page table maintained by OS for all process
In inverted page table, the number of entries is equal to the number of frames in the main memory
```
```ad-question
title:How Inverted page table convert a logical address to a physical address?
search the page number and pid in inverted page table and get it's index. The index is the frame number in memory. 後續在加上offset及為physical address

壞處：太慢、無法共享
好處：避免page table size過大
```
~~記錄每個frame(頁匡)所屬的process~~

> 以==physical Memory 為紀錄對象==**(非以process為對象)** ==若有n個frames則此表有n個entries== （frame數量成為page table 的高度）
> 每個entry紀錄 <Process ID, Page No.> 表示頁框被某個process之某page佔用，或是free（空白）

- ==整個系統keep一份表格==

ex: **PA 的 page table a 的位址**

search page對應的p的index即是frame的physical address前半

![](../../img/截圖%202022-12-27%20下午2.43.01.jpg)

```ad-example
title:例題
![](../../img/截圖%202022-12-27%20下午2.46.01.jpg)
```

**優點**

- 整個系統只有保持這一個表格(不是一個process一個table) -> 解決page table size太大問題

缺點

- linear search 耗時
- ==喪失了memory sharing公用==：因為PID不同，在memory 中共佔2份空間=>無法共用

# Segment Memory Management

> - physical memory 視為一個連續的可用空間
> - logical memory視為一組segment 之集合, 且==各段大小不一定相同==
>
> 「segment 段」的觀點採取"logical" viewpoint
>
> **配置方式**
> 段與段可以是非連續性配置
> 但就單一段而言、必須是連續性配置

**Logical Address轉physical Address**

1. CPU產生出之Logical Address為兩個量［s|d]
2. MMU 根據s查分段表，曲得該段的limit and base
3. 先check d<limit?
4. 成立：physical address= base+d

![](../../img/截圖%202022-12-27%20下午3.01.07.jpg)

- 支援memory sharing 及 memory protection
- 支援[dynamic loading](Dynamic%20loading.md), linking and virtual memory

![](../../img/截圖%202022-12-27%20下午3.00.37.jpg)

**優點：**

- 沒有internal fragmentation

**缺點**

- ==有外碎==
- 需要有extra HW support(分段表、MMU
- EMAT更久（有check d<limit?)

# Paged Segment

> 動機：
> 想要保有segment 採用logical viewpoint 之好處但又要解外部碎裂
> 觀念：
> 段再分頁，phy. memory = a set frames
