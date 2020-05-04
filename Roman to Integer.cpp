/*
    First version
*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> Symbol_value_pair; 
        Symbol_value_pair.insert({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                               {'C', 100}, {'D', 500}, {'M', 1000}});
        
        
        unordered_map<string, int> Special_case = {{"IV", 4}, {"IX", 9}, {"XL", 40},
                                            {"XC", 90}, {"CD", 400}, {"CM", 900}}; 
        int Value = 0;
        
        for (int i = 0;i < s.size();i++)
            if (i < s.size() - 1 && Special_case.find(s.substr(i, 2)) != Special_case.end()){
                Value += Special_case[s.substr(i, 2)];
                i++;
            }
            else
                Value += Symbol_value_pair[s[i]];
        
        return Value;
    }
};


/*
    Modify Version
*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> Symbol_value_pair; 
        Symbol_value_pair.insert({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                               {'C', 100}, {'D', 500}, {'M', 1000}});
        int preInt = 0;
        int total = 0;
        int idx = s.size() - 1;
        while (idx >= 0){
            int curInt =  Symbol_value_pair[s[idx]];
            if (curInt < preInt)
                total -= curInt;
            else
                total += curInt;
            
            preInt = curInt;
            idx--;
        }

        return total;
    }
};