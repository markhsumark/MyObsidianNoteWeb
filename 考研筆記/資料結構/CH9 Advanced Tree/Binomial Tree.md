Binomial Tree

> 定義：
>
> 1. 高度為０之Binomial Tree記為B0，只有Root 1個點
> 2. 高度=k...記為Bk，是由兩顆Bk-1所合成。

![200](../img/截圖%202022-10-17%20下午7.08.52.jpg)

```ad-note
title:相關數學(台大考過 #⭐️⭐️⭐️⭐️⭐️ )
collapse:none
- Bk 中第i level之Node樹 = C(k, i)
	**pf**(數學歸納法):
	Bk 第i層 = Bk-1中第i層 + Bk-1中第i-1層
	...
- Bk之Node總數 = 2^k
  pf:
  1. 歸納法
  2. 利用C(k, i)
```
