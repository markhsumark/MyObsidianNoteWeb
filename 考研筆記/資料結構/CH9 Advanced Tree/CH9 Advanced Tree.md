---
date created: 2022-10-12 15:36
date updated: 2022-12-31 15:27
---

# CH9 Advanced Tree

## Double-ended priority Queue

|            | Min-Max Heap, Deap, SMMH |
| ---------- | ------------------------ |
| Insert x   | O(logn)                  |
| Delete-min | O(logn)                  |
| Delete-Max | O(logn)                  |

### [Min-Max Heap](Min-Max%20Heap.md) 
~~min, max level交錯的Tree~~

### [Deap(Double-ended Heap)](Deap(Double-ended%20Heap).md)
~~左min右max，要跟對面比大小~~

### [SMMH(Symmetric Min-Max Heap)](SMMH(Symmetric%20Min-Max%20Heap).md) 
~~x會在祖父的左子(min)右子(max)的範圍內 ~~

## Extended Binary Tree #⭐️⭐️

[Greedy Algorithm](../../演算法/CH3%20Dynamic%20Programming/Greedy%20Algorithm.md)

> 定義：n個nodes之B.T若以link list 表示，則會有 n+1 條Nil links。_在這些Nil links 以一個特殊節點表示（☐），叫External nodes_，_其餘Nodes叫Internal nodes_，此種B.T稱之。
>
> ```ad-note
> title:外部結點數 = Nil link數 = n+1 = 比內部節點數多一
> ```
>
> ```ad-warning
> title:另外，考試或其他版本定義不同於Horowitz
> ```
>
> **I**: Internal path Length(到所有_內_部Node的路徑長_總和_)
> **E**: External path Length(到所有_外_部Node的路徑長_總和_)
> ![250](../img/截圖%202022-10-13%20下午6.35.09.jpg)
> **[WEPL](Weighted%20External%20path%20Length.md)**: Weighted External path Length
> **[min.WEPL](min.WEPL.md)**：建立一顆樹，具有最小的WEPL

## 定理E = I+2N #⭐️⭐️

```ad-note
title:E與I成正比
```

```ad-note
title:數高越小E, I值越小（反之越大）
```

### pf：數學歸納法對內部Node數歸納

1. 當Node數= 0時，此為empty，符合E = I+2N= 0+2*0 = 0。初值成立
2. 令Node數<= n-1時此定理成立
3. 若Node數=n時，令Root左子樹有(右子樹同理)

   - nL個內部節點
   - IL為其Internal path length
   - EL為其External path length

   所以總共的==I = IL + IR _+ nL + nR_==
   所以總共的==E = EL + ER _+ (nL+1) + (nR+1)_==

   因為nL, nR <= (n-1)，依2假設EL = IL+2_nL, ER = IR+2_nR
   E = _IL+2_nL + IR+2_nR_ + (nL+1) + (nR+1)
   E = (IL+IR+nL+nR)+2(nL+nR+1)
   E = I + 2N

   數規法得證

## [Huffman Algorithm](Huffman%20Algorithm.md)

### 應用問題

```ad-example
title:n個Runs之最佳合併方式 #ch7
```

```ad-example
title:n個messages之編碼/解碼之*平均編碼位元長度*最小（or平均解碼時間）的Encoding 方式
collapse:none
**例1：**
有39個messages，其中只有6種不同的messages: m1~m6，且出現頻率分別是：
m1 = 2/39, m2 = 3/39, m3 = 5/39, m4 = 7/39, m5 = 9/39, m6 = 13/39
今希望平均Encoding Bit Length 最小。則：
1. 畫出Encoding/Decoding Tree
2. 各message之編碼內容
3. Avg. Encoding Bit length = ?
4. 這39個messages之total Bit 數 ?

**ANS:**
messages=>外部結點
頻率=>加權值
1. 利用Huffman建立Tree...
	![400](../img/截圖%202022-10-13%20下午8.00.50.jpg)
2. m1 = 1010, m2 = 1011, m3 = 100, m4 = 00, m5 = 01, m6 = 11
   ==Note:編碼內容以自己的Tree為準==
3. *要考慮機率*
   (4\*2 + 4\*3+3\*5+2\*7+2\*9+2\*13)/39 = 93/39
4. 93
--- 
**例2:**
有一字串ABBBAACCDEFGFEAC
有A~G不同字母
求最小Encoding Bits length?

**ANS:**
求出[Huffman Algorithm](Huffman%20Algorithm.md) Tree 的[WEPL](Weighted%20External%20path%20Length.md)即為解。
43 Bits
```

**Huffman code是optimal _Prefix Code_**

## [AVL Tree](AVL%20Tree.md) #⭐️⭐️⭐️⭐️⭐️

## [m-way search Tree](m-way%20search%20Tree.md) #⭐️⭐️⭐️⭐️⭐️

## [B-Tree with minimum degree t](B-Tree%20with%20minimum%20degree%20t.md)#⭐️⭐️⭐️ 

## [Binary Tree of order m](Binary%20Tree%20of%20order%20m.md) #⭐️⭐️⭐️⭐️⭐️

## [Binary+ Tree of order m](Binary+%20Tree%20of%20order%20m.md) #⭐️⭐️⭐️⭐️⭐️

## [Red-Black Tree](Red-Black%20Tree.md) #⭐️⭐️⭐️⭐️⭐️

## [OBST(optimal BST)](OBST(optimal%20BST).md) #⭐️⭐️⭐️⭐️⭐️

## [splay Tree](splay%20Tree.md) #⭐️

## Leftist Tree, Leftist Heap

### [Leftist Tree](Leftist%20Tree.md) #⭐️⭐️⭐️
~~左[shortest](shortest.md)大於等於右[shortest](shortest.md)~~

### [Leftist Heap](Leftist%20Heap.md) #⭐️⭐️⭐️

~~左斜排（root 比較小的）一排一排移過去~~

## [Binomial Tree, Binomial Heap](Binomial%20Tree,%20Binomial%20Heap.md) #⭐️⭐️⭐️

## [Fibonacci Heap](Fibonacci%20Heap.md)
