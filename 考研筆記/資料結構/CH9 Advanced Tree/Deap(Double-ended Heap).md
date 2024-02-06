Deap(Double-ended Heap)

~~min heap & max heap合起來。對面的data符合min max的大小關係~~

> 定義：是一顆 [Complete B.T](CH5%20Tree%20and%20Binary%20Tree.md###Complete%20Binary%20Tree) ，且滿足：
>
> 1. Root 不存Data
> 2. Root之左子樹是min-Heap
> 3. Root之右子樹是Max-Heap
> 4. 令i是min-Heap中某Node編號，令j是i在Max-Heap中對應Node編號 則Deap[i] <= Deap[j]

![400](../img/截圖%202022-10-12%20下午4.49.52.jpg)

[Binary tree三個基本定理](CH5%20Tree%20and%20Binary%20Tree.md##%20Binary%20tree三個基本定理)
j =  i+ 2^(upper(log₂(i+1))-2)
if(j>n){j = j/2} //用爸爸代替

**Insert X** ~~跟對面的比大小~~

~~左右比（交換），然後往上檢查min/max heap正確性~~

1. x先暫時置於the last Node之下一個位置(n)
2. 分成下列2個cases: ~~右邊的要比左邊的大，否則換！~~
   1. x在Min-Heap：令j為在Max-Heap之對應位置
      ```C
      if(x> Deap[j]){ //x比對面的（min-Heap裡的）大
          Deap[n] = Deap[j];//j放到n
          InsertMax-Heap(Deap, j, x);//把x放在j的Heap然後往上檢查Heap
      }else{
          InsertMin-Heap(Deap, n, x);//把x保留，然後往上檢查Heap
      }
      ```
   2. x在Max-Heap
      與case a相反

**Delete-min**

~~last node移走，min heap調整，insert x~~

1. remove Root之_左子點_之Data，形成空Node
2. remove the last Node，並將其data設記在x
3. 左子樹Root（空格）依序由其左右子點最小值往上遞補，直到降到leaf(編號為i) #⭐️⭐️⭐️
4. 執行一個Deap的Insert => Insert x at i position #⭐️⭐️⭐️
