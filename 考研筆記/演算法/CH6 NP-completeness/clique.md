---
date created: 2022-11-08 17:46
---

> clique: G中最大的complete subgraph

給定一個圖G=(V, E)

- optimization version:
  給定一個圖G=(V, E)，求G中最大clique
- decision version:
  給定一個圖G=(V, E)與一個正整數 k，G中是否具有大小為k的clique

是一個[NP-complete](NP-complete.md)問題
證明
1. CLIQUE ∈[NP](NP.md)
2. [3-CNF-SAT](3-CNF-SAT.md) ≤𝑝 CLIQUE
