#include <bits/stdc++.h>
using namespace std;

class NumberMap{
public:
    string getString(char n){
        if (n == '2') return "abc";
        if (n == '3') return "def";
        if (n == '4') return "ghi";
        if (n == '5') return "jkl";
        if (n == '6') return "mno";
        if (n == '7') return "pqrs";
        if (n == '8') return "tuv";
        else return "wxyz";
    }
};

class Solution {
    NumberMap nmp;
    vector<string> results;
public:
    
    void solve(string digits, int index,string res){
        
        if (index >= digits.size()){
            results.push_back(res);
            return;
        }
        string curr = nmp.getString(digits[index]);
        for (int i=0;i<curr.size();i++){
            res += curr[i];
            solve(digits, index+1, res);
            res.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return results;
        solve(digits, 0, "");
        return results;
    }
};
