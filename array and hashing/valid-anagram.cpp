class Solution {
public:
    bool isAnagram(string s, string t) {
        int a= s.size();
        int b= t.size();

        if(a!=b){
            return false;
        }
        int store[26];
        for(int i=0; i<26; i++){
                store[i]=0;
            }
        
        for(int i=0; i<a; i++){
                store[s[i]-'a']++;
            }
        for(int j=0; j<b; j++){
                store[t[j]-'a']--;
            }
        for(int i=0;i<26;i++){
            if(store[i] != 0){
                return false;
            }
        }
        
        return true;
    }
};
