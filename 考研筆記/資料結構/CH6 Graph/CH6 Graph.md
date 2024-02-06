---
date created: 2022-10-26 16:51
date updated: 2022-10-29 18:21
---

```ad-danger
title:資工所要配合 #離散數學 一起念
```

## 定義

> 圖形用G=<V, E>表示

## 種類

以邊具不具有方向性做分類

1. Undirected Graph（無向圖）
2. Directed Graph（有向圖）

## 術語

1. [Eularian cycle](Eularian%20cycle.md)
2. [Eularian chain](Eularian%20chain.md)

其他術語

1. [Complete graph](Complete%20graph.md)
2. Subgraph
3. path（路徑）
4. path length
5. [simple path](simple%20path.md)
6. [cycle](cycle.md)
7. [Connected](Connected.md) #⭐️⭐️⭐️⭐️⭐️
8. Connected Component (連通子圖)
9. [Strongly Connected](Strongly%20Connected.md) #⭐️⭐️
10. [strongly connected component](../../演算法/CH4%20Graph%20Algorithms/strongly%20connected%20component.md)（強連通子圖）
11. [Degree](Degree.md)（分支度）

## Graph之表示方法 #⭐️⭐️⭐️⭐️⭐️

（五種）

1. [Adjacency Matrix](Adjacency%20Matrix.md) #⭐️⭐️⭐️⭐️⭐️
2. [Adjacency List](Adjacency%20List.md) #⭐️⭐️⭐️⭐️⭐️

| 比較表               | Adjacency Matrix | Adjacenty List     |
| ----------------- | ---------------- | ------------------ |
| 空間需求              | O(n²)            | O(n+e)             |
| if頂點多、邊數少         | 不適合              | 適合                 |
| 邊數很多 e = O(n²)    | 適合               | 不適合                |
| 判斷<i, j>邊是否存在     | 適合 O(1)          | 不適合 O(Vi長度)<= O(e) |
| 求圖形 邊數、連通？、cycle? | 不適合 O(n²)        | 適合O(n+e)           |

3. [Adjacency Multilist](Adjacency%20Multilist.md) #⭐️⭐️⭐️
4. [Index Array](Index%20Array.md)
5. [Incidence Matrix](Incidence%20Matrix)

## Graph Traversal 方法 #⭐️⭐️⭐️⭐️⭐️

### [DFS](../../演算法/CH4%20Graph%20Algorithms/DFS.md) #⭐️⭐️⭐️⭐️⭐️

### [BFS](../../演算法/CH4%20Graph%20Algorithms/BFS.md) #⭐️⭐️⭐️⭐️⭐️

## [spanning Tree](spanning%20Tree.md) #⭐️

## min. spanning Tree(MST) #⭐️⭐️⭐️⭐️⭐️

> 給ㄧ個Connected無向圖G=(V, E)且邊上有成本(weight)，則具有最少的成本總和之[spanning Tree](spanning%20Tree)，稱之。

```ad-quote
title:可能有多個MST(if成本皆一樣小)
```

**應用**
框架：有n個點要接通，如何以最小的成本使其連通

1. 電路佈局成本最小化
2. n個城市要連通，求最小交通建設/票價成本
3. u -> v 所有path中，哪條path具有最小的bottleneck

### [Kruskal's Algo](Kruskal's%20Algo.md) #⭐️⭐️⭐️⭐️⭐️

### [Prim's Algo](Prim's%20Algo.md) #⭐️⭐️⭐️⭐️⭐️

### [Sollin's Algo](Sollin's%20Algo.md)

## shortest path length problem #⭐️⭐️⭐️⭐️⭐️

==不一定是MST==

| -          | [DAG-Shortest-path](DAG-Shortest-path.md) | [Dijkstra's algorithm](Dijkstra's%20algorithm.md) | [Bellman-Ford algorithm](Bellman-Ford%20algorithm.md) | [Floyd-Warshall algorithm](Floyd-Warshall%20algorithm.md) |
| ---------- | ----------------------------------------- | ------------------------------------------------- | ----------------------------------------------------- | --------------------------------------------------------- |
| 適用圖形   | Direct Acyclic graph                      | Direct graph                                      | Direct graph                                          | Direct graph                                              |
| 可否有負邊 | yes                                       | no                                                | yes                                                   | yes                                                       |
|            | single-source-to-other-Destinations       | single-source-to-other-Destinations               | single-source-to-other-Destinations                   | All pair of vertex 之shortest path                        |
| 策略       | [Topological sort](Topological%20sort.md) | Greedy                                            | Dynamic Prgramming                                    | Dynamic Prgramming                                        |
| Time       | O(V+E)                                    | O(VlogV + E) `in Fibonacci Heap` ==最快的==       | `O(V E)`                                              |   `O(V^3)`                                                        |

### single-source-to-other-Destinations

1. [DAG-Shortest-path](../../演算法/CH4%20Graph%20Algorithms/DAG-Shortest-path.md)
2. [Dijkstra's algorithm](../../演算法/CH4%20Graph%20Algorithms/Dijkstra's%20algorithm.md)
3. [Bellman-Ford algorithm](../../演算法/CH4%20Graph%20Algorithms/Bellman-Ford%20algorithm.md)

### All pairs of vertex

也可以使用single-source-to-other-Destinations，並對所有的點跑一次
但是：

| Algo         | Time  | 限制             |
| ------------ | ----- | -------------- |
| Dijkstra     | O(n³) | 不能有負邊！         |
| Bellman-Ford | O(n⁴) | 雖說可以有負邊，但是超慢！！ |

1. [Floyd-Warshall algorithm](../../演算法/CH4%20Graph%20Algorithms/Floyd-Warshall%20algorithm.md)

#### Johnson's Algo

## AOV Network & Topological sort #⭐️⭐️

### [AOV Network](AOV%20Network.md)

### [Topological sort](Topological%20sort.md)

## AOE Network & critical tasks, critical path #⭐️⭐️⭐️

### [AOE Network](AOE%20Network)

## Articulation point, Biconnected Graph, Biconnected component #⭐️⭐️⭐️

1. [Articulation point](Articulation%20point.md)
2. [Biconnected Graph](Biconnected%20Graph.md)
3. [Biconnected component](Biconnected%20component.md)
