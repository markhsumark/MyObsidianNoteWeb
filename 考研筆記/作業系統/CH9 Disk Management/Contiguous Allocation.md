---
date created: 2022-12-28 19:49
---

> 定義：若File 大小 = n個Blocks，則OS必須在Disk中找到n個_連續的_free Blocks，才能配置給他

例：
![150](../../資料結構/img/截圖%202022-11-02%20下午8.10.11.jpg)
File 1 大小 = 3 Blocks
則OS配置_5, 6, 7_號Blocks給他且在"physical" Directory 中紀錄下列配置資訊

| File name | Start Block No. | size |
| --------- | --------------- | ---- |
| File 1    | 5               | 3    |

**分析**
優點：

1. 平均的seek time 較短（因為連續的Blocks大多落在同一條track上）
2. 可支援*[Random(Direct) Access](Random(Direct)%20Access.md)* 及_sequential Access_
3. 可靠度較高（than linked Allocation)
4. 訓序存取速度快（than linked Allocation)

缺點：

1. 會有[外部碎裂]問題
   > [!NOTE] 在Disk中是要Repack（磁碟重組）解決外碎，類似於 Memory 中之 Compaction
2. 檔案大小不易擴增
