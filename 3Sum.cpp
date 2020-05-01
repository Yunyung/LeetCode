/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        for (unsigned int i = 0;i < nums.size();i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int p1 = i + 1, p2 = nums.size() - 1;p1 < p2;){
                int s = nums[i] + nums[p1] + nums[p2];
                if (s > 0) p2--;
                else if (s < 0) p1++;
                else if (nums[i] + nums[p1] + nums[p2] == 0){
                    result.push_back(vector<int> {nums[i], nums[p1], nums[p2]});
                    
                    while(p1 < p2 && nums[p2] == nums[p2 - 1]) p2--;
                    while(p1 < p2 && nums[p1] == nums[p1 + 1]) p1++;
                    p2--;
                    p1++;
                }
                
                
            }
        }
        return result;
    }
};
