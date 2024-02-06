---
date created: 2022-09-29 20:34
date updated: 2022-09-29 20:41
---

# Equal(S, T)

> **觀念：**
> 以某一種序遞迴比較（類似[Copy a B.T](Copy%20a%20B.T.md))，但_傾向用前序_

```C
Equal(S:B.T, T:B.T){
	res = False
	if(S==Nil and T == Nil)
		res = True;
	else if(S!=Nil and T!= Nil)
		if(S->Data == T->Data)
			if(Equal(S->Lchild, T->Lchild))
				res = Equal(S->Rchild, T->Rchild);
	return res;
}
```
