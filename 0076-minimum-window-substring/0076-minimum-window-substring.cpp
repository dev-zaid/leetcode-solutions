class Solution {
public:
    bool contains(unordered_map<char,int> &sMap, unordered_map<char,int> &tMap){
        for(auto &it : tMap){
            if(sMap[it.first] < it.second){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(s.length() < t.length()){
            return "";
        }

        unordered_map <char,int> sMap;
        unordered_map <char,int> tMap;

        // populate tMap
        for(int i=0; i<t.length(); i++){
            tMap[t[i]]++;
        }

        int l=0, minLength=INT_MAX, minStart=0;

        for(int r=0; r<s.length(); r++){
            sMap[s[r]]++;

            while(contains(sMap, tMap)){
                int length = r-l+1;
                if(length < minLength){
                    minLength = length;
                    minStart = l;
                }

                sMap[s[l++]]--;
            }
        }

        return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
    }
};