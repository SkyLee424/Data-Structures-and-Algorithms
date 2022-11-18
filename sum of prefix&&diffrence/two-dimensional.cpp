/*基本顺序：
输入a[n]
求a[n]的差分，即b[n]
对b[n]操作（加c，即可让b[n]的前缀和k即a[n]在指定范围加c）
求b[n]的前缀和，即a[n]
输出b[n]*/
//55行后第二种方式
#include<iostream>
using namespace std;
void add(int x1,int y1,int x2,int y2,int c,int**b){
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
void init(int**a,int n,int m){
    for(int i = 0;i < n + 2;i++){
        a[i] = new int[m + 2];
        for(int j = 0;j < m + 2;j++){
            a[i][j] = 0;
        }
    }
}
int main(void){
    int n, m, q;
    cin >> n >> m >> q;
    int**a = new int*[n + 2]; //b[n]的前缀和
    int**b = new int*[n + 2];
    init(a,n,m); init(b,n,m);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
            b[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1]; //构建a[n]的差分
        }
    }
    while(q--){
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        add(x1,y1,x2,y2,c,b); // b[]+c后，a[]对应+c
    }
    cout << endl;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            b[i][j] += b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1]; ///求b[n]前缀和，即a[n]
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    //for(int i = 0;i < n;i++){
    //    delete[]a[i];
    //    delete[]b[i];
    //}
    //delete[] a;
    //delete[] b;
}

//将二维转为一维
/*
int main(void)
{
    int n, m, q;
    cin >> n >> m >> q;
    int num[n * m + 1];
    int d[n * m + 1];
    num[0] = 0;
    d[0] = 0;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> num[i];
        d[i] = num[i] - num[i - 1];
    }
    while (q--)
    {
        int x1, x2, y1, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        for (int h = x1; h <= x2; h++)
        {
            d[y1 + (h - 1) * m] += c;
            d[y2 + (h - 1) * m + 1] -= c;
        }
    }
    for (int i = 1; i <= n * m; i++)
    {
        d[i] += d[i - 1];
        cout << d[i] << " ";
        if (i % m == 0)
            cout << endl;
    }
}
*/