class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = "";
        int n = strs.size();
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[n-1];

        int p = min(first.length(),last.length());

        for(int i=0; i<p; i++){
            if(first[i]==last[i]){
                answer+=first[i];
            }
            else{
                break;
            }
        }
        
        return answer;
    }
};
