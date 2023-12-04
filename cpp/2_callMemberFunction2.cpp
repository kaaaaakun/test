#include <iostream>
#include <functional>

// 関数オブジェクトの型を定義
struct FunctionObject {
    void operator()(int arg) {
        std::cout << "Function called with argument: " << arg << std::endl;
    }
};

int main(int argc, char* argv[]) {
    // 関数オブジェクトを作成
    FunctionObject functionObject;

    // 関数オブジェクトをstd::functionにラップ
    std::function<void(int)> func = functionObject;

    // 引数の数に応じて関数オブジェクトを呼び出す
    func(argc);

    return 0;
}
