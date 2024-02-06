---
date created: 2022-12-24 17:59
date updated: 2022-12-24 18:01
---
```ad-example
![](../../img/截圖%202022-12-24%20下午6.01.02.jpg)
```



#### Quick Sort[Weiss版]

平均case下 actual exec. Time最快速
採用"[CH2 Divide-and-Conquer](../../演算法/CH2%20Divide-and-Conquer/CH2%20Divide-and-Conquer.md)"策略

> 觀念：
> 排序A[l]~A[u]
> 假設A[l]為_pivot key_(p.k)，經過==partition==後，即將pk放到“正確的”位置上，令為'q'
> {q左邊的} < q < {q右邊的}
> **核心:Partition**

**Algo**

> KEY:i從左邊往右(->)，j從右邊往左(<-)。
> 先找A[j] <= pk, 再找A[i] >= pk ，然後swap
> 中途交會就Swap(A[j], p.k)。
> end

```ad-example
title: 26, 5, 37, 1, 61, 11, 59, 15, 48, 19
collapse:none
![400](../img/截圖%202022-10-20%20下午5.05.06.jpg)
```

```ad-question
title: write down the result of Pass 1 of Quick Sort
1. 5, 8, 9, 1, 4, 7, 2, 3, 6
   ![200](../img/截圖%202022-10-20%20下午5.11.11.jpg)
2. 1, 2, 3, 4, 5
   ![200](../img/截圖%202022-10-20%20下午5.11.29.jpg)
3. 5, 4, 3, 2, 1, 無限
   ![200](../img/截圖%202022-10-20%20下午5.11.43.jpg)
4. 5*, 5, 5, 5, 5
   ![200](../img/截圖%202022-10-20%20下午5.12.01.jpg)
```

**Time Complexity分析：O(nlogn)**

- Avg. Case:
  說明：{s個元素} pk {n-s個元素}，s = 1~n
  ![400](../img/截圖%202022-10-20%20下午5.24.33.jpg)
  -> nT(n) - (n-1)T(n-1) = 2T(n-1)+T(n)-T(n-1)+c(n²-(n-1)²)
  -> nT(n)- nT(n-1)+ T(n-1)= T(n-1)+ T(n)+ c(2n-1)
  -> (n-1)T(n) = nT(n-1)+ c(2n-1)
  -> T(n)/n = T(n-1)/(n-1)+ c/n+ c/n-1
  --> T(n) = T(1) / 1 + c(1/2+ 1/3+ ... + 1/n) + c(1/1+ 1/2+ ... + 1/(n-1))
  --> T(n) = c(Hn -1) + c(Hn - 1/n)
  --> T(n) = 2 c n Hn -cn -c
  --> T(n) ~= 2 c n logn - cn - c ==<=2 c n log n <= O(nlogn)==
- Worst Case:
  遇到pivot key剛好是最小->沒有分割的效果
  遇到已排序的input -> ==使用隨機(or midddle-fo three or mediam-of-mediam)取pivot key==
- Best Case:
  5, 5, 5, 5, 5*（切割一半）

空間複雜度

- 位於 O(log n) ~ O(n) 之間。額外空間需求來自於遞迴所需的 Stack 空間，而 Stack Size 取決於 Recursive Call 的次數。

#### Quick Sort[Algo版]

```C
QuickSort(A, p, r){
//排序A[p] ~ A[r]
	if(p<r){
		q = Partition(A, p, r);//傳回pk的正確位置給q
		//遞迴左右半
		Quicksort(A, p, q-1);
		Quicksort(A, q+1, r);
	}
}
Partition(A, p, r){
	x = A[r];
	//i, j都從左邊出發，但是i只有在交換前回右移。
	//key:i是紀錄左半的最右index
	i = p-1;
	for j = p to (r-1){
		if(A[j] <= x){
			i = i+1;
			Swap(A[i], A[j]);
		}
	}
	Swap(A[i+1], A[r]);
	return (i+1);
}
```

![300](../img/截圖%202022-10-24%20下午2.43.42.jpg)

```ad-attention
title:遇到相同key值會使效益變差。使用==Hoare partition解決==
```

**分析**

- ==Worst Case O(n²)==: 5, 5, 5, 5, 5*（沒有切割效果）
  - 解法1. 先花O(n) Time check 是否所有elements are equal，若是，則可exits，否則才做Qsort。
  - 解法2. 改用[Hoare] partition

```ad-quote
title:Randomized Quick sort's worst case still O(n²)
```
