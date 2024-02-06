---
date created: 2022-09-29 21:12
---

# 針對Expression B.T求值

```C
Eval(T: Expression B.T){
	 if(T != Nil){
		 nl = Eval(T->Lchild);
		 nr = Eval(T->Rchild);
		 switch(T->Data){
			case {變數/常數名稱}: return {變數/常數值};
			case "+": return (nl+nr);
				...//其餘operator
			case "NOT": return NOT(nr);
			case "minus": return -nr;
		 }
	 }
}
```
