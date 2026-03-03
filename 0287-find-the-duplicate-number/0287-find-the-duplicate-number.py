class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for x in nums:
            print(x)
            if nums[abs(x) - 1] < 0:
                return abs(x)
            nums[abs(x) - 1] = nums[abs(x) - 1] * -1