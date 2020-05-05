class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for (char c: ransomNote)
            mp[c]++;
        
        int remain = mp.size();
        
        for (char c: magazine){
            mp[c]--;
            if (mp[c] == 0)
                remain--;
            if (remain == 0) break;
        }
            
        return remain == 0;
    }
};