~~混合式的[Index Allocation](Index%20Allocation.md)~~
![](../img/截圖%202022-12-05%20下午6.16.51.jpg)
結構
例：15個entry。其中(**依照題意**)：
- 1~12格：紀錄Data Blocks No
- 13格：*pointer* to Single-level Index structure
- 14格：*pointer* to Two-level Index structure
- 15格：*pointer* to Three-level Index structure

```ad-example
collapse:none
I-node 有15個entry(規定如上)
Block size = 8KB
Block No. (Address/pointer)佔4bytes

---
求 MAX File size

一個Index Block可以存 `8KB/4Bytes = 2¹¹`個Block No.
MAX File size = `(12+2¹¹+(2¹¹)²+(2¹¹)³)`個Data  = `(12+2¹¹+(2¹¹)²+(2¹¹)³)*8bytes`

---
有一File 大小 = 6000個Blocks。若要直接存取其第5000個Data Block內容，需要幾次Block I/O?（假設I-Node已在Memory中）

5000 -12 -2048 = 2940 (用了1~13)
2940 -2048 = 892 (用了14-1)
-> 用在14指向的Block 的第二個指向的第892個No 指向的資料
-> 3次

---
若要循序(sequence)存取此File的前5000個Data Blocks 則需?次I/O?

依照上題
5000th落在14Block下的 第2Block下的 第892個
前面有2048落在 2 level裏
-> `3*(892+2048)+ 2*2048+ 1*12`
```