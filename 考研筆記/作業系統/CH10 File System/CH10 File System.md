---
date created: 2022-12-14 19:08
date updated: 2022-12-29 16:36
---

# File open 與 close動作

> **緣由**
> OS對File進行任何運作(e.g read, write, change name,...)之前，_皆須先找到Disk中之**phsical Directory** ，進行搜尋，找到該File_

然而，有下列問題：

1. search time太長：因爲file數目太多
2. I/O次數多：因為phy. Directory 放在Disk中

所以才有File open & close 運作

## File open

> 定義：
> OS會在Memory 中建立一個table 叫做"open file table"，
> 若File _第一次_被使用時，OS會到Disk之physical Directory 找出他的配置資訊，**會copy 此資訊到 open File table** 。
> 將來OS進行任何運作前，只需_**到此表格中進行search**_ 即可

優點：

1. search Time 很小（一般才存20~30左右個檔案之配置資訊）
2. 存取速度快

## File close

> 定義：
> 當File不再使用了，OS會將open file table 中此file 之配置資訊 存回Disk中之physical Directory ，且open file  table 在刪去此一資訊

## 檔案共用

> 若考慮File被多個Processes共用，則system會create 2類的open file table
>
> 1. system-open-file-table：只會存放此_共用file_之共通配置資訊
> 2. process-open-file-table：保存該process對於檔案存取的個別資訊 （e.g存取權利、目前File pointer 位置）

# Consistency semantic

(一致性語意)
主要是討論_File共享之模式_及一些權利
有三種semantic：

1. UNIX semantic：
   例如：座次表（賣票系統）被多個Processes共用
   - 需互斥存取控制
   - 大家看到的內容是一致的
   - 某個process對他改變內容其結果是**visible to all**
2. session semantic：
   例如：空白報名表，供人下載使用
   - 不需要互斥存取控制
   - 大家看到的內容不見得一致
3. Immutable semantic：
   例如：總經理公告文件第0036號
   - 不可更改、read only、檔名不可重複

# File Access Control

`以UNIX為例（交大喜歡問）`

將File 之_user_分為三級

1. Owner：File建立者
2. Group(or member)：被Owner指定成為group member 者
3. others(or universal)：其他user

將File 之_存取權利_分為三級

1. r: read
2. w: write
3. x: execute

---

例：
`{Owner}{Group}{others}`

`rwx r-x --x` -> `111 101 001` -> `751`
=>命令 `chmod File-Name 751`

~~p343練習~~
