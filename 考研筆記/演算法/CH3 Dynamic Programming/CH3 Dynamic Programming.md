---
date created: 2022-09-19 22:06
date updated: 2023-01-03 17:46
---

# CH3 Dynamic Programming

```toc
```

## 3.1 Introduction

**Dynamic Programming**為一個解決遞迴型態問題的策略，相對於Divide-and-Conquer，傾向於直接從子問題著手，將可能會參考到的子問題皆算出並存下。

1. D.P方法三要素
   1. 定義問題solution公式
   2. 列表求出最終結果。此表格用來保存先前算過（子問題）的答案
   3. 會reuse subproblem 之solution

實用例子： [Fibonacci number](Fibonacci%20number.md)
重要性質： [Optimal structure](Optimal%20structure.md)

**優缺比較**
～～～～

## 3.2 The rod cutting problem

假設銷售長度為i的rod可得pi元，i = 1, 2, ..., n，如何切一條長隊為n的rod使得收入最大化

> KEY:怎麼切可以讓左右兩段總和收益最高

### Rod-Cutting遞迴解

令rn為在長為n的rod可以獲得的最大收益，則

> rn\
> = max{p1 + rn-1, p2 + rn-2, p3 + rn-3, ..., pn}, if n>=1\
> = p0 = 0, if n = 0

```c
Rod-Cutting(p, n){
	if(n == 0){
		return 0;
	}
	s = -無限;
	for(int i = 1; i<=n; i++){
		if(s < p[i]+Rod-Cutting(p, n-i)){
			s = p[i]+Rod-Cutting(p, n-i);
		}
	}
	return s;
}
```

> T(n) = 1 + T(n-1) + T(n-2) + ... + T(0)\
> T(n-1) = 1 + T(n-2) + T(n-3) + ... + T(0)\
> T(n) - T(n-1) = T(n-1)\
> =>T(n) = 2T(n-1)\
> **_=>T(n) = 2ⁿ_**

### Rod Cutting DP

```ad-quote
利用[cut-and-paste](cut-and-paste.md)可以證明有[Optimal structure](Optimal%20structure.md)
```

r[n]:長度為n的rod之最大收益
c[n]:長度為ｎ的rod的左大段切點，用於記錄在長度為n時的所有斷點從1~n依序算出最大收益
r[n] = max{p1+ r[n-1], p2+ r[n-2], ....}

```C
int* RodCuttingDP(p, n){
	new r[1..n+1]
	new c[1..n+1]
	r[0] = 0;
	for(int j = 0; j<= n; j++){
		s = -無限;
		for(int i = 1; i<=j; i++){
			if(s < r[j-i]+p[i]){ //max{p1+ r[n-1], p2+ r[n-2], ....}
				s = r[j-i]+p[i];
				c[j] = i;
			}
		}
		r[j] = s;
	}
	return r
}
```

_**Time Complexity: `𝝷(n²)`**_
![400](../../資料結構/img/截圖%202022-09-21%20下午1.25.29.jpg)

## 3.3 The knapsack problem

重要性質：[Greedy Algorithm](Greedy%20Algorithm.md)

### The fractional knapsack problem

給定n件物品I[1... n]其中第i艦隻價值為v[i]重量為w[i]，總負重限制<W ，如何取物(每件物品可取部分)獲利最大？

> 只需求出每件物品的單位價值，然後從單位價值最高的開始取，直到裝滿(>= W)
> _**Time Complexity: T(n) = `𝝷(n log n)`**_ ~~O(Sorting)+O(n)~~

### The 0-1 knapsack problem

給定n件物品I[1... n]其中第i艦隻價值為v[i]重量為w[i]，總負重限制<W ，如何取物(每件物品_只能取或不取_)獲利最大？

```ad-quote
collapse:none
具有[Optimal structure](Optimal%20structure.md)(證明略），但不具有[Greedy-choice property](Greedy-choice%20property.md)，因此不可用greedy algorithm策略
```

