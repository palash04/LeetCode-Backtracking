#include <bits/stdc++.h>
using namespace std;

class Solution {
    int size;
    vector<string> res;
    set<string> st;
public:
    void helper(string s, int index){
        if (index >= size) return;
        if (s[index] >= '0' && s[index] <= '9'){
            return helper(s,index+1);
        }
        int ind = -1;
        if (s[index] >= 'A' && s[index] <= 'Z'){
            ind = (int)s[index] + 32;
        }else if(s[index] >= 'a' && s[index] <= 'z'){
            ind = (int)s[index] - 32;
        }
        char ch = ind;
        if (st.find(s) == st.end()){
            st.insert(s);
            res.push_back(s);
            cout << s << "\n";
        }
        helper(s,index+1);
        s[index] = ch;
        if (st.find(s) == st.end()){
            st.insert(s);
            res.push_back(s);
            cout << s << "\n";
        }
        helper(s,index+1);
    }
    
    vector<string> letterCasePermutation(string S) {
        this->size = (int)S.size();
        helper(S,0);
        if (res.size() == 0) {
            res.push_back(S);
            return res;
        }
        return res;
    }
};
