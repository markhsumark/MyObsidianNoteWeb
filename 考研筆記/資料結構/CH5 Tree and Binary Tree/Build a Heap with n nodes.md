## Build a Heap with n nodes

分成

1. Top-Down法（慢O(nlogn)）
2. Bottom-up法（快==O(n)）

### Top-Down法建立

~~一個一個insert~~

**steps:**
即Inset x one by one 逐步建立Heap
**Time:**
Inset x into Heap 後，有i個點插入的time約logi -> _**O(nlogn)**_

### Bottom-up方法

~~先隨意建立(complete B.T)再修正~~

**steps:**

1. Input data 以Complete B.T呈現(Array[1..n])
2. 從"the last Parent"開始，調整子樹數成為Heap，再往前一個父點一直調整到Root。
   ![300x300](../img/截圖%202022-09-30%20下午8.32.23.jpg)

**Time分析** #⭐️⭐️⭐️
n個資料，complete B.T，高度`k= ⎡log₂(n+1)⎤`
假設父點在level i調整子樹，調整`子樹之最大成本為 = k - i`
而`level i最多有 2^(i-1) 顆子樹`，且level值: 1 ~ k
=> `Total cost = 2^(i-1) (k - i) = S , 取i = 1~k的總和`
```txt
S = 2^0x(k-1)+...+2^(k-2)x1
2S = ...
2S - S = -(k- 1)+ 2^1+ 2^2+ ...+ 2^k-1
= ((2^k)- 2) / (2- 1) -k+ 1
= 2^k - k - 1
=>因為k = ⎡log₂(n+1)⎤ ~= log₂n
=>S = n- logn -1
=> O(n)
```

#### Bottom-up 建 Heap之 Algo.

#⭐️⭐️⭐️⭐️⭐️
分成

1. Adjust(tree, i, n) 副程式 #⭐️⭐️⭐️⭐️⭐️
2. BuildHeap(tree, n) 主程式 #⭐️⭐️⭐️

##### Adjust(tree, i, n)

> 又稱heapify

tree: Array[1..n]
i:Node編號
調整以i為Root之子樹成謂Heep

> KEY：
> 1. 先保留root，開始往下檢查
> 2. 遇到符合大小的規則的，往上移，然後往他的位置繼續檢查
> 3. 直到往上移完之後再把root放到新的位置

```C
Adjust(tree, i, n) {
	temp = tree[i];
	j = 2*i;
	while(j <= n){   //還有子點
		if(j < n)    //j node還有兄弟（i有右兒子）
			if(tree[j] < tree[j+1])   //右子比較大
				j = j+1;   //j指向比較大的子點
			if(temp >= tree[j])   //i比右&左子大
				break;
			else{   //子點比較大
				tree[j/2] = tree[j];   //j往上放
				j = 2*j;   //下一個左子點位置
			}
	}
	//往上移完，把root放到正確位置
	//！！！因為是比j大，所以放j上一層
	tree[j/2] = temp;
}
```

_**Time: O(logn)**_

##### BuildHeap(tree, n)

針對tree:[1..n]建立Heap

```C
BuildHeap(tree, n){
	for(i = n/2; i>= 1; i--){   //從後一個「父」點調整
		Adjust(tree, i, n);
	}
}
```

_**Time: O(n)**_