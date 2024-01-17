class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) { 
            return "" ;
        }

        int start = 0, end = 0;
        // Iterando por todos os candidatos a centro do palíndromo
        for (int i = 0; i < s.length(); ++i) {
            int len1 = expand(s, i, i);      // expandindo palíndromo par
            int len2 = expand(s, i, i + 1);  // expandindo palíndromo ímpar

            int len = std::max(len1, len2);

            // Atualiza os índices do palíndromo mais longo
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }


private:
    // Função para expandir o palíndromo a partir de uma posição central
    int expand(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
};