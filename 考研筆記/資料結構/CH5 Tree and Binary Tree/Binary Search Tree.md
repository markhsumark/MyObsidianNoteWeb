---
date created: 2022-09-30 18:10
date updated: 2022-10-01 18:56
---

# Binary Search Tree #⭐️⭐️⭐️⭐️⭐️

```toc
```

> 定義：是一顆B.T，若不為空，則滿足：
>
> 1. 左子樹所有Data皆 < Root
> 2. 右子樹所有Data皆 > Root
> 3. 左右子樹亦是Binary Search Tree
>
> ~~左<中<右~~

## 利用BST進行排序

steps:

1. 將input Data 建成BST
2. 對BST進行 _[Inorder](CH5%20Tree%20and%20Binary%20Tree.md###Binary%20traversal)_ traversal 即可得出 _小->大_ order
   (補充：大->小呢？改用RDL or 利用[Stack](../CH3%20Stack%20and%20Queue/CH3%20Stack%20and%20Queue.md##Stack)做反序)

_**BST就代表中序**_

```ad-example
title:哪些可以決定唯一的BST?
collapse:false
> Key:BST就代表中序
1. BST+前序
2. BST+中序
3. BST+後序
4. BST+Level-order

ANS: 1, 3, 4
```

## 建立BST

A[1..n]: Array of Data
從A[1]開始放
遇到Node與Node->Data比大小，小則往左，大則往右。
放到A[n]結束

## Delete x in BST

#⭐️⭐️⭐️

**Steps:**

1. 先search for x
2. 分成下列case
   - case 1:x is leaf ，直接砍掉
   - case 2:x is Degree-1的Node，將x的_父點原本指向x的poinetr只向x的child_再在砍掉x
   - case 3:x is Degree-2，則先找出x的 _左/右 子樹中的最 大/小 子(y)_，y可能是leaf or Degree-1，將_x換成y_(Data)，x再依照y原本的情況(case 1 or case 2)做刪除。

## Search for x in BST

_Search for x是Insert x和Delete x之基礎_

recursive algo for search for x in BST

```C
Search(T, x){
	if(T != Nil){
		switch(比較(x, T->Data)){
			case "=" : return "Sucess";
			case "<" : return Search(T->Lchild, x);
			case ">" : return Search(T->Rchild, x);
		}
	}
	else{ // T = Nil
		return "Fail"; // 找不到x
	}
}
```

## Time分析:

- worst case: O(n)。(if BT is [skewed](CH5%20Tree%20and%20Binary%20Tree.md###skewed%20Binary%20Tree))
- Best case: O(lgn)。(e.g [Full B.T](CH5%20Tree%20and%20Binary%20Tree.md###Full%20Binary%20Tree), [Complete B.T](CH5%20Tree%20and%20Binary%20Tree.md###Complete%20Binary%20Tree))
- Average: O(logn)

```ad-quote
title:Note
Insert Time & Delete Time 都被Search影響=>Insert Time & Delete Time也是如此
```

## Binary Search 應用

### 找BST中第i小的數

> KEY:跟root的No.?做比較，然後往左或右子移動。

```C
Search(T, i){
	if(T != Nil){
		k = (T->Lsize)+1; //表示root是第k小
		if(i == k)
			return T->data;//找到
		else if(i < k)
			return  Serach(T->Lchild, i);//root比較大->No.i在左半
		else if(i > k)
			return  Serach(T->Lchild, i);//root比較小->No.i在右半第i-k小
	}
}
```
