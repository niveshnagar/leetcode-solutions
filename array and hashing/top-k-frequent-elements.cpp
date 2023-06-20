#include<unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //making answer vector;
        vector<int> answer;

        //making an unordered map and filling its values;
        unordered_map<int,int>freq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        //making a vector pair to copy content from map and sort;
        //making pair vector
        vector<pair<int,int>>pairs;
        unordered_map<int,int>::iterator p = freq.begin();
        while(p!=freq.end()){
            pairs.push_back(make_pair(p->second,p->first));
            p++;
        }
        //sorting vector pair
        sort(pairs.rbegin(), pairs.rend());
        for(int i=0; i<k; i++){
            answer.push_back(pairs[i].second);
        }
        return answer;
    }
};
