---
date created: 2022-10-29 18:29
date updated: 2022-10-31 20:47
---

# Array 中元素儲存位址計算 #⭐️⭐️⭐️

## 一維陣列

![200](../img/截圖%202022-10-29%20下午6.37.22.jpg)

## 二維陣列

![400](../img/截圖%202022-10-29%20下午7.17.01.jpg)

四大題型

1. 給所有必要資訊，求A[i, j]位址
   ![400](../img/截圖%202022-10-29%20下午7.17.19.jpg)
2. 給兩格已知元素位址以及d，求其他資訊
   key:需自行判斷row or column major
   ![](../img/截圖%202022-10-29%20下午7.22.47.jpg)
3. 給兩個已知元素位址及d，但判斷出Row Col major皆可能，則兩者皆需求算
   ![500](../img/截圖%202022-10-29%20下午7.29.15.jpg)
4. 給予三個元素位址判斷出Row or Col major後求出3個未知數(m, n, d)

```ad-quote
title: 若題目宣告A[m][n]，等同於A[0..m-1][0..n-1] （同C語言）
```

## 3, 4..., N維陣列

> ≧2維陣列，儲存方式也是兩種
>
> - Row-major:由左而右看待 ---->
> - Colemn-major:由右而左 <---

![500](../img/截圖%202022-10-31%20下午2.42.43.jpg)

# 特殊矩陣之有效儲存方法

## 上、下三角矩陣

| -                      | 下三角矩陣                  | 上三角矩陣       |
| ---------------------- | ---------------------- | ----------- |
| 實際空間                   | `n(n+1)/2`             | 同左          |
| 位置                     | 左下方包含對角線有元素            | 右上方包含對角線有元素 |
| A[i, j]-> 三角。Row-major | `i(i-1)/2 + j`         | i, j互換      |
| A[i, j]-> 三角。Col-major | `n(j-1)- j(j-1)/2 + i` | i, j 互換     |

下三角矩陣

1. Row-major:
   k = `{前面i-1（橫）列的元素}+{第i列上的第？格}`
   = `i(i-1)/2 + j`
2. Col-major:
   k = `{前面j-1行的元素}+{第j行上的第？格}`
   = `n(j-1)-(0+1+2+..+(j-2)) + i-(j-1)`
   = `n(j-1)- j(j-1)/2 + i`

上三角矩陣

1. Row-major:
   k = `{前面j-1列的元素}+{第j列上的第？格}`
   = `j(j-1)/2 + i`
2. Col-major:
   k = `{前面i-1行的元素}+{第i行上的第？格}`
   = `n(i-1)-(0+1+2+..+(i-2)) + j-(i-1)`
   = `n(i-1)- i(i-1)/2 + j`

![300](../img/截圖%202022-10-31%20下午3.28.14.jpg)

## 對稱矩陣

> 定義：A是nxn矩陣且A[i, j] = A[j, i]

有效存放方式：
只存在上三角or下三角

```ad-question
![](../img/截圖%202022-10-31%20下午4.05.54.jpg)
![](../img/截圖%202022-10-31%20下午4.06.06.jpg)
```

## 寬帶矩陣

> 令A (a, n, b) 是一個Band Matrix
> 代表：
>
> 1. A是一個nxn矩陣
> 2. A中對角線（含）左下a條斜線是元素
> 3. A中對角線（含）右上b條斜線是元素
> 4. 其他是空(0)
>
> ![150](../img/截圖%202022-10-31%20下午3.57.11.jpg)

![400](../img/截圖%202022-10-31%20下午4.06.29.jpg)

![400](../img/截圖%202022-10-31%20下午4.28.02.jpg)

# Link List種類 #⭐️⭐️⭐️⭐️⭐️

| Double link list  | Single link list |
| ----------------- | ---------------- |
| linking 具有兩個方向    | 1個方向             |
| 可立即知道左右Node       | 只知道單一邊的Node      |
| 從任何點皆可拜訪所有Node    | 一定要從第一個          |
| 可靠度高              | 可靠度低             |
| 刪除Node x時只需給x指標即可 | 必須要給x和x前一個Node   |
| 插入麻煩（修改四個pointer） | 插入簡單(2個)         |
| 刪除麻煩              | 刪除簡單(1個)         |
| 空間需求大             | 空間需求小            |

## Single

回收single link list

反轉single link list #⭐️⭐️⭐️⭐️⭐️
![200](../img/截圖%202022-10-31%20下午4.41.40.jpg)

## Circular

> 特性：
>
> 1. 不論從何點開始都可以辦訪所有點
> 2. 回收整條給AV-list, 及連結兩條串列 ->O(1)

回收整條list給AV-list
![200](../img/截圖%202022-10-31%20下午4.55.02.jpg)

Concatenate（連結） A, B兩個Circulat link list
![200](../img/截圖%202022-10-31%20下午4.55.17.jpg)

