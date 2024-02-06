---
date created: 2022-12-27 15:08
---

Dynamic linking #⭐️

又稱shared library
類似[Dynamic loading](Dynamic%20loading.md)，差在於保留在memory 的多為link而已

> 定義 :
> 在execution time時，若module被==真正呼叫到，才將他載入，**並與其他object code進行linking**==
>
> 需OS額外的support
> ( 如果要access其他processes 之外部符號，則必須透過OS來完成）

**好處**

- ==縮減了obj. Code 之space==
- 節省memory space
- Library可以共用  ~~又稱shared library~~
- ==有助於library更新（原本的程式碼不需更動）==
