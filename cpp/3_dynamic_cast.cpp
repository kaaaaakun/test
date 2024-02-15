#include <iostream>

// 基底クラス
class Base {
public:
    virtual ~Base() {} // 仮想デストラクタ
    virtual void doSomething() {
        std::cout << "Base::doSomething()" << std::endl;
    }
};

// 派生クラス
class Derived : public Base {
public:
    void doSomething() override {
        std::cout << "Derived::doSomething()" << std::endl;
    }
    void derivedOnlyFunction() {
        std::cout << "Derived only function" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived(); // DerivedオブジェクトをBaseポインタで保持
    // BaseポインタをDerivedポインタにダウンキャスト
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr != nullptr) {
        // ダウンキャスト成功
        std::cout << "Dynamic cast succeeded." << std::endl;
        derivedPtr->doSomething(); // 派生クラスのメソッド呼び出し
        derivedPtr->derivedOnlyFunction(); // Derivedクラス固有の関数を呼び出し
    } else {
        // ダウンキャスト失敗
        std::cout << "Dynamic cast failed." << std::endl;
    }
    delete basePtr; // オブジェクトの解放
    return 0;
}

