class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lp = 0, res=0, n = s.length();
        vector<int> characterMap(256, -1);

        for(int i=0; i<s.length(); i++){
            // Find and update the left pointer to the index after the previously occured char
            if(characterMap[s[i]] >= lp){
                lp = characterMap[s[i]] + 1;
            }

            // Add index of the character to the map
            characterMap[s[i]] = i;

            res = max(res, i-lp+1);
        }

        return res;
    }
};