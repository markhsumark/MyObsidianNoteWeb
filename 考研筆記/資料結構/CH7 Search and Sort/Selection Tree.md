## Selection Tree

> 目的：加速k-way merge 之過程(k>2)
> 如何合併k個Runs?

### Winner Tree

**Time 分析**

1. 建立Winner Tree![300](../img/截圖%202022-10-24%20下午5.11.04.jpg)
   1. 將k個Run中最小Data copy as a _leaf_ `-> O(n)time`
   2. 歷經k-1次的比較決定出Root `->O(k)`
2. 輸出Root的資料到New Run，並從其所屬的run補上資料(到tree裏)
3. 重新排Tree。經過`⎡log₂k⎤`次比較決定出下一個Root
   ```txt
   比較次數= selection tree 高度-1，若有k個Leaves。
   高度 = ⎡log₂k⎤+1
   比較次數 = 高度-1 = ⎡log₂k⎤
   ```
4. 依此，共要做`n-2`回合挑Root之動作

_**-> O(n logk)**_

```ad-quote
title:比傳統的O(nk)快
```

### Loser Tree

同上

1. 建立Loser Tree![300](../img/截圖%202022-10-24%20下午5.31.22.jpg)（圖中winner是2）
   1. 將k個Run中最小Data copy as a _leaf_ `-> O(n)time`
   2. 歷經k-1次的比較(比贏家、填輸家）決定出Root `->O(k)`
2. 輸出_Winner_的資料到New Run，並從其所屬的run補上資料(到tree裏)
3. 重新排Tree。![300](../img/截圖%202022-10-24%20下午5.35.56.jpg)經過`⎡log₂k⎤`次比較決定出下一個Root&Winner

**Time complexity:** 同winner tree O(n logk)

### 比較
>**Loser is BETTER**
>比較的過程較為輕鬆（參與比較的Node數較少）


