
等同於[Binary Tree of order 2t](Binary%20Tree%20of%20order%20m.md)

B-Tree 具備如下特性：
>1.  每一棵 B-Tree 都需要在建立前指定好 Minimal Degree ， `t` 。
>2.  樹上的每個節點內存放最少 `t-1` 個 keys ，最多 `2t-1` 個 Keys。
>3.  Root Node 較為特殊，允許存放最少 `1` 個 Key ，最多 `2t-1` 個 Keys。
>4.  每個節點當下擁有的子節點數為 `節點當下擁有的 key 數 + 1`
>5.  每個節點上的 Keys 都是以升序（ Increasing Order ）排列，相隔的兩 Key ，`K1`、 `K2` ，之間的任一子節點上的任一 Key ，其值必落在 `K1` - `K2`之間。
>6.  所有葉節點 （Leaf Node ）的深度（ Depth ）必定相同。

高度h時，最大node數為`(2t)^h +1`