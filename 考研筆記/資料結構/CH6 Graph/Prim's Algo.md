---
date created: 2022-10-28 17:34
---

#⭐️⭐️⭐️⭐️⭐️
~~從“已開拓的周圍”找最小~~
~~找“跨越的”邊~~
# Prim's Algo[DS版本]
>令G=(V, E)為*Connected無向圖*
>令V = {1, 2, 3, 4, 5, ..., n}
>令U= {1}。" 1 " 表起點

**steps**
1. 挑出最小的邊(u, v)*其中u∈U and v∈ V*
2. (u, v)加入S，且v自V-U中移除移到U中
3. repeat 1 ~ 2直到U=V or E為空

![200](../img/截圖%202022-10-28%20下午8.35.20.jpg)
~~最後一步是(4, 5)~~

# Prim's Algo[演算法版本]
```C
MSTPrim(G, w, r){
	for each u in G.V{
		u.key = ♾;
		u.𝝅 = Nil;
	}
	r.key = 0;
	Q = G.V; //依照key值建立priority queue: Q
	while(!isEmpty(Q)){
		u = Extract-min(Q);//就是找鄰近成本最低的頂點
		//而Extract出來的會影響周圍
		for each v in G.adj[u]{//u的相鄰
			if(v ∈ Q and w(u, v)< v.key){//刷新周遭v的價值
				v.𝝅 = u;
				v.key = w(u, v);
			}
		}
	}
}
```

**Time分析**
Init: `O(V)`
建立Queue(Heap):`O(V)`
Extract-min : O(logV) ，做V次->`O(VlogV)`
for loop共檢視 `2E`個頂點 -> `O(2E* logV)`(使用Heap)

```ad-note
title:此動作相當於一個Decrease-Key(Heap:[Heap](../CH5%20Tree%20and%20Binary%20Tree/CH5%20Tree%20and%20Binary%20Tree.md#operations%20及%20Time), Fib Heap:[Fibonacci Heap](../CH9%20Advanced%20Tree/CH9%20Advanced%20Tree.md#Fibonacci%20Heap)
```

-> `O(V) +O(V)+O(VlogV)+O(Elog V)`
->`O(ElogV)`與[Kruskal's Algo](Kruskal's%20Algo.md)相同

若要*加速*改用[Fibonacci Heap](../CH9%20Advanced%20Tree/Fibonacci%20Heap.md)
-> `O(V) +O(V)+O(VlogV)+O(E)`
->`O(VlogV + E)`