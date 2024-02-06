
https://hackmd.io/@vRN1CwEsTLyHOsG4mC0d4Q/B1xRTOC24

#⭐️⭐️
[Fibonacci Number ](../CH1演算法/數學/Fibonacci%20Number%20⭐️⭐️⭐️⭐️⭐️.md)

> 定義：是[Binomial Heap](Binomial%20Heap.md)之擴充版(懶惰版）。
> 除了Insert x, Delete-min, merge之外，增加：
>
> 1. Delete x
> 2. Decrease-key of a Node (Time: O(1)) #⭐️⭐️⭐️⭐️⭐️


| Insert                     | delete        | decrease-key                                          |
| -------------------------- | ------------- | ----------------------------------------------------- |
| `O(1)`                     | `O(logn)`  worst case:`O(n)`   | `O(1)`                                                |
| 刪掉之後，其subtree 往上放 | 刪除後，merge | decrease後，若不符合(min/max heap)規定，該subtree上移 |


**Delete x in Fib. Heap**

steps:

1. 若x = min, 則執行Delete-min運作
2. 否則，從所屬雙向link list中刪x，將x之各子樹之雙向link list 與roots間雙向link list串接，_具有相同高度之Binomial Tree不用合併_。

**Decrease-key of a Node**
（針對某點減少鍵值）

![400](../../演算法/img/截圖%202022-10-27%20下午2.49.57.jpg)
![](../../img/截圖%202023-01-10%20下午11.25.49.jpg)
O(1)