## Double link list

**Insert** #⭐️⭐️⭐️⭐️⭐️
insert t node after x node
![200](../img/截圖%202022-10-31%20下午5.09.53.jpg)
**Delete**
delete x node
![200](../img/截圖%202022-10-31%20下午5.10.09.jpg)

# Array v.s. List 比較表

| Array                   | List                    |
| ----------------------- | ----------------------- |
| 佔用Memory連續空間            | 可以隨意擺（只要有空間）            |
| Array 中個元素_型態要相同_       | 型態可不同                   |
| 可支援[Random(Direct) Access](../../作業系統/CH9%20Disk%20Management/Random(Direct)%20Access.md)        | 無法，只支援sequential Access |
| sequential Access速度快    | 慢（須讀取Node才知道下一個Node所在）  |
| 可靠度高                    | 低（if link 斷了）           |
| 插入刪除不便（需動到其他元素）         | 插入刪除方便                  |
| 空間無法動態擴充                | 空間可以動態擴充                |
| 無法支持共享（兩個變數無法用同一個Array） | 可支持共享                   |

# Generlize list（一般化串列） #⭐️⭐️⭐️

> 定義：令A=(a1, a2, ..., an)是general list，其中ai是A中的元素，而且ai的type有兩種:
>
> 1. Atomic data
> 2. Sublist

**術語**

1. |A|:A中的元素個數
2. Head of A: A中的第一個元素
3. Tail of A: A中除了Head以外的元素_集合_，是一個generalize list

![250](../img/截圖%202022-10-31%20下午5.33.19.jpg)
**Data Structure** #⭐️⭐️⭐️
![300](../img/截圖%202022-10-31%20下午5.39.56.jpg)

**Generalize list 之 recursive operations**

1. Copy 一條串列
2. Equal(S, T):判斷兩串列是否相同
3. Depth(S):求S串列深度

```ad-attention
title:下列皆不可作用在recursive的General list e.g: C = (a, C)
```

---

copy

```C
Copy(orig){
	if(orig == Nil)t = nil;
	else{
		new(t);
		t->Tag = orig->Tag;
		if(orig->Tag == False)
			t->Data = orig->Data;
		else
			t->dlink = Copy(orig->dlink);
		t->Next = Copy(orig->Next);
	}
	return t;
}
```

---

Equal(S, T)

```C
Equal(S, T){
	res = False:
	if(S==Nil and T == Nil)res = True;
	else if(S != Nil and T != Nil){//都還有Node 
		if(S->Tag == T->Tag){
			if(S->Tag == False){// 用Atomic data的情況
				if(S->Data == T->Data)
					x = True;
				else x = False;
			}
			else //用dlink的情況
				x = Equal(S->dlink, T->dlink);
			if(x == True)
			res = Equal(S->Next, T->Next);
		}
	}
	return res;
	
}
```

---

Depth(S) ~~往下延伸幾層~~
= 0, if S是空串列
= 1+MAX{depth(ai) | ai為S中子串列元素}, otherwise

```C
Depth(S){
	if(S == Nil)return 0;
	else{
		MAX = 0;
		P = S;
		while(P != Nil){
			if(P->tag == True){
				n = Depth(p->dlink);//子串列深度
				if(n > MAX) 
					MAX = n;
			}
			P = P->Next;
		}
		return MAX+1;//有遞迴才會加1 -> 有遇到sublist時
	}
}
```

# 多項式表示法 #幾乎不考

## 利用Array

**[法一]**
按照指數由高到低依序儲存個項次的 _係數值_
![300](../img/截圖%202022-10-31%20下午8.09.32.jpg)
缺點:若多項式A中有很多0項次 -> 一堆存0 ->浪費空間

**[法二]**
只存非0項次的 _指數和係數_
作法：若有k個非零項次，準備A[1..2k+1]
![200](../img/截圖%202022-10-31%20下午8.13.44.jpg)
缺點：若非零項次很多->浪費空間

## 利用Link List

**[法ㄧ]**
使用single (or 其他)link list 表示
![300](../img/截圖%202022-10-31%20下午8.19.57.jpg)
缺點：缺乏_一致性_的Node結構來表示各種多項式。

**[法二]** #⭐️⭐️
利用Generalize list觀念表示多項式

![500](../img/截圖%202022-10-31%20下午8.36.56.jpg)

# sparse matrix 表示法

稀疏矩陣 -> 0元素很多

## 利用Array表示

**[法一]**
直接利用mxn的陣列
-> 浪費一堆空間
**[法二]**
只存非0元素的資訊 <row, col, value>
作法：
若mxn sparse matrix中有k個非零元素
-> 準備A[0..k, 1..3]來存放

![500](../img/截圖%202022-10-31%20下午8.46.45.jpg)

## 利用"Double" link list表示
![500](../img/截圖%202022-10-31%20下午9.02.59.jpg)

