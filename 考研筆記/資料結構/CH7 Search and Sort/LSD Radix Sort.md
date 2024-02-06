# LSD Radix Sort
#⭐️⭐️⭐️⭐️ 考計算題

#stable 

1. 假設基底(or 進制)為r ->準備r個桶子，編號0~(r-1)
2. 令input data 中*最大值*之*位數個數*= `d`，代表要執行`d回合`，才可完成sorting
	```ad-question
	title: 如何知道MAX值位數個數？（等於*回合數*）
	collapse:none
	- [法一]：先花O(n) time找出MAX值
	- [法二]：已知（規定;限制）input data“值域範圍”~~此即為Radix sort關鍵~~
	```
	```ad-attention
	title:卡住/固定 回合數
	```
3. LSD：從*最低位數*開始，到*最高位數*執行各回合之工作。（例：pass1:個位數, pass2:十位數, ...）
4. 每一回合之2 個主要工作
	1. 分派：依資料某位數值分派到對應Bucket中
	2. 合併：依照Bucket *No:0~(r-1)*合併所有Buckets 之Data lists

```ad-note
title: LSD Radix Sort, 基底十進制。179, 208, 306, 93, 859, 984, 55, 9, 271, 33
![](../../img/截圖%202022-12-31%20下午2.59.16.jpg)
```

```txt
d是最大值位數個數
r是bucket數量
```

**分析**
1. Time Complexity: O(d*(n+r))
   說明：要執行d回合
   每回合：
   - 分派O(n)
   - 合併O(r)
	
	->每回合O(n+r)故total = O(d(r+n))
	`基底r可視為常數c1，因為值域受限d也可視為常數c2`
	`-> O(c2*(n+c1)) -> O(n)`
1. Space Complexity:O(r* n)
   ->額外空間需求=Bucket's total size
   ->要準備r個Buckets, 每個Bucket's size = n