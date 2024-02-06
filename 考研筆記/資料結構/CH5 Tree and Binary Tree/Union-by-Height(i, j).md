Union-by-Height(i, j)
> 樹較高的做New Root。若高度相同，則任意
> ~~也就是*矮的塞到高的tree裡*~~
> 只有兩個高度同的tree union起來，高度才會增加（加一)

![400](../img/截圖%202022-10-12%20下午2.20.46.jpg)
```C
Union-by-Height(i, j){
   if(Height(i) >= Height(j)){
	   if(Height(i) == Height(j))
		   Height(i)++;
		j->Parent = i;
   }
   else{
	   i->Parent = j;
   }
}
```
O(1)

**分析**：
若一開始*n個單一元素sets經過n-1次union後，創造的tree高度=`O(logn)`*

故Find(x)平均一次花O(logn) time