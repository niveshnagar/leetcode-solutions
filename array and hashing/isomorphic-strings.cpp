class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char,char> m,n;
        for(int i=0; i<s.length();i++){
            char c=s[i];
            char d=t[i];
            if((m.count(c) && m[c]!=d) || (n.count(d) && n[d]!=c)){
                return false;
                }
            
            n[d]=c;
            m[c]=d;
        }
        return true; 
    }
};
