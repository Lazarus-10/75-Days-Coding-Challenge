// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Naive - Solution(Brute-Force)
    
    /*int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        for(int i=0; i<n; i++){
            int h = heights[i];
            int j = i-1;
            int k = i+1;
            while(j >= 0 && heights[j] >= heights[i])j--;
            while(k < n && heights[k] >= heights[i])k++;
            maxArea = max(maxArea, h*(k-j-1));
        }
        return maxArea;
     }*/
    
    // The idea is to calculate first leftSmallest and first rightSmallest of every histo[i]
    // which is done here efficiently by maintaining a min stack
    // e.g for histo[2] = 5, leftSmallest index = 1, and rightSmallest index = 4
    
    // O(4n)
    /*int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        int left[n], right[n];
        stack<int> st;
        // This loop takes O(2n) time
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
     
        while(!st.empty())
            st.pop();
        
        int maxArea = 0;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
            maxArea = max(maxArea, arr[i]*(right[i] - left[i] - 1));
        }
        return maxArea;
    }*/
    
    // O(2n)
    // More optimized, single pass solution
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int l=0, h=0;
        int area = 0;
        for(int i=0; i <= n; i++){
            while(i==n || (!st.empty() && arr[st.top()] > arr[i])){
                if(i == n && st.empty())break;
                h = arr[st.top()];
                st.pop();
                l = st.empty() ? -1 : st.top();
                area = max(area, h*(i - l - 1));
            }
            st.push(i);
        }
        return area;
    }
};

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    Solution obj;
    cout << obj.largestRectangleArea(heights) << endl;
}