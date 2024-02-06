---
date created: 2022-09-27 18:13
date updated: 2022-10-12 15:16
---

# CH5 Tree and Binary Tree

## Tree definition, represnetations

### Tree

> 定義：由>個[Node](../CH3%20Stack%20and%20Queue/Node.md)構成，不可為空。
> 至少有一[Node](../CH3%20Stack%20and%20Queue/Node.md)稱為_root_

其他相關名詞：

- Node's Degree：Node的子樹個數
- Leaf：Degree = 0 的 Node
- Non-Leaf：Degree > 0 的 Node
- parent & child
- sibling(兄弟)
- Ancestors(祖先)、Descendents(後代)師

## Binary tree 定義, differences with tree

### Binary tree

![400](../img/截圖%202022-09-27%20下午7.31.00.jpg)

## Binary tree三個基本定理 #⭐️⭐️⭐️⭐️⭐️

正向

1. B.T.中_第 i level 之最多Node數 = 2^(i-1)_
   ```ad-quote
   title:數學歸納法證明
   ```
2. 高度 k 之B.T最多Node數 = 2^k  -1 (有k層的B.T.最多2^k  -1個Node)
   ```ad-quote
   title:每層之MAX節點數總和
     = 2^k -1
   ```

反向

1. 若B.T有n個Nodes，求最大高度
   Ans: n (一層一個點)

2. B.T有n個Nodes，求最小高度
   Ans: 用2^k -1 反推

3. 若B.T有n個leaf，求最小高度
   Ans:  upper(log₂n) +1
   ```ad-quote
   title: 用2^(i-1)反推
      2^(i-1)  = n
      i-1 = upper(log₂n)
      i = upper(log₂n) +1
   ```

4. 一個非空的B.T.，若有n0個leaf, n2個Degree-2 Node，則_n0 = n2+1_ #⭐️⭐️⭐️⭐️⭐️
   ```ad-quote
   title:Proof(KEY:分支數量與degree關係)
    1. 假設（很重要）
    n = Node數
    n1 = Degree-1 的node數
    B = Branch總數 ( = n-1)
    
    2. n = n0 + n1 + n2 = B+1
    = (n1 + 2\*n2)+1
    => (n1 + 2\*n2)+1 = n0 + n1 + n2
    => n0 = n2 + 1
   ```
   > 關鍵：
   > n = n0 + n1 + n2 + ....
   > n = B + 1
   > 找這兩者之間的關聯
   ```ad-example
   title: B.T. 有15個Leaf，求Degree-2的Node數量？
   因為n0 = n2 + 1 => 15 = n2 + 1 => n2 = *14*
   ```
   ```ad-example
   title: B.T. 有77個nodes，求Degree-1的Node數有44個，求leaf個數？
   n = n0 + n1 + n2
   77 = n0 + 44 + n2
   => 77 = 2\*n0 -1 + 44
   n0 = 17
   ```
   ```ad-example
   title: 有一顆Tree, 其Degree = 5且Degree為i之Node數有i個，求Leaf個數
   n = n0+n1+n2+n3+n4+n5
   n1 = 1, n1 = 2, n3 = 3, n4 = 4, n5 = 5
   n = Branch數+1
   => n = (1\*n1+2\*n2+3\*n3+4\*n4+5\*n5) +1 = 55+1 = 56
   => n0 = 56-15 = 41
   ```
   ```ad-example
   title:有一顆Tree, Tree's Degree = k且Degree為i之Node數有i個，求Leaf個數?
   同上一般化
   ```
   ```ad-question
   title:有一顆Tree, Tree's Degree = 4且每個Non-leaf必有4個children，若Leaf有n0個，求Node總數?
   {Node總數} = n = n0+n4

   n = B + 1 = 4\*n4+1
   => n0+n4 = 4\*n4+1
   => (4\*n0-1)/3
   ```

## Binary Tree 種類 #⭐️⭐️

### skewed Binary Tree

1. Left-skewed
   > 定義:每一個Non-leaf皆只有左子點，沒有右子點。
2. Right-skewed
   > 定義:每一個Non-leaf皆只有右子點，沒有左子點。

### Full Binary Tree

> 定義：高度k之B.T.具有最多Node數= 2^k-1，稱之。

### Complete Binary Tree

