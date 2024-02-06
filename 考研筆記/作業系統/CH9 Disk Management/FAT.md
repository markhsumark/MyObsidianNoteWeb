~~把指標存在一起的linked allocation（追蹤只要讀pointer不用整個block）~~

>定義：是[Linked Allocation](Linked%20Allocation.md)的變形
>差別：將原本存於Disk中Blocks之==linking info 存於Table中==，不用存於Disk之Allocated Blocks。
>當OS在做File Allocation 及accsee時，FAT會置於Memory中
>如此OS可*在 Table(in Memory)取得Allocated Blocks 間的linking info*，加速存取Data Blocks

優點：
1. 可改善傳統[Linked Allocation](Linked%20Allocation.md)方法無法快速存取ith Block（[Random(Direct) Access](Random(Direct)%20Access.md)）之問題
   （==因為FAT在memory裏，不像原始的link allocation需要不斷地讀取Disk==，藉由追蹤FAT的pointer，就可以得到ith個block）

例：
![150](../img/截圖%202022-11-02%20下午8.44.17.jpg)
File 2 大小 = 4 Blocks
則OS配置*5, 10, 8, 13*號Blocks給他且在"physical" Directory 中紀錄下列配置資訊

| File name | FAT entry(即start Block No.) |
| --------- | ---------------------------- |
| File 2    | 5                            |

![150](../img/截圖%202022-11-02%20下午8.50.42.jpg)

```ad-question
![](../../img/截圖%202022-12-29%20下午3.04.30.jpg)
```
