---
date created: 2022-09-19 15:58
date updated: 2022-09-26 17:32
---

# CH3 Stack and Queue

## Stack

> 定義：是一個具有LIFO之有序串列
>
> - insert 元素動作要_Push_
> - delete 元素動作叫_Pop_
>
> 且push 和pop動作皆發生在同一端，稱為_Top_

### Stack 之應用

==(記)(選擇題)(課本p.95-96標題)==

（六）ADD
（9）反序
（10）迷宮
（12）Compiler剖析之一例，palindrome(迴文)之判斷
（13）八后問題

### [Stack 之ADT(Abstract Data Type)描述](Stack%20之ADT(Abstract%20Data%20Type)描述.md)

### [Stack之製作](Stack之製作.md)

## Stack permutation

> 定義：將n個Data _依序push 入stack_，但在過程中，可穿插執行_任意合法的pop輸出data_，依此rules，所有n個data之輸出排列組合，稱之

n個data stack permutations 數目=1/(n+1)*C(2n,n)

Note:公式也=![300](../img/image.jpg)

### stack permutation with n個data與下列問題同義

1. n個Node可以形成的不同binary tree 結構數目
2. n個"("與n個")"之合法配對數目
3. n+1個matrix相乘之乘法組合數目（algo.中)
   ![200](../img/image%201.jpg)
4. n部台車入閘再出閘之順序組合![200](../img/image%202.jpg)

Note:陷阱題

1. n 個matrix 相乘之乘法組合數？
2. n台車無法出車順序=？

## Infix, Postfix, Prefix

| 名稱       | Infix                 | Postfix       | Prefix     |
| -------- | --------------------- | ------------- | ---------- |
| 格式       |                       |               |            |
| 例子       | a+b,a-b               | ab+           | +ab        |
| Compiler | _不易_ ：處理式子必須考慮優先權、結合性 | _容易_  只需左右掃一次 | _容易_ 從右而左掃 |


### [括號法](括號法.md)

### Infix to Postfix(Using Stack)

```C
// key : stack只能越放越「大」
while(Infix 尚未由左而右掃完){
	x = NextToken(Infix);
	if(x is operand)
		printf(x);
	else{ //x是operator
		if(x == ")"){
			repeat{
				y = pop(S);
				if(y!="(")printf(y);
			}until(y == "(")
		}
		else{ //其他operator
			switch(比較優先權(x, S->Top)){
				case ">":
					push(S, x); 
					break;
				case "<=":
					repeat{//把所有比x大的丟出來，達成優先的效果
						y = pop(S); 
						printf(y);
					}until(x > S->Top)
			}
		}
	}
}
while(!IsEmpty(S)){
	y = pop(S);
	printf(y);
}
```

_**Time:O(n), n = Infix長度**_

比較優先權的表

| operator         | 優先級 | 備註          |
| ---------------- | --- | ----------- |
| "("在stack外       | 高   |             |
| 負號               |     |             |
| "$"在stack外       |     | 因為右結合       |
| "$"在stack內       |     | 因為右結合       |
| ＊, /             |     |             |
| +, -             |     |             |
| ＝＝, <, >, >=, <= |     |             |
| NOT              |     |             |
| AND, OR          |     |             |
| "="在stack外       |     | 因為右結合       |
| "="在stack內       |     | 因為右結合       |
| "("在stack內       |     | 因為左括號內的要先做完 |
| stack empty      | 低   |             |


> _題目目標_
> 將一infix轉乘Postfix，使用stack，描述詳細過程
> 且stack size需>?才夠
> ![400](../img/1299FE09-F17B-4F89-B4A3-FB2B3533893B.jpeg)
> ![400](../img/AC141488-FD49-4212-9948-56023450966D.jpeg)

### Infix to Prefix

```ad-example
title: Infix 轉成Prefix
1. ~~~txt
   A=(B+(C-D*E))/F$G
   ans:
   (A=((B+(C-(D*E)))/(F$G)))
   => =A/+B-C*DE$FG
   ~~~
2. ~~~txt
   a+ (b-c)/d * e
   ans:
   (a+(((b-c)/d)*e))
   => +a*/-bcde
   ~~~
3. ~~~txt
   規定優先權: (,) > + > / > - > *
   且+,-右結合
   *, /左結合
   a+b+(c*d-f-g/h)
   ans:
   (a+(b+(c*(d-(f-(g/h)))))
   => +a+b*c-d-f/gh
   ~~~
```

