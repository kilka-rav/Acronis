#include "algo.h"


int main() {
    std::string string, substring;
    std::cin >> substring >> string;
    int number = KMP(string, substring);
    if ( number < -1 ) {
        std::cout << "Error\nNumber ERROR = " <<  -1 * number << std::endl;
        return number;
    }
    if ( number >= 0 ) {
        std::cout << "Substring is in string: begin symbol = " << number <<  std::endl;
    }
    else {
        std::cout << "Substring isn't in string"<< std::endl;
    }
}
