---
date created: 2022-10-24 15:40
date updated: 2022-10-24 17:33
---

# Merge Sort

#stable

```toc
```

常用於"External sorting"
術語

1. Run :排序好的_片段_串列
2. Run的長度：Run中之Data個數

k-way merge(k>=2)

> 一次是合併k個Runs成一個Run

---

## Iterative Merge sort

==考計算題==
(以2-way為例)
![300](../img/截圖%202022-10-24%20下午3.40.17.jpg)
合併2個Runs的algo

```C
while(Run1和Run2尚未掃描完){
	//小的先放入新的陣列
	if(p.data <= q.data){
		output p.data to New Run
		p = p+1;
	}else{
		output q.data to New Run
		q = q+1;
	}
}
while(Run1尚未掃描完){
	copy Run1 剩下的到New Run
}
while(Run2尚未掃描完){
	copy Run2 剩下的到New Run
}
```

**分析**
合併Run1, Run2
Run1 長度=n
Run2 長度=m

1. 最少比較次數= _n or m_
   （若某個Run之Data均比另一個Run的Data 小/大）~~A全部比B的大or小~~
2. 最多比較次數= _n+m-1_
   （有1個Run scan over，另一個只剩一個資料）~~全部都比對到，除了最後一個~~

如果Run1, Run2長度皆為n，比較次數->**O(n)**。==每回合(層)花O(n)合併==

Tree高度為⎡log₂n⎤+1，而合併的層數是 `高度-1 ->⎡log₂n⎤`

Merge Sort Time = ⎡log₂n⎤回合* O(n)time -> `O(nlogn)`

---

## Recursive Merge sort

(以2-way merge 為例)

採取[Divide-and-Conquer](../../演算法/CH2%20Divide-and-Conquer/CH2%20Divide-and-Conquer.md)策略

**steps**

1. 一律將list分成2等份之sublists。~~對半切~~`O(1)`
2. 左右各半自merge sort，得到左右半(Run1, Run2) `2T(n/2)`
3. 合併左右Runs成為一個Run`O(n)`

**Algo.**
排序x[l]~x[u]，結果Run: p

```C
RMSort(x, l, u, p){
	if(l >= u)p = l;
	else{
		mid = (l+u)/2;
		RMSort(x, l, mid, Q);
		//排序左半得到Run Q
		RMSort(x, mid+1, u, R);
		MergeTwoRuns(Q, R, p);
	}
}
```

**分析**

1. Time Complexity: Avg./Best/worst case 皆_O(nlogn)_
   T(n) = 2T(n/2)+cn
2. Space Complexity:_O(n)_
   額外空間來自於必須_保持每一回合之合併排序結果_->需要O(n)的空間

---

```ad-example
title:k-way merge on m個Runs,資料總數=n，Time=O(nlog m)與k無關，*證明之*
collapse:none
![300](../img/截圖%202022-10-24%20下午7.58.48.jpg)
每個Runs的資料數= n/m，每次合併k個Runs成一個Run(假設有用[Selection Tree](Selection%20Tree.md)加速)
-> 每次合併花O(k*n/m*log₂k)

有m/k組k-way merge
每一回合(層）之時間
= m/k * O(k*n/m*log₂k)
= O(nlog₂k)

高度 = ⎡logk m⎤+1
回合數 = 高度-1 = ⎡logk m⎤
而要做*`⎡logk m⎤`回合完成排序*

Total Time 
~= logkm\*O(nlog₂k)
= O(nlogkm*log₂k)
= O(nlog₂m)
```