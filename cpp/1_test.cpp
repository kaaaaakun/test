#include <iostream>
#include <cctype> // std::isdigit
#include <string> // std::string

int main() {
    std::string userInput;

    // ユーザーから文字列を入力
    std::cout << "Enter a single digit character: ";
    std::cin >> userInput;

    if (userInput.size() == 1) {
        char inputChar = userInput[0];

        if (std::isdigit(inputChar)) {
            // 入力された文字を整数に変換
            int result = inputChar - '0';
            std::cout << "Result: " << result << std::endl;
        } else {
            // エラー処理：数字でない場合
            std::cerr << "Error: Input is not a digit." << std::endl;
        }
    } else {
        // エラー処理：1文字以上の入力がある場合
        std::cerr << "Error: Please enter only a single digit character." << std::endl;
    }

    return 0;
}
