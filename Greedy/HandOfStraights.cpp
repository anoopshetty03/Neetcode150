// https://leetcode.com/problems/hand-of-straights/ 
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mpp;

        for(int i: hand){
            mpp[i]++;
        }

        for(auto x: mpp){
            if(mpp[x.first] > 0){
                for(int i=1;i<groupSize;i++){
                    mpp[x.first+i] -= mpp[x.first];
                    if(mpp[x.first+i] < 0){
                        return false;
                    }
                }
            }
        }
      return true;
    }
};