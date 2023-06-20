#include<unordered_map>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int,bool> mappings;
        for(int i=0; i<nums.size(); i++){
           if(mappings.count(nums[i])){
               return true;
           }
           else{
               mappings[nums[i]] = true;
           }
        }
        return false;
    }
};
