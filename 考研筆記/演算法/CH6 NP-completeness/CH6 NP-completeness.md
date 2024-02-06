---
date created: 2022-11-08 17:34
date updated: 2022-11-09 13:03
---

一般猜測

| P             | [NP-complete](NP-complete.md) |
| ------------- | ----------------------------- |
| shortest path | longest path                  |
| Euler circait | HC/HP TSP                     |
| 2-CNF-SAT     | 3-CNF-SAT                     |
| 2-coloring    | 3-coloring                    |
|               | max-cut                       |
|               | [clique](clique.md)           |
|               | independent set               |
|               | vertex cover                  |
|               | dominating set                |
|               | subset sum                    |

# 6.1 Complexity class

探討哪些是‘容易解的’(tractable)，而哪些是‘不容易解的’(intractable)
分類的好處：針對那些不易解的問題，我們可以_退而求其次，在有效時間內求出近似解_。

問題模式先分為兩種（以 [clique](clique.md) 為例）：

1. optimization problem:當尋求問題為解一個_最佳值_時，稱之。
2. decision problem:欲解的問題為一個_是非題_時，稱之

```ad-tip
collapse:none
如果求得optimization version之解，則decision version問題便很好回答
->decision version 不會比optimization versions難解
---
不同問題之decision version之間轉換比較容易
```

## 四種complexity class

對decision problem 做難度分類

| [P](P.md)  | [NP](NP.md) | [NP-hard](NP-hard.md) | [NP-complete](NP-complete.md) |
| ---------- | ----------- | --------------------- | ----------------------------- |
| 容易「解決」 的問題 | 容易「驗證」的問題   | NP中，最難的               |                               |

```ad-note
title:引理：若==A ≤𝑝 B==，則B為polynomial-time solvable => A 為polynomial-time solvable
```

```ad-note
title:定理：若存在一個NP-complete的問題為polynomial-time solvable，則P = NP

假設N != NP 則所有NP-complete都無法在poly.-time之內解決
換言之，如果可以證明一個NP-complete的問題具有poly.-time的解法，相當於證明 P = NP
```

# 6.2 NP-complete problem

首先了解[CNF](CNF.md)

## [3-CNF-SAT](3-CNF-SAT.md)

## [clique](clique.md)

## [VERTEX-COVER](VERTEX-COVER.md)

## [HC](HC.md)/[HP](HP.md)

## [TSP](TSP.md)

## [LP](LP.md)

# 6.3 Approximation algorithms

針對NP-complete問題找出==近似演算法==

條件與定義
>假設==V*==為一個最佳解做對應之最佳值，任給一個大小為==n==之instance，若V為在使用A（用來解此問題的演算法）解此問題的最佳值
>==max{V/V*, V*/V}≤𝛒(n)==
>則稱𝛒(n)為approximation ratio，且稱A為Q(問題)之𝛒(n)-approximation algorithm



## Approx-Vertex-Cover

## Approx-[ETSP](ETSP.md)

