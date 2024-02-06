~~當時該page有被access，register最左邊補 1 ~~

>定義：
>==每個page== 會有一個欄位(Register)==保存最近幾次的ref. bit 值==，每隔一段時間system會做...
>1. 每個page's register ==右移一位==，空出==最左（最高）==位元
>2. copy page 的ref. bit 到register之最高位元
>3. ref. bit reset 為0
>
>將來，要==挑選register值最小的page ==為victim page。
>若多個register值相同，則以FIFO為準
>
>`越近被access，register值越大`



