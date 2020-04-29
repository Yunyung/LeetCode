class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int maxA = 0;
        while(start != end){
            int minHeight = min(height[start], height[end]);
            maxA = max(maxA, (end - start) * minHeight);
            
            if (minHeight == height[start]) start++;
            else end--;
        }
        
        return maxA;
    }
};
