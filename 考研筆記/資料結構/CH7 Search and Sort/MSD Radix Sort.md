---
date created: 2022-10-25 18:03
---

#⭐️

steps:

1. 將n個Data一最高位數進行_分派_到對應的Bucket中
2. 每個Bucket 自行排序
3. _合併_

```ad-quote
title:與[LSD](LSD%20Radix%20Sort.md)最大不同在於MSD的分派＆合併動作*只做1次*而已
```

每個Bucket內的data數目 = n/r
大家都一樣的data數目->可視為常數 c
所以每個Bucket各自排序之時間 = `O(c²) or O(clogc) -> O(1)`

_**r個 buckets sort time = r \* O(1) = O(r)**_

---

## Algo 版Bucket Sort
(就是MSD Radix Sort)

```ad-note
title:基底十進制。給78, 17, 39, 26, 72, 94, 21, 12, 23, 68實施
collapse: none

Ans: 
最大值位數2位，所以個Data先除以10² = r² （或是用mod取十位數）
得：
0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68
依照小數點後第一位數進行分派到Bucket去，每個Bucket各自實施[Insertion sort](Insertion%20sort.md)
![250](../img/截圖%202022-10-25%20下午6.19.38.jpg)
```