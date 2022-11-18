/*输入一个长度为n的整数序列。
接下来再输入m个询问，每个询问输入一对l, r。
对于每个询问，输出原序列中从第l个数到第r个数的和。
输入格式:
第一行包含两个整数n和m。
第二行包含n个整数，表示整数数列。
接下来m行，每行包含两个整数l和r，表示一个询问的区间范围。*/
#include<iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int *a = new int[(n + 1)]; //b[n]的前缀和
    int *b = new int[(n + 1)];
    a[0] = 0;
    int i = 1;
    for(;i <= n;i++){
        cin >> a[i];
        b[i] = a[i] - a[i - 1]; //逆运算求b[n]的每一项
    }
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        b[l] += c;             //b[l]+c后 a[l]后的值都会+c 
        b[r + 1] -= c;         //故b[l]后的数需-c才能满足[l，r]内的a[n]+c 
    }
    for(i = 1; i <= n; i++){
        b[i] += b[i - 1];     //求前缀和，即a[n]
        cout << b[i] << " ";
    }
    delete[] a;
    delete[] b;
}