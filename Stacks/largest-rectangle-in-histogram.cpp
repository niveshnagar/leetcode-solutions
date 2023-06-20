class Solution {
private:
    vector<int>nextSmallerIndex(vector<int>& arr ,int size){         
        stack <int> st;
        st.push(-1);
        vector<int> answer(size);
        for(int i = size-1; i>= 0; i--){
        int curr= arr[i];

        while ( st.top() != -1 && arr[st.top()] >= curr ) {
            st.pop();
        }
        answer[i] = st.top();
        if(answer[i] == -1){
            answer[i] = size;
        }
        st.push(i);
        }
        return answer;
    }

    vector<int>prevSmallerIndex(vector<int>& arr , int size){         
        stack <int> st;
        st.push(-1);
        vector<int> answer(size);
        for(int i = 0; i <= size-1; i++){
        int curr= arr[i];

        while ( st.top() != -1 && arr[st.top()] >= curr ) {
            st.pop();
        }
        answer[i] = st.top();
        st.push(i);
        }
        return answer;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        next = nextSmallerIndex(heights,n);

        vector<int> prev(n);
        prev = prevSmallerIndex(heights,n);

        int area = INT_MIN;

        for(int i=0; i<n; i++){
            int width = next[i] - prev[i] -1;
            int height = heights[i];
            int currArea = width * height;
            area = max(area, currArea);
        }
        return area;
    }
};
