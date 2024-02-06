Min-Max Heap

> 定義：是一顆 [Complete B.T](CH5%20Tree%20and%20Binary%20Tree.md###Complete%20Binary%20Tree),且滿足
>
> 1. 其level是_min-Level與Max-Level 交互出現_
> 2. Root位於min-Level ~~從min作為頭~~
> 3. 若x位於min-Level/Max-Level，代表_以x為root之子樹中，x具有最小值/最大值_。

![400](../img/截圖%202022-10-12%20下午4.03.05.jpg)

**VerifyMax**
>檢查在所有Max levels中，最大的會在最上層的Max level

`VerifyMin同理`


**Insert X**

~~parent level的node和新的node大小關係正確（只往上一層看）~~
~~在用Verify去往上修正~~

1. x先暫時放在最末端的下一個位置(n)
2. 令x的parent稱為p。分成下列兩case
   1. p位於min-level：
      ```C
      if x<= H[p]{
          H[n] = H[p]; // p值下移
          VerifyMin(H, p, x)
      }else{
          VerifyMAX(H, n, x)
      }
      ```
   2. p 位於Max-Level
      與case a相反
3. Time: O(log n)

**Delete-min**

```txt
令last node是x
1. (root跟max level比較) root's左右子存在比x小，和左右子的min交換 
2. (root跟min level比較) 若此時有交換，以交換的node為root繼續遞迴
```
~~找出下兩層的min，在子node交換就結束了。在孫子，交換之後遞迴~~

1. remove root data（因為root最小）
2. 將_the last Node刪除，設給x變數_
3. x要插入到一個root為空的min-Max Heap中。分成下列case ~~往下找最小的看最小的在第幾層~~
   1. root下無子點：x置入root，結束
   2. root的子孫中最小值位於root左子or右子（下一層）中（令為k）
      if x<= k: x放到root
      else: x放到k的位置，k放到root
   3. Root之最小值在Root的孫子中（下下層）之其中一個（令為k），且k之父點為p
      if x<= k: x放入root
      else: k放到root，if x> p: x, p互換，_goto step 3_~~這一個case有遞迴~~
