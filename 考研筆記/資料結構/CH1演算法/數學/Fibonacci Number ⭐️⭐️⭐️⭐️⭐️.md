---
date created: 2022-09-14 10:52
---

## Fibonacci Number ⭐️⭐️⭐️⭐️⭐️

- 定義：
  - > 0 , if n = 0
    1 , if n = 1
    F(n-1)+F(n-2), if n>= 2

- 例：求<=500之最大費式數Fa。Fa = ?, a = ?
  F(14)

- Q1:Write a _Recursive_ Algo of  Fn

  > O({n在指數})

  ```C
  int Fib(int n){
  	if(n == 0)return 0;
  	if(n == 1)return 1;
  	return Fib(n-1)+ Fib(n-2);
  }
  ```

  _延伸：問次數_
  T(n) = T(n-1)+T(n-2)+1

- Q2:Write a _Iterative_ Algo of Fn
  > O(n)
  ```C
  int Fib(int n){
  	if(n == 0)return 0;
  	else if(n == 1)return 1;
  	else{
  		int a = 0, b = 1, c;
  		for(int i = 2; i<= n ; i++){
  			c = a + b
  			a = b;
  			b = c;
  		}
  		return c;
  	}
  }
  ```

- Q3:使用DP方法求Fn

  ```C
  	int A[n + 1];
  	int Fib(int n){
  		A[0] = 0;
  		A[1] = 1;
  		if (n == 0)return A[0];
  		else if(n == 1)return A[1];
  		else{
  			for(int i = 2; i<=n; i++){
  				A[i] = A[i-1] + A[i-2];
  			}
  			return A[n];
  		}
  	} 
  ```

  _延伸：問次數、個別被呼叫次數_：

> T(n)

```
=>T(n+1)+T(n+2), if n >= 1;
=>T(2), if n = 0
```

```ad-question
![](../../../img/截圖%202022-12-29%20下午6.38.32.jpg)
```