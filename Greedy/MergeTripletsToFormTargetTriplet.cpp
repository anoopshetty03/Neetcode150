// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();

        bool x1 = false,x2 = false,x3 = false;

        for(int i=0;i<n;i++){
            if(triplets[i][0] == target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]) x1 = true;
            if(triplets[i][1] == target[1] && triplets[i][0]<=target[0] && triplets[i][2]<=target[2]) x2 = true;
            if(triplets[i][2] == target[2] && triplets[i][1]<=target[1] && triplets[i][0]<=target[0]) x3 = true;
        }
        return x1 && x2 && x3;
    }
};