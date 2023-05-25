/**
给你一个数组 nums 和一个值 val，你需要​ 原地​ 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并​ 原地​ 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);
// 在函数里修改输入数组对于调用者是可见的。 // 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。 for (int i = 0; i < len; i++) {     print(nums[i]); }

示例 1：

输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2]
解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
示例 2：

输入：nums = [0,1,2,2,3,0,4,2], val = 2
输出：5, nums = [0,1,4,0,3]
解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
提示：

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
出处：

https://edu.csdn.net/practice/28091686
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    // c++和c不同是，可以以"引用"的方式进行参数传递，可以有效避免数组降阶，使用方法如下：
    // 在c++中，数组应用不会按值传递，它传递的是第一个元素，准确的说是第0个指针；
    // https://blog.csdn.net/hffyfdt/article/details/86776735
    // 需要注意的是，此处数组必须加上长度[N];
    int removeElement_usearr (int (&arr)[4], int length, int remove_num) {
        int new_length = 0;
        for(int i = 0; i< length; i++) {
            if (arr[i] != remove_num) {
                arr[new_length] = arr[i];
                new_length++;
            }
        }
        return new_length;
    }

    int removeElement_usevec (vector<int> &arr, int remove_num) {
        int new_length = 0;
        for(int i = 0; i< arr.size(); i++) {
            if (arr[i] != remove_num) {
                arr[new_length] = arr[i];
                new_length++;
            }
        }
        return new_length;
    }
};

int main () {
    int array[] = {3, 2, 2, 3};
    int array_copy[] = {3, 2, 2, 3};
    int remove_num = 3;
    
    Solution ss;
    int a = ss.removeElement_usearr (array, 4, remove_num);
    cout<<" ++++++ removeElement_usearr = "<<a<<endl; // ++++++ removeElement_usearr = 2

    vector<int> vec;
    for (int i = 0; i<4; i++) vec.push_back(array_copy[i]); 
    int b = ss.removeElement_usevec (vec, remove_num);
    cout<<" ++++++ removeElement_usevec = "<<b<<endl; // ++++++ removeElement_usearr = 2
    
}