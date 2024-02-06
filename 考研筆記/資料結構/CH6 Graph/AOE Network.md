Activity On Edge

>定義：以有向圖G=<V, E>表示，其中
>1. vertex：代表*Event*
>2. edge：代表Activity(工作)
>3. edge之數字：代表此工作所需的工作時長
>
>意義：
>1. 所有射入事件(V)的工作皆完成，此事件V才會發生
>2. 事件發生後，所有從此事件射出的工作(edge)才可開工

**應用**
Project Management

**例**
> [!example] 
> ![400](../img/截圖%202022-10-29%20下午4.48.36.jpg)
> ---
> Q1. 完成此project 最快需要？天
> Ans:求s到e之*最長*path長度
> 每輪選擇時間最長的->30days
>  ---
>  Q2. critical path有哪？條
>  Ans:
>  1. S->A->B->x->E
>  2. S->A->B->y->E
>  ---
>  Q3.列出所有critical tasks?
>  Ans:
>  critical tasks：不可delay的工作 = 最早和最晚開工是同一天的task  = 所有critical path的工作 = {a1, a5, a7, a8, a10, a11}
>---
>Q4. 哪些是Bottleneck task?。或者*加速哪些功做*方可有效縮短Project 完工天數？
> Ans:所有critical path的共同工作 = {a1, a5}
> ---
> Q5. 求出每個工作的最早開工和最晚開工之時間，判斷哪些工作可以delay?且delay?天不至於影響進度。
> Ans:
> >key:
> >- Event最早發生時間 = S到該event之最長路徑
> >- Event最晚發生時間 = 從End往回推，求最小值
> 
> 1. 先求出各*事件之最早發生(ee)以及最晚發生(le)*之時間
