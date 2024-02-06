---
date created: 2022-12-28 19:57
---

> 定義：若File 大小 = n Blocks，則OS只需在Disk中找到n 個free Blocks 但_不一定要連續_。此外，各Allocated Blocks 之間用Link 串連起來

例：
![150](../../資料結構/img/截圖%202022-11-02%20下午8.10.11.jpg)
File 2 大小 = 3 Blocks
則OS配置_9->12->14_號Blocks給他且在"physical" Directory 中紀錄下列配置資訊

| File name | Start Block No. | End Block No. |
| --------- | --------------- | ------------- |
| File 2    | 9               | 14            |

**分析**
與[Contiguous Allocation](Contiguous%20Allocation.md)相反
