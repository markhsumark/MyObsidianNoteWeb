---
date created: 2022-10-25 21:20
date updated: 2022-10-26 16:40
---

```toc
```

## 簡介

### 定義

> 定義：是一種data_儲存_與_搜尋_之機制，欲存取資料時，需先經過==Hashing function== 計算，求出==Hash address==，依此位址到==Hash Table==中對應的Bucket 存入或找出資料x
>
> 而Hash Table 結構主要是由B個Buckets組成，每個在由S個slots（槽）組成，每個slot可存一筆Data
> `Hash table size = B * S`
> ![300](../img/截圖%202022-10-26%20下午2.35.23.jpg)

### 相關術語

1. **Idenetifier density**(識別字密度):`n/T` & **Loading density**(負載密度):`n/(B*S) = 𝞪`
   𝞪越高Table利用度越高，但相對_collision_也多
   > - T為identifier總數
   > - n為目前用到的identifier個數
   > - B * S 為hash table size
2. **collision**(碰撞)
   > 不同的data，經由hashing function計算後，得出_相同的hash address_，謂知==碰撞==
3. **overflow**(溢位)
   > 當_collision發生_且對應的_Bucket中無空間可存_，稱之。
   >
   > ```ad-note
   > title: Note
   > collapse:none
   > 1. 有collision，**不一定**會overflow
   > 2. 有overflow，**必定有**collision
   > 3. 若每一個Bucket只有一個slot，則collision = overflow
   > ```

### 優點

1. 以searching 而言，data不需事先排序，且若每有collision下，_search for xi之time = O(1)，與資料量n無關_。
2. 保密性高，若不知Hashing function，則無法取得資料。
3. 可做資料壓縮、密碼學、Block-chain等應用。

## Hashing function Design

一個良好的Hashing function Design，宜滿足：

1. 計算宜簡單
2. collision宜少
3. 不要造成Hash Table局部儲存之情況（分布均勻）

名詞：

1. _Perfect_ Hashing function:此函數_保證不會發生collision_
2. _Uniform_ Hashing function:此函數保證_每個Bucket內Data數約莫相等_(~= n/B)
3.

### criteria

#⭐️

### 常見的設計方法

（四種）

1. [middle square](middle%20square.md)
2. [除法Division or Mod](除法Division%20or%20Mod.md)
3. [Folding Addition](Folding%20Addition.md)
4. [Digits Analysis](Digits%20Analysis.md)

## overflow 處理方法

#⭐️⭐️⭐️⭐️⭐️

### Linear probing

線性探測

> 當H(x)發生overflow，則探測`(H(x)+i)%B` Bucket，其中B是Bucket數目(i = 1~B-1)，直到有空的Bucket或表格全滿。

```ad-example
例：hash function: H(x)= x%10 採取linear probing處理overflow，今有下列Data依序存入empty Hash Table(Hash Table有10個，每個Bucket只有1個slot)
`Data = 33, 13, 19, 23, 15, 10, 29, 25`
求table內容？找23, 15個字需比較幾次才能找到？

---

![80](../img/截圖%202022-10-26%20下午4.00.13.jpg)
```

**分析**

- 優點:
  1. simple
  2. 保證table空間可以充分利用
- 缺點:
  1. 容易形成[Primary clustering](Primary%20clustering.md) 現象，造成平均searching x時間大幅增加之不良效應

### Quadratic probing

(二次方探測)

> 當H(x)發生overflow，則探測`(H(x)± i²)`Bucket  (i = 1~B/2)，直到有空的Bucket or 探測的都滿了。

```ad-example
例：hash function: H(x)= x%10 Quadratic probing處理overflow，今有下列Data依序存入empty Hash Table(Hash Table有10個，每個Bucket只有1個slot)
`Data = 33, 13, 19, 23, 15, 10, 29, 25`
求table內容？

---
![200](../img/截圖%202022-10-26%20下午4.00.56.jpg)
```

**分析**

- 優點：
  解決[Primary clustering](Primary%20clustering.md)問題
- 缺點：
  1. 表格空間不見得充分利用（有些探測不到）
  2. 會有[Secondary clustering](Secondary%20clustering.md)問題，造成search time增加。

### Double Hashing

> 令H1為Hashing function，當H1(x)發生overflow，則探測`(H1(x)+i*H2(x))%B`，其中*H2(x)函數在求探測距離/間隔* (i= 1,2,3...直到有空Bucket or 探測格子)
> 此外H2之格式為`(R-x%R)，R為質數`(依題目為主)

```ad-example
例：hash function: H1(x)= x%10, H2(x)=7-(x%7) Double Hashing處理overflow，今有下列Data依序存入empty Hash Table(Hash Table有10個，每個Bucket只有1個slot)
`Data = 33, 13, 19, 23, 15, 10, 29, 25`
求table內容？

---
![200](../img/截圖%202022-10-26%20下午4.20.11.jpg)
```

**分析**

- 優點：
  解決[Secondary clustering](Secondary%20clustering.md)以及[Primary clustering](Primary%20clustering.md)問題
- 缺點：
  不保證table空間可以充分利用



### Chain probing

> 具有相同hashing adress之資料均放到同一個Bucket中，而Bucket內之Data是以link list串接
> 是屬於"close" addressing mode
> (其他則是open)

```ad-example
`Data = 33, 13, 19, 23, 15, 10, 29, 25`
求table內容？

--- 
![200](../img/截圖%202022-10-26%20下午4.29.14.jpg)
```

**補充**
![40](../img/截圖%202022-10-26%20下午4.46.00.jpg)
### (不考)rehashing

> 提供一系列的Hashing function，使用Hi發生overflow，則改用Hi+1
