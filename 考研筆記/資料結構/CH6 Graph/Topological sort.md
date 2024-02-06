---
date created: 2022-10-29 14:27
date updated: 2022-10-29 14:35
---

> 給予一個*不具[cycle](cycle.md)*的AOV Network, 則至少有>= 1組頂點拜訪順序滿足：“若i有path到 j ，則在此排序中, i必定出現在j之前“，此種順序稱之

```ad-quote
title: 有cycle則無Topological sort
```

**求Topological sort[DS]**

1. 找出In-Degree = 0之頂點 i
2. 輸出 i，且假設有*i -> j，則j之In-Degree--*
3. repeat 1, 2直到*所有點均輸出* or *沒有In-Degree = 0*的點
4. 若非所有點皆輸出，則無Topological sort


**[Topological Sort[Algo]](../../演算法/CH4%20Graph%20Algorithms/Topological%20Sort.md)**



