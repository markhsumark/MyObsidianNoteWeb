OBST(optimal BST)

#⭐️⭐️⭐️⭐️⭐️

> 定義：給予n個內部Nodes加權值:
>
> - pi, 1<=i<=n
> - qj, 0<=j<=n
>
> 則在所有不同的BST中，具有==最小的搜尋總成本_之BST==稱為[OBST](../../演算法/CH3%20Dynamic%20Programming/CH3%20Dynamic%20Programming.md#3.5%20Optimal%20binary%20search%20trees)

**成功成本**
內部Nodei之level＊pi(i = 1~n)

**失敗成本**
外部Nodej之level＊qj(j = 0~n)

### 使用Dynamic Programming求出OBST成本及結構

[CH3 Dynamic Programming's OBST](../../演算法/CH3%20Dynamic%20Programming/CH3%20Dynamic%20Programming.md#%203.5%20Optimal%20binary%20search%20trees)

1. [D.P方法](../../演算法/CH3%20Dynamic%20Programming/CH3%20Dynamic%20Programming.md#3.1%20Introduction)
2. 假設：
   - T[i, j]表由 a[i+1]~a[j] 所組成的OBST
   - C[i, j]代表T[i, j]的ESC。~~演算法中的s[i, j]的功能~~
   - W[i, j]代表T[i, j]內 外部nodes weights加總
   - r[i, j]表T[i, j]之Root No.

==C[i, j] = W[i, j]+ min{C[i, k-1]+C[k, j]}==

### 與演算法版本的差異

- 失敗成本的定義不同。在演算法中，失敗node的level沒有-1
  _**解法：Algo答案 = 資結答案 + 外部加權值總和**_
- T[i, j]在兩個版之間不同

```ad-attention
title:所以考試時必須先定義所有公式，可以的話重新推導
```