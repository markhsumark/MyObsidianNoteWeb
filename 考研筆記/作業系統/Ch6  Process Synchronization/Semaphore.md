---
date created: 2022-12-26 23:37
---

Semaphore(號誌）

> 定義：
> synchronization **tool** that provides more sophisticated way(than [mutex lock](mutex%20lock.md)) for process synchronize their activities.
>
> ->semaphore 是一個data type，若S為semaphore type 變數，則S是一個==integer==，且在S上會提供2個**"atomic" operations :** 
>
> - **_[wait](wait.md)(S)_**
> - **_[signal](signal.md)(S)_**

### 用於C.S design

`共享變數宣告。semaphore mutex = 1;(初值)`
P𝒾程式如下

```C
while(True){
	wait(mutex);
	C.S.
	signal(mutex);
	R.S.
}
```

### synchronization problem

何為sync? ==互相協作時，因為某事件發生/未發生，而被迫停頓==

> 一群cooperating processes/Threads 在執行中，弱process因為某事件發生/不發生 而被迫wait，等其他processes do something 才可往下執行

simple problem

> Pi中的A必須在Pj中的B先執行完成此要求

```C
//Pi
A;
signal(S);
//------
//Pj
wait(S);
B;
```

### semaphore誤用所造成之問題

> 導致違反mutual exclusion 或形成deadlock

```ad-example
title:例1 (違反互斥)
~~~C
	semaphore mutex = 1;
	signal(mutex)
	C.S.
	wait(mutex)
	R.S.
~~~
```

```ad-example
title:例2(deadlock)
~~~C
	wait(mutex);
	C.S
	wait(mutex);
~~~
```

```ad-example
title:例3 (可能形成deadlock)
~~~C
S1 = 1, S2  = 1
Pi(){
	wait(S1)
	wait(S2)
	...
	signal(S1)
	signal(S2)
}

Pj(){
	wait(S2)
	wait(S1)
	...
	signal(S2)
	signal(S1)
}
~~~
```

[Liveness](Liveness.md)

### 種類

#### [Binary Semaphore](Binary%20Semaphore.md)

#### [Counting Semaphore](Counting%20Semaphore.md)

#### [non-busy waiting semaphore](non-busy%20waiting%20semaphore.md)

### 製作

[Race condition 兩大策略](Ch6%20%20Process%20Synchronization.md#Race%20condition%20兩大策略)
**分析**

| -                 | [non-busy waiting semaphore](non-busy%20waiting%20semaphore.md) | Busy waiting semaphore |
| ----------------- | --------------------------------------------------------------- | ------------------------------------------------------- |
| Disable interrupt | Algo1                                                           | Algo2                                                   |
| C.S. Design       | algo1的interrupt 換成entry/exit section                            | algo2的interrupt 換成entry/exit section                    |

```ad-note
title:Algo1
~~~C
signal(S):  
    "Disable interrupt"  
    S.value = S.value+1;  
    if(S.value <= 0)then{  
		remove process P from S.Q  
		Wakeup(P); // sys. call 用以將Ｐ移到ready state  
    }  
    "Enable interrupt"
    
wait(S):  
    "Disable interrupt"S.value = S.value-1;  
    if(S.value < 0)then{  
		add process P into S.Q  
		Block(P); // sys. call 用以將Ｐ移到wait state  
    }else{  
		"Enable interrupt"
	}
~~~
```

```ad-note
title:Algo2
~~~C
signal(S):  
	"Disable interrupt"  
    S = S +1  
    "Enable interrupt"
wait(S):  
    "Disable interrupt"  
    while(S<= 0){  
		"Enable interrupt"  
		"Disable interrupt"  
    }  
    S = S-1;  
	"Enable interrupt**
~~~
```

**結論：**

> non-busy waiting並不能完全避免busy waiting

down 到製作層次

1. 看不到B. waiting
   -> 但不適用於multiprocessors且風險高
2. C.S desgin:
   Entry code中皆是B. waiting
   -> 沒有辦法避免B. waiting
