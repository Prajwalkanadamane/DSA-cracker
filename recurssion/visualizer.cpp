#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void printIndent(int level) {
        for (int i = 0; i < level; ++i) cout << "  ";
    }

    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result, int depth = 0) {
        printIndent(depth);
        cout << "Enter: start=" << start << ", current={";
        for (int num : current) cout << num << " ";
        cout << "}" << endl;

        result.push_back(current); // Save current subset

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                printIndent(depth);
                cout << "Skip duplicate: nums[" << i << "]=" << nums[i] << endl;
                continue;
            }

            current.push_back(nums[i]);
            printIndent(depth);
            cout << "Include: nums[" << i << "]=" << nums[i] << endl;

            backtrack(nums, i + 1, current, result, depth + 1);

            current.pop_back();
            printIndent(depth);
            cout << "Backtrack: removed nums[" << i << "]=" << nums[i] << endl;
        }

        printIndent(depth);
        cout << "Exit: start=" << start << ", current={";
        for (int num : current) cout << num << " ";
        cout << "}" << endl;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> subsets = sol.subsetsWithDup(nums);

    cout << "\nAll Unique Subsets:\n";
    for (auto& subset : subsets) {
        cout << "{ ";
        for (int num : subset) cout << num << " ";
        cout << "}\n";
    }

    return 0;
}
