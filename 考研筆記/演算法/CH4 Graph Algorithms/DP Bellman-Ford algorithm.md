DP Bellman-Ford algorithm

k: 走到第幾的邊（前面迴圈的次數）

`distᴷ[j]`
= `w[0, j], if k =1`
= `min{distᴷ⁻¹[j], min{distᴷ⁻¹[i]+w[i, j]}}, if k > 1`
(min{ {上一輪紀錄的shortest path length}, {中間經過點 i 的path })

```ad-tip
collapse:none
- 可畫出w的表方便運算
- min{之前（上一層）的自己, 上一層的其他點連到自己}
```

![500](../img/截圖%202022-10-27%20下午10.06.49.jpg)
