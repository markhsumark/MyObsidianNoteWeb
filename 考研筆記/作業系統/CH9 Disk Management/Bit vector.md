## Bit vector

> 定義：
> 每一個Block用一1Bit表示配置與否（0:free, 1:allocated）
> 若Disk有n個Blocks 則its Bit vector = n bit

優點

1. Simple, easy implementation
2. 適用小型Disk
3. 容易找到連續的free Blocks

缺點

1. 不適合用在大型的Disk(要是Bit vector多到無法載到memory中，部分Block就無法讀取)