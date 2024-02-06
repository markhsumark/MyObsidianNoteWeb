---
date created: 2022-09-19 22:06
date updated: 2022-09-19 22:06
---

# cut-and-paste

以求shortest path 問題為例。

```ad-info
title: shortest path

若具有cut-and-paste性質，設P為shortest path，則P中的所有從a->b點的shortest subpath。

*矛盾證明*
若p為一條shortest path
若存在一條subpath p1(a -> b, 不為shortestpath)
令p2為一條a->b的shortest path，則p2 < p1
令P'為換成經過p2的路徑，p' < p
發現更短的路徑
=>矛盾
```
