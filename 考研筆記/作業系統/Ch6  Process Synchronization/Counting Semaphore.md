---
date created: 2022-12-25 20:32
date updated: 2022-12-25 20:36
---

> 定義：
>
> - 號誌值不限0, 1
> - **可以是負值**
> - 且若值為 -N代表有N個processes卡在wait中

## 使用 [Binary Semaphore](Binary%20Semaphore.md)製作

共享變數宣告：

1. int C;
2. Binary-Semaphore S1 = 1;\
   對C做互斥存取，防止C的data race
3. Binary-Semaphore S2 = 𝜙\
   卡住process用，if C < 0

![](../../img/截圖%202022-12-25%20下午8.32.44.jpg)
