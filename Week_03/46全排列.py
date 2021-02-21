class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
		优秀代码 善用python语法糖
        """

        res = []
		self.dfs(nums, [], res)
		return res
        def dfs(self, nums, path, res):
			if not nums:
				res.append(path)
				# return # backtracking
			for i in xrange(len(nums)):
				self.dfs(nums[:i]+nums[i+1:], path+[nums[i]], res)