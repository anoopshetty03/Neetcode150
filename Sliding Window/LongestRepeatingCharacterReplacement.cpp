// https://leetcode.com/problems/longest-repeating-character-replacement
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>count(26);
        int maxFreq  = 0;
        int i = 0;
        int j = 0;
        int result = 0;
        while(j < s.size()){
            count[s[j] - 'A']++;
            maxFreq = max(maxFreq,count[s[j] - 'A']);
            if(j - i + 1 - maxFreq > k){
                count[s[i] - 'A']--;
                i++;
            }
            result = max(result,j - i + 1);
            j++;
        }
        return result;
    }
};