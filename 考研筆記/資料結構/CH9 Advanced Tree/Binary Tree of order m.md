## Binary Tree of order m #⭐️⭐️⭐️⭐️⭐️

> 定義：是一顆_Balanced m-way search Tree_，主要用於[External search/sort](../CH9%20Advanced%20Tree/external%20search%20or%20sort.md)
> 若不為空，則滿足
>
> 1. Root至少有>=2個子點，即==_2<= Root's Degree <= m_==
> 2. 扣除Root即Failure Node之外，其餘Node's Degree 介於⎡m/2⎤與m之間。即`⎡m/2⎤<= Node's Degree <= m`
> 3. 所有的failure nodes 皆位於同一level ==此即為"balanced" 之意==

![400](../img/截圖%202022-10-14%20下午4.30.33.jpg)
![400](../img/截圖%202022-10-14%20下午4.35.48.jpg)

```ad-example
title:計算高度為h的B-tree of order m，求(1)最多Node數(2)最多Key數(3)最少Node數(4)最少key數

m^0+m^2+...= (m^h-1)/(m-1)

---

m^h -1

---

![250](../img/截圖%202022-10-14%20下午4.40.18.jpg)

---

= 1 + {最少node數(不包含Root)}\*(⎡m/2⎤-1)
= 2\*⎡m/2⎤^(h-1) -1
```

```ad-question
title: B tree of order 3 with n個 Data/key，求(1)最小高度(2)最大高度
```

**Insert x**

1. search for x, 找出適當置入Node並_將x置入_ ~~置入後再做檢查~~
2. check if Node overflow
   1. 沒有overflow，放入，結束～
   2. 有overflow，需要做"_split_"處理，且針對父節點goto step2.(往上檢查)

> split處理：把中間(⎡m/2⎤)的key拉到父親，左半和右半各自成Node

```ad-example
title:給予2,3,5,7,1,8,4,6,9，建立2-3Tree
```

**Delete x**

1. search for x, 找出位於哪個Node
2. 分為兩大情況
   1. **x位於Leaf**：
      1. 刪x
      2. check Node是否_underflow（key數<⎡m/2⎤-1）_ ~~是否破產~~
         1. 沒有underflow（沒破產），結束～
         2. 有underflow，先看能否用"_Rotation_"(跟兄弟借錢)處理 ->結束。若不可(兄弟可能也沒錢)，則"_conbine_"，然後回到ii._檢查父點_。若一直到root也破產就移除root。
   2. **x位於Non-Leaf**
      1. 刪x
      2. 左子樹最大or 右子樹最小 作為y，將y自leaf中刪掉並取代x，所以leaf少一個key=>_回到a.處理_

> Rotation：跟兄弟借（兄弟給爸，爸給自己）
> Combine：跟爸爸要錢，並且和兄弟合併

```ad-tip
title:解題技巧：父破產，先移除該下面level的所有撫養關係，往上同理，直到平衡後在連起來。
```

```ad-example
title:綜合T or F
(1)若BST之Root的左右子樹是[AVL Tree](CH9%20Advanced%20Tree.md##AVL%20Tree), 則此BST也是[AVL Tree](AVL%20Tree.md)
*F*
(2)B tree of order m 之insert & delete x動作時間為O(logn)
*T*
(3)In [AVL Tree](AVL%20Tree.md)，任何Leaf之level值之差值皆<= 1
*F*
(4)[AVL Tree](AVL%20Tree.md) 之inset x, Delete x, search for x 之worst case Time 皆O(logn)
*T*
(5)[AVL Tree](AVL%20Tree.md) Inset x時，最多發生1 種rotation
*T* (因為rotation完就結束了)
(6)[AVL Tree](AVL%20Tree.md) 使用Postorder traversal 可得到 大->小 order
*F*
(7)[AVL Tree](AVL%20Tree.md)及B Tree 皆是Balanced search Tree
*T*
```