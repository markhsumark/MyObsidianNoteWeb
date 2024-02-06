Red-Black Tree

#⭐️⭐️⭐️⭐️⭐️
#balancedBST之一

==[Algorithm 版]==

> 定義：是一種"balancedBST"，若不為空，則滿足：
>
> 1. Node之color_非黑即紅_
> 2. _root一律是黑色_
> 3. _Nil也視為黑色_
> 4. 紅色Node之子點必為黑色（path上不可出現連續的紅色Nodes）
> 5. Root 到任何Leaf之path上必定有相同數目之黑色

**Insert x**
[weiss: Top-Down版本]

```ad-tip
title:search(&check雙紅子) -> push x -> rotate -> end
```

1. search for x
2. 在search過程中，若有經過_某Node，其兩個子點是紅色_，則先做"_color change"_，且color change之後要_檢查是否有連續的紅色_，若有則需用_Rotation調整_。
3. 此時_新點標紅色_
4. 檢查是否有連續的紅色Nodes，若有，則需做_Rotation調整_
5. Root一律改黑色(if needed)

```ad-attention
title:只會出現一次/一種Rotation
```

```ad-attention
title:不會回頭到上一步
```

```ad-quote
title:Note
collapse:none
1. RB Tree: Insert/search/Delete x之time皆O(logn)
2. RB Tree
	- Insert x:need O(1)rotations
	- Delete x:need O(1)rotations(優於[AVL Tree](AVL%20Tree.md))
```

### Rotation in RB Tree

類似[AVL Tree](AVL%20Tree.md)
差別：需加上顏色調整

- 中間鍵往上拉，標黑色
- 小放左 大放右，標紅色 (兒子標紅)
- LL, LR, RL, RR
  1. LL rotation![200](../img/截圖%202022-10-17%20下午2.41.56.jpg)
  2. LR roataion![200](../img/截圖%202022-10-17%20下午2.42.17.jpg)
  3. RR roataion![200](../img/截圖%202022-10-17%20下午2.42.50.jpg)
  4. LR rotation![200](../img/截圖%202022-10-17%20下午2.43.30.jpg)

```ad-note
title:給3,1,2,9,6,7,4,5,8,10建立RB Tree
![400](../img/截圖%202022-10-17%20下午3.03.08.jpg)
![](../../img/截圖%202022-12-31%20下午4.31.31.jpg)
```

### RB Tree[DS版]

> 定義：是2-3-4 Tree對應的BST，若不為空，則滿足:
>
> 1. Link之color非黑即紅
> 2. 若此link 在原本2-3-4 Tree中存在的，則不為黑色links否則是**紅色**links
> 3. 任何path不會出現"連續的"**紅色**links
> 4. Root到任何不同的leaf之path皆**具有相同數量的黑色**

### 2-3-4 Tree轉成RB Tree

[Binary Tree of order m](Binary%20Tree%20of%20order%20m.md)

```ad-tip
title:原*Node中的關聯*用*紅link*連起來
```

![600](../img/截圖%202022-10-17%20下午3.29.11.jpg)

### RB Tree有n個Nodes, height <= 2 log(n+1)

**pf:**
令h = RB-Tree且依照property 4，==最長path必定是黑紅交錯==*。
所以_至少有一半Nodes是黑色_，`RB tree至少包含>= (2^(h/2) -1)個Nodes`
-> `n >= 2^(h/2) -1` -> `2^(h/2)  <= n+1`
-> `h <= 2log(n+1)`
