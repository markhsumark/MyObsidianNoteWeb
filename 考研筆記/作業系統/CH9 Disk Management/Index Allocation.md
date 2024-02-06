---
date created: 2022-11-02 20:57
date updated: 2022-12-28 19:55
---

# Index Allocation

~~用額外的Index Block指向所有分配的Block~~

> 定義：若File 大小= n 個Blocks，則OS除了_配置n個free Blocks_ 給他之外，另須_**額外**_配置 ==Index Block==給他，記錄所有Allocated Data Blocks之No.

例：
![150](../img/截圖%202022-11-02%20下午8.44.17.jpg)
File 3 大小 = 4 Blocks
則OS配置`12, 6, 4, 9`號Blocks給他，==另外配置15號作為Index Block==，且在"physical" Directory 中紀錄下列配置資訊

| File name   | Index Block No |
| ----------- | -------------- |
| File 3      | 15             |
| Index Block |                |

| 15 |   |   |   |   |
| -- | - | - | - | - |
| 12 | 6 | 4 | 9 | - |

優點：

1. 沒有外部碎裂
2. 可支援[Random(Direct) Access](Random(Direct)%20Access.md)及sequential Access
3. 可以動態擴充大小
4. 建立File前於須事先宣告大小

缺點：

1. Index Blocks佔用額外空間
2. linking 欄位之overhead/浪費（不論有幾個linking 都是佔用一樣「大」的空間）
3. 若File 大小很大則可能*單一一個Index Block無法記錄全部*

# 解決單一Index Block不夠容納所有Data Blocks' No.之方法

## [法ㄧ] 使用多個Index Blocks且彼此以link方式串連

## ~~看起來像link list~~
用==Index Blocks中的其中一個索引紀錄下一個Index Block的No.(Address)==
缺點：存取ith資料的平均I/O次數增加

## [法二] Multilevel Index structure法

~~看起來像tree~~
例：(2 level)
優點：存取ith Block之I/O次數為固定值（固定`level數+1`)
缺點：極不適合小型檔案

## [法三] [I-Node](I-Node.md) #⭐️⭐️⭐️⭐️⭐️
