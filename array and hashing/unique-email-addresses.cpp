class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int>m;
        for(int i=0;i<emails.size();i++){
            string temp = emails[i];
            int j=0;
            string mailId="";
            bool domainReached = false;
            while(j<temp.size()){
                char ch = temp[j];
                if(domainReached){
                    mailId+=ch;
                    j++;
                }
                else{
                    if(ch=='@'){
                        mailId+=ch;
                        domainReached = true;
                        j++;
                    } else if(ch=='.'){
                        j++;

                    } else if(ch=='+'){
                        while(temp[j]!='@'){
                            j++;
                            }

                    } else{
                        mailId+=ch;
                        j++;
                    }
                }
            }
            m[mailId]++;
        }
        return m.size();
    }
};
