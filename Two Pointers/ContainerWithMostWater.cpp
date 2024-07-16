class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int area = 0;
        int maxi = 0;
        while(i<j){
            int x = min(height[i],height[j]);
            area = x*(j-i);
            maxi = max(maxi,area);
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxi;
    }
};