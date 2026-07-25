class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ans = 0;

        for (int x : nums) {
            if (freq[k - x] > 0) {
                ans++;
                freq[k - x]--;
            } else {
                freq[x]++;
            }
        }

        return ans;
    }
};