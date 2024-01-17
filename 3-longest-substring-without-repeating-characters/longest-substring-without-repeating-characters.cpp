#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> characters;
        int solution = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            // Checa se o caractere já está no conjunto de caracteres da subtring
            while (characters.find(s[right]) != characters.end()){   
                characters.erase(s[left]);
                ++left;
            }
            // caso contrário adicionamos este e atualizamos o tamanho máximo
            characters.insert(s[right]);
            solution = std::max(solution, right - left + 1);
        }
        
        return solution;
    }
};