# B.T Height

> 以某一種序遞迴，找出左右子樹高度，取*MAX{左子樹高度, 右子樹高度}+1*

```C
Height(T){
	if(T == Nil)
		return 0;
	else{
		hl = Height(T->Lchild);
		hr = Height(T->Rchild);
		return MAX(hl, hr)+1;
	}
}
```