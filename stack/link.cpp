#include<iostream>
#include<stack>
using namespace std;
#define SUCCESS 1
#define ERROR 0
#define Status int
class link_stack{
public:
    int val;
    link_stack* next;
    Status init(void){
        next = nullptr;
        return SUCCESS;
    }
    Status push(int val){
        link_stack* newnode = new link_stack[sizeof(link_stack)];
        newnode->val = val;
        newnode->next = next;
        next = newnode;
        return SUCCESS;
    }
    Status Pop(){
        if(next == nullptr) return ERROR;
        link_stack* temp = next;
        next = next->next;
        delete temp;
        return SUCCESS; 
    }
    Status clear(void){
        if(next == nullptr) return ERROR;
        while (next)
        {
            next = next->next;
        }
        return SUCCESS;
    }
    Status destroy_list_stack(void){
        if(next == nullptr) return ERROR;
        while (next)
        {
            auto temp = next;
            next = next->next;
            delete temp;
        }
        return SUCCESS;
    }
    int Top(void){
        return next->val;    
    }
};
int main(void){
    link_stack s;
    s.init();
    int n;
    cin >> n;
    int val, i = 0;
    for(i = 0;i < n;i++){
        cin >> val;
        s.push(val);
    }
    for(i = 0;i < n;i++){
        if(s.Top()) {
            cout << s.Top() << " ";
            s.Pop();
        }
        else{
            cout << "ERROR" << endl;
            break;
        }
    }
    cout << endl;
    s.clear();
    s.destroy_list_stack();
    
}