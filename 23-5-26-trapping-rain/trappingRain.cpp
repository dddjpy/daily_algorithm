/**
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水)

示例(如附图trappingRain.png):

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
 * 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    // 遍历每一列，根据每一列左右最高最矮的柱子，求出所接的雨水，时间复杂度O{n²}，空间复杂度O(1);
    int violence (vector<int> &height) {
        int rain_sum = 0;
        // 第一根柱子和最后一根柱子肯定不会蓄水，所以不需要遍历；
        for (int i =1; i < height.size() -1 ; i++) {
            int left_max = height[i];
            int right_max = height[i];
            // 找出左侧最高的柱子
            for (int j = 0; j < i; j++) {
                left_max = std::max(height[j], left_max);
            }
            // 找出右侧最高的柱子
            for (int j = i + 1; j < height.size(); j++) {
                right_max = std::max(height[j], right_max);
            }
            // 找出两端较矮的柱子，只有较矮的柱子高于当前柱子才会蓄水
            int slide_max = std::min(left_max, right_max);
            rain_sum = rain_sum + slide_max - height[i];
        }
        return rain_sum;
    }
};

int main() {
     vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    Solution ss;
    int a = ss.violence (vec);
    cout<<" ++++++ violence = "<<a<<endl; // ++++++ violence = 1
    return 0;
}