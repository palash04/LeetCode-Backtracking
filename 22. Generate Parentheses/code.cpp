#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> res;
public:
    void solve(int o,int c, string s){
        if (o == 0 && c == 0){
            res.push_back(s);
            return;
        }
        if (o > 0){
            s += "(";
            solve(o-1,c,s);
            s.pop_back();
        }
        if (c-o > 0){
            s += ")";
            solve(o,c-1,s);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        solve(n,n,"");
        return res;
    }
};
