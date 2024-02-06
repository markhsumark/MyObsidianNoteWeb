---
date created: 2022-10-19 16:42
date updated: 2022-10-25 19:44
---

# CH7 Search and Sort

## Search

### Linear Search

從左到右一一搜尋直到找到為止or找不到為止

### Binary Search #⭐️⭐️⭐️

> 資料必須事先排序
> 資料須保存於[Random(Direct) Access](../../作業系統/CH9%20Disk%20Management/Random(Direct)%20Access.md)機制上

O(logn)

## Sort

### 名詞解釋

#### internal v.s. External sorting

可否一次全部放在記憶體內。常見的外部排序方法，[Merge sort](#Merge%20sort),[m-way search tree](../CH9%20Advanced%20Tree/CH9%20Advanced%20Tree.md#m-way%20search%20Tree) , [B Tree](../CH5%20Tree%20and%20Binary%20Tree/CH5%20Tree%20and%20Binary%20Tree.md#Binary%20tree), B+ Tree等

#### stable & unstable sorting方法 #⭐️⭐️⭐️

>通常Input data中常會有*一些具有相同鍵值的資料*，若A, B, C, ...經過排序(過程中）後仍為A, B, C, ...，則稱此方法為Stable，否則Unstable

- Stable: [Insertion Sort](#Insertion%20sort), [Bubble Sort](#Bubble%20sort), [Merge Sort](#Merge%20sort), Radix sort, Bucket sort, counting sort
- Unstable: [Selection sort](#Selection%20sort), Shell, Quick, Heap sort

==Unstable會比Stable多了不必要的交換==
==不代表Unstable比較差==

#### sorting in-place #⭐️⭐️

>An in-place algorithm is an algorithm that does not need an extra space and produces an output in the same memory that contains the data by transforming the input 'in place'
>=> 排序過程中會不會利用到額外空間(包含遞迴的stack)

高等以及初等排序方法中，==_只有[Merge Sort](Merge%20Sort.md)不是sorting in-place_==，其餘都是。
但若不考慮遞迴的stack空間，Quick Sort也是 in-place

### 初等排序

==都是屬於Comparison-based==

#### [Insertion sort](Insertion%20sort.md)

~~將每個元素依序丟入，元素會「落」到對應的位置~~

#### [Selection sort](Selection%20sort.md)

~~找出剩餘集合中最小的，往前放~~

#### [Bubble sort](Bubble%20sort.md)

#### [Shell sort](Shell%20sort.md)

==少考==

### 高等排序 #⭐️⭐️⭐️⭐️

#### [Quick Sort](Quick%20Sort.md)

==最快速==
~~跟pivot key比大小，往左右堆起來，然後pivot塞中間。~~

#### [Merge Sort](Merge%20Sort.md)

#stable

##### [Selection Tree](Selection%20Tree.md)

#### [Heap Sort](Heap%20Sort.md)

### 排序可以達到多快？ #⭐️⭐️⭐️⭐️

1. 在限定使用*"Comparison-based" skill，則最快𝝮(n log n)*

```ad-quote
title:初等及高等排序皆是Comparison-based
```

2. 若果_未限定_使用此技巧，則排序時間有_可能達到linear time: O(n)_

```ad-question
title:Any sorting method 最快可達𝝮(nlogn)? Ans :False
```

```ad-question
title:Any sorting method that based on Comparison, 最快可達𝝮(nlogn)? Ans :True
```

#### 證明
```txt
總排序有n!種
Decision Tree 高度必≧⎡log(n!)⎤+1
->比較次數≧⎡log(n!)⎤ ~= nlogn
𝜴(n log n)
```


![300](../img/截圖%202022-10-24%20下午3.39.38.jpg)
由上述Desision Tree知

1. It's a Binary Tree
2. Non-Leaf 表_比較_Node
3. Leaf表某_排序結果_
4. n個Data之排序可能結果有n!種
5. 最多比較次數=高度-1

證明：

> n個Data做Sorting, 有n!個可能的排序結果，以描述比較過程的Desision Tree而言，即有n!個Leaves，他又是Binary Tree，_高度至少 >= ⎡log(n!)⎤_
> 比較次數 = 高度-1 >= ⎡log(n!)⎤ >= c n logn -> 𝝮(n log n)

```ad-question
title:5個Data以Comparison-based skill doing sorting，最少比較次數?
不可用nlogn = 5log₂5
要用⎡log(n!)⎤  = ⎡log(5!)⎤ =7
```

==雖然題目是說「最少」，但通常依然使用⎡log(n!)⎤==

### 線性時間排序

==這裡的都是屬於Counting-based==

> Linear-Time Sorting methods
> 當排序技巧並非採用Comparison-based, 則有機會_突破𝝮(nlogn)限制，來到O(n)time_

| DS版本                | Algo版本      |
| ------------------- | ----------- |
| [LSD Radix Sort](LSD%20Radix%20Sort.md)      | [Radix Sort](Radix%20Sort.md)  |
| [MSD Radix Sort](MSD%20Radix%20Sort.md)      | Bucket Sort |
| [Counting Sort](Counting%20Sort.md)       | Count Sort  |
| Radix = Bucket sort |             |

#### [Radix Sort](Radix%20Sort.md)

#### Buckets Sort(也就是DS中的[MSD Radix Sort](MSD%20Radix%20Sort.md))

#### [Counting Sort](Counting%20Sort.md) 
~~限制0~k排序，記錄出現次數，姐此找出出現起始位置~~

### 比較表

| .                                     | Best Time   | Worst Time | Avg. Time | Space        | stable/unstable |
| ------------------------------------- | ----------- | ---------- | --------- | ------------ | --------------- |
| [Insertion sort](Insertion%20sort.md) | _O(n)_      | O(n²)      | O(n²)     | O(1)         | S               |
| [Selection sort](Selection%20sort.md) | O(n²)       | O(n²)      | O(n²)     | O(1)         | U               |
| [Bubble sort](Bubble%20sort.md)       | _O(n)_      | O(n²)      | O(n²)     | O(1)         | S               |
| [Shell sort](Shell%20sort.md)         | _O(n^(2/3)_ | O(n²)      | O(n²)     | O(1)         | U               |
| [Quick Sort](Quick%20Sort.md)         | O(nlogn)    | _O(n²)_    | O(nlogn)  | O(logn)~O(n) | U               |
| [Merge Sort](Merge%20Sort.md)         | O(nlogn)    | O(nlogn)   | O(nlogn)  | O(n)         | S               |
| [Heap Sort](Heap%20Sort.md)           | O(nlogn)    | O(nlogn)   | O(nlogn)  | O(1)         | U               |

|                                           | Time       | Space  | stable/unstable |
| ----------------------------------------- | ---------- | ------ | --------------- |
| [Radix Sort/Bucket Sort](Radix%20Sort.md) | O(d*(n+r)) = O(n) | O(r*n) | S               |
| [Counting Sort](Counting%20Sort.md)       | O(n+k)     |   O(n+k)     | S               |

### 演算法補充

### Find min max #⭐️

#### [法ㄧ]

steps:

1. 先經過`(n-1)`次比較後，即可找到min
2. 在剩下(n-1)個Data中，再經過`(n-2)`次比較即可找到Max

`總共比較次數=(n-1)+(n-2) = 2n-3次`

```ad-question
title:有沒有其他方法，比較次數< 2n-3 ?
```

#### [法二]

steps:
1. 比較A[1], A[2] 1 次及可知誰小誰大（不失一般性令A[1]小）
2. 遞迴針對剩下(n-2)個data，找出min (x) & Max (y)
3. 比較A[1]與x 1次，即可知道整體的min;比較A[2]與y 1次，即可知道整體的Max
```txt
T(n) = T(n-2)+ 3, T(0) =0, T(1) = 0, T(2) = 1
T(n) = 3n/2 < 2n-3 當n很大
```


### Selection problem #⭐️⭐️⭐️

n個unsorted data 找出第i小的data

#### [法一]
steps: 
1. 將n個data做Sorting
2. return Array[i];

Total time = O(nlog n)
```ad-question
title:有沒有其他方法在O(n) Avg time 達成? 
```

#### [法二]

利用[Quick Sort](Quick%20Sort.md)中的==Partition==副程式

**Algo**
```C
Select(A[], p, r, i){
	//在A[p]~A[r]中找出ith小元素
	if(p<r){
		q = Partition(A, p, r);
		k = q-p+1; //pk是A[p]~A[r]中kth 小的data
		if(i==k)return A[q]
		else if(i<k)return Select(A, p, q-1, i);
		else return Select(A, q+1, r, i-k); //i在q右邊
	}
}
```

Time 分析:
1. Best case:完美分兩半
   T(n) = T(n/2)+O(n) 
   -> T(n) =`O(n) or 𝝷(n)`
2. Avg. case:`O(n)`
3. Worst case: 切割沒有效果（若pk剛好是最大or最小值）
   -> `O(n²)`

#### [法三]
[The Selection algorithm](../../演算法/CH2%20Divide-and-Conquer/CH2%20Divide-and-Conquer.md#The%20selection%20algorithm)
希望可以在Worst case下，找ith 小元素可以在O(n)time完成

**原則：慎選pk**
先前：
1. middle-of-three
2. ***以"median-of-medians"為pk***進行切割

```C
Select(A, p, r, i){
	1. data切割成⎡n/5⎤個groups，每個group內有5個data（最後一個group可能不到5個）//O(n)
	2. 每個group各自排序好//T(⎡n/5⎤)*O(1) = O(n)
	3. 取每一個group的3th資料（中間），在這些中間值中找出中間值，以它作為pk。//T(⎡n/5⎤)
	q = Partition(A, p, r) //O(n)
	k = q-p+1;
	if(i == k)return A[q];
	else if(i<k)return Select(A, p, q-1, i);
	else return Select(A, q+1, r, i-k);
}
```

Time: 
T(n) = O(n)+O(n)+T(⎡n/5⎤)+O(n)+ T(⎡7n/10⎤+6)
-> T(n) = T(⎡n/5⎤)+O(n)+ T(⎡7n/10⎤)
~= T(n/5)+ T(7n/10)+ cn
<= cn\*常數 -> O(n)

```ad-quote
title: 也可以7, 9, ...個一組，唯獨不能<5個為一組(會變成O(nlogn))
```
```ad-attention
title:若每個group元素數量 = 3，T(n)= ?
![500](../img/截圖%202022-10-25%20下午9.14.47.jpg)
```