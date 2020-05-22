#include <bits/stdc++.h>
using namespace std;

class Solution {
    string resStr;
    int countK;
public:
    
    vector<int> getCurrentSpace(int n){
        vector<int> v;
        if (n == 97) v = {98,99};
        if (n == 98) v = {97,99};
        if (n == 99) v = {97,98};
        return v;
    }
    
    void solve(int index,int n,int k,string res,vector<int> v){
        
        if (index == n){
            countK++;
            if (countK == k){
                resStr = res;
            }
            return;
        }
        
        for (int i=0;i<v.size();i++){
            res += v[i];
            vector<int> vv = getCurrentSpace(v[i]);
            solve(index+1,n,k,res,vv);
            res.pop_back();
        }
    }
    
    string getHappyString(int n, int k) {
        vector<int> v = {97,98,99};
        countK = 0;
        solve(0,n,k,"",v);
        return resStr;
    }
};
