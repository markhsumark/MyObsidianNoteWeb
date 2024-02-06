---
date created: 2022-12-27 15:07
---

Dynamic loading #⭐️

> 目的：節省記憶體空間
> 呼叫程序時，會先檢查memory內有沒有此程序，沒有才會load近來

不需要OS額外的支援（這是programmer or loader的責任）

**缺點：**
process執行時間較久、較不具效率。尤其還牽扯到I/O.
