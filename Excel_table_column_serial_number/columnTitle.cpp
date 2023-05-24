/**
给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。返回该列名称对应的列序号。

例如，

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
示例 1:

输入: columnTitle = "A"
输出: 1
示例 2:

输入: columnTitle = "AB"
输出: 28
示例 3:

输入: columnTitle = "ZY"
输出: 701
示例 4:

输入: columnTitle = "FXSHRXW"
输出: 2147483647
提示：

1 <= columnTitle.length <= 7
columnTitle 仅由大写英文组成
columnTitle 在范围 ["A", "FXSHRXW"] 内
出处：

https://edu.csdn.net/practice/28091685
**/

// This method needs to know ascii, not recommended.
#include <string>
#include <iostream>
#include <cstring>

using namespace std;
class Solution
{
public:
    int titleToNumber(string s)
    {
        long num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            num = (num * 26) + (s[i] - 64);
        }
        return num;
    }
};

int main() {
    Solution SS;
    string s = "A";
    // string类型有成员方法length()、size()求字符串长度；
    cout<<" ++++++ s.length() = "<<s.length()<<endl; // ++++++ s.length() = 1
    cout<<" ++++++ s.size() = "<<s.size()<<endl; // ++++++ s.size() = 1
    // sizeof(sting)返回的是string对象所占用的空间，而不是string所存储的字符串大小，不同的库实现可能不同，
    // string字符串所占的空间是从堆中动态分配的，与sizeof()无关；
    cout<<" ++++++ sizeof(s) = "<<sizeof(s)<<endl; // ++++++ sizeof(s) = 32
    // 也可以利用char类型的strlen()方法，但需要用c_str()将string类型转为char*类型；
    cout<<" ++++++ strlen(s.c_str()) = "<<strlen(s.c_str())<<endl; // ++++++ strlen(s.c_str()) = 1
    // 注意：当在函数内部使用sizeof()求解由函数的形参传入的字符数组的长度时，得到的结果为指针的长度，
    // 既对应变量的字节数，而不是字符串的长度，此处一定要小心;
    cout<<" ++++++ sizeof(s.c_str()) = "<<sizeof(s.c_str())<<endl; // ++++++ sizeof(s.c_str()) = 8

    const char* cs = s.c_str();
    cout<<" ++++++ strlen(cs) = "<<strlen(cs)<<endl; // ++++++ strlen(cs) = 1
    cout<<" ++++++ sizeof(cs) = "<<sizeof(cs)<<endl; // ++++++ sizeof(cs) = 8

    char css[] = "A";
    // strlen()函数求出的字符串长度为有效长度，既不包含字符串末尾结束符 '\0';
    // sizeof()函数求出的字符串长度为有效长度包含字符串末尾结束符 '\0';
    cout<<" ++++++ strlen(css) = "<<strlen(css)<<endl; //  ++++++ strlen(css) = 1
    cout<<" ++++++ sizeof(css) = "<<sizeof(css)<<endl; //  ++++++ sizeof(css) = 2

    int result = SS.titleToNumber(s);
    cout<<" ++++++ result = "<<result<<endl; // ++++++ result = 1
    return 0;
}