# Deadlock Free
若系統中有n個process，m個res.數量(單一類)，則滿足2條件就保證Deadlock Free
1.  1<=MAX𝒾<=m ~~資源數量大於總需求~~
2.  ∑ MAX𝒾 < n+m ~~每個人全部所需小於資源總量加process數量(鴿洞定理)~~