> 定義：高度k之B.T.具有n個nodes，滿足...
>
> 1. 2^(k-1)-1 < n <= 2^k -1 ~~長到最高層但不一定長滿~~
> 2. Node之增長順續_為由上而下，同level由左而右增長_。

#### Complete Binary Tree定理

Complete Binary Tree具有n個Nodes，Node編號1~n
若某Node編號是i，則

- 左子點編號=2i, if 2i > n, then 無左子
- 右子點編號=2i+1, if 2i+1 > n, then 無右子
- 父點= i/2, if i/2 < 1 then 無父點

#### Examples

```ad-example
title:1000個Nodes編號1~1000。最後一個父點No.?
ans: 1000/2 = *500*
```

```ad-example
title:1000個Nodes編號1~1000。How many leaves?
ans: N0.501~N0.1000 => *500*

**=>求complete B.T的Leaf數->最後一個parent的下一個到對後一個的編號長。**
```

```ad-example
title:1000個Nodes編號1~1000。有多少個Degree-1的Node?編號是？
ans: 已知n0 = 500 , n2 = 499
n1 = 1000-500-499 = 1

**=> 最後一個parent**
```

```ad-example
title:(True or False)In a Complete B.T, n1 = 0 or 1
True
```

```ad-question
title: True or False
1. 若樹根的左右子書都是C.B.T，則此樹必為C.B.T (可延伸為其他樹型)
	False
1. 一C.B.T.的任何左右子樹必為C.B.T
	True
1. C.B.T中若Node沒有左子點，則此Node必為Leaf
	True
2. C.B.T with n nodes高度必為upper(log₂(n+1))
	True
3. n個branch則必有n-1個node
	False


```

### Strict Binary Tree

> 定義：B.T中，every Non-Leaf must have 2 child Node. that is, n1 = 0.。~~有孩子就要放滿~~

```ad-example
title: True or False
1. Full BT => strict BT
2. CBT => strict BT
3. strict => Full BT
4. Strict BT => CBT

ANS:
1. T
2. F
3. F
4. F
```

```ad-example
title: 在不同Binary tree中，選出正確項目
KEY: [Binary tree三個基本定理](CH5%20Tree%20and%20Binary%20Tree.md##Binary%20tree三個基本定理)
1. n0 = n2+1
2. n = 2\*n0-1
3. 高度 = upper(log₂(n+1))
4. n0+n2 <= n <= n0+n2+1

ANS:
對於任意Binary Tree: {1} 
對於Full Binary Tree:{1, 2, 3, 4} 
對於Complete Binary Tree:{1, 3, 4} 
對於Strict Binary Tree:{1, 2, 4} 
```

## Binary Tree representations #⭐️⭐️⭐️

### [法一]利用Array表示

**作法**
if BT's heigh = k, then prepare A:array[1..2^k -1], 依照Node 編號，存入對應的Data
另外，若是Complete/Full BT則只需n個node（Array[1..n])即可

```ad-example
title: Draw the B.T, if you can. otherwise, say "invalid"
1. [A, X, B, Y, , C, ]
	可以
1. [A, B, , C, D, E, ]
	invalid
```

**優點**

1. 容易存取
2. 對於Full/Complete B.T之儲存充分利用Space

**缺點**

1. 不易增/刪 Node(可能須改變array大小和元素搬動)
2. 對於skewed B.T 來說極度浪費空間

### [法二]利用Link List 表示

**作法**
Node structure設計
[Lchild | Data| Rchild]

**缺點**

1. 不易存取(例如找父Node)
2. ⭐️link space 浪費一半左右
   n個nodes共2n條links，其中_有用的link: n-1條_ ，_浪費n+1條_。

**優點**

1. 增加刪除方便
2. 對於skewed B.T儲存，比Array節省空間

## Binary traversal and applications #⭐️⭐️⭐️⭐️⭐️

### Binary traversal

_**O(n)**_

