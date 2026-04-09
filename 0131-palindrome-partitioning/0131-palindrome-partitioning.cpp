class Solution {
public:
    bool isPalindrome(string a){
        string b = a;
        reverse(b.begin(), b.end());
        return a == b;
    }

    void solve(string s, vector<string> &part, vector<vector<string>> &ans){
        if(s.size()==0){
            ans.push_back(part);
            return;
        }

        for(int i=0; i<s.size(); i++){
            string strA = s.substr(0,i+1);
            
            if(isPalindrome(strA)){
                part.push_back(strA);
                solve(s.substr(i+1), part, ans);
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;

        solve(s, part, ans);
        return ans;
    }
};