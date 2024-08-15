class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        nums = {}
        for num in arr:
            if num not in nums:
                nums[num] = 0
            nums[num] += 1
        occurences = set()
        for i in nums.values():
            if i in occurences:
                return False
            occurences.add(i)
        return True