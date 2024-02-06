---
date created: 2022-10-24 20:24
date updated: 2022-10-24 20:35
---

# Heap Sort

#unstable
steps

1. 先用Bottom-up方式[建立Max-Heap](../CH5%20Tree%20and%20Binary%20Tree/Build%20a%20Heap%20with%20n%20nodes.md)->Time:O(n)
2. 執行(n-1)回合，每一回合執行類似[Delete-MAX](../CH5%20Tree%20and%20Binary%20Tree/Delete-MAX%20in%20%20MAX-Heap.md###%20Delete-MAX%20in%20%20MAX-Heap)運作。`及Root與當時the last Node做Swap, 針對剩下的Data, adjust 成Heap`

```ad-note
collapse:none
title:給3, 7, 1, 5, 9, 8, 10, 2, 6實施之
1. 先建立Heap
2. 尾補到Root（頭放入排序的Max），再做adjust
3. 一直拿走Root直到Heap為空
```

Algo
分成

1. [Adjust(tree, i, n)](../CH5%20Tree%20and%20Binary%20Tree/Build%20a%20Heap%20with%20n%20nodes.md#####%20Adjust(tree,%20i,%20n))
2. HeapSort(tree, n)
   ```C
   HeapSort(tree, n){
   	for(i=n/2; i>=1; i--)//Build
   		Adjust(tree, i, n);
   	for(i=n-1; i>=1; i--){
   		Swap(tree[1], tree[i+1]);
   		Adjust(tree, 1, i);//對剩下的資料重新整理
   	}
   }
   ```

**分析**

1. Time Complexity: Avg./ worst/ Best case : O(nlogn)
   建立：`O(n`
   (n-1)回合，每回合花O(logn)，共花`O(nlogn)`
   ->`O(nlogn)`
2. Space Complexity:O(1)
   例如：5, 5*, 1
