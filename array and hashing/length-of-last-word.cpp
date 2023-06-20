class Solution {
public:
    int lengthOfLastWord(string s) {
        int wordlength = 0;
        int n= s.length()-1;
        while(n>=0){
            if(wordlength==0 && s[n]==' '){
                n--;
            }
            else if(s[n] != ' '){
                wordlength++;
                n--;
            }
            else if(s[n]== ' ' && wordlength !=0 ){
                break;
            }
        }
        return wordlength;

    }
};
