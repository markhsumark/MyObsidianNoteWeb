---
date created: 2022-09-14 10:51
---

## Ackerman's function

> A(m, n)

=>n+1, if m = 0
=>A(m-1, 1), if n = 0
=>A(m-1, A(m, n-1)), otherwise

- 求A(2, 2)之值：

> A(2, 2)->A(1, A(2, 1))->A(1, A(1, A(2, 0)))->....
