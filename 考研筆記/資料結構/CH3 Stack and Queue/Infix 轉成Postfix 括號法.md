---
date created: 2022-09-20 20:38
date updated: 2022-09-20 21:04
---

**Infix 轉成Postfix範例**

```ad-example
title: Infix 轉成Postfix
1. ~~~txt
   a*(b+c-d)/(e+f*g)
   ans:
   ((a*((b+c)-d))/(e+(f*g))
   => abc+d-*efg*+/
   ~~~
2. ~~~txt
   a*b$c$(d-e/f)
   ans:
   (a*(b$(c$(d-(e/f)))))
   => abcdef/-$$*
   ~~~
3. ~~~txt
   ~A and (B>C or D<E) or ~F
   ans:
   (((~A) and ((B>C) or (D<E))) or (~F))
   => A~BC>DE< or and F~ or
   ~~~
```
