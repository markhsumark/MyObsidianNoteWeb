---
date created: 2022-09-24 17:37
date updated: 2023-01-12 19:30
---

# Working Set Model

## 是基於*[Locality Model](Locality%20Model.md)* 之理論

## 相關名詞

1. Working Set Window: 記為∆，_表示以∆次Memory Access作為統計 Working Set 之依據_（∆直可通帶調整）
2. Working Set: 在∆次page access中所參考到的_不同pages_所形成之集合
3. Working Set Size(WSS): working set 之page 個數，即 process 在此時期_所需之 Frame 數_

```ad-example
...2 3 4 5 3 6 7 7 7 7 3 4 2 3 4...
∆ = 10
第一期的working是{2,3,4,5,6,7}
```

## OS如何運用

令 n =process數目
WSSᵢ: Processᵢ在此時期之working set size
M: phy. memory 大小
求出D = Sigma i =1~n(WSSᵢ) = _頁匡總需求？_

分成2 case

- case 1: 若D <= M
  則OS會依照WSSᵢ直飛給個Pᵢ足夠的frame數，如此可預防thrashing
- case 2: 若D > M
  則OS會select_一些processes將他們swap out_到Disk，以_降低D值_，直到D<= M(case 1)在做分配，等到有足夠記憶體空間

## 優點

1. 可預防Thrashing
2. 對於Prepaging 也有助益

## 缺點

1. 不易制定精確的Working Set(∆不好制定)
2. 若前後期working set差異太大，易造成太多I/O運作。

```ad-example
{1,2,3} => {4,5,6}
6次I/O

{1,2,3} => {2,3,4}
2次I/O
```
