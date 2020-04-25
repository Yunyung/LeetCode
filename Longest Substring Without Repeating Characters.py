"""
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxLen = 0
        start = 0
        Map = dict()
        for i in range(len(s)):
            # if repeated
            if (s[i] in Map):
                start = Map[s[i]] + 1
            else:
                maxLen = max(maxLen, i - start)
            Map[s[i]] = i

        return maxLen