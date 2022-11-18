#include<iostream>
using namespace std;
#define mian main
int find_Cattelan0(int n);
int find_Cattelan1(int n);
int mian(void){
    int n;
    cin >> n;
    int res = find_Cattelan0(n);
    cout << res << endl;
    res = find_Cattelan1(n);
    cout << res << endl;
}
/*递归求卡特兰数*/
int find_Cattelan0(int n){
    int cat[30] = {0};
    cat[0] = cat[1] = 1;
    int i, j;
    for(i = 2;i <= n;i++){
        for(j = 0;j < i;j++){
            cat[i] += cat[j] * cat[i - j - 1];
        }
    }
    return cat[n];
}
/*组合数求卡特兰数*/
int find_Cattelan1(int n){
    int **cat = new int*[n * 2 + 1];
    for(int i = 0; i <= n * 2;i++){
        cat[i] = new int[n];
    }
    for(int i = 1;i <= 2 * n;i++){
        cat[i][0] = cat[i][i] = 1;
        for(int j = 1;j < i;j++){
            cat[i][j] = cat[i - 1][j] + cat[i - 1][j - 1];
        }
    }
    return cat[2 * n][n] / (n + 1);          //cat(n) = c(2n,n)/(n+1)
}