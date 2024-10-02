// https://leetcode.com/problems/generate-parentheses 
class Solution {
public:
    void helper(vector<string> &ans,int n,int oc,int cc,string s){
        //base case
        if(oc == n && cc == n){
            ans.push_back(s);
            return;
        }
        if(oc < n){
            helper(ans,n,oc+1,cc,s+'(');
        }
        if(cc < oc){
            helper(ans,n,oc,cc+1,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int oc = 0;
        int cc = 0;
        helper(ans,n,oc,cc,"");
        return ans;
    }
};