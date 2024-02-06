---
date created: 2023-01-10 23:01
---

~~彌補Dijkstra的「不能有負邊」缺點~~

> 使用**reweighting**，調整**權重皆為非負**，再利用[Dijkstra's algorithm](Dijkstra's%20algorithm.md)計算(n次)

Time`:O(|V|²lg|V| +|V||E|)`
當G為sparse時，此方法比[Floyd-Warshall algorithm](Floyd-Warshall%20algorithm.md)有效率

## reweight

保證成立：

1. reweight後的最短路徑 = 原圖的最短路徑
2. 原圖沒有負環 -> reweight後應沒有負環
3. reweight後的所有邊的權重皆非負

> 新的w(u->v) = 原本的w(u->v) + {s到起點 s->u} - {s到終點 s->v}
> `ŵ(u, v) = w(u, v) + 𝛿(s, u) - 𝛿(s, v)`
