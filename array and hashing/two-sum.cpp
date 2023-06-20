#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //create answer vector;
        vector<int>answer;
        int n = nums.size();

        //create an unordered map;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int a= target-nums[i];
            if(m.count(a)){
                answer.push_back(i);
                int idx = m[a];
                answer.push_back(idx);
                break;
            }
            m[nums[i]]=i;
        }
        return answer;


    }
};
