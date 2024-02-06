#⭐️⭐️⭐️⭐️⭐️ 
>求**All pairs of vertix**

有向圖
可以有cycle
可有負邊

## 演算法

> 相臨矩陣w[i, j]
> D = [d[i, j]] (d[i, j] = 𝛿(i, j))
> ~~𝛿(u, v)= u~v的路徑中的最小權重和~~
> ∏ = 𝝅[i, j] :從i到j的倒數第二個點

```ad-tip
collapse:none
所有的邊同時一起跑。計算i->j時，比較i->k->j, k=1 ~ n。即可求出所有解 
`Dᴷ[i, j] = min{Dᴷ⁻¹[i, j], Dᴷ⁻¹[i, k]+Dᴷ⁻¹[k, j]}`
```
![550](../../資料結構/img/截圖%202022-11-02%20上午10.09.36.jpg)
**Time**
`O(|V|³)`

可用來求[transitive closure](transitive%20closure)

## 資料結構

>Aᴷ: nxn matrix, n = |V|, v = {1, 2, 3, ..., n}，A⁰是成本矩陣
>其中Aᴷ[i, j] = i-> j的shortest path length，途中經過的頂點編號<= k
>~~同演算法版本~~


