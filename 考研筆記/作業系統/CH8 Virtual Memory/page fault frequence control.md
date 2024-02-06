---
date created: 2022-09-24 17:09
---

**page fault frequence control**
>定義：OS會訂定process page fault ratio之*合理的上限值與下限值*，若page fault ratio可以控制在一區間，可以降低Thrashing發生機率。


- 若OS發現P.F.R**太高**=> OS應該多分配頁匡給該process，降低其P.F.R
- 若OS發現P.F.R太低=> OS應取走多餘頁匡，分給其他process