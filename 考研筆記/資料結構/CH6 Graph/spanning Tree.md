spanning Tree

#⭐️
~~用某種搜尋法(BFS, DFS)建出來的Tree~~

> 給一個Connected, 無向圖G= (V, E)，令S=(V, T)為G的其中一個spanning Tree，則S滿足下列性質：
>
> 1. `E = T + B`：T為拜訪經過的edges，B為未經過的edges
> 2. 自B中任取一邊加入S中，必定會形成一個unique cycle
> 3. 在S中，任何頂點之間存在一條unique "simple path"

```ad-quote
title:若G is unconnected則無spanning tree
```