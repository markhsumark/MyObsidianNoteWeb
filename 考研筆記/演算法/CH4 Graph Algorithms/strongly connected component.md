---
date created: 2022-10-15 22:56
date updated: 2022-10-15 23:07
---

### strongly connected component

```ad-tip
collapse:none
**觀察＆假設**

1. component graph G'=(V', E')，任意Vi ∈V', Vi = Ci,且Ci和Cj之間必有一路徑
2. 觀察到G'必為DAG，因為if G'有cycle，此cycle經過的點應屬於同一個component

---

**ALGO.**
1. 對G做DFS(起點不重要)
2. 觀察到：G'中，(Vi, Vj)∈E'(Ｃi->Ｃj，Cj先結束)，則==finish_time(Ci) > finish_time(Cj)(後代要先結束，才會跑到parent)==
4. 若反過來跑，DFS(Gᵀ)，會先走完Ci，且發現Ci走不到Cj

```

> 給定一G=(V, E)為一個_有向圖_，若C ⊆ V為maxiaml 滿足⦡u, v ∈C，_**存在路徑可從v->u &u->v**_，即為strongly connected component

![400](../img/截圖%202022-10-15%20下午10.57.30.jpg)
可以發現component graph(圖中Ｇ‘) 必為DAG（因為弱G'具有cycle，則該cycle經過的點對應回G，應再組合成一個component）。
![500](../img/截圖%202022-10-15%20下午11.04.33.jpg)
#### Kosaraju's algorithm
```C
SCC(G){
	執行DFS(G)求出v.f（最後一個結束的點）
	執行DFS(Gᵀ)，以DFS(G)求出的finish time從大道小依序選點
	return DFS(Gᵀ)的depth-first forest，其中每一個forest是一個SCC
}
```

