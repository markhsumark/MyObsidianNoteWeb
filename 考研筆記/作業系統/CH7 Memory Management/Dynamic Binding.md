---
date created: 2022-12-27 00:05
date updated: 2022-12-27 10:26
---

# Dynamic Binding

> 定義\
> 程式執行之memory 起始位置delay到execution time 才動態的決定\
> ->process執行時，OS可以任意移動process的位址，且仍可正確執行

**優點**

- 增加OS對memory管理彈性度
- 有助於compaction的實施

**缺點**

- Process執行時間較長 叫沒有效率
- 需要extra hardware support

==**Hardware support**==
由MMU（硬體單元）將邏輯位置轉到實際位置
