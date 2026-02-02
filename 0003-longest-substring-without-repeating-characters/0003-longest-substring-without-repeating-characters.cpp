class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lp = 0, res=0, n = s.length();
        unordered_map<char, int> characterMap;

        for(int i=0; i<s.length(); i++){
            // Find and update the left pointer to the index after the previously occured char
            if(characterMap.find(s[i]) != characterMap.end()){
                lp = max(lp, characterMap[s[i]] + 1);
                cout << lp << "," << s[i] << endl;
            }

            // Add index of the character to the map
            characterMap[s[i]] = i;

            cout << "resBefore: " << res;
            res = max(res, i-lp+1);
            cout << ", resAfter: " << res << endl;
        }

        return res;
    }
};