1. Preorder:DLR 中左右~~右子在左子~~
2. Inorder:LDR 左中右 ~~從左往右掃~~
3. Postorder:LRD 左右中 ~~左子在右子~~
4. Level-order: 由上而下由左而右 => [Queue](../CH3%20Stack%20and%20Queue/CH3%20Stack%20and%20Queue.md##Queue)之應用

![400](../img/截圖%202022-09-29%20下午7.18.15.jpg)

#### 四大題型 #⭐️⭐️⭐️⭐️⭐️

1. 給B.T寫出traversal sequence ~~記熟各種Binary traversal~~
2. 給B.T的_前序&中序_ 或 _後序&中序_，_可決定unique B.T_，但若給_前&後序則無法_ #⭐️⭐️⭐️⭐️⭐️
   ```ad-example
   title:給前序/後序 & 中序 還原Tree
   collapse: false
   ![450x350](../img/截圖%202022-09-29%20下午7.26.54.jpg)
    > 前序：左而右看Root
   > 後序：右而左看Root
   ```
   ```ad-example
   title:舉例說明給前&後序無法決定唯一B.T ***!!記下此案例***
   collapse: false
   ![400](../img/截圖%202022-09-29%20下午7.40.22.jpg)
   ```
   ```ad-example
   title:給予前序後序決定all posible B.T
   collapse: false
   >L&R如何切割 => 靠人 
   >=>判斷原則：
   >1. 集合元素相同
   >2. Root要一致

   ![400](../img/截圖%202022-09-29%20下午7.58.30.jpg)
   ```
   ```ad-example
   title: 下列哪些組合可以決定唯一B.T ⭐️
   collapse: false
   > key:拿左斜右斜驗證
   1. 前+中:T
   2. 後+中:T
   3. 前+後:F
   4. 前+level-order:F
   5. 中+level-order:T
   6. 後+level-order:F

   >Complete B.T => 結構卡死 => 依照[]序放資料
   1. Complete B.T + 前:T
   2. Complete B.T + 中:T
   3. Complete B.T + 後:T
   4. Complete B.T + level-order:T
   ```
   ```ad-example
   title:決定下列B.T各可為哪些種類？
   collapse: false
   1. 此B.T下的 前序=中序
   2. 此B.T下的 後序=中序
   3. 此B.T下的 前序=後序

   Ans:
   1. DLR = LDR
      => empty, root, Right-skewed B.T(去掉L)
   2. LRD = LDR
      => empty, root, Left-skewed B.T(去掉R)
   2. DLR = LRD
      => empty, root
   ```
3. B.T_前中後序recursive algo._ (Assume B.T以link list表示)~~資工較少~~

   > 原則：
   > D=>列印Node Data
   > L, R=>遞迴追蹤

   ~~...覺得簡單。省略~~
4. B.T recursuve Traversal algo.之應用 #⭐️⭐️⭐️⭐️
   1. [Copy a B.T](Copy%20a%20B.T.md)
   2. [Equal(S, T)](Equal(S,%20T).md)：判斷S, T是否相等
   3. [Count B.T Node總數](Count%20B.T%20Node總數.md)
   4. 求[B.T Height](B.T%20Height.md)
   5. [Swap a B.T](Swap%20a%20B.T.md)
   6. [以B.T表示expression](以B.T表示expression.md)，[針對Expression B.T求值](針對Expression%20B.T求值.md)之algo.
   7. [Binary Tree sorting](Binary%20Tree%20sorting.md) #⭐️⭐️⭐️⭐️⭐️

## [Binary Search Tree](Binary%20Search%20Tree.md) #⭐️⭐️⭐️⭐️⭐️

## Heap #⭐️⭐️⭐️⭐️⭐️

> 定義：（分為MAX-Heap, Min-Heap）
> 以MAX為例：
>
> 1. 是一顆Complete B.T.
> 2. 父點皆>= 其子點
> 3. Root具有最大值

### 用途

1. 製作_priority Queue_之最適合資料結構
2. [Heap Sort](../CH7%20Search%20and%20Sort/Heap%20Sort.md)
3. Heap適合用Array保存

### operations 及 Time

| operation                                                              | Time Complexity |
| ---------------------------------------------------------------------- | --------------- |
| _[Insert x](Insert%20x%20into%20MAX-Heap.md)_                          | O(logn)         |
| _[Delete-MAX(min)](Delete-MAX%20in%20%20MAX-Heap.md)_                  | O(logn)         |
| _[Build a Heap](Build%20a%20Heap%20with%20n%20nodes.md)_  ⭐️           | O(n)            |
| _Find-MAX(min)_                                                        | O(1)            |
| [Merge two Heaps into a Heap](Merge%20two%20Heap%20into%20a%20Heap.md) | O(n)            |
| Increase/Decrease-key of Node                                          | O(logn)         |
| Delete x                                                               | O(Logn)         |
| search for x                                                           | O(n)            |

## The number of binary tree structures with n nodes #⭐️⭐️⭐️

**公式**：1/(n+1) C(2n, n) ~~證明在課本~~

```ad-example
title: 1,2,3 3個integer可以形成?顆不同的[BST](Binary%20Search%20Tree.md)，並求其後序。
Ans: =>公式 = 5顆
後序剛好是[Stack permutation](../CH3%20Stack%20and%20Queue/CH3%20Stack%20and%20Queue.md##Stack%20permutation)
![400](../img/截圖%202022-10-01%20下午7.01.40.jpg)
```

```ad-example
title: 令Bn代表n個nodes可形成的不同B.T數目。完成下列題目
1. write down the Recursive definition of Bn.
   設Root的右子樹有i個點，左子有n-i-1個
   > Bn = sigma(i=0~n-1)(Bi + Bn-i-1)
   > B0 = B1 = 1
   
2. 求解Bn = ?(資工離散) #離散 #⭐️⭐️⭐️⭐️⭐️ 
3. Write the Recursive Algo. code
	~~~C
	int B(int n){
		if(n == 0|| n == 1)return 1;
		else{
			int s = 0;
			for(int i; i<= (n-1); i++)
				s += B(i)+ B(n-i-1);
			return s;
		}
	}
	~~~
   
```

## Transformations among tree, forest and binary tree

#⭐️⭐️

### Tree <--> B.T

#### Tree --> B.T

**方法:"Leftmost-child - Next-Right-sibling"法**
**Steps**

1. 建立sibling 間的平行links ~~
2. 刪除父點與子點間的links但保留leftmost-child的link
3. 順時針轉45度。
   - 即次右兄弟變成右子點
   - 保留的最左子當左子

**優點：**
- 可充分利用Nil link 空間
- 方便找到任意一node的中序前/後一個點
- 簡化中序追蹤，不需遞迴（不用stack)
![400](../img/截圖%202022-10-01%20下午6.25.53.jpg)

