page

實際記憶體以固定size切分 -> 一塊就是一個frame
邏輯記憶體以固定大小切分 -> 一塊就是一個page

> 1. 採用**非連續性**配置策略
> 2. "physical" memory(i.e. RAM)：是為（切成）一組frame(頁框)之集合，且各frame size均相同  `NOTE:由硬體決定frame size，非ＯＳ`
> 3. "Logical" Memory：視為一組Page頁面集合且page size = Frame size  `NOTE:Page 採用physical viewpoint`
> 4. 配置方式：
>    令Process 大小 = n 個pages，則OS必須在physical Memory 中找到n個free frame(==不一定要連續==)\
> 所以！OS必須對==每一個Process建立他們的Page Table(分頁表)==，記錄各個page被放置的frame No.\
> ==NOTE:Page Table is kept in *kernel的PCB*中"memory management info."==


**優點**

- 解決[外部碎裂](External%20Fragmentation(外部碎裂).md)
- 支持Memory sharing & memory Protection之實施
- 支持[Dynamic loading](Dynamic%20loading.md) linking& Virtual memory實施

**缺點**

- 有[內部碎裂](Internal%20Fragmentation%20(內部碎裂).md)
- 需要額外硬體支援（MMU）
- Effective Memory Access Time([EMAT](../CH8%20Virtual%20Memory/CH8%20Virtual%20Memory.md#EMAT計算%20⭐️⭐️⭐️⭐️))會較久
- Increase context switch time
