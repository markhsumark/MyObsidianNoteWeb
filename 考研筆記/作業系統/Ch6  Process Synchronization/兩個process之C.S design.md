
#### Algo1 #❌

> 效果：Pi, Pj要一直輪流進入C.S才可運作，否則容易卡住

```ad-note
title:共享變數宣告
int turn;
初值為i or j
意義：ture 值為誰，誰就有資格進入C.S
```

```C
Pi:
repeat {
	while (turn!= i){do no-op;}
	C.S
	turn = j;
	R.S
}until False;
```

```C
Pj:
repeat {
	while (turn!= j){do no-op;}
	C.S
	turn = i;
	R.S
}until False;
```

**分析：**

- Mutual exclusion :OK
- Progess違反(i)
- Bounded waiting : OK

#### Algo2 #❌

> Ａ會讓B用完在給自己用。彼此會互相禮讓，導致沒人能進C.S

```ad-note
title:共享變數宣告
Flag[i..j] of Boolean;
初值皆為false
意義：True：有意願/False：沒有意願
```

```C
Pi:
repeat {
	flag[i] = True;//表明意願
	while (flag[j]){do no-op;}//若對方想進，我等
	C.S
	flag[i] = False
	R.S
}until False;
```

```C
Pj:
repeat {
	flag[j] = True
	while (flag[i]){do no-op;}
	C.S
	flag[j] = False;
	R.S
}until False;
```

**分析：**

- Bounded waiting : OK
- Progress違反：
  若兩個process同時都有意願進入C.S，則產生**Deadlock**
- Mutual exclusion :OK
-

#### Algo3: Peterson solution #✅

> Algo1 + Algo2
>
> - 同時，權杖（turn）在自己身上=> run C.S
> - 若有人有意願則有機會進入，但不會是上一個執行過的（因為會把trun交給別人）
> - Turn 只是用於爭奪優先

```ad-note
title:共享變數宣告
Flag[i..j] of Boolean;
初值皆為false
意義：True：有意願/False：沒有意願
int turn;
初值為i or j
意義：ture 值為誰，誰就有資格進入C.S
```

```C
Pi:
repeat {
	flag[i] = True;//表明意願
	turn = j;//禮讓對方
	while (flag[j] && turn == j){do no-op;}//若對方想進且權杖在對方身上=>等
	C.S
	flag[i] = False;//表明無意
	R.S
}until False;
```

```C

Pj:
repeat {
	flag[j] = True;
	turn = i;
	while (flag[i] && turn == i){do no-op;}
	C.S
	flag[j] = False;
	R.S
}until False;
```

**分析：**

- Mutual exclusion :OK
  若雙方想進入C.S，執行到while時，表示雙方皆分別執行過「turn = j」,「turn = i」（差別只是先後順序有別而已）。
- Progress：OK
  - (i) 假設Pi不想進C.S（flag[i] == False, turn == i）\
  若此時Pj 想進C.S，因為Ｐi不想進->Pj可進入
  - (ii) 若Pi, Pj都想進入C.S，由於權杖(turn)必定會在其中一人身上->必有一位可進入C.S
- Bounded waiting : OK
  假設雙方皆想進C.S
  另turn = i，Pi先進\
  若Pi離開後又立刻想要進入C.S，則**Pi必定會將turn交給Pj\
  =>不會讓Pj [starvation](../CH4%20Process%20Management%20&%20Tread%20Management/starvation.md)

```ad-attention
title:缺點
collapse:none
上述程式雖符合C.S. design 之正確性，但peterson's solution在現代電腦架構中，不保證正確。
ex:為了improve sys. performance，processors and/or compiler may reorder read and write operations that have no dependencies，然而，這種reordering of instructions may suffer inconsistency or unexpected result。
compiler 可能對調(reordering)沒有相關性的程式碼以達到最佳化->對peterson's algo是致命的
所以我們應該要合理的使用其他同步處理方法（硬體...)
```
