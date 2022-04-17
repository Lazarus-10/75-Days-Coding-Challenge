// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // we know that left half is always going to be smaller than right half
    // arr1 can contribute between 0 and all of its element to first half
    // we will use binary seach on the contribution

    // let's say contribution of arr1 in first half is cut1
    // e.g : arr1 = {7,12, 14, 15}, arr2 = {1,2,3,4,9,11};
    // cut1 = 2, => arr1 = {7 , 12 / 14, 15}
    // cut2 = 3, => arr2 = {1,2, 3 / 4, 9, 11}
    // we know l1 is always going to be smaller than r1 as they belong to same array, similar for l2 and r2
    // we compare only l1 with r2 and l2 with r1
    
    // compare 12(l1) with 4(r2) and 3(l2) with 14(r1)
    // as l1 > r2 means 12 can't be on left hand side of the merged array, so shift the end to cut-1

    // cut1 = 0 => arr1 = {-INFINITY / 7,12,14,15} 
    // cut2 = 5 => arr2 = {1,2,3,4,9 / 11}
    // compare -INF(l1) with 11(r2) and 9(l2) with 7(r1)
    // as l2 > r1 means we have shift start to cut + 1, so that 9 goes other side

    // cut1 = 1 => arr1 = {7       / 12,14,15} 
    // cut2 = 4 => arr2 = {1,2,3,4 / 9, 11}
    // compare 7(l1) with 9(r2) and 4(l2) with 12(r1)
    // as l1 <= r2 and l2 <= r1 means it is correct partition
    // so the element at mid will be max(l1, l2) and min(r1, r2) in case of even length OR max(l1, l2) in case of odd length

    // O(Log(m+n)) , O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())return findMedianSortedArrays(nums2, nums1); // to make sure to run our search on smaller size array
        int n1 = nums1.size();
        int n2 = nums2.size();
        int start = 0, end = n1;
        while(start <=  end){
            int cut1 = (start + end) >> 1;
            int cut2 = (((n1+n2+1) >> 1) - cut1);
            
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if(l1 <= r2 && l2 <= r1){
                if((n1+n2)&1){
                    return max(l1, l2);
                }else{
                    return (max(l1,l2) + min(r1, r2))/2.0;
                }
            }else if(l1 > r2){
                end = cut1 -1;
            }else{
                start = cut1 + 1;
            }
        }
        return 0.0;
     }
//O(m + n), O(1)
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int i = 0, j = 0, k= 0;
//         int m = nums1.size();
//         int n = nums2.size();
//         int mid1 = (m+n-1)>>1;
//         int mid2 = (m+n)>>1;
        
//         int ans = 0;
//         while(i < m and j < n){
//             if(nums1[i] < nums2[j]){
//                 if(k == mid1 or k == mid2){
//                     ans += nums1[i];
//                 }
//                 i++, k++;
//             }else{
//                 if(k == mid1 or k == mid2){
//                     ans += nums2[j];
//                 }
//                 j++, k++;
//             }
//         }
//         while(i < m){
//             if(k == mid1 or k == mid2){
//                 ans += nums1[i];
//             }
//             i++,k++;
//         }
//         while(j < n){
//             if(k == mid1 or k == mid2){
//                 ans += nums2[j];
//             }
//             j++,k++;
//         }
//         return (m+n)&1? ans : ans/2.0;
//     }
};