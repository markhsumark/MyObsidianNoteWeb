Compaction 技術
~~移動執行中的process使其在memeory 連續~~
> OS藉由==移動「執行中的process」==使得原本非連續的holes, 得以==聚集形成一個連續的hole==

**優點**

- 解決外部碎裂

**缺點**

- 不易制定optilam compaction plicy
- process必須是[Dynamic Binding](Dynamic%20Binding.md)才可支持