#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        int l = 0, r = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (l < m && r < n) {
            if (g[r] <= s[l]) {
                r++;
            }
            l++;
        }

        return r;
    }
};

int main() {
    // Test input
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    // Create Solution object
    Solution obj;

    // Pass test input to the function
    int result = obj.findContentChildren(g, s);

    // Print result
    cout << "Maximum number of content children: " << result << endl;

    return 0;
}