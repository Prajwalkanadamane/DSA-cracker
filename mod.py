nums = [3,0,1]
res = len(nums)
for i in range(len(nums)):
    res += i - nums[i]
print(res)