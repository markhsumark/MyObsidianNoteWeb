---
date created: 2022-09-14 10:52
---

# Analysis(or 預估)方法
## 基礎：統計Algo中*"指令執行steps總和"*
  - 例1:不考慮"_指令難易程度_"
    程式：
    ```C
    //int count = 0;
    int test(int n){
    	int i;
    	int s = 0;
    	//count++;
    	for(i = 1; i<= n; i++){
    		//count++;
    		s = s+ i;
    		//count++;
    	}
    	//count++; //for失敗的那次
    	return s;
    }
    ```
    1. 宣告全域變數count
    2. 在適當處加入count++
    3. 統計
    Ans: 1+2n+1+1 = **2n+3次**
  - 例2:考量"_指令難易程度_"
    - | 敘述            | S/P | Frequency | Total |
  | ---------------         | --- | --------- | ----- |
  | int test(int n){        | 0   | 0         | 0     |
  | int i ;                 | 0   | 0         | 0     |
  | int s = 0;              | 1   | 1         | 1     |
  | for(i = 1; i<= n; i++){ | 3   | n+1       | 3n+3  |
  | s = s+ i;               | 2   | n         | 2n    |
  | return s;               | 1   | 1         | 1     |
	=> **5n+5**
