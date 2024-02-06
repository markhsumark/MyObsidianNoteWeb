---
date created: 2022-12-27 19:34
date updated: 2022-12-28 16:59
---

# LRU

~~過去（包含pages外的）很久沒使用的~~~~

> 定義：選擇最近（過去）不常使用之page 為victim page，
> 即是"reverse OPT "
> 即"The last reference Time"最小的page 即為LRU page

#### 分析

- Page fault ratio 可接受
- ==沒有[Belady Anomaly](Belady%20Anomaly.md)==
- _LRU的製作cost 很高_（==需大量HW支援 for recording==)

### LRU的製作方法

1. 使用Counter(作logical timer)
   每發生memory access
   - counter++
   - 且copy Counter值到該存取page 的"the last ref time"欄位中
   - OS要select victim 時，則"the last ref time"的page為LRU page
2. Stack 法
   - ==最近一次被存取的置於stack頂部==
   - stack bottom即為LRU page
   - Frame 數目即為stack size
   圖示
   ![[../img/image 2.jpg]]

![[../img/image.jpg]]
