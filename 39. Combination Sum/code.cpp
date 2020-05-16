class Solution {
    vector<vector<int>> res;
    set<vector<int>> st;
public:
    void solve(vector<int> &candidates,int target,vector<int> temp){
       if (target == 0){
           sort(temp.begin(),temp.end());
           if (st.find(temp) == st.end()){
               res.push_back(temp);
               st.insert(temp);
           }
           return;
       } 
       for (int i=0;i<candidates.size();i++){
           if (target-candidates[i] >= 0){
               temp.push_back(candidates[i]);
               solve(candidates, target-candidates[i], temp);
               temp.pop_back();
           }
       } 
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates,target,temp);
        return res;
    }
};
