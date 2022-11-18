#include <iostream>
using namespace std;
#define MAXSIZE 100 // 注意：maxsize的值减1后才是数组的最大存储值
#define Status int
#define Success 1
#define Error 0
class queue
{
public:
    int *base;
    int front; // 前“指针”
    int last;  // 末“指针”
    Status init(void)
    {
        base = new int[sizeof(int) * MAXSIZE];
        if (!base)
            exit(Error);
        front = 0;
        last = 0;
        return Success;
    }
    Status push(int val)
    {
        if ((last + 1) % MAXSIZE == front)
            return Error; //队满
        base[last] = val;
        last = (last + 1) % MAXSIZE;
        return Success;
    }
    Status pop(void)
    {
        if (last == front)
            return Error; //队空
        front = (front + 1) % MAXSIZE;
        return Success;
    }
    int Front(void)
    {
        if (last == front)
            return Error; //队空
        return base[front];
    }
};
int main(void)
{
    queue q;
    q.init();
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        q.push(val);
    }
    q.pop();
    cin >> val;
    q.push(val);
    for (int i = 0; i < n; i++)
    {
        cout << q.Front() << " ";
        q.pop();
    }
}