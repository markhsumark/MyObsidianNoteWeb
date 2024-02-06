---
date created: 2022-09-14 10:52
date updated: 2022-09-14 10:52
---

# Towers of Hanoi

> _河內塔_

- ## 規則
  - 每次只能移動一個盤子
  - 過程中，小盤不可在大盤之下
- ### Q1：設計一Recursive algo for Hanoi(n, A, B, C)
  - Ans:
    - code
    ```C
    void Hanoi(int n, char A, char B, char C){
    	if(n == 1)
    		printf("move disk %d from %c to %c \n", 1, A, C);
    	else{
    		// move n-1 plate form A to B
    		Hanoi(n-1, A, C, B);
    		// move 1 plate form A to C
    		Hanoi(1, A, B, C); // or printf("...")
    		// move n-1 plate in B to C
    		Hanoi(n-1, B, A, C);
    	}
    }
    ```
  - ### HW:四個盤子->15steps
  - ### Q2：令T(n)代表使用Hanoi法搬移n個盤子之次數，write down the recursive definition of T(n)。
    - > T(n) = T(n-1)+1+T(n-1) = 2T(n-1) + 1
    - > T(n) = 2^n -1
