# Disk scheduling Algorithm #⭐️⭐️⭐️⭐️⭐️

在 Disk queue會有多個track access requests，OS如何安排服務順序使得==tracks movement== 數較少，此為Disk scheduling目的

```ad-note
title:沒有最差，也沒有最佳的法則
```


| FCFS     | SSTF         | SCAN   | C-SCAN     | LOOK                 | C-LOOK                   |
| -------- | ------------ | ------ | ---------- | -------------------- | ------------------------ |
| 先進先出 | 最短距離先出 | 來回掃 | 單一方向掃 | 來回掃（不會撞到底） | 單一方向掃（不會撞到底） |

tip: C代表單一方向（中途不會改變掃描的方向）


## FCFS(First-Come-First-Servie)

> 定義：早來的track request優先服務

例：Disk 有200track，編號0~199，**Head目前停在53**，剛服務完60，現有下列track requests**依序到達**`98, 183, 37, 122, 14, 124, 65, 67`，求track 移動總數？
`|98-53|+|37-183|+|122-37|+|14-122|+|124-14|+|65-124|+|67-65| = 640`

```ad-attention
title:!!!不准算錯
```

**分析：**

1. Simple, 易於實施
2. 公平，No [Starvation](../CH4%20Process%20Management%20&%20Tread%20Management/starvation.md)
3. 排班效果不是很好，移動數度稍多->平均seek time偏長

## SSTF(Shortest Seek-time Track First)

> 定義：目前離Head位置最近的track request優先服務

例：呈上
ans:服務順序: 53-> 65-> 67-> 37-> 14-> 98 -> 122-> 124-> 183

**分析：**

1. 不公平，可能有[Starvation](../CH4%20Process%20Management%20&%20Tread%20Management/starvation.md)
2. 效果不錯，seek-time平均較短。

## SCAN

> 定義：Head來回移動掃描，育有Track request立刻服務。==（！！到兩端才會改變方向）==

例：呈上
![](../img/截圖%202022-12-05%20下午7.00.55.jpg)

**分析：**

1. 排班效果尚可
2. _適用於大量track requests(overload重)的時候可獲得較均勻地等待時間_
3. 在某一些時刻對於某些track request似乎不盡公平 。==Note:C-SCAN==
4. Head 非得遇到兩端才折返，此舉浪費不必要的seek-time ==Mote:用look改善==

## C-SCAN

> 定義：SCAN之變形，提供「單向」服務

Note:計算有爭議
最多版本

1. 回程的移動時間不列入
2. 回程的移動時間列入
3. 加1軌

## Look

~~提早折返的SCAN~~

> 定義：類似SCAN，差別：Head在「服務完該方向之最後一個track request後就會折返」

## C-Look

~~單向的Look~~