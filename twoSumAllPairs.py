from typing import List, Tuple, Set


class Solution:
    def twoSum(self, nums: List[int], target: int) -> Set[Tuple[int, int]]:
        h = {}
        pairs = set()

        for i in range(len(nums)):
            h[nums[i]] = i

        for i in range(len(nums)):
            y = target - nums[i]
            if y in h and h[y] != i:
                pair = tuple(sorted([i, h[y]]))
                pairs.add(pair)

        return pairs


# Example usage:
nums = [2, 7, 11, 15, 7, 2]
target = 9
solution = Solution()
result = solution.twoSum(nums, target)
# result should be {(0, 1), (4, 5)} since both pairs sum to 9
print(result)
