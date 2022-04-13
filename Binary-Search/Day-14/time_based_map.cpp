// https://leetcode.com/problems/time-based-key-value-store/
#include <bits/stdc++.h>
using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
    static bool compare(const pair<int, string> &a, const pair<int, string> &b){
        return a.first < b.first;
    }
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp) {
        // auto it = upper_bound(mp[key].begin(), mp[key].end(), pair<int, string>{timestamp, ""}, compare);
        auto it = upper_bound(begin(mp[key]), end(mp[key]), pair<int, string>(timestamp, ""),[](const pair<int, string>& a, const pair<int, string>& b) { 
            return a.first < b.first; 
        });
        return it == mp[key].begin() ? "" : (--it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// class TimeMap {
// private:
//     unordered_map<string, map<int, string>> mp;
// public:
//     TimeMap() {
        
//     }
    
//     void set(string key, string value, int timestamp) {
//         mp[key][timestamp] = value;
//     }
//     string get(string key, int timestamp) {
//         auto it = mp[key].upper_bound(timestamp);
//         return it == mp[key].begin() ? "" : (--it)->second;
//     }
// };

// /**
//  * Your TimeMap object will be instantiated and called as such:
//  * TimeMap* obj = new TimeMap();
//  * obj->set(key,value,timestamp);
//  * string param_2 = obj->get(key,timestamp);
//  */