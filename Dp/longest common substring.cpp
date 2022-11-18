#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*https://www.nowcoder.com/practice/f33f5adc55f444baa0e0ca87ad8a6aac?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=*/
/*https://www.bilibili.com/video/BV1aK411J7b8/?spm_id_from=333.788.top_right_bar_window_history.content.click&vd_source=d0b9d5e9bd4f7a2a478a53a71ea8ee05*/
/*https://alchemist-al.com/algorithms/longest-common-substring*/
/*
static const auto io_sync_off = [](){
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return nullptr;
};
*/
class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    int mymax(int a,int b){
        return a >= b ? a : b;
    }
    /*
    string LCS(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length();
        vector<vector<int>> dp(len1 + 1,vector<int>(len2 + 1,0));
        int end = 0;
        int maxlen = 0;
        for(int i = 1;i <= len1;i++){
            for(int j = 1;j <= len2;j++){
                if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = 0;
                }
                if(dp[i][j] > maxlen){
                    maxlen = dp[i][j];
                    end = i - 1;
                }
            }
        }
        cout << maxlen << " " << end;
        
        return str1.substr(end - maxlen + 1,maxlen);
    }
    */
    string LCS(string str1, string str2){
        int len1 = str1.length(), len2 = str2.length();
        int end = 0, maxlen = 0;
        vector<int>dp(len2 + 1,0);
        for(int i = 1;i <= len1;i++){
            for(int j = len2;j > 0;j--){
                if(str1[i - 1] == str2[j - 1]){
                    dp[j] = dp[j - 1] + 1;
                    if(dp[j] > maxlen){
                        maxlen = dp[j];
                        end = i - 1;
                    }
                }
                else dp[j] = 0;
            }
        }
        cout << end << " " << maxlen;
        return str1.substr(end - maxlen + 1,maxlen);        
    }
};