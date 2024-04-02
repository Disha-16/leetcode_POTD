class Solution {
public:
    bool isIsomorphic(string s, string t) {
         if(s.length() != t.length()) {
        return false;
    }

   
    unordered_map<char, char> sToT;
    unordered_map<char, char> tToS;

    for(int i = 0; i < s.length(); i++) {
        char sChar = s[i];
        char tChar = t[i];

       
        if(sToT.find(sChar) != sToT.end()) {
            if(sToT[sChar] != tChar) {
                return false;
            }
        } else {
           
            if(tToS.find(tChar) != tToS.end()) {
                return false;
            }
            sToT[sChar] = tChar;
            tToS[tChar] = sChar;
        }
    }
    return true;
        
    }
};
