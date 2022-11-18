#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*https://www.bilibili.com/video/BV14A411v7mP/?spm_id_from=333.337.search-card.all.click&vd_source=d0b9d5e9bd4f7a2a478a53a71ea8ee05*/
/*
static const auto io_sync_off = [](){
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return nullptr;
}();
*/
class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    int mymax(int a,int b){
        return a >= b ? a : b;
    }
    string LCS(string s1, string s2) {
        if(s1.size() == 0 || s2.size() == 0){
            return "-1";
        }
        int len1 = s1.length(), len2 = s2.length();
        vector<vector<int> > dp(len1 + 1,vector<int>(len2 + 1,0));
        for(int i = 1;i <= len1;i++){
            for(int j = 1;j <= len2;j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
        string res = "";
        int i = len1, j = len2;
        while(dp[i][j]){
            if(dp[i][j] == dp[i - 1][j]) i--;
            else if(dp[i][j] == dp[i][j - 1])j--;
            else if(dp[i][j] > dp[i - 1][j - 1]){
                i--;j--;
                res += s1[i];
            }
        }
        reverse(res.begin(),res.end());
        return res == "" ? "-1" : res;
    }
};