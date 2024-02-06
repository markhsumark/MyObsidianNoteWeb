---
date created: 2022-10-20 15:56
date updated: 2022-10-20 15:58
---

#### Shell sort
#unstable 
> 定義：
>
> - 每一回合, i = 1 to (n-span)比較A[i]& A[i+span]，若前者>後者，則Swap(A[i], A[i+span])
> - _每一回合_需持續執行到_No Swap_發生，才可進入下一回合
> - _回合數目_由_span型式_決定
>   1. n/2^k型(span = n/2, n/4, n/8, ...)
>   2. 2^k -1型(span = 15, 7, 3, 1)
>   3. 其他
>   4. 自定型(eg. span = 5, 3, 1)
>   
>   **Unstable**

**效果**
若某回合span值= k，則代表有k調sublists要排序好，每條sublist 之Data量 ~= n/k

```ad-example
collapse: none
title:例：給予10, 13, 15, 2, 7, 6, 4, 12, 18, 3。span採⎡n/2^k⎤型，實施shell sort
![400](../img/截圖%202022-10-20%20下午4.09.20.jpg)
```

**Algo**
```C
ShellSort(A, n){
	//排序A[1]~A[n]
	//span採n/2^k型
	span = n/2;
	while(span > 1){
		do{
			flag = 0;
			for i to (n-span){
				if(A[i] > A[i+span]){
					Swap(A[i], A[i+span]);
					flag = 1;
				}
			}
		}until(flag == 0)
		span = span/2;
	}
} 
```

**Time Complexity: O(n²)**