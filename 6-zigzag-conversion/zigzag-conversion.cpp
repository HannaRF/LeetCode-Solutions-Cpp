#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {

        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }
        
        std::string solution = "";
        int N = s.length();

        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < N; j += 2 * (numRows - 1)) {
                solution += s[j];

                if (i != 0 && i != numRows-1 && j + 2 * (numRows - 1 - i) < N) {
                    solution += s[j + 2 * (numRows - 1 - i)];
                }
                if(solution.length()==N){
                    return solution;
                }
            }
        }
        return solution;
    }
};
