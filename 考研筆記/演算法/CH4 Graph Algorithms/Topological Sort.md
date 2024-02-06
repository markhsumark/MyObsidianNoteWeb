---
date created: 2022-10-27 22:10
---

### Topological Sort

可用於安排工作順序

```ad-attention
title:只有**[DAG-Shortest-path](DAG-Shortest-path.md)**的Topological Sort(拓撲排序)才有意義。
因為根據定義，再有cycle 的情況下，前後順序會變得沒有意義
```

```C
Topological-Sort(G){
	//宣告一個linked list L
	//執行DFS，在v塗黑時，將v插到linked list 前端。
	return L
}
```

Time: O(V+E)

