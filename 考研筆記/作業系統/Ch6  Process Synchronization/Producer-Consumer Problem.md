---
date created: 2022-12-25 21:07
date updated: 2022-12-25 21:22
---

> **描述：**
>
> - Producer: 生產資訊給別人使用之processes
> - Consumer:消耗/使用 生產者產出之資訊的process
>
> 在shared memory 溝通方式下，雙方會共用一個buffer
>
> Bounded Buffer
>
> - 當buffer沒有空格，則Producer被迫wait
> - 當buffer沒有資料，則Consumer被迫wait
>
> unBounded Buffer
>
> - Producer不會被迫等待
> - if no data ,consumer wait

# 原始程式

> 共享變數：
> Buffer[0..n-1]
> in, out = 0
> count = 0
>
> Producer: count ++
> Consumer:count --
> ==但count可能有race condition問題==

**Producer**

```C
//Producer
while(true){
	"produce an item in nextp"
	while(count == N)
		{}; //producer wait
	buffer[in] = nextp;
	in = (in+1)%N;
	count ++;
}
```

**Consumer**

```C
//Consumer
while(true){
	while(count == 0)
		{};  //buffer 內沒有資料
	nextc = buffer[out];
	out = (out+1)%n;
	count--; //item 數少1
	"consume the item"
}
```

# 用Semaphore完成 #⭐️ 

==先測同步，再測互斥==
共享變數：

- **Buffer[0..n-1]**
- **in, out = 0**
- **semaphore mutex = 1;**
  作為buffer, in, out之互斥控制用，防止race condition
- **semaphore empty = n
  **代表buffer內==空格數(需不需要produce item)==，當empty = 0表示無空間（滿），卡住Producer之用
- **semaphore full = 0
  **代表Buffer內==item數==，當full = 0表示無item可取用->卡Consumer之用

**Producer**

```C
//Producer
while(true){
	"produce an item in nextp"
	wait(empty);//是否坐滿位子
	wait(mutex);//搶奪buffer的使用權
	"add nextp into Buffer"
	signal(mutex):
	signal(full);  // item已填入buffer，可救/供給Consumer
}
```

**Consumer**

```C
while(true){
	wait(full);//等待資源
	wait(mutex);//搶奪buffer（才可以使用）
	"retrieve an item in nextc from buffer"
	signal(mutex);
	signal(empty);// 消耗掉item，讓producer有空間可以製作
	"consume the nextc"
}
```

```ad-example
title:若將Producer or Consumer其中一個（或雙方）process，將前面兩個wait對調，依舊正確嗎？Why?
錯：可能產生Deadlock。一人搶走mutex，等待資源/空間，另一人在等著使用mutex，以填入/拿出data
```

# 號誌變數之思考(取決於用途)

滿足同步條件之用

- empty
- full

防止共享data之race condition（要mutual exclusion之用）

- Buffer
