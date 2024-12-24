#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

void non_repeating(string s) {
    unordered_map<char, int> mp;
    for (const auto& c : s) {
        mp[c]++;
    }

    for (const auto& c : s) {
        if (mp[c] == 1) {
            auto itr = find(s.begin(), s.end(), c);
            cout << itr - s.begin() << endl;    
            return;
        } 
    }

    cout << -1 << endl;
}

int main(int argc, char* argv[]) {
    string s = "aabb";
    non_repeating(s);
    s = "leetcode";
    non_repeating(s);
    s = "loveleetcode";
    non_repeating(s);
    return 0;
}