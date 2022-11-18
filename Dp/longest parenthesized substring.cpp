#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    /**
     *
     * @param s string字符串
     * @return int整型
     */
    int longestValidParentheses(string s)
    {
        // write code here
        int len = s.length();
        vector<int> dp(len, 0); // dp[i]指以下标为i的子符结束的序列中最长的合法括号序列
        int res = 0;
        for (int i = 1; i < len; i++)
        {
            // s[i] == '('默认为0 跳过
            if (s[i] == ')')
            {
                //相邻的就是'(' 则加上之前的合法括号序列长度
                if (s[i - 1] == '(')
                {
                    dp[i] = (i > 1 ? dp[i - 2] : 0) + 2;
                }
                //不相邻，则先获得其所对应的'('的下标位置，即i - dp[i - 1] - 1，加上'('前合法括号序列的长度，再加上')'相邻的合法括号序列长度，即dp[i - 1]，再加2
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    dp[i] = (i - dp[i - 1] > 1 ? dp[i - dp[i - 1] - 1 - 1] : 0) + dp[i - 1] + 2;
                }
            }
            //实时维护最大值
            res = max(res, dp[i]);
        }
        return res;
    }
};