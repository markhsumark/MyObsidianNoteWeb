Binomial Tree, Binomial Heap #⭐️⭐️⭐️

### [Binomial Tree](Binomial%20Tree.md)
### [Binomial Heap](Binomial%20Heap.md)

#### Data structure表示方式

![400](../img/截圖%202022-10-19%20下午2.22.40.jpg)

#### Merge  two B.Heap H1 & H2

**Lazy merge**

> 作法：Root間雙向鏈結串接即可，min重設![200](../img/截圖%202022-10-19%20下午2.25.38.jpg)

**“勤勞”合併**
Time:O(log n)

steps:

1. 具有相同高度的Binomial Tree要合併
2. repeat直到沒有相同高度的Tree

![400](../img/截圖%202022-10-19%20下午2.37.26.jpg)
因為最多log(n+1)棵要合，兩棵Tree合併O(1)
=> O(log(n+1))

**Delete-min in Binomial Heap**

steps:

1. 找出Roots為最小值的Tree為T，其他Tree集合稱為Binomial Heap: (H1)
2. 刪T之Root，得到T之子樹集合，另為H2
3. Merge(H1, H2) (勤勞合併)

![200](../img/截圖%202022-10-19%20下午2.44.39.jpg)
Time: O(log n)

**Insert x into Binomial Heap H1**
steps:

1. x自己成為一個B.Heap H2
2. Merge(H1, H2)
   1. Lazy [DS], [Algo]
   2. 勤勞 [Weiss]  （分擔成本=O(1)）

```ad-example
title:給1,2,3,4,5,6,7建立Binomial Heap(勤勞合併)
![400](../img/截圖%202022-10-19%20下午2.50.08.jpg)

```

大部分的情況都是O(1)
少部分的情況是O(log n):~~n=2^k -1(也就是log(n+1)棵樹)變成n = 2^k(一棵樹)~~
_分攤成本-> O(1)_

| 運作             | Time                  |
| -------------- | --------------------- |
| merge two heap | lazy:O(n)/ 勤勞:O(logn) |
| Del-min        | O(log n)              |
| Find-min       | O(1)/O(log n)         |
| Insert x       | O(1)                  |
