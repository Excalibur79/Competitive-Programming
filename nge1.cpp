#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        stack<int> st;
        for (int data : nums2) {
            if (st.empty() || data <= st.top())
                st.push(data);
            else {
                while (!st.empty()) {
                    hash[st.top()] = data;
                    st.pop();
                }
                st.push(data);
            }

            // while (!st.empty() && st.top() <= data) {
            //     hash[st.top()] = data;
            //     st.pop();
            // }
            // st.push(data);
        }
        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            if (hash.find(nums1[i]) != hash.end()) ans[i] = hash[nums1[i]];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> ans = sol.nextGreaterElement(nums1, nums2);
    for (int data : ans) cout << data << endl;
    return 0;
}