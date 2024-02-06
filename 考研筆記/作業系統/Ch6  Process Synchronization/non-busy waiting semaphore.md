~~放到ready queue~~

>不用互斥所&用Block, wakeup替代互斥所 的[Counting Semaphore](Counting%20Semaphore.md)
>將semaphore變成一個struct type 如下：  

```C
struct semaphore{  
	int value;  
	Queue Q;  
};
```

![](../../img/截圖%202022-12-25%20下午8.40.53.jpg)

down 到製作層次
1. 看不到B. waiting
	-> 但不適用於multiprocessors且風險高
1. C.S desgin:
	Entry code中皆是B. waiting
	-> 沒有辦法避免B. waiting