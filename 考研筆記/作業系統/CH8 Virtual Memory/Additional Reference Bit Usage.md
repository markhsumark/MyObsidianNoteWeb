## 作法
- 每個page會有一個register  紀錄最近幾次Ref. Bit之值。
- 系統每隔一段時間會執行下列工作
	1. 每一個頁面的暫存器均右移一位（最右（低）的位元捨棄，空出最左（高））
	2. Copy page 的Ref. Bit值到register 之最左位元
	3. Reset their ref. Bit 為0
- 將來OS若要select victim , OS會選擇register值最小的page ，若有多個page 具有相同值，則採FIFO
==NOTE:所有的LRU近似法則皆可能退回成FIFO==

![[../img/image 3.jpg]]