### shortest 
>定義：令x是[Extended B.T](#Extended%20Binary%20Tree)中某Node，則
>```txt
>shortest(x)
>= 0, if x is External node
>= 1+min{shortest(x->Lchild), shortest(x->Rchild)}
>```
>![200](../img/截圖%202022-10-17%20下午6.25.17.jpg)