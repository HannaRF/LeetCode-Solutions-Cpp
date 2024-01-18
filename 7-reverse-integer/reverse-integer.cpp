
class Solution {
public:
    int reverse(int x) {
        try {
            bool is_negative = x < 0;

            if (is_negative) {
                if (x == std::numeric_limits<int>::min()) {
                    // Special case for the minimum value
                    throw std::exception();
                }
                x = -x;
            }

            std::string str_x = std::to_string(x);
            std::reverse(str_x.begin(), str_x.end());
            x = std::stoi(str_x);

            if (str_x.length() > 6) {
                int divisor = static_cast<int>(std::pow(10, 3));
                std::string str_x_digits = std::to_string(x % divisor);
                if (str_x_digits != str_x.substr(str_x.length() - 3, 3)) {
                    return 0;
                }
            }

            if (is_negative) {
                x = -x;
            }

            if (x < std::numeric_limits<int>::min() || x > std::numeric_limits<int>::max()) {
                return 0;
            } else {
                return x;
            }

        } catch (std::exception& e) {
            // Catch the exception and return 0
            return 0;
        }
    }
};





