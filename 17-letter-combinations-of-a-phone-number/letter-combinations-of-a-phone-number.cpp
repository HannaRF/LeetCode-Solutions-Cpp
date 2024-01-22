class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {{'2', "abc"},
                                          {'3', "def"},
                                          {'4', "ghi"},
                                          {'5', "jkl"},
                                          {'6', "mno"},
                                          {'7', "pqrs"},
                                          {'8', "tuv"},
                                          {'9', "wxyz"}};

        std::vector<std::string> solution = {};
        if (digits.empty()) return solution;

        letterCombinationsRecursive(digits, 0, "", mp, solution);

        return solution;
    }

private:
    void letterCombinationsRecursive(const std::string& digits, int index, std::string current,
                                     const std::unordered_map<char, std::string>& mp,
                                     std::vector<std::string>& solution) {
        // End
        if (index == digits.size()) {
            solution.push_back(current);
            return;
        }

        char digit = digits[index];
        for (char letter : mp.at(digit)) {
            letterCombinationsRecursive(digits, index + 1, current + letter, mp, solution);
        }
    
    }
};