```ad-tip
title:應用（相關思路）問題
Let S be a set of n positive integers, and we are interested if we can select some of the integers from S so that their sum is exactly m. Explain in details how this can be done in O(nm)

`Tip:看到「O(nm)」、「sum」聯想`
`定義出S是關鍵`

---
Ans:
S(i, j) （前i個數字的情況下，「是否」可以取出sum = j）
= S(i-1, )

```

s[i, k]表示在負重限制 k 之下，取前 i 個物品可達到的最大獲利

```txt
s[i, k] （在前i個物品中，裝進負重為k的包包的最大獲利）
= 0,                                     if i = 0 or k = 0
= s[i-1, k],                             if i != 0 and w[i] > k (新物品絕對放不下)
= max{v[i]+ s[i-1, k- w[i]], s[i-1, k]}, if i != 0 and k>= w[i] (放入或不放入新物品)
```

```C
//w不用sort
01-Knapsack(n, v, w, W){
	new s[0..n, 0..W] 
	for k = 0 to W
		s[0, k] = 0
	for i = 1 to n
		s[i, 0] = 0
		for k = 1 to W
			if k < w[i]
				s[i, k] = s[i-1, k] 
			else
				s[i, k] = max{v[i]+s[i-1, k-w[i]], s[i-1, k]}
	return s[n, W]
}
```

> KEY（填表時）:
> 由左而右由上而下填表
> 往下時，_若新物品可放_，往左邊w[i]格再上面一格的值+v[i] v.s 上面的值，反之則=上面那一格
> ~~自己寫題目很耗時間~~

_**Time Complexity: 𝝷(nW)**_
![](../../資料結構/img/截圖%202022-09-21%20下午2.10.34.jpg)

```ad-attention
- 其並不是polynomial time，因為假設m = lg W，則W作為input需要O(lgW) = O(m)的空間 => 𝝷(nW) = 𝝷(n2ᵐ)，是指數成長
但我們探討的是n的變化關係
- 實際上01-knapsack是[[NP-complete](../CH6%20NP-completeness/NP-complete.md)]問題
```


## 3.4 Matrix-chain multiplication problem

給定n個矩陣Aᵢ, i= 1~n，其中Aᵢ的大小為p[i-1]*p[i]。以何種括號法計算可使得_純量乘法次數最少_

```ad-quote
collapse:none
設s[i, j]為計算Aᵢ成到A𝚓所需的最少純量乘法次數，討論最後一個括號(B x C的意思，B = Aᵢ~Ak, C 是剩下的)
s[i, j] 
= 0                                                    , if i = j
= min{s[i, k]+ s[k+1, j]+ p[i-1]*p[k]*p[j]},其中 *i<=k<j* , if i < j
```

![250](../../資料結構/img/截圖%202022-09-21%20下午3.15.25.jpg)
![](MatrixChain.cpp)

```C
void MatrixChain(int p[4]){
	for(int i=0; i<4; i++){
		cout << i << endl;
	}
	for(int i= 1; i<= n; i++){
		s[i][i] = 0;
	}
	for(int l=2; l<= n; l++){ //控制一次要處理幾個矩陣
		for(int i = 1; i<= n-l+1; i++){
			int j = i+l-1;
			cout << i << ", " << j << endl;
			s[i][j] = s[i][i]+s[i+1][j]+p[i-1]*𝝷p[i]*p[j];
			for(int k=i; k<= j; k++){
				int r = s[i][k]+s[k+1][j]+p[i-1]*p[k]*p[j];
				if(r < s[i][j])
					s[i][j] = r;
					c[i][j] = k;
			}
		}
	}
}
```

_**Time Complexity: 𝝷(n³)**_
![300](../img/截圖%202022-09-21%20下午4.47.01.jpg)

## 3.5 Optimal binary search trees

[OBST(optimal BST)](../../資料結構/CH9%20Advanced%20Tree/OBST(optimal%20BST).md)

