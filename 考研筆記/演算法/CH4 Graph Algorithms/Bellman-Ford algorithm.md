~~全部一起更新拉！~~
#⭐️⭐️⭐️⭐️⭐️ 

> 核心概念為每一輪_對圖上的每一條邊做 relaxation_`n-1次`，則最終必可依序relax的圖上所有s到ui之最點路徑中的邊
> !!由於_s到任一點的最短距離所經過的邊數必 <= n-1_

```ad-attention
collapse: none
- 允許有負邊
- 當然不能有負環
```

```C
BellmanFord(G, w, s){
	InitializationSingleSource(G, s);
	n = |G.V|;
	for i = 1 to n-1 // 做n-1次
		for each (u, v) ∈ G.E //對每一個邊relax
			Relax(u, v, w);
	//判斷負cycle
	for each (u, v) ∈ G.E
		if v.d > u.d + w(u, v)
			return false;
	return true;
}
```

![400](../img/截圖%202022-10-27%20下午10.00.43.jpg)
![400](../img/截圖%202022-10-27%20下午10.00.27.jpg)

**分析**
可用於檢查有無負cycle:多跑一次Bellman-Ford，若有任何一點變短->有負cycle
#### Time Complexity:O(|V||E|)

(使用[Adjacency List](../../資料結構/CH6%20Graph/Adjacency%20List.md)的情況)

### 資料結構
>定義：
>Distᴷ[1..n] of int;
>其中Distᴷ[i]:代表*起點*且經過的邊數需<=k

step:
1. Dist¹[1..n]即為Cost Matrix中 起點那一列元素值
2. 依序求出 Distᴷ[1..n]

[DP Bellman-Ford algorithm](DP%20Bellman-Ford%20algorithm.md)
`distᴷ[j]`
= `w[0, j], if k =1`
= `min{distᴷ⁻¹[j], min{distᴷ⁻¹[i]+w[i, j]}}, if k > 1`