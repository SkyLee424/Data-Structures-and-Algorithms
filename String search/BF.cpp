#include<iostream>
#include<string>
using namespace std;
int main(void)
{
    string s0,s1;
    getline(cin,s0);
    getline(cin,s1);
    int len0 = s0.length(),len1 = s1.length();
    int i,j;
    int flag = 1;
    for(i = 0; i < len0 - len1 + 1;i++){
        for(j = 0;j < len1;j++){
            if(s0[i + j] != s1[j]) break;
        }
        if(j == len1){
            if(flag) cout << i + 1;
            else cout << "," << i + 1;
            flag = 0;
        }
    }
    if(flag) cout << "Not found!" << endl;
    else cout << endl;
}