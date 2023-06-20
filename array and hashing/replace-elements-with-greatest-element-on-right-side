class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int temp = INT_MIN;
        for(int i = arr.size()-1; i > 0; i--){
            int currmax = max(temp,arr[i]);
            temp = arr[i-1];
            arr[i-1] = currmax;
            

        }
        arr.pop_back();
        arr.push_back(-1);
        return arr ;
    }
};
