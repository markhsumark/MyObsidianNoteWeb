Race condition

> 定義：若多個process使用shared variable 溝通，若未對這些共享變數之read/write提供任何synchronization 控制機制，則共享變數之最終值可能會因processes之間的交錯執行順序不同而有不同的結果值，此一Data in consistency 之問題， 稱之

例：假設C是共享變數，初值=5