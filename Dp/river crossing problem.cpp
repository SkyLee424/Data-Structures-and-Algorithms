#include<iostream>
#include<algorithm>
using namespace std;
int mymin(int a,int b){
    return a < b ? a : b;
}
int main(void)
{
    int n;
    cin >> n;
    int people[n]; //存放每个人的过河时间
    for(int i = 0;i < n;i++){
        cin >> people[i];
    }
    sort(people,people + n);
    int dp[n];
    dp[0] = 0;
    dp[1] = people[1];
    /*假设未过河的人有i个*/
    /*先考虑 i - 1 个的情况*/
    /*即假设未过河的人为1个，过河的为 i - 1 个，先让对岸的把手电筒送过来，时间为people[0]*/
    /*然后people[0]和第i个人一起过河，时间为people[i]*/
    /*若未过河的为2个，情况类似*/
    for(int i = 2;i < n;i++){
        dp[i] = mymin(dp[i - 1] + people[0] + people[i],dp[i - 2] + people[0] + people[i] + 2 * people[1]);
    }
    cout << dp[n - 1];
}