// https://leetcode.com/problems/find-the-duplicate-number/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        do{
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(tortoise != hare);
        int itr = nums[0];
        while(itr != tortoise){
            itr = nums[itr];
            tortoise = nums[tortoise];
        }
        return itr;
    }
};