// https://leetcode.com/problems/permutation-in-string/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m[26] = {0};  // Frequency map for characters in s1
        for(char c: s1)
            m[c - 'a']++;
        
        int i = 0, j = 0, total_chars = s1.size();  // Initialize total_chars to s1's length
        
        while (j < s2.size()) {
            // Process the current character in s2
            if (m[s2[j] - 'a'] > 0) {
                total_chars--;  // We have one less character to match
            }
            m[s2[j] - 'a']--;  // Decrease the frequency
            j++;
            
            // If we matched all characters
            if (total_chars == 0) {
                return true;
            }
            
            // If the window size exceeds s1.size(), slide the window
            if (j - i == s1.size()) {
                // When sliding the window, we need to restore the leftmost character
                if (m[s2[i] - 'a'] >= 0) {
                    total_chars++;  // We are reintroducing this character to be matched again
                }
                m[s2[i] - 'a']++;  // Restore its frequency
                i++;
            }
        }
        
        return false;
    }
};
