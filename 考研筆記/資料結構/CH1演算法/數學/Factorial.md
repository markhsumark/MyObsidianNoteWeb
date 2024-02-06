---
date created: 2022-09-14 10:52
---

- ## Factorial
  - Q1:write iterative Algo/Code
    - Ans:
    ```C
    int Fac(int n){
    	int s = 1;
    	int i;
    	if(n == 0)return 1;
    	else{
    		for (i=1; i<= n; i++)
    			s = s* i;
    		return s;
    	}
    }
    ```
  - Q2:write Recursive Algo/Code
    - Ans:_**KEY:記住數學定義的遞迴式**_
    ```C
    int Fac(int n){
    	if(n == 0)
    		return 1;
    	else{
    		return Fac(n-1)* n;
    	}
    }
    ```
