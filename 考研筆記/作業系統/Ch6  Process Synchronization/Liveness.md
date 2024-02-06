
>process may have to wait indefinitely while trying to acquire a synchronization tool such as a [mutex lock](mutex%20lock.md) or semaphore waiting indefinitely violates the progress and bounded-waiting crteria  
>
>**所以 Liveness**: refers to a set of properties that a system must satisfy to ensure processes make progress 而indefinite waiting is an example of a "Liveness failure"  

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

例：上述之deadlock case   
例：starvation 也是失敗之例