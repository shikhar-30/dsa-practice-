class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int ms=0, ws=0;
        for(int i=0;i<k;i++){
            ws=ws+nums[i];
        }
        ms=ws;
        for(int i=k;i<nums.size();i++){
        ws =ws+nums[i]-nums[i-k];
        ms=max(ws,ms);
        }
    
    double ans=(double)ms/k;
    return ans;
    }
};