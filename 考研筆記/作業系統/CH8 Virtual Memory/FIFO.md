---
date created: 2022-09-24 15:12
date updated: 2022-09-24 15:13
---

# FIFO

~~應該不用多說了吧，最簡單的~~

> 定義：最早載入的page作為victim page

```ad-example
**Q**:給予3個frames, they are all empty initially, 
給予下列page reference string(也就是page number)
求page fault次數?
7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1
(or page size = 100, string = 742, 302, 492, 089, ...)

**ANS:**
圖示
![400](../img/296AF51D-F3CC-4760-95BD-4285CD97B985.jpeg)
```

#### 分析：

- page fault ratio 相當高，效果不佳
- Simple, easy製作
- _**可能有[Belady Anomaly](Belady%20Anomaly.md)**_

==NOTE:在所有replacement法則中，沒有最差的==