### Postfix to Infix

```ad-example
title: Postfix 轉成Infix
*Key: Postfix是op1 op2 operator*
1. ~~~txt
   ABC-D+/E*
   ans:
   A/((B-C)+D)*E
   => A/(B-C+D)*E
   ~~~
2. ~~~txt
   a+ (b-c)/d * e
   ans:
   (a+(((b-c)/d)*e))
   => +a*/-bcde
   ~~~
3. ~~~txt
   規定優先權: (,) > + > / > - > *
   且+,-右結合
   *, /左結合
   a+b+(c*d-f-g/h)
   ans:
   (a+(b+(c*(d-(f-(g/h)))))
   => +a+b*c-d-f/gh
   ~~~
```

### Postfix Evaluation 之algo.(using stack)

```C
while(Postfix尚未由左往右掃完){
	x = NextToken(Postfix);
	if(x is operand){
		push(S, x);
	}
	else{
		1. pop stack取出適當數目之operands
		2. 計算
		3. 結果push回stack
	}
}
```

stack內之值即為後序式結果值

```ad-example
postfix: 6 2 / 3 - 4 2 * +
使用stack描述計算過程。
且stack>= ?才足夠
![600x180](../img/截圖%202022-09-24%20下午7.54.43.jpg)
```

_**Algo. Time: O(n)**_, n= Postfix長度

```ad-question
postfix: ABC-D+/E*
使用stack描述計算過程。
且stack>= ?才足夠
```

### 總結

```ad-question
Choose the Correct items
(A)Infix 轉postfix中，stack內放的是operator(除了")")
(B)Postfix中不會有括號出現
(C)Postfix計算時，stack內放的是operands
(D)Postfix計算比Prefix計算容易for Compiler

Ans: ABC
```

### 補充

#### Prefix Evaluation algo.

類似，差別在Prefix是從右往左掃，先pop的放前面，做運算。

#### Infix to Prefix algo.

使用S, T兩個stack(T是為了反序列印用)
Infix是由右往左掃
"(", ")"處理相反
左結合：stack外優先權>stack
由結合：內外相等
要列印的先push到T，最後pop&print出來

#### Parsing 例子

- [Parsing括號配對](Parsing括號配對.md)
- [回文判別](Parsing回文判別.md)

## Queue

> 定義：
> 是一個有FIFO性質的有序串列
>
> - Insert 元素動作叫_Enqueue_插入元素到_Rear_(尾端)
> - Delete元素叫_Dequeue_從Queue之_Front_(前端)刪除

### 應用

1. OS中各種Queues
2. Buffer(緩衝區)FIFO設計
3. Binary Tree 之_Level-order Traversal_
4. Graph 之 _BFS_
5. 系統效能評估：Queueing Theorem
6. 日常生活中的排隊行為

### Queue 之 ADT 描述

operators

1. Enqueue
2. Dequeue
3. IsEmpty
4. IsFull
5. Create(Q)
6. Front(Q):回傳front元素，但不刪除

### Queue的製作

#### 利用Array

##### [法一]Linear Array

1. Create(Q)
   > 宣告Q: array[1..n] of items;
   > Rear: int = 0;/指末端元素
   > Front: int = 0;//指的是前端元素的前一個位置
2. Enqueue(Q, item)
   ```C
   Enqueue(Q, item){
   	if(Rear == n)return "Q滿"
   	else{
   		Rear ++;
   		Q[Rear] = item;
   	}
   }
   ```
3. Dequeue(Q)
   ```C
   Dequeue(Q){
   	if(Rear == front)return "Q空"
   	else{
   		front++;
   		item = Q[front];
   		return item;
   	}
   }
   ```

**分析**
最大問題在於當Rear==n成立時，不代表Queue真的是滿的，極度浪費空間
**解決**
把元素往前挪（但operator運行時間加長）

##### [法二]Cirular Array(最多用n-1格)

Circular => front & rear會循環跑

