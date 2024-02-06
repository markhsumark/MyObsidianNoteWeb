---
date created: 2022-09-14 15:46
---

## _Modification Bit_

> 用以表示page Content是否曾經被修改過自上次載入貨reset此Bit後

- 若Bit = 1:表曾被修改過
- 若Bit = 0:表未曾被修改過

### 使用方式：

OS selects a Victim page後，check 該 Bit 值

- 若Bit = 0:無需swap out
- 若Bit = 1:需swap out
