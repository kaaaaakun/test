#include <iostream>

class MyClass {
public:
    void function1() {
        std::cout << "Function 1 called." << std::endl;
    }

    void function2() {
        std::cout << "Function 2 called." << std::endl;
    }
};

// メンバ関数ポインタの型を定義
typedef void (MyClass::*MemberFunctionPointer)();

// 条件分岐を行わない関数
void callMemberFunction(MyClass* obj, MemberFunctionPointer func) {
    // メンバ関数ポインタを使用して関数を呼び出す
    (obj->*func)();
}

int main() {
    MyClass obj;

    // メンバ関数ポインタを使用して関数を呼び出す
    callMemberFunction(&obj, &MyClass::function1);
    callMemberFunction(&obj, &MyClass::function2);

    return 0;
}

