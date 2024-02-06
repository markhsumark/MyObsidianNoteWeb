# Second chance
作法：以[FIFO](FIFO.md) order為基礎*Reference Bit* 使用
>刷新他的資訊

steps:
1. 若next page存在，reset it's R.Bit = 1
2. 先以FIFO order排出一個page
3. check page 的R.Bit
	- case1: 若為0，則他即是victim page
	- case2: 若為1，則
		1. 給他機會，先留在記憶體
		2. Reset it's R.Bit = 0
		3. Reset loading time(改為現在時間)，變成最晚排入的
		4. goto 1.

```ad-example
![400](../img/截圖%202022-09-24%20下午2.52.55.jpg)
箭頭指向FIFO order的最後一個
![450](../img/截圖%202022-09-24%20下午2.53.01.jpg)
```