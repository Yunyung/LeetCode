/* 
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I 
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int curRow = 0; // indicate which row are pointed
        int goDown = true; // indicate the pointed row is going up or down
        vector<string> StringEachRow(numRows);
        
        for(char c : s)
        {
            StringEachRow[curRow] += c;
                
            if (goDown) curRow++;
            else curRow--;
            
            if (curRow == 0) goDown = true;
            if (curRow == numRows - 1) goDown = false;
        }
        
        string ans;
        for (string s: StringEachRow)
            ans += s;
        return ans;
    }
};