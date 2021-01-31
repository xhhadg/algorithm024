class Solution {
public:
// 双指针 将较低的指针向较高的指针移动
    int trap(vector<int>& height) {
        
        if(height.size() < 3)
            return 0;
        
        int temp1 = 0, temp2 = 0, i=0, j = height.size()-1, count = 0;
        while(i < j)
        {
            if(height[i] < height[j])
            {
                if(temp1 < height[i])
                    temp1 = height[i];
                else
                    count += temp1 - height[i];
                i++;
            }
            else
            {
               if(temp2 < height[j])
                    temp2 = height[j];
                else
                    count += temp2 - height[j];
                j--;
            }
        }
        return count;
    }
    
};