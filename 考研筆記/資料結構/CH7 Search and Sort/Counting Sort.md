Counting Sort
#stable 

假設n= Data 個數, or 值域0~k
```ad-note
title:8個data, 值域:0~5，給 2, 5, 3, 0, 2, 3, 0, 3 實施Counting Sort
collapse:none
steps:
1. 統計各個值域之出現次數，紀錄在Count[0..k]中。
2. 求各鍵值知*未來排序好之起始位置*，紀錄在start[0..k]中
3. 依照各鍵值之start位置將，input data置入output array中的*正確位置*，且*對應的start加1*

![300](../img/截圖%202022-10-25%20下午6.44.07.jpg)
~~~C
for i = 0 to k
	count[i] = 0;
for i = 1 to n
	count[A[i]]++;
start[0] = 1;
for i = 1 to k
	start[i] = start[i-1] + Count[i-1]
for i=1 to n{
	output[start[A[i]]] = A[i];
	start[A[i]]++;
}
~~~~
```
分析：
- Time Complexity: O(k)+O(n)+O(k)+O(n) = `O(n+k)`
- Space Complexity: 額外空間需求-> Count[0..k], start[0..k]及output[1..n] ->`O(n+k)`

```ad-quote
title:為何TimeO(n+k)是linear time?
collapse: none
- 說法一
  若值域range 0~k而k是`O(n)等級`，則O(n+k) = O(n+O(n)) ∈ O(n)
- 說法二
  因為值域k受到限制，可視為常數c -> O(n)
```
```ad-question
collapse: none
title:經典問題(Counting Sort Bible問題)
已知O(n+k)是linear time if k belong to degree of O(n)
但是如果k belong to degree of O(n²)，則O(n+k) = O(n+O(n²)) != O(n)
請問是否仍可創造出linear time Sorting 呢？

---
Ans: True
![250](../img/截圖%202022-10-25%20下午6.58.36.jpg)
原則：利用[LSD](LSD%20Radix%20Sort.md)觀念
分成兩個回合完成排序
1. 以 `Data[i]%n` 為排序依據實施Counting Sort。因為值域在o~(n-1), k∈O(n)等級 -> 此回合花O(n+k) ∈O(n)等級
2. 以 `(Data[i]/n)%n`為排序依據且以1.之output為input實施Counting Sort。也是O(n)time

依據[LSD Radix Sort](LSD%20Radix%20Sort.md)的概念，加上Counting Sort is stable，所以可以排序正確結果
=> 這兩回合2 * O(n) time 仍為linear time

擴充：O(n^k) k>2 也可以創造linear time sorting
```