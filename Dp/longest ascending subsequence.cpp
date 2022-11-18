#include <vector>
using namespace std;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 给定数组的最长严格上升子序列的长度。
     * @param arr int整型vector 给定的数组
     * @return int整型
     */
    int mymax(int a, int b)
    {
        return a > b ? a : b;
    }
    /*类似最长子序列的解决，不推荐使用*/
    int LIS0(vector<int> &arr)
    {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        int dp[arr.size() + 1][arr.size() + 1];
        int i, j;
        for (i = 0; i < arr.size() + 1; i++)
        {
            dp[0][i] = 0;
        }
        for (i = 0; i < arr.size() + 1; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 1; i < arr.size() + 1; i++)
        {
            for (int j = 1; j < arr.size() + 1; j++)
            {
                if (arr[i - 1] == temp[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = mymax(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[arr.size()][arr.size()];
    }
    /*dp，但空间复杂度为O(n)*/
    int LIS1(vector<int> &arr)
    {
        if (arr.size() == 0)
            return 0;
        int dp[arr.size()];
        int res = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            dp[i] = 1; //无论如何，原数组只要不为空，递增子序列最小长度一定大等于1
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i])
                {                                    //只要前面有数字小于后面的，就符合递增条件
                    dp[i] = mymax(dp[i], dp[j] + 1); //长度要么在原来的基础加一，要么不变（难点）
                }
            }
            res = mymax(dp[i], res);
        }
        return res;
    }
    //找到res中第一个大于target的数，返回其位置(注意：res为上升序列)
    int search(int arr[], int target, int end)
    {
        int l = 0, r = end;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= target)
            {
                r = mid;
            }
            else
                l = mid + 1;
        }
        return l;
    }
    /*二分查找，时间复杂度O(nlogn)，核心为维护一个递增序列*/
    int LIS2(vector<int> &arr)
    {
        if (arr.size() == 0)
            return 0;
        int res[arr.size()];
        int end = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i == 0 || arr[i] > res[end])
            {
                res[++end] = arr[i];
            }
            else
            {
                int tmp_index = search(res, arr[i], end);
                res[tmp_index] = arr[i]; //替换
            }
        }
        return end + 1;
    }
};