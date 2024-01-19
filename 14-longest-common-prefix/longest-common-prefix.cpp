class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string match = strs[0];
        for(int i = 1; i<strs.size(); i++){
            for(int j = 0; j<match.length(); j++){
                if(strs[i][j] != match[j]){
                    match = match.substr(0,j);
                    break;
                }
            }
        }
        return match;
    }
};