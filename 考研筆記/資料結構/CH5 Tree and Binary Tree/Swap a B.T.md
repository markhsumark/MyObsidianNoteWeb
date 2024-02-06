---
date created: 2022-09-29 20:59
---

# Swap a B.T

> 定義：B.T中每個Node之左右子點互換
> 觀念：左子swap，右子swap，左右子swap

```C

Swap(T){
	if(T == Nil){
		Swap(T->Lchild);
		Swap(T->Rchild);
		temp = T->Lchild;
		T->Lchild = T->Rchild;
		T->Rchild = temp;
	}
}
```
