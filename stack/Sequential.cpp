#define SUCCESS 1
#define ERROR 0
#define OVERFLOW 1
#define Status int
#define MAXSIZE 100
#include<iostream>
using namespace std;
class stack
{
public:
    int* top;
    int* base;
    int maxsize;
    Status init(void){
        base = new int[MAXSIZE];
        maxsize = MAXSIZE;
        if(base){
            top = base;
            return SUCCESS;
        }
        return ERROR;
    }
    Status isoverflow(void){
        if(top - base == maxsize) return OVERFLOW;
        return 0;
    }
    Status push(int num){
        if(isoverflow()) return ERROR;
        *top = num;
        top++;           //为使后续计算方便，使top指向栈顶的上面
        return SUCCESS;
    }
    Status Pop(int &val){
        if(base == top){
            return ERROR;
        }
        top--;
        val = *top;
        return SUCCESS;
    }
    Status clear(void){
        top = base;
        return SUCCESS;
    }
    Status destroy_stack(void){
        if(base == nullptr) return ERROR;
        delete base;
        base = nullptr;        //避免野指针
        top = nullptr;
        return SUCCESS;
    }
};
int main(void){
    stack s;
    int status = s.init();
    if(status == SUCCESS) cout << "Success!" << endl; 
    else cout << "Error!" << endl;
    int i = 0, n;
    int val = 0;
    cin >> n;
    for(i = 0;i < n;i++){
        cin >> val;
        s.push(val);
    }
    for(i = 0;i < n;i++){
        s.Pop(val);
        cout << val << " ";
    }
    cout << endl;
    if(s.destroy_stack()) cout << "Success!" << endl;
    else cout << "ERROR" << endl;
}