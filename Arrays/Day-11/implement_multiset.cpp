// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection {
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> mp;
public:
    RandomizedCollection() {
       srand(time(0)) ;
    }
    
    bool insert(int val) {
        bool isPresent = mp.find(val) == mp.end();
        mp[val].push_back(nums.size());
        nums.push_back({val, mp[val].size()-1});
        return isPresent;
    }
    
    bool remove(int val) {
        bool isPresent = mp.find(val) != mp.end();
        // keep in mind, do all the removals in last(because for some values(like insert 1 and remove 1) nums[indx] is equal to nums.back(), and if 
        // we remove it earlier, it will cause problem)
        if(isPresent){
            int indx = mp[val].back(); //find the index to be deleted
            nums[indx] = nums.back(); // overwrite last element in nums to that position
            mp[nums[indx].first][nums[indx].second] = indx; // update the new index of that element in map

            
            mp[val].pop_back(); // remove last element index
            if(mp[val].empty())
                mp.erase(val);
            nums.pop_back(); // remove last element from num, as we already copied it to indx
        }
        return isPresent;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */