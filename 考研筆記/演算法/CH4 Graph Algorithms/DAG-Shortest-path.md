~~安排順序，更新答案~~

> 主要想法是依照[Topological Sort](Topological%20Sort.md)的順序對圖上每一點連出去的邊作relaxation
> 則[Bellman-Ford algorithm](Bellman-Ford%20algorithm.md)中的_迴圈只需執行一次_
> ->求[Topological Sort](Topological%20Sort.md)&對每邊作relaxation 皆可在`𝝷(|V|+|E|)`

```ad-tip
collapse:none
1. Topological Sort（排序）
2. 對排完順序的點依序Relax
```

```C
DAGShortestPath(G, w, s){
	v = TopologicalSort(G, s);
	InitializaeSingleSource(G, s);
	for i = 1 to n
		for each v in adj[v[i]]
			Relax(v[i], v, w);
}
```
