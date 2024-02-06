---
date created: 2022-10-29 18:21
---

### Articulation point

（關節點）

> 定義：_在Connected_ 無向圖中，若將某點及其連接邊刪除，_會造成剩下的子圖變成unconnected_，則此頂點稱之

![300](../img/截圖%202022-10-29%20下午5.33.53.jpg)

**計算**
如何找出Articulation point
Ans:

1. 先用[DFS](../../演算法/CH4%20Graph%20Algorithms/DFS.md)求出個頂點的dfn([DFS](../../演算法/CH4%20Graph%20Algorithms/DFS.md) Number)(從任何點開始做皆可)
2. 畫出[DFS](../../演算法/CH4%20Graph%20Algorithms/DFS.md) [spanning Tree](spanning%20Tree.md) 且標出BACK edge
3. 求出個頂點的 _Low_ 值
   ![300](../img/截圖%202022-10-29%20下午6.10.12.jpg)
   ![200](../img/截圖%202022-10-29%20下午6.09.32.jpg)
   ```txt
   low(x) = min{dfn(x), dfn(y)}, y是x的後代，最多經過一條Back edge所到的頂點
   ```
4. 判斷規則：
   - 針對spanning tree之root：若root有>= 2個子點，則root是Articulation point
   - 針對非root之頂點x：存在一個x的子點y，若low(y) >= dfn(x)，則x是articulation point
