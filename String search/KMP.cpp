#include<iostream>
#include<string>
using namespace std;
void find_next(string s,int* &next,int len);
int main(void)
{
    string s0,s1;
    getline(cin,s0);
    getline(cin,s1);
    int len0 = s0.length(),len1 = s1.length();
    int* next = new int[len1];
    find_next(s1,next,len1);
    /*
    for(int k = 0;k < len1;k++){
        cout << next[k] << " ";
    }
    */
    int i = 0,j = -1;
    while(i < len0 && j < len1){
        if(j == -1 ||s0[i] == s1[j]){   //j == -1说明j已经在最左边了，需将i右移
            i++;j++;                   //暂时匹配成功，则继续遍历s0，s1
        }
        else j = next[j];            //匹配失败，j后移至next[j]，i无须回溯，不变
    }
    if(j >= len1) cout << i - len1 + 1 << endl; //即i < len0时就已结束循环，成功找到，首元素下标为i - len0
    else cout << "Not found!" << endl;
    delete[] next;
}
void find_next(string s,int* &next,int len){
    int i = 0, j = -1;
    next[0] = -1;
    while(i < len){
        if(j == -1 || s[i] == s[j]){
            if(s[++i] == s[++j]){
                next[i] = next[j]; //两个字符相等时跳过(注：i > j)
            }
            else next[i] = j;
        }
        else j = next[j];
    }
}