from typing import List
from termcolor import colored  # install via: pip install termcolor

class Solution:
    def print_indent(self, level):
        return "  " * level

    def backtrack(self, nums: List[int], start: int, current: List[int], result: List[List[int]], depth=0):
        indent = self.print_indent(depth)
        print(indent + colored(f"Enter: start={start}, current={current}", "cyan"))

        result.append(list(current))

        for i in range(start, len(nums)):
            # Skip duplicates
            if i > start and nums[i] == nums[i - 1]:
                print(indent + colored(f"Skip duplicate: nums[{i}] = {nums[i]}", "red"))
                continue

            print(indent + colored(f"Include: nums[{i}] = {nums[i]}", "green"))
            current.append(nums[i])

            self.backtrack(nums, i + 1, current, result, depth + 1)

            print(indent + colored(f"Backtrack: remove nums[{i}] = {nums[i]}", "yellow"))
            current.pop()

        print(indent + colored(f"Exit: start={start}, current={current}", "cyan"))

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()  # Sort to handle duplicates
        result = []
        self.backtrack(nums, 0, [], result)
        return result


# Example usage
if __name__ == "__main__":
    nums = [1, 2, 2]
    sol = Solution()
    print("\n--- Backtracking Process ---\n")
    result = sol.subsetsWithDup(nums)

    print("\n--- All Unique Subsets ---\n")
    for subset in result:
        print(subset)
