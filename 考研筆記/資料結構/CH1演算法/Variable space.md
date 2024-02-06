---
date created: 2022-09-14 10:53
---

Variable space 需求:

- 參數為_結構型參數_ 且採用_call-by-value_參數傳遞方法，或是_call-by-address_
- Stack space for 'Recursion' :
  sp(n) = c + sp(i)
  > 我們只關心sp(i)的大小
  > call-by-address -> sp(i) = 0
