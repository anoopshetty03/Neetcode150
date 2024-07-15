class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mpp;

        for(auto x: strs){
            string word = x;  // eat(acts as value)
            sort(word.begin(),word.end()); // aet(acts as key)
            mpp[word].push_back(x);   // "aet": ["eat", "tea", "ate"]
        }

        vector<vector<string>>ans;

        for(auto x: mpp){
            ans.push_back(x.second);
        }
        return ans;
    }
};