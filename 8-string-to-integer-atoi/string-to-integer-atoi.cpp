#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <sstream>

class Solution {
public:
    int myAtoi(std::string s) {
        std::string s_clean = "0";
        bool is_negative = false;

        // Skip leading whitespaces
        size_t i = 0;
        while (i < s.size() && std::isspace(s[i])) {
            ++i;
        }

        // Check for optional sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            is_negative = (s[i] == '-');
            ++i;
        }

        // Process numeric characters
        while (i < s.size() && std::isdigit(s[i])) {
            s_clean += s[i];
            ++i;
        }

        // Convert string to integer
        long long s_long;
        std::stringstream(s_clean) >> s_long;

        // Handle negative sign
        if (is_negative) {
            s_long = -s_long;
        }

        // Handle overflow
        if (s_long < std::numeric_limits<int>::min()) {
            return std::numeric_limits<int>::min();
        }

        if (s_long > std::numeric_limits<int>::max()) {
            return std::numeric_limits<int>::max();
        }

        return static_cast<int>(s_long);
    }
};