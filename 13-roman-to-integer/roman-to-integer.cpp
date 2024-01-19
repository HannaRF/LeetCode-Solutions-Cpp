#include <string>

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        char old_i = ' ';

        for (auto i : s) {
            if (i == 'M') {
                if (old_i == 'C') num += 1000 - 2*100;
                else num += 1000;
            } 
            else if (i == 'D') {
                if (old_i == 'C') num += 500 - 2*100;
                else num += 500;
            } 
            else if (i == 'C') {
                if (old_i == 'X') num += 100 - 2*10;
                else num += 100;
            } 
            else if (i == 'L') {
                if (old_i == 'X') num += 50 - 2*10;
                else num += 50;
            } 
            else if (i == 'X') {
                if (old_i == 'I') num += 10 - 2;
                else num += 10;
            }
            else if (i == 'V') {
                if (old_i == 'I') num += 5 - 2;
                else num += 5;
            }
            else num++;

            old_i = i;
        }

        return num;
    }
};
