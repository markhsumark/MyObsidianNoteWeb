Binding #⭐️

> 定義：決定Process執行在Memory的起始位置

**時間點（由誰做）**

- Compiling Time: compiler負責。若知道執行位置->absolute code，若不知道未來執行位置->Relocatable code
- Loading Time：[Linking loader](Linking%20loader.md)負責
- Execution Time([Dynamic Binding](Dynamic%20Binding.md)):拖到(delay)執行時期，由OS動態決定。