#include<iostream>
using namespace std;
#define Status int
#define Success 1
#define Error 0
#define Empty 1
class linked_queue{
public:
    int val;
    linked_queue* next;
    linked_queue* front; //前指针
    linked_queue* rear;
    void init(void){
        val = 0;
        front = new linked_queue[sizeof(linked_queue)];
        front->next = nullptr;
        rear = front;
    }
    void push(int val){
        linked_queue* temp = new linked_queue[sizeof(linked_queue)];
        temp->val = val;
        temp->next =nullptr;
        rear->next = temp;
        rear = temp;
    }
    Status isempty(void){
        if(front->next == nullptr && rear == front) return Empty;
        return 0;
    }
    Status pop(void){
        if(isempty()) return Error;
        auto temp = front->next;
        front->next = front->next->next;
        if(temp == rear) rear == front; // 易忘
        delete temp;
        return Success;
    }
    int top(void){
        if(isempty()) return Error;
        return front->next->val;        
    }
    Status _destroy(void){
        if(isempty()) return Error;
        while(front->next){
            auto temp = front->next;
            front->next = front->next->next;
            delete temp;
        }
        delete front;
        return Success;
    }
};
int main(void){
    linked_queue q;
    q.init();
    int num = 0;
    while(1){
        cin >> num;
        if(num == -1) break;
        q.push(num);
    }
    while(q.front->next){
        cout << q.top() << " ";
        q.pop();
    }
    
}