1. Create(Q)
   > 宣告Q: (同linear array)
   > array[0..n-1] of items;
   > Rear: int = 0;//指末端元素
   > Front: int = 0;//指的是前端元素的前一個位置
2. Enqueue(Q, item)
   ```C
   Enqueue(Q, item){
	   Rear = (Rear + 1)%n;
	   if(Rear == Front){
		   Rear = (Rear-1)%n
		   return "Q滿";
		}
		else{
			Q[Rear] = item;
		}
	}
   ```
3. Dequeue(Q)
   ```C
   Dequeue(Q){
       	if(Rear == front)return "Q空";
       	else{
       		Front = (Front+1)%n;
       		item = Q[Front];
       		return item;
       	}
   }
   ```

**分析**

- 最多用可利用n-1個空間
- Enqueue, Dequeue 之time : O(1)
- 判斷 Q空 跟 Q滿 的寫法一樣

##### [法三]Circular Array(最多用n格)

```ad-tip
Enqueue到碰在一起 => 必定是滿的 => Tag = True
Dequeue到碰在一起 => 必定是空的 => Tag = True
```

1. Create(Q)
   > 宣告Q:
   > array[0..n-1] of items;
   > Rear: int = 0;//指末端元素
   > Front: int = 0;//指的是前端元素的前一個位置
   > _Tag: Boolean  = False;_//協助判斷Q空or滿
2. Enqueue(Q, item)
   ```C
   Enqueue(Q, item){
		if(Rear == Front and Tag == True)
		   return "Q滿";
		else{
			Q[Rear] = item;
			if(Rear == Front)Tag = True;
			Rear++;
		}
   }
   ```
3. Dequeue(Q)
   ```C
   Dequeue(Q){
		if(Rear == front and Tag == False)return "Q空";
		else{
			Front = (Front+1)%n;
			item = Q[Front];
			if(Rear == Front)Tag == False; 
			return item;
		}
   }
   ```

**分析**

- 最多可用n格
- Time 皆為O(1)
- 雖然充分使用n格，但_實際執行時間比[法二]長一些_（因為多了if測試）

```ad-example
利用n, front, rear求出Q的元素個數
ANS:(Rear - Front + n)%n
```

#### 利用Link list

##### [法一]Single link List

1. Create(Q)
   > 宣告:
   > [Node](Node.md)結構
   > rear, front: pointer = Nil;
2. Enqueue(Q, item)
   **分析：**

   - case1: Q原本為空
     F->Nil，R->Nil ==> F->Node1，R->Node1
   - case2: Q原本不為空

   Rear->next = {new node}
   Rear -> {new node}

   ```C
   Enqueue(Q, item){
		new(T);
		t->Data = item;
		t->next = Nil;
		if(Front == Nil){
			Front = t;
			Rear = t;
    	}
		else Rear-> next = t;
   }
   ```
3. Dequeue(Q)
   **分析：**
   - case1: Q只有一個Node
     先把原node資訊保留(t, item)
     F = F->next
     _R = Nil_
     回收t
     return item
   - case2: Q有>1個Node
   先把原node資訊保留(t, item)
   F = F->next
   回收t
   return item
   ```C
   Dequeue(Q){
		if(Front == Nil)return "Q空";
		else{
			t= Front;
			item = Front->item;
			Front = Front-> Next
			if(Front == Nil)
				Rear = Nil;
			free(t);
			return item;
       	}
   }
   ```

##### [法二]Circular link List

**優點**：只用_一個_指標變數Rear指向尾端，Raer->Next指向前端

1. Create(Q)
   > 宣告:
   > [Node](Node.md)結構
   > Rear: pointer = Nil;
2. Enqueue(Q, item)
   **分析：**

   - case1: Q原本為空
   - {new Node}->Next = {new Node}
     R->{new Node}
   - case2: Q原本不為空

   {new node}->Next = Rear->next
   Rear->next = {new node}
   Rear -> {new node}

   ```C
   Enqueue(Q, item){
       	new(t);
       	t->Data = item;
       	if(Rear == Nil) t->next = t;
       	else{
    	   	t->Next = Rear->Next;
    	   	Rear->next = t;
    	}
    	Rear -> t;
   }
   ```
