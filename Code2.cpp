class Solution {
public:
      int mappedNumber(int num, vector<int>& mapping) {
        string s = to_string(num);
        for (char &c : s) {
            c = '0' + mapping[c - '0'];
        }
        return stoi(s);
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp.push_back(make_pair(i, mappedNumber(nums[i], mapping)));
        }

        auto compare = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second)
                return a.first < b.first; 
            return a.second < b.second;   
        };

        sort(mp.begin(), mp.end(), compare);

        vector<int> ans;
        for (int i = 0; i < mp.size(); i++) {
            ans.push_back(nums[mp[i].first]);
        }
        return ans;
    }

};
