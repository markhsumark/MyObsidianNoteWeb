---
date created: 2022-12-05 20:52
---

# Mirror(or shadow)技術

~~存兩份資料~~

> 定義：對每一部正常的Disk均配置一部_mirror Disk_，Data 除了寫入正常Dusk以外，也同步存入Mirror disk 中
> 若有N部正常Disks，另需配置N部Mirror Disk

EX:
若有4部正常的Disks，容量各1TB，則採Mirror機制
需要`8`部Disks。
可以儲存的最大容量= `4TB`

優點：

1. 可靠度最高
2. Data recovery速度最快

缺點：

1. 貴！！
