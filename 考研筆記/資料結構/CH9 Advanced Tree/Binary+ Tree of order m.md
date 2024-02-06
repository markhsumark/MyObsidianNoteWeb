Binary+ Tree of order m #⭐️⭐️⭐️⭐️⭐️

> 定義：是B Tree之變種，主要支持 _ISAM(Index Sequential Access Method)_ 方法，常用於DBMS之內層製作
>
> 分為兩大layer:
>
> 1. **Index** Layer(索引)：採B Tree結構
> 2. **Data** Block：以_link list_ 串連，_所有Data_均放在_Data Blocks_(不一定要遵守B Tree數量)
>
> ![400](../img/截圖%202022-10-14%20下午8.19.32.jpg)

**Insert x**
==!!不能用B Tree的想法，不會有DATA往上移，只有往上Copy==

1. search 正確Node並放入x
2. 兩狀況：
   1. **是Leaf（在Data區域）**。檢查overflow==類似B Tree of order m，只是不能實際上移==
      1. 有overflow：中間COPY往上放，作為索引。<⎡m/2⎤的為新的左Node，>=⎡m/2⎤的為新的右Node，且針對父節點goto step2.(往上檢查，這部分就是存粹B Tree)
      2. 沒overflow：結束
3. **不是Leaf**：同[B Tree of order m](CH9%20Advanced%20Tree.md##Binary%20Tree%20of%20order%20m)

![](../img/截圖%202022-10-14%20下午8.39.08.jpg)
**Delete x** ~~索引要一起刪~~

![](../img/截圖%202022-10-14%20下午8.47.12.jpg)

![](../img/截圖%202022-10-14%20下午8.47.30.jpg)

```ad-attention
title:在Data Layer層的時候要注意不要做出奇怪的動作，該加的要留下，該刪的要刪掉。
```