#### Tree <-- B.T

**Steps**:~~Tree化成B.T的反向~~

1. 逆轉45度
2. 補上父子link
3. 刪sibling連結

> 右子變右邊兄弟，左子還是子（左右沒差）

### Forest <--> B.T

#### Forest -->  B.T

**Steps**:

1. Forest 中每顆Tree先化B.T（若原本觀察下來就是B.T，依舊要換）
2. Roots連再一起，平行連
3. 針對Roots順時鐘轉45度（其餘不變）

#### Forest <-- B.T

~~Forest 化成B.T反向~~

## Thread Binary Tree

**緣由**：n個nodes之B.T，若以link list 表示，則有 _n+1_ 條Nil links，為了充分運用這些links，故將他們視為"Thread pointer"，改成只向其他Node，此種B.T稱之。

**一般我們是以Inorder順序規範**：

1. 若x的leftchild is Nil，則當_左引線指向中序順序中x的**前**一個Node_
2. 若x特Rightchild 為Nil，則當_右引線指向中序順序中x的**下**一個Node_

### Data Structure design

[ LeftThread | Lchild | Data | Rchild | RightThread ]

- LeftThread: Boolean 。True表Lchild是左引線, False表Lchild是左子  ~~有子點 --> False~~
- RightThread: 類上
- 額外新加一個_Head node_，規定如下：
  ![300](../img/截圖%202022-10-01%20下午7.44.53.jpg)
  ![300](../img/截圖%202022-10-01%20下午7.44.40.jpg)

### Thread Binary Tree 之基本操作

1. Insuc(x)/Inpre(x):找出x的中序後繼者/先行者
2. 簡化的中序追蹤
3. Insert t node 成為S的右子點/左子點

#### Insuc(x)

找出x的中序後 _下一個_ Node
**規則**：

1. 若x的RightThread = True（沒右子），則x->Rchild則是
2. 若x的RightThread = False（有右子），_沿著右子開始往左下尋找_，直到某個Node的LeftThread是True，其Rchild則是。

```ad-question
title: Insuc(Head) = ?

```

```C
Insuc(x){
	temp = x->Rchild;
	if(x->RightThread == False)
		while(temp->leftThread != True)
			temp = temp->Lchild;//往左子移動
	return temp;
}
```

#### Inpre(x)

對稱於Insuc(x)

