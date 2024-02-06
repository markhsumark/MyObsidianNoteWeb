---
date created: 2022-10-29 15:05
---

![500](../img/截圖%202022-10-15%20下午4.59.16.jpg)

**演算法**

```C
Enqueue(Q, s)
while(Q != Nil){
	u = Dequeue(Q)
	for v in adj[u]:
		if v.color == while
			//塗成灰色
			v.d = u.d+1
			v.𝝅 = u
			Enqueue(Q, s)
	u.color = black
}
```

**Time 分析**：

1. 利用adjacency list 來儲存G，每個點進到Queue一次，每個邊進到演算法一次（有向圖2次）=> _**O(|V|+|E|)**_
2. 利用adjacency matrix儲存G，時間為 => _**O(|V|²)**_

```ad-hint
title:可用來檢查G是否為connected
```

### BFS應用

1. s到各點的最短距離 ( = 𝛿(s, v))
2. 是否為connected
3. Diameter:求出u, v（G中距離最遠的兩點），以及u, v的最短距離。
   ![400](../img/截圖%202022-10-15%20下午5.15.53.jpg)

可在O(V時間內解決)，是 #[NP-complete](../CH6%20NP-completeness/NP-complete.md) #ch6

### 資料結構

```C
BFS(v){
	visited[v] = True;//algo: 塗灰
	create Q(Q);
	Enqueue(Q, v);
	while(!IsEmpty(Q)){
		v = Dequeue(Q);
		for each u in W[v]{//加入u下面的Node
			if(!visited[u]){
				visited[u] = True;//algo: 塗灰
				Enqueue(Q, u);//存下下一層
			}
		}
		//v點的children都拜訪完了
	}
}
```

```ad-quote
title:Note
collapse:none
[B.T之Level order Traversal](../CH5%20Tree%20and%20Binary%20Tree/CH5%20Tree%20and%20Binary%20Tree.md#Binary%20traversal)即是圖形的BFS
```
Time:O(V+E) (使用adjacency list)