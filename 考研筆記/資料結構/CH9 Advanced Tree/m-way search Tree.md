m-way search Tree #⭐️⭐️⭐️⭐️⭐️

(Tree's Degree = m)

> 緣由：在"[external search/sort](../CH9%20Advanced%20Tree/external%20search%20or%20sort.md)"，==效能關鍵在於降低I/O次數==，通常在Disk內資料區塊，一般都用search Tree結構維護，而其高度 = 最多的I/O次數
> =>**_降低seach Tree高度才可降低I/O次數_，而有效辦法即是加大Tree's Degree***

```ad-example
title:m-way search Tree高度 = h。(1)求最多Node數(2)最多key(or Data)數
![300](../img/截圖%202022-10-14%20下午4.18.22.jpg)
= (m^h-1)/(m-1)

---

= (m^h-1)/(m-1) \* (m-1) = m^h - 1
```

```ad-question
title:m-way search tree Node數 = n，求最小高度=?
`m^h -1 = n`
`h =  ⎡log𝚖 n+1⎤`
```
