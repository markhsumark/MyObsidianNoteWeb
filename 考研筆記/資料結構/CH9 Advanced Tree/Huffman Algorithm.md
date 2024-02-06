Huffman Algorithm

求[min.WEPL](min.WEPL.md)
#⭐️⭐️⭐️⭐️⭐️

[Greedy Strategy](../../演算法/CH3%20Dynamic%20Programming/Greedy%20Algorithm.md)

令W = n個外部結點_加權值集合_

1. 從W中取出2個最小的加權值，建Tree
2. 並將他的合(WEPL)視為新權值，加入W中
3. repeat 1, 2直到W只剩一個值  _**（n-1回合）**_
4. 建完的Tree叫Huffman Tree，其WEPL值即為min

```ad-example
title:W = {2,3,5,7,9,13}，求[min.WEPL](min.WEPL.md)
ANS:
![200](../img/截圖%202022-10-13%20下午7.31.13.jpg)
![](../../img/截圖%202022-12-31%20下午2.44.45.jpg)
min. WEPL = 2\*7+2\*9+3\*5+ 4\*2+ 4\*3 + 2\*13 = 93

```

==Node struct [ Lchild | weight | Rchild ]==

```C
Huffman(W:加權值集合, n:加權值個數){
	for i = 1 to n-1{
		new(t);
		t->Lchild = Del-min(w);
		t->Rchild = Del-min(w);
		t->weight = t->Lchild->weight + t->Rchild->weight;
		Insert(W, t->weight);
	}
}
```

**Time:** W適合==用[min-Heap](../CH5%20Tree%20and%20Binary%20Tree/CH5%20Tree%20and%20Binary%20Tree.md#Heap%20⭐️⭐️⭐️⭐️⭐️)來maintain ===> Insert & Del-min 均分別花O(logn)，所以
_**Huffman Algo. Time = `O(nlogn)`**_