> 給定n個keys(k1 ~ kn)以及n+1個dummy key(d0 ~ dn)，假設_ki被搜尋到的頻率/機率 為pi，di被搜尋到的頻率/機率 為qi_ ，如何建立一個_**expected search cost最小的binary search tree**_ =>Optical Binary Search Tree(OBST)

**expected search cost(ESC):**
"Root到某一點所經之路徑長" ＊ "該點出現頻率" （高度＊權重） 的所有點的總和
==深度1 => level 2 (root是level 1)==
ESC = ESC(左子樹)+ESC(右子樹)+w[整棵樹]
![400](../img/截圖%202022-09-21%20下午4.56.28.jpg)

w[i, j] = keyi...keyj的所有頻率總和

```txt
w[i, j]
= q[i-1],               if j = i-1 ~~沒有key~~
= w[i, j-1]+ p[j]+ q[j],if i <= j ~~往右加了一層~~
```

s[i, j] = keyi...keyj的建立的OBST's cost
![300](../img/截圖%202022-10-15%20下午3.38.10.jpg)

```txt
s[i, j]
= q[i-1],                          if j = i-1
= min{s[i, r-1]+s[r+1, j]+w[i, j]},if i <= j。(i <= r <= j)
```

~~最後+w[i, j]是因為高度加一~~

```ad-tip
title:（填格子順序）w:從上而下，從左而右；s從左而右，從下而上。
```

![500x500](../img/截圖%202022-10-15%20下午4.33.07.jpg)

```ad-example
![](../img/截圖%202022-10-15%20下午4.42.53.jpg)
```

## 3.6 Longest common subsequences(LCS)

給定X= <x₁, ..., x𝑚>, Y = <y₁, ..., y𝒏>,  Z = <z₁, ..., z𝒌>為三個字串
若存在X的子序列=Y的子序列 = Z，則稱Z為X, Y的共同子序列

令X= <x₁, ..., xᵢ>, Y = <y₁, ..., y𝚓>,  Z = <z₁, ..., z𝒌>
假設_s[i, j] = k為 Xᵢ 與 Y𝚓之LCS長度_

```txt
s[i, j]
= 0                        , if i=0 or j=0
= s[i-1, j-1]+1            , if i,j >0 and xᵢ = y𝚓(目前已知的LCS)
= max{s[i, j-1], s[i-1, j]}, if i,j > 0 and xᵢ!=y𝚓(用於繼承，但不知道是X還是Y那邊的)
```

```ad-tip
title:檢查Xi, Yj是否一樣，一樣就繼承當下的LCS並長度加一，否則繼承就好。
```

```C
LCS(X, Y){
	//X,Y第一列 = 0
	n = Y.length
	m = X.length
	for i = 0 to n
		s[i, 0] = 0
		for j = 0 to m
			if X[i] == Y[j]
				//往左上，加長LCS
				s[i, j] = s[i-1, j-1] + 1
			else if s[i-1, j] > s[i, j-1]
				//往上，繼承LCS
				s[i, j] = s[i-1, j]
			else 
				//往左，繼承LCS
				s[i, j] = s[i, j-1]
	return s
}
```

(m= |X|, n = |Y|)
_**Time complexity: 𝝷(mn)**_

**圖表法**
![450](../img/截圖%202022-09-21%20下午5.29.04.jpg)

### Longest Common Increasing Subsequence(LIS)

找出Ａ中的最大遞增子序列

```C
LCIS(A, B){
	Sort A and store the result in B
	return LCS(A, B)
}
```

_**Time complexity: 𝝷(n log n) + 𝝷(n²) = 𝝷(n²)**_

### Longest Common 'Substring'

找出最長的共同子字串

> key: 和LCS差在，判斷X[i] 和Y[j]關係時，若 != s[i, j] =0

