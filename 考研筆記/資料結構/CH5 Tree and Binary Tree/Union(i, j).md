任意的Union(i, j)
令i, j為root
任取一個i作為New root, 另一個為其子樹
```C
Union(i, j){
	j->Parent = i;
}
```