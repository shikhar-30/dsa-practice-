class Solution {
public:

    void helper(int i, int k, int target, vector<int> &store, vector<vector<int>> &result)
    {
        if(store.size() == k)
        {
            if(target == 0){

            result.push_back(store);
            return;
            }
        }
        if(i > 9 || target < 0) return;
        store.push_back(i);
        helper(i+1, k, target-i, store, result);
        store.pop_back();
        helper(i+1, k, target, store, result);

    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> store;
        vector<vector<int>> result;
        helper(1, k, n, store, result);
        return result;
    }
};