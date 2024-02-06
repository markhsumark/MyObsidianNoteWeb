產生可重新定位的程式碼(Relocatable object code)
- Allocation:向OS 要求一個起始位置base on size
-   Loading: 將obj. code 中 Text records 載入memory 
-   Linking修正：將sin obj. code 載入到記憶體, 得到起始位置。
-   Relocation修正：針對當下和未來的起始位置做修正