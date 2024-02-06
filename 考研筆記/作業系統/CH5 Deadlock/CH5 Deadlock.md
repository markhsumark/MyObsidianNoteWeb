---
date created: 2022-09-14 12:37
date updated: 2022-12-25 19:33
---

# 例子：四個十字路口

# 四個必要條件

```ad-note
直接思考紅綠燈卡死狀況
1. 十字路口一次通過一輛車 -> mutual exclusion
2. 汽車通過時，十字路口被那一台佔用 -> hold and wait
3. 汽車按照順序通過、不可以把其他車撞開 -> no preemption
4. A等B等C等D等A... -> Circular waiting
![](../img/截圖%202022-12-22%20下午5.51.54.jpg)

```

1. ## [Mutual exclusion](Mutual%20exclusion.md)
2. ## [Hold and wait](Hold%20and%20wait.md)
3. ## [No preemption](No%20preemption.md)
4. ## [Circular waiting](Circular%20waiting.md)

# 與[starvation](../CH4%20Process%20Management%20&%20Tread%20Management/starvation.md)比較(Deadlock/Starvation)

| 情況      | Deadlock                    | [Starvation](../CH4%20Process%20Management%20&%20Tread%20Management/starvation.md) |
| ------- | --------------------------- | ---------------------------------------------------------------------------------- |
| 1. 定義   | 沒有機會完成                      | 有機會完工只是機會渺茫                                                                        |
| 2. 發生條件 | 4個條件                        | 發生在不公平環境＆可搶奪環境                                                                     |
| 3. 影響   | 產能下降                        | 無                                                                                  |
| 4. 解決方法 | prevention, Avoidance, etc… | Aging                                                                              |

# Deadlock

> 定義：系統中存在一組processes彼此行程circular waiting 情況，造成陷入死結之processes皆無法往下執行，使得Throughput, utilization不良之結果。

# RAG 資源配置圖(Resource Allocation Graph)

![](../img/截圖%202022-12-22%20下午5.51.39.jpg)
三點結論

- _No cycle => No deadlock_
- _有cycle =?> 有deadlock_ （如果有一種resource的初始數量為0，即便沒有cycle也會Deadlock）
- _每種Resources皆為單一數量，有cycle => 有deadlock_*

# Deadlock 處理方法

```ad-tip
title: Deadlock Free(絕對不會deadlock的最小resource數量)
若系統中有n個process，m個res.數量(單一類)，則滿足2條件就保證Deadlock Free
1.  1<=MAX𝒾<=m ~~資源數量大於總需求~~
2.  ∑ MAX𝒾 < n+m ~~每個人全部所需小於資源總量加process數量(鴿洞定理)~~

```
```ad-question
title:為什麼即便有辦法處理deadlock，仍然很多系統不願處理(假裝沒看見deadlock)？
因為
不論是 prevention, avoidance, detection, recovery 都會造成
1. resources utilization偏低
2. throughput 不高

等問題
```
```ad-question
title:What are the differences between "deadlock prevention" and "deadlock avoidance"
```

> deadlock prevention & deadlock avoidance
> 優：
>
> - 保證不會出現deadlock
>
> 缺：
>
> - 對資源的限制很多
> - 可能造成starvation

> deadlock detection & deadlock recovery
> 優：
>
> - 資源利用度高、產出量也高
>
> 缺：
>
> - system有可能進入deadlock
> - 成本高

---

## Prevention

> 破除四項條件

1. 破除mutual exclusion
   辦不到！！！
2. 破除hold&wait
   _作法一_：process要一次取得所有所需的資源，否則無法取得
   _作法二_：可取得部份資源，但要取得其他資源時，要將先前的資源全部歸還。
3. 破除No preemption
   (Easy)改為preemption
4. 破除Circular waiting
   Resource ordering (每個process只能依照遞增的序號(每個資源獨有)來申請資源)
   ![](../img/截圖%202022-12-22%20下午6.00.08%201.jpg)

**若是採用預防的方式，結論：**

- throughtput降低
- 裝置率用率降低

---

## Avoidance

~~預先算一次需要的資源量即可預防~~

>定義：當某個process提出資源申請時，OS必須執行一個Banker algorithm，用以判斷准許資源後，系統是否處在[Safe state](Safe%20state.md)。若是，准許請求，否則否決此次申請讓process需等待下次再提出申請。

- [Safe state](Safe%20state.md)
- [Unsafe state](Unsafe%20state.md)
- ### [Banker Algorithm](Banker%20Algorithm.md)

**結論：**

- 優點：不會進入deadlock
- 缺點：Banker Algorithm 運算成本高

---

## Detection


### 若每種res.都只有一個->可用RAG「簡化」

claim edge: “P𝒾- - - - >R𝒾”:代表P𝒾未來會對R𝒾申請資源
過程（4 steps）

1. Check 對應的claim是否存在
2. Check 申請的R𝒾是否avaialble（是：goto 3./否：等待）
3. 試算：claim edge 改成 Allocation
4. 執行Safe Algo. （有cycle:否決/沒cycle:核准）

### 若每種res.都只有一個->可用RAG「簡化」-> 使用Wait-For Graph

Wait-For Graph**

> 移掉res.，變成P1等待P2的關係圖(有circle就有deadlock)

---

## Recovery

1. Process 在deadlock時終止
   - （法ㄧ）終止所有process: [cost高]過去的成果全白費
   - （法二）一次==中止==一個process直到deadlock cycle消失：[cost高]需不斷執行[Detection Algo.](Detection%20Algo..md)
2. [Resource Preemption](Resource%20Preemption.md)

> 缺：cost 高，注意[starvation](../CH4%20Process%20Management%20&%20Tread%20Management/starvation.md)
