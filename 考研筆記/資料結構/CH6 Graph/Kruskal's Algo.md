---
date created: 2022-10-28 17:34
date updated: 2023-01-20 12:05
---

# Kruskal's Algo

~~挑最小的到完成~~
#⭐️⭐️⭐️⭐️⭐️
找出G中的[spanning Tree](spanning%20Tree.md)的一種演算法

> 令G=(V, E)為_Connected 無向圖_

steps

1. 自E中挑出_最小成本_的邊(u, v)
2. _檢查_(u, v)加入後是否會_出現cycle_
   - 出現cycle:放棄此邊
   - 沒有cycle:加入S
3. Repeat 1. ~ 2. `n-1`次 or `E為空`

**Time 分析**
假設G的頂點數:V，邊數:E

- 令E中各_成本值_以[min Heap](../CH5%20Tree%20and%20Binary%20Tree/CH5%20Tree%20and%20Binary%20Tree.md##%20Heap%20#⭐️⭐️⭐️⭐️⭐️)維護
- 最多執行E回合
- 每一回合執行
  1. Delete min edge from E: O(log E)
  2. 判斷cycle：利用[Disjoint Sets 中的Union &Find](../CH5%20Tree%20and%20Binary%20Tree/CH5%20Tree%20and%20Binary%20Tree.md#Union(i,%20j)與Find(x)運作之3種組合,討論)運作。
     ```C
	if(Find(u)!= Find(v)){
		//if 採"Union-by-weight", "Find-with-path-compression"
		Add(u, v)edge into S;
		Union(u, v) 
	}
     ```
     Find(u), Find(v): O(1)
     Union(u, v): O(1)

-> O(logE)+O(1)
-> O(logE)
執行E回合 -> `O(ElogE)`

# Kruskal's Algo[演算法版本]

```C
Kruskal(G, w){
	A = {};
	for each vertex v in G.V{
		MakeSet(v);//頂點各自為一個集合
	}
	G.E = Sort(G.E)//成本由小->大排序
	for each edge(u, v) in G.E{
		if(Find(u)!=Find(v)){
			A = A ∪{u, v};
			Union(u, v);
		}
	}
	return A;
}
```

**Time 分析**
O(V)+O(ElogE)+O(E)
-> `O(Elog E)`
此外由於E << V² (E最多C(V, 2))
所以O(Elog E) <= O(Elog V²) = O(2ElogV)
-> `O(Elog V)`
