---
date created: 2022-12-25 21:55
date updated: 2022-12-25 22:05
---

> 描述：
>
> - 有5位哲學家P0~P4吃晚餐，坐在圓桌，坐一圈
> - 兩兩哲學家之間放”一根“筷子
> - 哲學家必須取得左右兩塊子才能吃飯
> - 吃完放下筷子，進入thinking

```ad-attention
title:錯誤solution
~~~C
P𝒾（第i號哲學家）
while(true){
	hungry now;
	wait(chopstick[i]);
	wait(chopstick[(i+1) % 5;]);
	eat now;
	signal(chopstick[i]);
	signal(chopstick[(i+1) % 5;]);
	think now;
}
~~~
此soluton有誤因為可能發生deadlock，如果每位哲學家只取得左邊的筷子，則沒有一位可以拿到右邊的筷子
```

# 正確solution

## solution[法一]

~~限制同一時間拿筷子的人數~~

```ad-note
title:說明
若有5位哲學家，則至多允許4個哲學家上餐桌  
定理：
-   m = 5（根） MAX𝒾 =2
-   條件
    1.   1 <= MAX𝒾 <= m
    2.   MAX𝒾總和< n+ m

==控制總人數要<n==
```

```C
//P𝒾（第i號哲學家）
semaphore No = 4
wait(No);
hungry now;
wait(chopstick[i]);
wait(chopstick[(i+1) % 5]);
eat now;
signal(chopstick[i]);
signal(chopstick[(i+1) % 5]);
signal(No);
think now;

```

## solution[法二]

~~一次拿一雙筷子~~

```ad-note
title:說明
規定==“除非可以同時拿到兩隻筷子，才允許持有，否則不可持有任何筷子”==。  
->==破hold-and-wait==
```

## solution[法三]

~~偶數先拿右，奇數先拿左~~

```ad-note
title:說明
規定：”==偶數號==折學家，先取左邊的快子，再取右筷；奇數好相反“  
->破除circular waiting
```
