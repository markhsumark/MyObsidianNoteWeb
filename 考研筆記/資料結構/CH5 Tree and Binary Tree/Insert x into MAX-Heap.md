### Insert x into MAX-Heap

> x放末端，向上比大小到輸

**steps**:

1. x先放在末端後一個位置
2. x向上挑戰父點（比大小，比父大就對換）
3. 重複2.到失敗

**Time分析**:因為x最大移動從底到高，即為樹高。又Heap是Complete B.T -> _**O(logn)**_