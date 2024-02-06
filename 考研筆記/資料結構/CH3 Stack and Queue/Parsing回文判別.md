```ad-example
write an algo 判斷輸入的字串是否符合回文
> 除以2
~~~C
n = string長度
for(int i=0; i<n/2; i++){
	x = Token(S);
	push(S, x);
}

if(n % 2 == 1) x = Token(S); //多抓一個，並忽略他

for(int i=0; i<n/2; i++){
	x = Token(S);
	y = pop(S);
	if(x != y)
		return "NO";
}
return "Yes"
~~~
```
Time: O(n)