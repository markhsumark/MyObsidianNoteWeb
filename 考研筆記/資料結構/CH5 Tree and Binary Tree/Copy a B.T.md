---
date created: 2022-09-29 20:29
date updated: 2022-09-29 20:34
---

# Copy a B.T

~~easy~~

> **觀念:**
> 走某一種序的順序複製
> steps（前序）:
>
> 1. assign Top Root
> 2. Copy(L)
> 3. Copy(R)

```C
Copy(orig : BinaryTree):
	if(orig == None):
		t = None;
	else{
		new(t);
		t->Data = orig->Data;
		t->Lchild = Copy(orig->Lchid);
		t->Rchild = Copy(orig->Rchid);
	}
	return t;
```
