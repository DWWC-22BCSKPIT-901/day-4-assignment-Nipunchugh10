#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> max_sliding_windows(vector<int>& nums, int k) {
    vector<int> res;
    deque<int> dq;

    for (int i = 0; i < nums.size(); ++i) {
        if (!dq.empty() && dq.front() == i - k) { dq.pop_front(); }

        while (!dq.empty() && nums[dq.back()] < nums[i]) { dq.pop_back(); }
        dq.push_back(i);

        if (i >= k - 1) { res.push_back(nums[dq.front()]); }
    }

    return res;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = max_sliding_windows(nums, k);

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
