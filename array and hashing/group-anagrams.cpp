#include<unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;

        unordered_map <string, vector<string>> mymap;
        int n = strs.size();
        string temp;
        for(int i=0; i<n; i++){
            temp=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mymap[strs[i]].push_back(temp);
        }
        unordered_map <string, vector<string>> :: iterator p = mymap.begin();
        while(p!=mymap.end()){
            answer.push_back(p->second);
            p++;
        }

        return answer;
    }
};
