### Delete-MAX in  MAX-Heap

> 末端拉到第一個，再從上往下重新排序

**steps**:

1. remove Root資料
2. 把最後的Node資料移到Root
3. 從Root(x)往下調整。~~x向下移動到符合的位置~~
   1. 找出左右子點最大值
   2. if x < M then M往上x往下
   3. 重複b.直到x >= M

**Time分析**:同Insert