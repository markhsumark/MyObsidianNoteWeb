```ad-example
write an algo. 判斷輸入的"("及")"字串*是否為正確的括號配對*，若正確回傳yes，反之No.

> 若")"數目 > "("數目 => 必錯
> 其他："(" ")"數目不同 => 必錯
~~~C
while(還未掃完input){
	x = NextToken()
	if(x == "("){
		push(S, x);
	}
	else{
		if(IsEmpty(S)){
			then return "NO";
		}else{
			pop(S);
		}
	}
}
if(IsEmpty(S)) return "Yes";
else return "No";
~~~
```