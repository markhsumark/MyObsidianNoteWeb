Simple-Find(x)
沿著x的parent link 一直往上直到Root 為止，傳回root
```C
Simple-Find(x){
temp = x;
while(temp->Parent!= temp)
	temp = temp->Parent;
return temp;
}
```
O(h)。h是樹高