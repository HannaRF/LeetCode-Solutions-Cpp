class Solution {
public:
    bool isPalindrome(int x) {
        string str_x = to_string(x);
        string str_x_original = str_x;
        reverse(str_x.begin(), str_x.end());
        return str_x == str_x_original;
    }
};