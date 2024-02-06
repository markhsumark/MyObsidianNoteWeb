---
date created: 2022-12-26 21:47
---

~~用於c.s design~~
~~利用busy waiting 實作的高階軟體工具 -> ~~

> OS提供一個==higher-level software tool==給Application programer 使用
>
> 1. 起因：之前hardware-based solutions to the c.s. problem 太複雜，且inaccesible to Application programmers
> 2. OS designers建立一個 ==high-level Software tools to solve the c.s. problem 其中最簡單的一種是mutex lock==
>
> ---
>
> 提供兩個 atomic functions:
> `Available 是共享變數，初值為true`
>
> - [acquire](acquire.md)
> - [release](release.md)
>
> 一個上鎖，一個歸還鑰匙（開鎖）

**缺點**
因為是busy waiting ->可能會浪費cpu time
此種==**_busy waiting 之mutex lock 也叫spin lock_**==，但也有**好處，即no context switch is required**  when a process must wait on a lock
