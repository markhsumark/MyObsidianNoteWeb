---
date created: 2022-09-29 20:41
---

# Count B.T Node總數

> 以某一種序遞迴計數

```C
int Count(T){
	if(T == Nil)
		return 0;
	else{
		int ln += Count(T->Lchild);
		int rn += Count(T->Rchild);
		return ln+ rn+ 1;
	}
}
```
