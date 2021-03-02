class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
		// 贪心算法		时间复杂度O(n)		空间复杂度O(1)
		int five = 0, ten = 0;
		for (auto& bill : bills) {
			if (bill == 5) {	//收钱收到5元
				five++;
			}
			else if (bill == 10) {	//收钱收到10元
				if (five == 0) {  //没有5元无法找零
					return false;
				}
				five--;
				ten++;
			}
			else {	//收钱收到20元
				if (five > 0 && ten > 0) {  //若有5元和10元的零钱，各找零一张
					five--;
					ten--;
				}
				else if (five >= 3) {  //若有三张以上5元，找三张5元
					five -= 3;
				}
				else {  //不然无法找零
					return false;
				}
			}
		}
		return true;
	}
};