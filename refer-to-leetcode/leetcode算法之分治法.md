今天来盘一盘 **分治法 ** 这类题目



使用**python**刷题分类整理的笔记,请参考:  [https://github.com/lxztju/leetcode-algorithm/tree/v1](https://github.com/lxztju/leetcode-algorithm/tree/v1)

## 分治法
**分而治之**： 就是把一个复杂的问题分成两个或更多的相同或相似的子问题，直到最后子问题可以简单的直接求解，原问题的解即子问题的解的合并


* 241 	为运算表达式设计优先级 (Medium)
* 95 不同的二叉搜索树 II (Medium)


#### 241 	为运算表达式设计优先级 (Medium)

* 以运算符为分界将计算过程分为两部分，左侧的计算结果与右侧的结果相互组合运算即可。

```c++
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int index = 0;
        int num = 0;
        while (index < input.size() && isdigit(input[index])){
            num = num* 10 + input[index] - '0';
            index++;
        }
        if (index == input.size())
            return {num};
        vector<int> ans;
        for(int i = index; i< input.size(); i++){
            if (input[i] == '+' || input[i] == '-' || input[i] == '*'){
                auto left = diffWaysToCompute(input.substr(0, i));
                auto right = diffWaysToCompute(input.substr(i+1));
                for (auto l : left){
                    for (auto r: right){
                        if (input[i] == '+')
                            ans.push_back(l + r);
                        else if (input[i] == '-')
                            ans.push_back(l - r);
                        else
                            ans.push_back(l * r);
                    }
                }
            }
        }
        return ans;
    }
};
```



#### 95 不同的二叉搜索树 II (Medium)

```c++
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {    
        auto res = buildBST(1, n);
        return res; 
    }
    vector<TreeNode*> buildBST(int left, int right){
        if (left > right) return {nullptr};
        vector<TreeNode*> trees;
        for (int i = left; i <= right; i++){
            auto leftTrees = buildBST(left, i-1);
            auto rightTrees = buildBST(i+1, right);
            for (auto l : leftTrees){
                for (auto r : rightTrees){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};
```