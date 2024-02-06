Atomic value

~~只要指定的變數不會Race condition就好~~

> 定義：
> provides atomic operations on basic data types such as integers and booleans.
> 用途：
> 例如Data Race on a single variable while it is begin updated
>
> ```ad-quote
> 通常CAS指令is not used directly to provide mutual exclusion. Rather, it is used as a basic building Block for construction other tools. That solve critical-section problem  
> e.g其中一個tool like atomic variable
> ```

使用CAS指令製作variable之例子

```C
//檢查v&temp的值是否相同
void increment(atomic_int *v){
	int temp;
	do{
		temp= *v;
	}while(temp!= CAS(v, temp, temp+1)
}
```

`若發生data race，CAS的結果會使得再跑一次回圈，使得temp重新讀取v的值(也就是其他process的結果使用data後的)，所以不會有複寫data的問題`
