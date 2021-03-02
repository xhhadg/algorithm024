class Solution {
public:
    int maxProfit(vector<int>& prices) {
		// 贪心算法		时间复杂度O(n)		空间复杂度O(1)
		int ans = 0;
		int n = prices.size();
		for (int i = 1; i < n; ++i) {
			ans += max(0, prices[i] - prices[i - 1]);
		}
		return ans;
    }
	// 思考：为什么贪心算法是最优的 但是速度和内存都没有超过80%的用户？
};