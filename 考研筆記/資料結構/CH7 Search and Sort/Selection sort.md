#### Selection sort
#unstable

> 觀念：
> 自第i~n筆資料找出最小值:A[m]
> 然後swap(A[i], A[m])
>
> eg: input 3, 3*,  2
> 
> **降低swap 次數**

**Algo** 

```C
SelectionSort(A, n){
	for i = 1 to n-1 do{
		min = i;
		for j  = i+1 to n do{//找後面(剩餘的)最小值，並保存index
			if(A[j] < A[min])
				min = j
		} 
		if(min != j)
			swap(A[min], A[i])
	}
}
```



**分析 Time Complexity: Best/Worst/Avg.皆為O(n²)**
一psudo Code中 A[j] < A[min]中比較次數
共為 =(n-1)+(n-2)+...+1 = (n(n-1))/2次 
-> O(n²)

**Space Complexity -> O(1)**
min變數、swap函式中的temp變數。

**其他討論：**
Selection Sort適用於*“大型紀錄”（紀錄由很多欄位組成）排序*
`insertion sort搬移的成本較高，selection sort 只需紀錄欄位位置，成本較低`

`if(min != i)`是否省略
- 省略：多出不必要的自己對自己交換->適合大多數都不落在正確位置的
- 不省略：