#### 簡化的中序追蹤

**規則**

1. _從Head node開始Incus(x)_，直到回到Head node。

```C
Inorder(T: Head node){
	temp = T;
	repeat{
		temp = Insuc(temp);
		if(temp!= T)
			print(temp-> Data);
	}until(temp == T);
}
```

#### Insert t node 成為S的右子點

- case 1: S原無右子點
  ![400](../img/截圖%202022-10-01%20下午8.32.04.jpg)
- case 2: S原本有右子點。則原本的右子變成t的右子。
  ![400](../img/截圖%202022-10-01%20下午8.31.47.jpg)

```C
//t的線先連好（［1］［2］）
//更新S
//原本有無子點（有則中序的後一個連到t)
Insert(S, t){
	//case1
	//[1]
	t->RightThread = S->RightThread;
	t->Rchild = S->Rchild;
	//[2]
	t->LeftThread = True;
	t->Lchild = S;
	//[3]
	S->RightThread = False;
	S->Rchild = t;
	//[4] in case 2
	if(t->RightThread == False){
		temp = Insuc(t);//找出S原本的中序後繼者
		temp->Lchild = t;
	}
	
}
```

```ad-quote
title: note:若是插入t為S的左子呢？
Left <-> Right
Insuc -> Inpre
```

## Disjoint sets #⭐️⭐️⭐️

### representation

~~link往上指的tree喔！！~~

> 定義：一堆互斥的sets組成

#### Data structure Design

> _每一個集合均用一顆Tree表示_，從set中_任取一個元素作為Root_，其餘為Root的子點

#### 實際儲存方式

##### [法ㄧ]用link list 表示

Node設計：[ Data | Parent ]
Parent: pointer to 父點

（root可指向自己或Nil）

##### [法二]利用 Array 表示

**作法：**

|          |    |    |
| -------- | -- | -- |
| Index No | .. | .. |
| Data     | .. | .. |
| Parent   | .. | .. |

Parent:若有父親則紀錄父親的No.

#### 兩個基本運作

- Union聯集(等同於Merge 2個sets)
- Find(x)找出x元素所在set之root，傳回root

### 應用

1. [kruskal's algo](../CH6%20Graph/Kruskal's%20Algo.md) 求MST 判斷邊(u, v)加入是否會形成cycle
2. 依照_等價關係配對_找出_[等位集合](等位集合.md)_
3. #ch6 求無相圖之Connected component 方法之一

### Union(i, j)與Find(x)運作之3種組合,討論

==在面對十分大的graph時，Union and Find比DFS, BFS還要好==

#### [組合一]：任意的Union(i, j) & simple-Find(x)之組合

[Union(i, j)](Union(i,%20j).md)
[Simple-Find(x)](Simple-Find(x).md)

**分析**
_可能會創造出O(n)高度之tree結構_，導致`Find(x)  = O(n) time`（例：n個單一元素的sets Union起來）

#### [組合二]：Union-by-Height(i,  j) & simple-Find之組合

~~避免組合一的問題，降低樹高~~

[Union-by-Height(i, j)](Union-by-Height(i,%20j).md)

**分析**：
若一開始_n個單一元素sets經過n-1次union後，創造的tree高度=O(logn)_，故Find(x)平均一次花O(logn) time

```ad-example
title:定理：創造出Tree之高度頂多是 log₂n+1 (or ⎡log₂(n+1)⎤)
1. n=1時，高度log₂1 +1 = 1，初值成立。
2. 假設node數<n-1時成立
3. node數 = n時，假設最後一次union是union(k, j)
   tree j的node數= m
   tree k的node數= n-m
   不失一般性假設1<=m<=n/2
   1. m< n/2 : union後以n/2的高度為準=>新樹高<= log₂(n-m)+1 <= log₂n +1
   2. m= n/2 : union後新樹高度= treej or treek 高度+1 =>  <= log₂(n/2)+1*+1* <= log₂n +1
3. 由數學歸納得證
```

#### [組合三]：Union-by-Height(i,  j) & Find(x)-with-path-Compression

[Find(x)-with-path-Compression](Find(x)-with-path-Compression.md)

**分析**
此種組合Findㄧ次的時間=O(𝞪(m, n)), 𝞪(m, n)是Ackerman's反函數，成長數率極緩= O(log*n)，趨近於O(1)
