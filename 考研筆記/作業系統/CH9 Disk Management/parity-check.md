---
date created: 2022-12-05 21:05
---

# parity-check技術

> 定義：對N部正常使用的Disks再額外配置**一部**Disk作為Parity-check Disk。所以共需`N+1`部Disks
> Data寫入時，除了Data Block存入之外，另需額外花時間求出_parity-check Block_內容，然後寫入_Parity Disk_

![](../img/截圖%202022-12-05%20下午9.03.49.jpg)
將來，若某一Data Block is BAD 則可用其他Data Blocks和parity Blocks再做「偶同位」，即可回覆
優點：成本便宜
缺點：

1. 可靠度比[mirror](Mirror.md)低
2. Data recovery speed 慢於[Mirror](Mirror.md)
3. 需花額外時間求parity Block，write速度較慢
