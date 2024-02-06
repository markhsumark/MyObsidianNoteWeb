---
date created: 2022-12-31 15:31
date updated: 2023-01-31 16:18
---

## AVL Tree #⭐️⭐️⭐️⭐️⭐️

#balancedBST之一

> 緣由：BST在面對"Dynamic Data Set(資料插入、刪除等異動頻繁)時。BST有可能形成skewed情況，造成Insert/Delete/search x之time變成O(n)之worst case，故==需要有一種BST可以動態維持高度最小化==，使得上述運作在worst cas下任為O(logn)，此即AVL Tree的目的

> 定義：是一種**_高度平衡化的BST_**
> 滿足： ==任意節點的左右子樹差<= 1==
>
> 1. |HL - HR| <= 1, HL, HR是Root左右子數的高度
> 2. Root之左右子樹也是AVL Tree

**定義：**

- Node的平衡係數(Balance Factor) = Node左子樹高 - Node右子樹高度
- In AVL Tree，任何一個點的B.F值只有 -1, 0 , +1 , 3種

**AVL Tree之不平衡狀況**分成：LL, LR, RL, RR四種。判斷原則：

- Insert **新點**後，看哪一個==離**新點**最近的Node(往上找)==變成不平衡且**新點** _在此_ ==**不平衡點** _之"什麼子樹"方向分出_==

**AVL Tree不平衡之調整**(rotation)
兩大原則: ==依照BST的大小放就對了==

- **中間**鍵值往上拉，**小**放左，**大**放右（LL, LR, RL, RR連到的三個node）
- 孤兒之Node or子樹一BST結構，即可置入正確位置。

![200](../img/截圖%202022-10-13%20下午9.19.26.jpg)
![200](../img/截圖%202022-10-13%20下午9.19.38.jpg)

![300](../img/截圖%202022-10-14%20下午2.21.21.jpg)

### AVL Tree定理

（令Root level = 1）形成==高度h之AVL Tree，所需之最小Node數=F(h+2)-1==

Note:Node數≤ `2^h -1`=Full BST
Note:Node數≧`F(h+2)-1`

Space Complexity : `O(n)`
Insert Complexity : `O(logn)`

![](../../img/截圖%202023-01-31%20下午4.17.43.jpg)
![](../../img/截圖%202023-01-31%20下午4.27.45.jpg)
！！~~1/c在log裏面~~
```ad-note
title:數學歸納法證明最少Node數= F(h+2)-1
collapse:none
1. 當高度 = 0，empty。F(0+2)-1 = 0
3. 令高度 <= h-1時定理成立。
4. 當高度= h時，要最少Node數必定*發生在左右子樹高度差1*的情況。

不失一般性，令左子數高 = h-1，右h-2
F(h-1+2)-1 = F(h+1)-1
F(h-2+2)-1 = F(h)-1
整棵樹的最少Node樹 = (F(h+1)-1)+ (F(h)-1) +1
=>**F(h+2)-1**

```

```ad-example
title:形成高度5之AVL Tree所需最少節點數？(並畫Tree)。所需最多節點數？(並畫Tree)
F(h+2)-1 = 12
讓每個非leaf的Node 的左右子數高度差一即可
![200](../img/截圖%202022-10-14%20下午3.13.37.jpg)
```

```ad-example
title:AVL Tree Node數=200。求最小高度？最大高度？
2^h -1 = 200
h = ⎡log 200+1⎤ = 8

---

F(h+2)-1求出在高度h下最少Node數。
h=10時透過F(h+2)-1可得>143個Node
h=11時透過F(h+2)-1可得232
所以200個node最高只能建成h=10的Tree
```

```ad-example
title:令Nh代表形成高度H之AVL Tree的最少Node數。(1)write the recursive definition of Nh 。(2)Based on (1)求出N5=?
==Key:最少Node數必定*發生在左右子樹高度差1*的情況==
![](../../img/截圖%202022-12-31%20下午3.35.44.jpg)
N(h) = N(h-1) + N(h-2) + 1
---

~~類似費氏數列~~
ANS = 12
```
