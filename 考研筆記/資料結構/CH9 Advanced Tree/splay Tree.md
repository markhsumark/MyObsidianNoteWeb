splay Tree #⭐️

~~簡化的AVL tree，且splay起點會totation到root~~

**緣由：**

|          | [AVL Tree](AVL%20Tree.md) | splay Tree |
| -------- | -------- | ---------- |
| 調整過程     | 複雜       | 簡單         |
| 實際成本（最差） | O(logn)  | O(n)       |
| 分攤成本     | -        | O(logn)    |

> 定義：splay Tree是一顆BST，其Inset/search/Delete x操作同BST。
> 主要差別：
> 做完運算後必須針對*[splay起點](splay起點.md)_執行_[splay 運算](splay%20運算.md)（由一連串rotations組成）_，目的是要 ==將[splay起點](splay起點.md)變成**New Root**==