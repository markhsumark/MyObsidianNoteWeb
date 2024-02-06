---
date created: 2022-09-14 10:52
---

## Binomial coe.

~~C幾取幾~~
- Q1:
  - Ans:
    ```C
    int Bin(int n, int m){
    	if(m == 0 || n == m)return 1;
    	else return Bin(n - 1, m)+Bin(n-1, m-1);

    }
    ```
- Q2:依上述Code求Bin(5, 3)值和呼叫次數：
  - Ans:
    T(n, m) = T(n-1, m-1)+T(n-1, m)+1
    T(1, 0) = 1
    T(0, 0) = 1
- Q3(極少考):Design Iterative or Dynamic programing 求C(n, k)=?
  - Ans:
  ```C
  int Bin(int n, int k){
  	int c[n+1][k+1];
  	for(int i = 0; i<= n; i++){
  		for(int j = 0; j<=min(i, k);j++){
  			if(j==0||j==i)c[i][j] = 1;
  			else c[i][j]= c[i-1][j-1]+c[i-1][j];
  		}
  	}
  	return c[n][k];
  }
  ```
