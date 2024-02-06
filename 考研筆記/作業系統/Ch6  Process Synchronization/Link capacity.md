>定義：  
>在每一條Communication link 皆附屬有一個messages Queue, 除了正在傳輸的訊息之外，其他sender送出之messages皆放在此Queue中  
  
這個**Queue的大小即為Link Capacity**

**收方** ~~必等~~
「一律規定：要收到message後才可往下執行。」

**送方**
由Link Capacity決定sync mode
- [Zero capacity](Zero%20capacity.md) ~~送方要等回覆~~
- [Bounded capacity](Bounded%20capacity.md) ~~送到對方信箱已滿~~
- [unBounded capacity](unBounded%20capacity.md) ~~送就對了~~