---
date created: 2022-10-29 15:36
date updated: 2022-12-29 18:02
---

#⭐️⭐️⭐️⭐️⭐️
~~一邊往當下最短外圍連，一邊更新最短距離~~

[Greedy Algorithm](../CH3%20Dynamic%20Programming/Greedy%20Algorithm.md)

```ad-attention
collapse: none
- 不允許有負邊
- 當然不能有負環
```

```C
InitializeSingleSource(G, s){
	for each v in G.V{
		v.d = 無限;
		v.𝝅 = nil;
	}
	s.d = 0;
}
Relax(u, v, w){
//用於更新v.d
	if(v.d > u.d+w(u, v)){
		v.d = u.d+w(u, v);
		v.𝝅 = u;//更新parent
	}
}
Dijkstra(G, s){
	InitializeSingleSource(G, s);
	S = {s};//搜集已確認的點
	let Ｑ= 紀錄所有點的Queue，key為v.d
	while(Q非空){
		u = ExtractMin(Q);//最小的v.d 拿出來
		//不用擔心會有cycle，因為v拜訪過後就不再Q裡面，不會再取出
		S = S 𝖴 {u};
		for each v ∈ G.adj[u]{//更新周圍的點
			Relax(u, v, w);
		}
	}
}
```

```ad-tip
collapse:none
1. 找目前(已經連到的）最小v.d的點儲存在u
2. 把u設為已確定（不會再檢查u)
4. 更新u周圍的點
```

#### Time complexity:

`(迴圈*每一次Extract-Min + Relax次數*Relax時間)`
Relax次數：O(|E|)。（發現每個邊剛好被檢查1次)

- 使用array: `O(|V|²+|E|) = O(|V|²)`
- 使用[binary heap](../../資料結構/CH5%20Tree%20and%20Binary%20Tree/CH5%20Tree%20and%20Binary%20Tree.md#Heap%20⭐️⭐️⭐️⭐️⭐️): `O(|V|lg|V|+|E|lg|V|)` = `O(|E| lg |V|)`
- 使用[Fibonacci Heap](../../資料結構/CH9%20Advanced%20Tree/Fibonacci%20Heap.md): `O(|V|*lg|V|+|E|)`
- 使用Binomial Heap: `O(|E|log|V|`

| -              | Initialization | Extract-min      | Decrease-Key(Relax) | Total                |
| -------------- | -------------- | ---------------- | ------------------- | -------------------- |
| Array          | `O(V)`         | `V * O(V)`       | ` O(E) * O(1)   `   | `O(V²)`              |
| Binary Heap    | ` O(V)  `      | `  V * O(lg V) ` | ` O(E) * O(lg V)  ` | `O(E lg V + V lg V)` or `O(ElogV)` |
| Fibonacci Heap | `O(V)`         | `V * O(lg V)`    | ` O(E) * O(1)  `    | `O(V lg V +E)`       |

```ad-example
![500](../img/截圖%202022-10-27%20下午8.58.44.jpg)
```

#### 分析

1. relax順序不影響結果（可用數歸法證明）
2. s到任一點的最短距離所經過的邊數必 <= n-1 !!重要
