---
date created: 2022-12-14 21:04
date updated: 2022-12-14 21:12
---

#### Test-and-Set

是*privilege instruction*

~~傳回target舊值，target設為true~~

```C
boolean test_and_set(boolean *target){  
	boolean rv = *target;  
	*target = true;  
	return rv;  
}
```

##### Algo1 #❌

```C
while(true){
	while(test_and_set(&Lock)){ };
	C.S
	Lock = False;
	R.S.
}
```

**分析：**

- Mutual exclusion :OK
- Progress：ＯＫ
- Bounded waiting 違反
  若Pi離開C.S後又想進入C.S，==Pi有可能先於其他processes再度進入C.S==
  =>[starvation](../CH4%20Process%20Management%20&%20Tread%20Management/starvation.md)

##### Algo2 #✅

> 思路：
> 先搶test-and-set 先進，隨機、公平
> 自己進入C.S後改為沒有需求
> 找下一位（不是自己 -> 避免[Starvation](../CH4%20Process%20Management%20&%20Tread%20Management/starvation.md) -> 避免Bounded waiting
> 改變下一位的wait值，若沒其他人且自己有需求，拿回鑰匙

```C
do{
	waiting[i] = True
	key = True;
	while(waiting[i] and key){
		key= Test-and-set(&Lock);
	}
	waiting[i] = False //避免第一個進入的process造成progress
	//...
	C.S.
	...//
	//找到下一個(並非隨機，是往下選）想進入C.S的process
	j = (i+ 1)% n;
	while(j!= i and !waiting[j]){
		j =(j+1)%n
	}
	//若有人想進，給他。否則再把鑰匙給自己
	if(j == i)then Lock = False;
	else waiting[j] = False; //->Pj離開while進入C.S
	R.S
}
```

EX:移除

```ad-question
title:思考。移除“waiting[i] = False;” C.S. 會正確嗎

**不正確！！**

第一個進入C.S的process可能會被誤認為「想進入」
已違反Progress。無故佔用資源＆Deadlock(Lock是True)
```

**分析：**

- Mutual exclusion :OK
  ```ad-note
  title:說明
  Pi要進入C.S要滿足兩條件**_之一_**
  - case1: Key == False  
  代表是**第一個搶到Test-and-set執行之process**，才能將key改為false，否則key仍為True  
  **=> 唯一性**
  - case2: waiting[i] == False  
  Pi自己不會將自己的waiting[i]改成false before進入C.S，**只有仰賴從C.S離開的Process才有資格改別人的waiting，且C.S只有一個process  
  =>唯一性**
	```
	
- Progress：ＯＫ
    ```ad-note
  title:說明
  (i)若Pi不想進入->waiting[i] = false->不會爭奪test-and-set的執行  
  (ii)若多個Process想進入c.s則在有限的時間內必有一個Process之key或waiting[i]被改為false而進入c.s  
  -> no deadlock
  ```
- Bounded waiting :OK
  ```ad-note
  title:說明
  - 若P0~Pn-1皆想進入C.S。  
    假設P0進入c.s，**Lock=True->其他人不能進入c.s**
  - 當P0離開後，**一定會改變下一個（其他）想進入c.s的Process之waiting[i]為False**.**->P1進入**
  - 以此類推，每個Process最多等n-1個就能進入c.s
  =>no [starvation](../CH4%20Process%20Management%20&%20Tread%20Management/starvation.md)
```