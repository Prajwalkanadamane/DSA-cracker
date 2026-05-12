#include<iostream>
#include<vector>
using namespace std;

int Solve(vector<int>& nums){

    int count = 0;
    int candidate = 0;

    for (int num : nums){
        if (count == 0){
            candidate = num;
        }

        if (num == candidate){
            count++;
        }else{
            count--;
        }
    }

    return candidate;

}

int main(){

    vector<int> nums = {3,2,3};

    int ans = Solve(nums);
    cout << ans << endl;

    return 0;
}


// Quick 5-Step Procedure for Moore's Voting Algorithm (Majority Element)

// Initialize: Set candidate = 0 (or any value) and count = 0.
// Iterate through array: For each num:
// If count == 0, set candidate = num and count = 1.
// Else if num == candidate, increment count.
// Else, decrement count.
// Candidate found: After the loop, candidate is the potential majority element.
// Verify (optional, since problem assumes it exists): Count occurrences of candidate in the array.
// Check: If count > n/2, return candidate; else, no majority (but won't happen here).
// That's it—simple, efficient, and unforgettable. Practice with [2,2,1,1,1,2,2] to see it in action! Ready for the next problem?

// in words!

// Start by picking the first number as your candidate and giving it a count of 1. For each next number, if it matches your candidate, increase the count; if not, decrease it. If the count ever drops to zero, switch to the current number as the new candidate with count 1. After going through all numbers, your candidate is the potential winner. Double-check by counting how many times it appears—if more than half the total, it's the majority element. That's the core of Moore's Voting Algorithm in a nutshell!