---
date created: 2022-10-20 14:33
date updated: 2022-10-20 14:35
---

#### Insertion sort
#stable

> 觀念：
> 將第[i]筆Data插入到前面(i-1)筆以排序好的串列中之正確位置，使之成為i筆已排序好的串列
> i = 2 to n，做n-1回合
>


Algo 由下列兩項組成

- Insert(A[], r, i)副程式
- Insort(A[], n)主程式

```C
Insert(A[], r, i){
	//資料r插入到A[0]~A[i]以排序的串列。r是A[i+1]的data
	j = i;
	while(r < A[j]){
		A[j+1] = A[j];
		j = j-1;
	}
	A[j+1] = r
}
```

```C
Insort(A[], n){
	//排序A[1]~A[n] n筆data
	//會多一個額外空間
	
	A[0] = -無限; //防止r的湧入
	for i = 2 to n  do
		Insert(A[], A[i], i-1);
}
```

**複雜度分析**

1. Best case:O(n) （Input data剛好是小->大排序）
   說明：
   1. 量化：每回合比較一次後就找出正確位置->n-1回合。
   2. recursive funciton：T(n) = T(n-1)+{第n比要插入的最小比較次數 = 1次} = n-1
   3. (很少用)Inversion(x):在input Data中_出現在x左邊sublist 中大於的Data 數目_
2. Worst case : O(n²) （input data是反序給予，大->小）
   說明：
   1. 直接舉例
   2. recursive Time function：T(n) = T(n-1) + _n-1_ = (n-1)(n)/2
3. Avg. case：O(n²)
   T(n) = T(n-1)+{O(n) or c n or n/2}

**Space Complexity -> O(1)**
額外空間需求（除了input data外）是固定的，與資料量n無關。

#### Insertion sort 之變形[很少考]

原本的每一回合做兩個工作

| 工作         | 機制                | Time |
| ---------- | ----------------- | ---- |
| 找出r的正確插入位置 | 使用linear search   | O(n) |
| 元素往後       | 用Array keeps data | O(n) |

` 每一回合花O(n), 做(n-1)回合 -> O(n²)  `

常見之變形：

##### Binary insertion sort

| 工作         | 機制                    | Time    |
| ---------- | --------------------- | ------- |
| 找出r的正確插入位置 | 改用Binary Search       | O(logn) |
| 元素往後       | (不變)用Array keeps data | O(n)    |

` 因此improve the Comparison 次數但未improve data movement 次數->   `

##### Linear(list) insertion sort

| 工作         | 機制                                                       | Time |
| ---------- | -------------------------------------------------------- | ---- |
| 找出r的正確插入位置 | （不變）使用linear search                                      | O(n) |
| 元素往後       | 使用link list keeps data, 如此無需data movement, _改變pointer_即可 | O(1) |

` 因此improve the data movement 次數但未improve Comparison 次數->   `
