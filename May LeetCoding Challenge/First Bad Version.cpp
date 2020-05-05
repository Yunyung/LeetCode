// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int right = n;
        int left = 1;  
        while(left < right){
            int mid = left + (right - left) / 2; // similar to (left + right) / 2, but it's about overfitting issue.
            if (isBadVersion(mid)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        
        return left;
        
        // time complexity => O(logn)
        // space complexity => O(1)
    }
};