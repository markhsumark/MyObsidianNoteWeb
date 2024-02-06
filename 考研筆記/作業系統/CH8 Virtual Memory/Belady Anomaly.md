# Belady Anomaly
>定義：分配給*process的頁匡(frame)數增加*，照理page fault ratio 應當下降，但是其*page fault ratio竟然不降反增之異常現象*

### 例：
給page 參考：1,2,3,4,1,2,5,1,2,3,4,5
~~建議記下此題目~~
圖示

## Stack Property
>定義：*n個frames所包含的pages set，必定是(n+1)的frames所包含的pages set之子集合*，此性質稱之：**具有stack property 之法則**，絕不會發生Belady Anomaly

>==OPT及LRU法則具有stack property==
所以他們不會發生Belady Anomaly