Leftist Heap

> 定義：是一顆[Leftist Tree](#Leftist%20Tree)且min. Tree。

**關鍵基礎運作**
**Merge two Leftist Heap H1 & H2**
steps:~~root較小的Heap就保留其左子樹到New Heap~~

1. 比較H1, H2之roots找出最小值，不失一般性假設H1's root較小
2. H1's root當作new root，且H1's root(較小的root的左子樹保留)左子樹保留成New root 之左子樹
3. （遞迴）**Merge** H1's Root之右樹及H2成為New Root 之右子樹。上述repeat成為一顆min. Tree
4. 檢查每一個點的shortest是否符合[Leftist Tree](#Leftist%20Tree)?若有違反，則swap its左右子樹。

```ad-tip
title:root比大小，小的root的左子樹放到新樹的右側，repeat。最後檢查shortest&swap
```

```ad-example
![600](../img/截圖%202022-10-17%20下午6.46.57.jpg)
```

**Delete-min in Leftist Heap**
steps:

1. 將root刪除得到兩顆子樹(H1, H2)
2. **Merge(H1, H2)**

**Insert x**
steps:

1. x自己成為一個Leftist Heap:H2
2. Merge(H1, H2)