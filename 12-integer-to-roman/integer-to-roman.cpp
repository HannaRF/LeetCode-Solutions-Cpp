#include <string>

class Solution {
public:
    std::string intToRoman(int num) {
        std::string roman;

        roman += std::string(num / 1000, 'M');
        num %= 1000;
        roman += std::string(num >= 900 ? 1 : 0, 'C') + std::string(num >= 900 ? 1 : 0, 'M');
        num %= 900;
        roman += std::string(num / 500, 'D');
        num %= 500;
        roman += std::string(num >= 400 ? 1 : 0, 'C') + std::string(num >= 400 ? 1 : 0, 'D');
        num %= 400;
        roman += std::string(num / 100, 'C');
        num %= 100;
        roman += std::string(num >= 90 ? 1 : 0, 'X') + std::string(num >= 90 ? 1 : 0, 'C');
        num %= 90;
        roman += std::string(num / 50, 'L');
        num %= 50;
        roman += std::string(num >= 40 ? 1 : 0, 'X') + std::string(num >= 40 ? 1 : 0, 'L');
        num %= 40;
        roman += std::string(num / 10, 'X');
        num %= 10;
        roman += std::string(num == 9 ? 1 : 0, 'I') + std::string(num == 9 ? 1 : 0, 'X');
        num %= 9;
        roman += std::string(num / 5, 'V');
        num %= 5;
        roman += std::string(num == 4 ? 1 : 0, 'I') + std::string(num == 4 ? 1 : 0, 'V');
        num %= 4;
        roman += std::string(num, 'I');  

        return roman;
    }
};

