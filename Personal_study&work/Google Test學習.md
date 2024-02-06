---
date created: 2024-01-16
---

# Google Test學習

Status: Completed
Created time: August 16, 2023 9:53 PM
Last edited time: September 13, 2023 8:40 PM
Tags: 工研院

# 基礎功能與結構

## Assertions

> 最小的測試指令
> 

`ASSERT_*`: 測試若是失敗，則該局部測試會終止。所以用於較關鍵的檢測

`EXPECT_*`: 測試若是失敗，則該局部測試會繼續執行。於較「不」關鍵的檢測

[Google Test(GTest)使用方法和源码解析——断言的使用方法和解析_vs 使用gtest浮点数断言_breaksoftware的博客-CSDN博客](https://blog.csdn.net/breaksoftware/article/details/51059406)

## Simple Tests

> 將相關的Assertions與要測試的內容寫成一個Test unit
> 

```cpp
Test(TestSuiteName, TestName){
	... test body...
}
```

`需採用funciton或是Class的命名規`

## Test Fixtures

> 測試資料結構或是物件時
> 

可以透過創建並繼承testing::test 的class，客製化測試用的class，並提供 `SetUp()` 、 `TearDown()` 客製化

```cpp
template <typename E> class ClassA{
		int a;
}
```

```cpp
class ClassTest:public::testing::Test{
	proctected:
		void SetUp() override{
			A.a = 1;
		}
	// 不一定需要TearDown就可以測試
	ClassA A;
}
```

```cpp
TEST_F(ClassTest, TestName){
	EXPECT_EQ(A.a, 1);
}
```

## main function

```cpp
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
```

# Assertions Reference

## Explicit Success and Failure

## Generalized Assertion

## Boolean Conditions

## Binary  Comparison

## String Comparison

## Floating-Point Comparison

## Exception Assertions

# 參考連結

[https://youtube.com/watch?v=16FI1-d2P4E&feature=shareb](https://youtube.com/watch?v=16FI1-d2P4E&feature=shareb)

[GoogleTest 寫 C++ 單元測試的用法與教學](https://shengyu7697.github.io/googletest/)

**編譯指令**

```
g++ filename.cpp -o filename -Igtest/include -Lgtest/lib -lgtest -lpthread
```