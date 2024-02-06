## Extended Master Theorem
若`T(n) = aT(n/b)+n^(log_b a * log^k n)`，或f(n)/n^(log_b a) = (log n)^k，
則Extended Master Theorem，否則master theorem case 3
- #### EX:
	
	```txt
	(1)
	T(n) = 2T(n/2) + nlogn
	Ans:
		n^(log_b a) = n^1
		而f(n)/n^(log_b a) = logn, k = 1
		Extended.M.T => 𝝷( n(logn)^2 )
		```	

![500](img/截圖%202022-09-15%20下午8.50.01.jpg)
## 例外情況（不能用master theorem）

T(n) = 2T(n/2)+n/log n 