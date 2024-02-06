---
date created: 2022-09-24 17:22
date updated: 2022-09-24 17:40
---
feat: 計組
# Locality model

> 定義:process在執行期間對於所有存取的memory location 並非是均勻的，而是某種局部/集中之特性

一般而言分為

- **Temporal(時間) Locality:**
  目前存取之memory area, _過不久後又會被存取_ => 此區域經常被存取
  EX:Loop, Counter, Subroutine(副程式), pure code, stack(eg. TOP element).
- **Spatial(空間) Locality**
  目前存取之memory area, 其_鄰近的區域也馬上會被參考_ => 與鄰居有關聯
  EX:Array, sequentail code execution, Commom data area, vector operation.

若process結構_符合Locality model對V.M來說是好的_
反之則不好(EX:Link list, Hashing, Binary Search, goto, Jump, Indirect  addressing mode)

違背Temporal(時間) Locality少見

`EX:p.300:75`
