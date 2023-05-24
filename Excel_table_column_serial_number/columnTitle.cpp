#include <bits/stdc++.h>
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