class Solution {
public:
    
    unordered_map<char, int> M;
    
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        for(int i=0; i<s.size(); i++){
            M[s[i]]++;    
        }    
        
        for(int i=0; i<t.size(); i++){
            if(--M[t[i]]<0) return false;
        }
        
        return true;
    }
};