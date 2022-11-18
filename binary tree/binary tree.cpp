#include <iostream>
#include <stack>
#include <queue>
#include<vector>
using namespace std;
/*Input:ABC##DE#G##F###*/
/*Expected Output:
5
5
7
3
C B E G D F A
A B C D E G F
C G E F D B A
A B C D E F G
A
B
C D
E F
G
C B E G D F A*/
class bitree
{
public:
    char val;
    bitree *lchild;
    bitree *rchild;
    bitree() : val(0), lchild(nullptr), rchild(nullptr) {}
};
void add(bitree *&bt)
{
    char Val;
    cin >> Val;
    if (Val == '#')
    {
        bt = nullptr;
        return;
    }
    bt = new bitree;
    bt->val = Val;
    add(bt->lchild);
    add(bt->rchild);
    return;
}
int depth(bitree* bt){
    if(!bt) return 0;
    int llen,rlen;
    llen = depth(bt->lchild);
    rlen = depth(bt->rchild);
    return max(llen,rlen) + 1;
}
int depth1(bitree *bt){
    /*利用队列，避免递归因元素过多而导致栈溢出*/
    int res = 0;
    if(!bt) return res;
    queue<bitree*> q;
    q.push(bt);
    while (!q.empty())
    {
        int n = q.size();
        for(int i = 0;i < n;i++){
            bitree* temp = q.front();
            q.pop();
            if(temp->lchild){
                q.push(temp->lchild);
            }
            if(temp->rchild){
                q.push(temp->rchild);
            }
        }
        res++;
    }
    return res;

}
int nodecnt(bitree* bt){
    if(!bt) return 0;
    return nodecnt(bt->lchild) + nodecnt(bt->rchild) + 1;
}
int leafcnt(bitree *bt){
    if(!bt) return 0;
    if(!bt->lchild && !bt->rchild) return 1;
    return leafcnt(bt->lchild) + leafcnt(bt->rchild);
}
void copy(bitree* &newbt,bitree* &bt){
    if(!bt){
        newbt = nullptr;
        return ;
    }
    newbt = new bitree;
    newbt->val = bt->val;
    copy(newbt->lchild,bt->lchild);
    copy(newbt->rchild,bt->rchild);
}
void traverse0(bitree *bt)
{
    stack<bitree *> s; //存放双亲节点
    bitree *temp0, *temp1;
    temp0 = bt; //利用temp0遍历左子树
    //中序遍历（利用栈实现递归）
    while (temp0 || !s.empty()) 
    {
        if (temp0)
        {
            s.push(temp0);
            temp0 = temp0->lchild;
        }
        else
        {
            temp1 = s.top();
            s.pop();
            cout << temp1->val << " ";
            temp0 = temp1->rchild; //temp0又被赋值为新的二叉树（原双亲节点的右子树）
        }
    }
}
void traverse1(bitree *bt){
    //前序遍历（利用栈实现递归）
    if(!bt) return;
    stack<bitree*> s;
    s.push(bt);
    while (!s.empty())
    {
        bitree *temp = s.top();
        s.pop();
        cout << temp->val << " ";
        if(temp->rchild) s.push(temp->rchild);
        if(temp->lchild) s.push(temp->lchild);
    }
    
}
void traverse2(bitree *bt){
    //后序遍历
    stack<bitree*> s;
    bitree *temp0 = bt;
    bitree *pre = nullptr;
    while (temp0 || !s.empty())
    {
        if(temp0){
            s.push(temp0);
            temp0 = temp0->lchild; //多次循环后，s.top()->lchild = nullptr;
                                   //此时可遍历“柚”子树，即else部分
        }
        else{
            bitree *temp1 = s.top();
            s.pop();
            /*当temp1->rchild == nullptr，即右子树无力，就可以访问根节点的值*/
            /*或者，temp1->rchild == pre，即已经遍历过该右子树，也可访问根节点值*/
            if(temp1->rchild == nullptr || temp1->rchild == pre){
                cout << temp1->val << " ";
                pre = temp1;
            }
            /*将根节点压栈*/
            else{
                s.push(temp1);
                temp0 = temp1->rchild; //temp0被赋值为右子树，供下一次循环遍历使用
            }
        }
    }
}
void traverse3(bitree *bt){
    //层次遍历
    queue<bitree *> q;
    q.push(bt);
    while (!q.empty())
    {
        bitree *temp2;
        temp2 = q.front();
        q.pop();
        cout << temp2->val << " ";
        if (temp2->lchild)
        {
            q.push(temp2->lchild);
        }
        if (temp2->rchild)
        {
            q.push(temp2->rchild);
        }
    }
}
vector<vector<char> > traverse4(bitree *bt){
    //层序遍历 但二维数组版
    vector<vector<char> >res;
    if(!bt) return res;
    queue<bitree*> q;
    q.push(bt);
    while(!q.empty()){
        bitree* cur = q.front();
        int n = q.size(); // 存放每层的元素个数
        vector<char> row;
        for(int i = 0; i < n;i++){
            cur = q.front();
            q.pop();
            row.push_back(cur->val);
            if(cur->lchild){
                q.push(cur->lchild);
            }
            if(cur->rchild){
                q.push(cur->rchild);
            }
        }
        res.push_back(row);
    }
    return res;
}
int main(void)
{
    bitree *bt;
    add(bt);
    cout << depth(bt) << endl;
    cout << depth1(bt) << endl;
    cout << nodecnt(bt) << endl;
    cout << leafcnt(bt) << endl;
    traverse0(bt);
    cout << endl;
    traverse1(bt);
    cout << endl;
    traverse2(bt);
    cout << endl;
    traverse3(bt);
    cout << endl;
    vector<vector<char> >res = traverse4(bt);
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    bitree* bt1;
    copy(bt1,bt);
    traverse0(bt1);
}