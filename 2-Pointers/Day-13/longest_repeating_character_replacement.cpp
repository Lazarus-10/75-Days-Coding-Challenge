// https://leetcode.com/problems/longest-repeating-character-replacement/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// maxCount may be invalid at some points, but this doesn't matter, because it was valid earlier in the string, and all that matters 
//is finding the max window that occurred anywhere in the string. Additionally, it will expand if and only if enough repeating 
//characters appear in the window to make it expand. So whenever it expands, it's a valid expansion.
    
// The window size can either grow by one, or stay the same
// If <=k replaced chars, we accept new char at right into our window. Left stays the same, so the window grows by one
// Else s[right] does not keep <=k replaced chars, so we shrink the window by increasing left. But we take right into our window anyway, thus being -1 + 1 = 0
// So the window can only grow when there are <=k replaced chars.
// Hence the max will only increase if there are <=k replaced chars.
// So essentially after each iteration, the window size will remain max long, or increase to max+1 long.

    int characterReplacement(string s, int k) {
        int freqArr[26] = {0};
        int start = 0, end;
        int maxFreq = 0, maxLength = 0;
        for(int end = 0; end < s.length(); end++){
            maxFreq = max(maxFreq, ++freqArr[s[end] - 'A']);
            if(end - start + 1 - maxFreq > k){
                --freqArr[s[start++] - 'A'];
            }
            else maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};