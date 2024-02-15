#include <iostream>
#include <string>

int main() {
    std::string fruit = "apple";

    switch (fruit[0]) {
        case 'a':
            std::cout << "The fruit starts with 'a'" << std::endl;
            break;
        case 'b':
            std::cout << "The fruit starts with 'b'" << std::endl;
            break;
        default:
            std::cout << "Unknown fruit" << std::endl;
            break;
    }

    return 0;
}

