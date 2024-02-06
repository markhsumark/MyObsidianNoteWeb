### Stack之製作

#### 使用Array製作

1. Create(S):
   > S: array[1..n]of items
   > Top: int, 初值 = 0

2. Push(S, item)
   ```C
    Push(S, item){
    	if(Top == n) return "S已滿";
    	else{
    		Top++;
    		S[Top] = item;
    	}
    }
   ```
   _**Time: O(1)**_

3. pop(S)
   ```C
    pop(S){
    	if(Top == 0)return "S空"
    	else{
    	item = S[Top];
    	Top--;
    	return item;
    	}
    }

   ```
   _**Time: O(1)**_

#### 使用 Link List製作

1. Create(S):
   > S: _[Node](Node.md)_ 結構
   > Top：pointer = Nil(空)

2. Push(S, item)
   ```C
      Push(S, item){
        	Node *t;
        	t = new(Node);
        	t->Data = item;
        	t->Next = Top;
        	Top = t;
      }
   ```
   _**Time: O(1)**_

3. pop(S)
   ```C
    pop(S){
    	if(Top == Nil)return "S空"
    	else{
    		item = Top->Data;
    		Top = Top->Next;
    		return item;
    	}
    }

   ```
   _**Time: O(1)**_