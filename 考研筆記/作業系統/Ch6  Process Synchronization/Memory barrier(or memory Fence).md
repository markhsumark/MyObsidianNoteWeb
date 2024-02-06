# Memory barrier(or memory Fence)
~~確保順序，內容改變必須讓其他processors知道~~

>很多硬體提供一種指令強迫(force)任何memory, 內容改變必須讓其他processors知道, 此指令叫"memory barriers/fence"
>- ==在後續的operation load前，要確保前面的operation is completed==
> - typically only used by kernel developer 

- [Strongly ordered](Strongly%20ordered.md)
- [Weakly ordered](Weakly%20ordered.md)

**應用例子**
>memorybarrier前的operation一定要保持在memorybarrier前
```C
//thread1
//保證flag value is loaded before 'x'
while (!flag){
	memory_barrier();
	print(x);
}
```
```C
//thread2:
//保證x的assignment 先於flag assignment
x=100;
memory_barrier();
flag = true
```