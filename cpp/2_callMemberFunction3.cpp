#include <iostream>

// 関数オブジェクトの基底クラス
class BaseFunction {
public:
    virtual void operator()(int arg) const = 0;
    virtual ~BaseFunction() {}
};

// 偶数の場合の関数オブジェクト
class EvenFunction : public BaseFunction {
public:
    virtual void operator()(int arg) const {
        std::cout << "Even function called with argument: " << arg << std::endl;
    }
};

// 奇数の場合の関数オブジェクト
class OddFunction : public BaseFunction {
public:
    virtual void operator()(int arg) const {
        std::cout << "Odd function called with argument: " << arg << std::endl;
    }
};

// 引数の数に応じて関数オブジェクトを切り替える関数
void callFunctionBasedOnArgumentCount(int argc, char* argv[]) {
    // 関数オブジェクトの配列
    BaseFunction* funcObjects[] = { new OddFunction(), new EvenFunction() };

    // 引数の数が偶数か奇数かで関数オブジェクトを選択し、関数を呼び出す
    (*funcObjects[argc % 2])(argc);

    // 配列の解放
    delete funcObjects[0];
    delete funcObjects[1];
}

int main(int argc, char* argv[]) {
    // 引数の数に応じて関数を呼び出す
    callFunctionBasedOnArgumentCount(argc, argv);

    return 0;
}

