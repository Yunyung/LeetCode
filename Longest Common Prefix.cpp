class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        
        int end = -1;
        for (int i = 0;i < strs[0].size();i++){
            int j;
            for (j = 1;j < strs.size();j++){
                if (i > strs[j].size() - 1 || strs[j][i] != strs[0][i]) break;
            }
            if (j == strs.size()) end = i;
            else break;
        }
        if (end >= 0)
            return strs[0].substr(0, end + 1);
        else
            return "";
    }
};

/* another method:
  1.sort the vecotrs container
  2.extract min string and max string
  3.conpare min and max, then you can get the answer   
*/