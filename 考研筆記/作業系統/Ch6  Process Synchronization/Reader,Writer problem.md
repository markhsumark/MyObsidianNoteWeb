---
date created: 2022-12-25 21:25
date updated: 2022-12-25 21:37
---

> - reader:只會reading共享data之process
> - writer:會更新/寫入共享data值之process
>
> 基本的同步條件
>
> - writer &reader之間要互斥
> - writer & writer之間要互斥
> - reader 之間不用互斥

# First #⭐️⭐️⭐️⭐️⭐️

~~reader 有利~~

> 對reader有利，writer不利\
> ->writer可能starvation
>
> if有reader is reading, 又來了一個reader，則下一個reader也進去reading，==直到沒有reader，writer才能進去==

## 程式

> reader(第一個）一進去就先卡writer

共享變數：

- **semaphore wrt = 1;**
  作為R/W及W/W互斥控制用，此外兼作
- **int readcnt = 0**
  統計目前reader個數
- **semaphore mutex = 1;**
  對==readcnt存取之互斥控制==，防止他race condition

**Writer**

```C
...
wait(wrt);
執行writing;
signal(wrt)
...
```

**Reader**

1. readcnt++(要先[mutex lock](mutex%20lock.md))
2. 檢查是否是第一個，是的話wait(wrt)

```C
...
wait(mutex);
readcnt = readcnt + 1;
if(readcnt == 1){    //成立表示你是第一個reader
	wait(wrt);   
	//若是有wrt，則會卡在這裡等當下的wrt完成，在設立阻擋
}
signal(mutex);
"執行Reading"
wait(mutex)
readcnt = readcnt - 1
if(readcnt == 0){   //自己是最後一個reader才能釋放
	signal(wrt)
}
signal(mutex)
...
```

# Second #⭐️⭐️⭐️⭐️ 

~~writer有利~~

> 對writer有利，reader不利\
> ->reader可能starvation
>
> writer優先於reader（即使reader比較早進來等）

## 程式

> 1. +1
> 2. 築牆（不讓reader進入）
> 3. w/w互斥，然後執行
> 4. if沒有writer了，解除阻擋

共享變數：

- **int readcnt = 0**
  統計目前reader個數
- **semaphore mutex = 1;**
  對readcnt存取之互斥控制，防止他race condition
- semaphore wrt = 1;
  作為R/W及W/W互斥控制
- int wrtcnt = 0;
  統計writer個數
  writer到 -> 加1, writer走 -> -1
- semaphore ==y== = 1;
  對wrtcnt之互斥控制防止race.
- semaphore ==rsem== = 1;
  對Reader不利之阻擋
- semaphore ==z== = 1;（可有可無）
  reader之入口控制
  目的：多卡一關，delay reader's speed

**Reader**

```C
wait(z);
wait(rsem);   //可否通過對reader不利之阻擋
wait(mutex);
readcnt = readcnt + 1;
if(readcnt == 1)
	wait(wrt);
signal(mutex);
signal(rsem);
signal(z);
"執行reading"
wait(mutex);
readcnt = readcnt - 1;
if(readcnt == 0)
	signal(wrt);
signal(mutex);
```

**Writer**
注意y的位置

```C
wait(y);
wrtcnt = wrtcnt + 1;
if(wrtcnt == 1){
	wait(rsem)  //築起對reader不利之阻擋
}
signal(y);
wait(wrt);   // w/w互斥
"執行writing"
wait(y);
wrtcnt = wrtcnt - 1;
if(wrtcnt == 0){  //沒有writer，解除阻擋
	signal(rsem);
}
signal(wrt);
signal(y);
```
