#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @param pattern string字符串
     * @return bool布尔型
     */
    bool match(string str, string pattern)
    {
        // write code here
        int slen = str.length(), plen = pattern.length();
        vector<vector<bool> > dp(slen + 1, vector<bool>(plen + 1, false)); // dp[i][j] 指长度为i的str与长度为j的pattern是否匹配
        dp[0][0] = true;                                                  //空串与空串一定匹配
        for (int i = 2; i <= plen; i++)
        {
            if (pattern[i - 1] == '*')
            {
                dp[0][i] = dp[0][i - 1 - 1]; // 只需判断i - 1的前一位是否匹配
            }
        }
        for (int i = 1; i <= slen; i++)
        {
            for (int j = 1; j <= plen; j++)
            {
                if (pattern[j - 1] == '.' || str[i - 1] == pattern[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // pattern[j - 1] == '*'时，pattern前一位能多匹配一位，可用'*'让它多出现一次或不出现
                else if (j >= 2 && pattern[j - 1] == '*')
                {
                    if (pattern[j - 1 - 1] == '.' || pattern[j - 1 - 1] == str[i - 1])
                    {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1 - 1];
                    }
                    else
                        dp[i][j] = dp[i][j - 1 - 1];
                }
            }
        }
        return dp[slen][plen];
    }
};