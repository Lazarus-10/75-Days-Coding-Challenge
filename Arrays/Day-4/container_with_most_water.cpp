// https://leetcode.com/problems/container-with-most-water/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j = height.size()-1;
        int volume = 0;
        while(i < j){
            int h = min(height[i], height[j]);
            volume = max(volume, (j-i)*h);
            // if(height[i] < height[j])i++;
            // else j--;
            
            //As we have evaluated that widest container, skip lines at both ends that don't support a higher height
            while(height[i] <= h && i < j)i++;
            while(height[j] <= h && i < j)j--;
        }
        return volume;
    }
};