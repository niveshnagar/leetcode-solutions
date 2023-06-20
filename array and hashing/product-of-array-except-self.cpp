class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // solution array;
        vector<int>ans;

        // going from left to right and collecting cumulative product in answer array;
        int product = 1;
        for(int i=0; i<nums.size(); i++){
            product*= nums[i];
            ans.push_back(product);
        }
        ans[nums.size()-1]= ans[nums.size()-2];

        // redefining product to 1 and traversing left to right;
        product = 1;
        for(int i = nums.size()-1; i > 0; i--){
            ans[i]=product*ans[i-1];
            product*=nums[i];
        }
        ans[0]= product;
        return ans;

    }
};
