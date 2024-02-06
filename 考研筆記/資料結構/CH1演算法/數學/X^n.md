---
date created: 2022-09-14 10:52
---

## X^n

- 慢速

```C
int exp(n){
	if(n == 0)return 1;
	else
		return exp x*exp(n-1);
}
```

- 加速：

> X^2 = X  (X^2)^n/2, if n是奇數
> X^2 = 1  (X^2)^n/2, if n是偶數
