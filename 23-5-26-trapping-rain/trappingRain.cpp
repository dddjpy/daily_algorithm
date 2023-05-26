/**
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水)

示例(如附图trappingRain.png):

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
 * 
 */

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
    public:
    // 方法一 ：暴力解法
    // 遍历每一列，根据每一列左右最高最矮的柱子，求出所接的雨水，时间复杂度O(n²)，空间复杂度O(1);
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
            int slide_min = std::min(left_max, right_max);
            if (slide_min > height[i])
              rain_sum = rain_sum + slide_min - height[i];
        }
        return rain_sum;
    }

    // 方法二 ：动态规划
    // 暴力解法中时间复杂度可以降低，不用每次对每个柱子遍历，可以在一次遍历中求出每个柱子的左高和右高，这样时间和空间复杂度都是O(n)
    int dynamic (vector<int> &height) {
        int rain_sum = 0;
        const int pillar_num = height.size();
        // 首先用两个数组，max_left [i]代表第 i 列左边最高的墙的高度，max_right[i] 代表第 i 列右边最高的墙的高度。（一定要注意下，第 i 列左（右）边最高的墙，是不包括自身的，和力扣上边的讲的有些不同）
        // 这种动态分配数组需要配合delete[] left_max进行释放，可以使用vector进行动态分配
        // int* left_max = new int[pillar_num];
        vector<int> left_max(pillar_num, 0);
        vector<int> right_max(pillar_num, 0);

        for (int i = 1; i < pillar_num - 1; i++) {
            // 从左往右依次遍历柱子，计算当前柱子的左侧最高柱子，遍历不包括第0根柱子和第pillar_num-1（最后一根）柱子
            left_max[i] = std::max(height[i - 1], left_max[i - 1]);
        }

        for (int i = pillar_num - 2; i > 0; i--) {
            // 从右往左依次遍历柱子，计算当前柱子的右侧最高柱子，遍历不包括第0根柱子和第pillar_num-1（最后一根）柱子
            right_max[i] = std::max(height[i + 1], right_max[i + 1]);
        }

        for (int i = 1; i < pillar_num - 1; i++) {
            int pillar_min = std::min(left_max[i], right_max[i]);
            if (pillar_min > height[i])
              rain_sum = rain_sum + pillar_min - height[i];
        }
       return rain_sum;
    }
    // 方法三 ：双指针
    // 方法四： 栈
};

int main() {
     vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution ss;
    int a = ss.violence (vec);
    cout<<" ++++++ violence = "<<a<<endl; //  ++++++ violence = 6

    vector<int> vec2 = {0,1,0,2,1,0,1,3,2,1,2,1};
    int b = ss.dynamic(vec2);
    cout<<" ++++++ dynamic = "<<b<<endl; //  ++++++ dynamic = 6
    return 0;
}