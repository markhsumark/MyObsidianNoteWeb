~~(Test-and-Set做修改)~~
>定義：
> ```C
> int Compare_and_swap(int *value, int expected, int new_value){  
> 	int temp = *value;  
> 	if(*value == expected)  
> 		*value = new_value;  
> 	return temp;  
> }  
> ```

**_  
如果*value == expected 則*value改為new_value  
否則不動  
一律傳回*value舊值_**

## Algo1 #❌ 

```C
while(true){
	while(compare_and_swap(&Lock, 0, 1) != 𝜙 );
	C.S.
	Lock=𝜙
	R.S.
}
```

分析：
- Mutual exclusion :OK
- Progress：ＯＫ
- ==Bounded waiting 違反==
  若Pi離開C.S後又想進入C.S，**Pi有可能先於其他processes再度進入C.S**  
  =>[starvation](../CH4%20Process%20Management%20&%20Tread%20Management/starvation.md)

## Algo2 #✅ 


[Test-and-Set的Algo2換成用compare-and-swap](Test-and-Set.md#Algo2%20✅)