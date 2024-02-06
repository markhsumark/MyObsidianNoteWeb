

> discovery time u.d
> finishing time u.f
> u.color
>
> - white: undiscovered
> - gray: discovered but 有子點is undiscovered(while)
> - black:子點皆finished

```C
DFSVisit(G, u){
	t = t+1;
	u.d = t;
	u.color = gray;
	for each v ∈ G.adj[u]{
		if v.color = white{
			v.𝝅 = u;
			DFSVisit(G, v);
		}
	}
	u.color = black;
	t = t+1;
	u.f = t;
}
DFS(G){
	for each u ∈ G.V{
		u.color = white;
		u.𝝅 = ♾;
	}
	t = 0;
	for each u ∈ G.V{
		if u.color = white{
			DFSVisit(G, u);
		}
	}
}
```

**Time:**𝝷(|V|+|E|)**

### depth-first forest

在執行DFS的過程中將每個edge分類：

1. Tree edge: if v.𝝅 = u (u到v的邊)~~parent關係~~
2. Back edge: 在forest中，v是u的上輩（含loop）
3. Forward edge:在forest中，v是u的_孫子_。(遇到黑色，u的discover比v小)
4. Cross edge: 其他（跨越不同 樹/樹枝 的）(遇到黑色，u的discover比v大)

> 在undirected graph中，G只有_tree edge&back edge_
> _**沒有cycle <=> 沒有back edge**_

### DFS應用

1. 判斷是否connected
2. 判斷是否為acyclic(下一個檢查的點是灰色/Back-edge的就是cycle)。但是無向圖中可能誤判（必須要判斷v.𝝅）
4. 在 directed acyclic graph(DAG)上找出一個[Topological Sort](Topological%20Sort.md)
5. directed graph 中找出所有[strongly connected component(SCC)](strongly%20connected%20component.md)
6. undirected graph中找出[biconnected component](../../資料結構/CH6%20Graph/Biconnected%20component.md) 與 [articulation point](../../資料結構/CH6%20Graph/Articulation%20point.md)

### 資料結構
[CH6 Graph](../../資料結構/CH6%20Graph/CH6%20Graph.md)
> 皆為無向圖
> visited[1..n] of Boolean

```C
DFS(v:strat vertex){
	visited[v] = True;//algov塗呈灰色
	for each vertex w adjancent to v do{
		if (not visited[w])//algo: w如果是白色
			DFS(w);
	}
	//algo: 塗成黑色
}
```

```ad-quote
title:Note
collapse:none
1. DFS order並不唯一
2. 通常會規定頂點編號小者優先
```