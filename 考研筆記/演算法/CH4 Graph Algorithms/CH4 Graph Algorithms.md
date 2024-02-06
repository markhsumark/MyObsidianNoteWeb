---
date created: 2022-10-15 17:17
date updated: 2022-12-29 18:04
---

```ad-attention
title:在這章節基本上都用adjecency list儲存G
```

```ad-danger
title: [資料結構CH6 Graph](../../資料結構/CH6%20Graph/CH6%20Graph.md)
```


| [Dijkstra's algorithm](Dijkstra's%20algorithm.md)                                              | [Bellman-Ford algorithm](Bellman-Ford%20algorithm.md) | [Floyd-Warshall algorithm](Floyd-Warshall%20algorithm.md) | [Johnson's algorithm](Johnson's%20algorithm.md)                                        |
| ---------------------------------------------------------------------------------------------- | ----------------------------------------------------- | --------------------------------------------------------- | -------------------------------------------------------------------------------------- |
| **single source shortest paths**                                                               | **single source shortest paths**                      | **All pairs shortest paths**                              | **All pairs shortest paths**                                                           |
| 從端點往外延伸                                                                                 | 每回合對每個edge做relexation                          | 所有點一起跑。vertex i經過k到vertex j的最短距離           | 先reweight再做[Dijkstra's algorithm](Dijkstra's%20algorithm.md)                        |
| 不能有負邊                                                                                     | 可以有負邊                                            | 可以有負邊                                                | 可以有負邊                                                                             |
| `O(V lg V +E)`(使用[Fibonacci Heap](../../資料結構/CH9%20Advanced%20Tree/Fibonacci%20Heap.md))，大部分時間用`O(ElogV)`or`O(V²)` |  `O(V E)`                                           | `O(V³) `                                                | `O(V²lgV +V E)`                                                                 |
| -                                                                                              | -                                                     | -                                                         | 當G為sparse時，此方法比[Floyd-Warshall algorithm](Floyd-Warshall%20algorithm.md)有效率 |




## 4.1 [BFS](BFS.md)

## 4.2 [DFS](DFS.md)

## 4.3 Single-source shortest paths

> 定義：G=(V, E)為一個_directed weighted graph_，function w(P)為路徑P上的所有邊的權重合
> 𝛿(u, v)= u~ v的路徑中的最小權重和
> 若P為u ~ v，且滿足w(P) = 𝛿(u, v)，則_稱P為最短路徑_
> ==給定一點s，求s到個點的最短路徑==即為The single-source shortest paths problem

- T為以s 為Root的Tree，s到tree中的node皆為最短路徑，則稱T為_shortest-path tree_
- v.d為s到v的最短路徑估算值

### [Dijkstra's algorithm](Dijkstra's%20algorithm.md) #⭐️⭐️⭐️⭐️⭐️

### [Bellman-Ford algorithm](Bellman-Ford%20algorithm.md) #⭐️⭐️⭐️⭐️⭐️

### [DP Bellman-Ford algorithm](DP%20Bellman-Ford%20algorithm.md)

### [DAG-Shortest-path](DAG-Shortest-path.md)

## 4.4 All-pairs shortest path problem

[CH3 Dynamic Programming](../CH3%20Dynamic%20Programming/CH3%20Dynamic%20Programming.md)

> 在G=(V, E)的directed weighted graph中，求出u~v的最短路徑

利用（對每個點(n次)都做一次single source shortest path）

- [Dijkstra's algorithm](Dijkstra's%20algorithm.md)花費：`O(|V|³)`
- [Bellman-Ford algorithm](Bellman-Ford%20algorithm.md)花費:`O(|V|⁴)`

### [Floyd-Warshall algorithm](Floyd-Warshall%20algorithm.md) #⭐️⭐️⭐️⭐️⭐️

### [Johnson's algorithm](Johnson's%20algorithm)

## 4.5 Minimum spanning trees

#離散數學

### [Kruskal's Algo](../../資料結構/CH6%20Graph/Kruskal's%20Algo.md)

## 4.6 The Maximum Flow Problem

> 給定一個directed weighted graph，具有s(source), t(sink)兩點，且滿足任意v ∈ V，s->v->t皆存在~~任意點皆可到t＆被s連到~~
> 令：
>
> - c(u, v)：u->v的容量
> - f(u, v)：u->v的流量
> - augmenting path: 一s->v的路徑，滿足路徑上所有邊的flow < capacity，並將流量充滿
>
> capacity constraint : 0 ≤ f(u, v) ≤ c(u, v)
> 每一點的`流入=流出`
> **求最大value之flow為何？`∑ᵥf(s, v)`**

**Cut**

- 若(S, T)是V之partition，即S∪T = V & S∩T = ∅ 又s ∈ S, t∈T，則稱(S, T)是G之一cut
  令c(S, T) = ∑ᵤ∑ᵥc(u, v)，稱c(u, v)為cut(S, T)之capacity

Time 分析:
設`𝒇*` 為maximum flow (整數)，每一輪flow至少加一，所以while最多執行  `O(|𝒇*|)`
另外利用 BFS or DFS 可求出一條augmenting path
->`O(|𝒇*|(|V|+|E|)) = O(|𝒇*||E|)`

### Max-flow min-cut theorem

_minimum-cut 可以找出Max-flow_
下列敘述等價：

- 𝒇 為G之maximum flow
- G𝙛中不含augmenting path ~~反向為空~~
- 存在一個cut(S', T')使得 |𝒇| = cut(S', T') ~~可以切出最大流量~~

### Ford-Fulkerson method

~~有往回指的流向~~

![500](../../資料結構/img/截圖%202022-11-02%20下午3.35.47.jpg)

### Edmoinds-Karp algorithm

~~[BFS](BFS.md)  -> Ford-Fullkerson ，改變走流向的次序~~

> Ford-Fulkerson 的特例
> 每回合皆以==BFS==選取augmenting path->每次選取==邊數最少的path==，此法保證while至多執行`O(|V||E|)`
> -> `O(|V||E|(|V|+|E|)) = O(|V||E|²)`

### normal Graph -> flow network #⭐️

三種轉換方法：
![400](../../資料結構/img/截圖%202022-11-02%20下午3.55.32.jpg)
