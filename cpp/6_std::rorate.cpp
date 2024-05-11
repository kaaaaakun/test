#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    // サンプルとして使用する要素を持つベクターを作成
    std::vector<int> vec;
	for (int i = 1; i <= 10; ++i) {
		vec.push_back(i);
	}

    // 要素を表示
    std::cout << "Before rotation: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 3番目から８番目の要素を先頭に移動することで回転させる
    std::rotate(vec.begin(), vec.begin() + 2, vec.end() - 2);

    // 回転後の要素を表示
    std::cout << "After rotation: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 5番目から最後までの要素を先頭から２番目に移動
    std::rotate(vec.begin()+2, vec.begin() + 5, vec.end());

    // 回転後の要素を表示
    std::cout << "After rotation: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