3. Dequeue(Q)
   **分析：**
   先保留R->next
   t = R->next
   item = R->next->item
   - case1: Q有>1個Node
     R的下一個接到下下個（因為要取出下一個）

     回收t
     return item
   - case2:Q只有一個node
     也就是若R->next == R，就是只有一個的意思
     所以把R = Nil並回收t就行
   ```C
   Dequeue(Q){
		if(Front == Nil)return "Q空";
		else{
			t= Rear->next;
			item = t->item;
			if(Rear->next == Rear)Rear = Nil;
			else{
				R->next = t->next
			}
			free(t);
			return item;
		}
   }
   ```

### Queue的種類

#### FIFO Queue

原本的性質

#### priority Queue

> 定義：此Queue運許插入任意權值資料，但刪除資料是刪最大/最小 元素，並非以FIFO order來刪
> 提供至少兩個基本運作
>
> 1. Insert
> 2. Delete-MAX/ Delete-MIN(擇一)
>
> ==Heap data structure最適合==

#### Double-ended Queue

> 定義：Queue之任意兩端皆可插入及刪除元素

==[SMMH](../CH9%20Advanced%20Tree/SMMH(Symmetric%20Min-Max%20Heap).md)==

#### Double-ended priority Queue

> 定義：此Queue提供至少三個基本操作
>
> 1. Insert
> 2. Delete-min
> 3. Delete-MAX
>
> ==最適合的data structure：Min-Max Heap, [Deap](../CH9%20Advanced%20Tree/Deap(Double-ended%20Heap).md), [SMMH](../CH9%20Advanced%20Tree/SMMH(Symmetric%20Min-Max%20Heap).md)==

## Stack 與 Queue之相互製作 ⭐️⭐️⭐️⭐️⭐️

雖然兩著是不同性質的data structure(LIFO vs FIFO)，但彼此可相互製作。

### 用Stack製作Queue

1. Create(Q)
   ```C
   Create(Q){
   	Create(S); // Stack
   	Create(T); // Stack
   }
   ```
2. Enqueue(Q, item)
   ```C
   Enqueue(Q, item){
       if(IsFull(S))return "Q滿";
       else push(S, item);
   }
   ```
3. Dequeue(Q)
   > 利用T再次反轉並且保留在T，以供後續使用
   ```C
   Dequeue(Q){
       if(IsEmpty(S) and IsEmpty(T))return "Q空";
       else{
    		if(IsEmpty(T))
    			while(!IsEmpty(S)){ // S移到T
    			   temp = pop(S);
    			   push(T, temp);
    			}
    		item = pop(T)
       }
       return item;
   }
   ```
   _**大部分case T!= 空 => Time: O(1)**_
   _**少部分Time: O(n)**_
   _**Amotized cost:O(1)**_

### 用Queue製作Stack

1. push(S, item)
   ```C
   push(S, item){
    	if(IsFull(Q)) return "S滿";
    	else Enqueue(Q, item);
   }
   ```
2. pop(S)
   > dequeue出所有前面的並重新push回去，直到可以pop 出top元素
   ```C
   pop(S){
    	if(IsEmpty(Q))return "S空";
    	else{
    		n = Q.length;
    		for i = 1 to n-1
    			x = Dequeue(Q);
    			Enqueue(Q, x);
    		item = Dequeue(Q);
    	}
    	return item;
   }
   ```

### 練習

```ad-example
（少考）在一個array[1..n]上製作兩個stack
Ans:
兩個Stack從兩端往相反的方向放

宣告：
A = array[1..n]
top1 : int 0;
top2 : int n+1;
~~~C
push(i, item){ // push到Si
	if(i == 1){
		if(top1 +1 == top2)return "滿了";
		else{
			top1++;
			A[top1] = item;
		}
	}
	else{
		if(top2 -1 == top1)return "滿了";
		else{
			top2--;
			A[top2] = item;
		}
	}
}
~~~
~~~C
pop(i){
	if(i == 1){
		if(top1 == 0)return "S1空";
		else{
			top1--;
			x = A[top1];
		}
	}
	else{
		if(top2 == n+1)return "S1空";
		else{
			top2++;
			x = A[top2];
		}
	}
	return x;
}
~~~

```
