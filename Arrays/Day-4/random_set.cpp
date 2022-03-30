// https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/
#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> vec;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())return false;
        vec.push_back(val);
        mp[val] = vec.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())return false;
        mp[vec.back()] = mp[val];
        vec[mp[val]] = vec.back();
        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};
// class RandomizedSet {
//     list<int> st;
// public:
//     RandomizedSet() {
        
//     }
    
//     bool insert(int val) {
//         if(find(st.begin(), st.end(), val) == st.end()){
//             st.push_back(val);
//             return true;
//         }
//         return false;
//     }
    
//     bool remove(int val) {
//         auto itr = find(st.begin(), st.end(), val);
//         if(itr != st.end()){
//             st.erase(itr);
//             return true;
//         }
//         return false;
//     }
    
//     int getRandom() {
//        auto itr = next(st.begin(), rand()%st.size());
//         return *itr;
//     }
// };

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
