class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        n = len(nums)
        
        for i in range(n) :
            need = target - nums[i]
            if need in dic :
                return [dic[need],i] 
            dic[nums[i]] = i