```C
LCSubstring(X, Y){
	m = X.length
	n = Y.length
	length = 0
	new s[0..m, 0..n]

	for j = 0 to n:
		s[0, j] = 0
	for i = 0 to m
		s[i, 0] = 0
		for j = 0 to m:
			if X[i] == Y[j]
				s[i, j] = s[i-1, j-1]
				length = max{length, s[i, j]}
			else
				s[i, j] = 0
	return length	
}
```

_**Time: 𝝷(mn) ?**_

### (補充題目)Longest palindrome sequence

最長回文子序列

```ad-quote
collapse:none
L(i, j)代表s[i..j]的最長回文子序列的長度，n = X.length
L(i, j)
= max{ L(i,  j-1), L(i+1,  j) }, if i>0 & j> 0
= 0, if i = j+1
= 1, if i = j
= L(i+1, j-1)+2, if i < j & s[i] == s[j]

> 對角線 = 1
> 左下半 = 0
> 其餘：注意
> - if s[i] == s[j] ，左下+2 (L(i+1, j-1)+2)
> - if s[i] != s[j] ，左 V.S 下 取大者
```

![500](../img/截圖%202022-09-25%20下午5.55.24.jpg)
Time: 𝝷(n²)

### (補充題目)Minimum Edit Distance（回去翻演算法的課本理解）

最短改動距離(cost)
假設有兩個字串A, B（長不為m, n），求如何用下列三個運算變成一樣的字串
Deletion: 刪除一元素，cost = 1
Insertion:加入一個元素，cost =2
Substitution: 更改一個元素，cost = 3

```ad-tip
c[i, j] = A[1..i]和B[1..j]的M.E.D
**遞迴關係：**
- if A[i] == B[j] => c[i, j] = c[i-1, j-1]
- if A[i] != B[j]
	- if 
```

## 3.7 The KMP algorthm

Knuth-Morris-Pratt
給定T[1..n]為一篇文章，P[1...m]為一段字串，m<= n，找出所有的P在T中之[valid shift](valid%20shift.md)

若以暴力法求解，Time: O(mn)
有別於暴力法每次將pattern右移一個位子再做比對。KMP可以_利用已比對的資料一次位移多個位置_

Pk = P[1..k]

> **PrefixFunction**
> 首先定義**𝝅[k] = "Pk之suffix(後面開始的子字串)與P之prefix 可配對的最大長度"**_**也就是P[1~k-1]和P[2~k]的重疊程度。**_
> 用於決定遇到T[i]!= P[k]時需要shift到哪
> 
> failure function: 𝝅[k]的值-1 而且index從 0 開始

![](../img/截圖%202022-09-30%20上午10.46.38.jpg)

```C
PrefixFunction(P){
	m = P.length;
	new(𝝅[1..m])
	𝝅[1] = 0;
	k = 0;
	for i = 2 to m:
		while k >0 and P[k+1]!= P[i]: //若P[k+1]與P[i]不同，則代表在Pi這段與Pk只能match到這
			k = 𝝅[k];	
		if P[k+1] = P[i]:
			k = k+1;
		𝝅[i] = k;
}
```

```C
KMP(T, P){
	n = T.length
	m = P.length;
	𝝅 = PrefixFunction(P);
	k = 0;
	for i = 2 to m:
		while k >0 and P[k+1]!= T[i]: //直到shift後的下一位數相等（P[k+1] == T[i]）或是k = 0（完全shift）
			k = 𝝅[k];	
		if P[k+1] = T[i]://相同長度加一
			k = k+1;
		if k == m:
			print "valid shift", i-m;
			k = 𝝅[k];
}
```

![](../img/截圖%202022-09-30%20上午11.06.56.jpg)

**分析**
_**Time: `O(m+n)`**_
有while看次花很久時間，但根據Amortized analysis，定多O(n)，PrefixFunction同理`O(m)`

```ad-example
title:應用問題
使用KMP辨認string S is cyclic rotation of another string?
(ex: tea and eat is cyclic of each other)
---

令T = S strcat S ，用KMP的pattern mathing，若存在match <=> 是cyclic
```