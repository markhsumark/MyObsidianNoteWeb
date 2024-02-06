---
date created: 2022-10-20 15:06
date updated: 2022-10-20 15:31
---

#### Bubble sort
#stable 
> 觀念：
>
> - 由左而右/有而左，兩兩比較，若前者(左邊)>後者(有邊)，SWAP(前, 後)
> - 每一回合完，當時的sublist中最大值回到最高位置
> - 最多做(n-1)回合。若某一回合未發生任何SWAP則提前結束。
> 
> **Stable**

**Algo**

```C
BubbleSort(A[], n){
	for i = 1 to (n-1) do{
		flag = False;//表示有無SWAP
		for j = i to n-i do{
			if(A[j] > A[j+1]){
				Swap(A[j], A[j+1]);
				flag = True;
			}
		}
		if(!flag)return;
	}
}
```

**分析Time Complexity（類似[Insertion sort](Insertion%20sort.md))**
1. Best Case:O(n)
   情況：input data 小->大
   說明：
   1. 量化比較/Swap次數，在pass1中，經過n-1次的兩兩相互比較，沒有Swap發生-> 完成 -> O(n)
    2. recursive Time function：T(n) = n-1 + 0 = O(n)
3. Worst Case:O(n²)
   情況：input data是反序（大->小）
   說明：
   1. 量化：第一回合swap(n-1)次、第二回合swap(n-2)次，總共n(n-1)/2 -> O(n²)
   2. Recursive Time function：T(n) = T(n-1) + n-1 = n(n-1)/2 = O(n²)
4. Avg. 
   說明：T(n) = c n + T(n-1), c為常數

**Space Complexity: O(1)**

