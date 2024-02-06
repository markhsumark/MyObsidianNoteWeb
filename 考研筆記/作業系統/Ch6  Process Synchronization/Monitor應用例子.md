---
date created: 2022-12-25 22:46
---

# 解決Dining-philosophers problem

```C
Monitor Dining-ph{
	enum{thinking, hungry,
	eating}state[5];
	Condition self[5];

	void pickup(int i){
		state[i] = hungry;
		test(i);
		if(state[i] != eating) self[i].wait;
	}
	void test{
		if(state[(i+4)%5] != eating && state[i] == hungry && state[(i+1)%5]!= eating){
		// 我可以吃飯
			state[i] = eating;
			self[i].signal;
		}
	}
	void putdown(int i){
		state[i]= thinking;
		test((i+4)%5);
		test((i+1)%5);
	}
	initialization_code(){
		for(int i = 𝜙; i< 5; i++){
			state[i] = thinking;
		}
	}
}
```

使用方式：

//宣告一個共享變數
Dining-ph dp;
while

```C
 //Pi code如下  
while(true){  
	 hungry now;  
	 dp.pickup(I);  
	 eating now;  
	 dp.putdown(I);  
	 thinking now;  
}
```

# 例子1

```C
Monitor ResourceAllocation{
	Boolean busy;
	Condition x;
	void Acquire(int time){
		if(busy)
			x.wait(time);
		busy =true;
	}
	void Release(){
		busy = false;
		x.signal
	}
	initialization_code(){
		busy = false;
	}
}
```

使用方式：

```C
ResourceAllocation R;

time = t
…
R.Acquire(t);
//使用resource now
R.Release();
…
```

此處的monitor內之x的waiting Queue 及monitor的entry queue 皆是priority queue（time越小priority越高）

# 例子2

```C
Monitor Fileread{
	int sum;
	Condition x;
	void RFile(int I){
		while(sum+I >=n)
			x.wait;
		sum = sum +I;
	}
	void Left(int i){
		sum = sum - i;
		x.signal;
	}
	initialization_code(){
		sum = 0;
	}
}
```

宣告

```C
Fileread FR;

Pi code:
…
FR.RFile(i);
reading this file;
FR.Left(i);
…
```

有一個read-only file 可被多個processes讀取但規定：
正在存取的這些processes.ID加總必須<n才可讀取，否則wait
Process.ID小的優先權大
