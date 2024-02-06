
> 在Disk中直接將這些free Blocks 以 Link list方式串連

優點

1. 適用於大型Disk
2. 加入刪除方便

缺點
1. 不易找到連續的free Block
3. 不易迅速找到大量的free Block(在Disk 中，沿著linking 找，這是I/O運作)