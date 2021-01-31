class Solution {
public:
// 学习优秀解法 时间复杂度O(n)
    int removeDuplicates(vector<int>& nums) {
          if (nums.empty()) {
              return 0;
          } 
          int j = 0;
          for (int i = 0; i < nums.size(); i++ ){
              if (nums[j]!=nums[i]){
                 j++;
                 nums[j] = nums[i];
             }
         }
     return j+1;    
     }
};