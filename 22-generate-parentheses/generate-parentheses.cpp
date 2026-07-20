class Solution {
public:
    vector<string> ans;
    void helper(string s,int open,int close) {
        if(open==0 && close==0) {
            ans.push_back(s);
            return;
        }
        if(open>0) {
            s+='(';
            helper(s,open-1,close);
            s.pop_back();
        }
        if(close>0) {
            if(open<close) {
                s+=')';
                helper(s,open,close-1);
                s.pop_back();
            }
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        helper("",n,n);
        return ans;
    }
};