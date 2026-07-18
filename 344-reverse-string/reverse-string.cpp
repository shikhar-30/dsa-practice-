class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> stc;
        for (int i = 0; i < s.size(); i++) {
            stc.push(s[i]);
        }
        int i = 0;
        while (!stc.empty()) {
            s[i] = stc.top();
            stc.pop();
            i++;
        }
    }
};