#include "list.h"

inline Node * initList()
{
    int i,v;
    Node * start = new Node(0);
    Node * last = start;
    rep(i,1,10)
    {
        cin >> v;
        Node * node = new Node(v);
        last->next = node;
        last = node;
    }
    return start;
}
inline void outList(Node * start)
{
    int i,cnt = 0;
    int a[100];
    Node * x = start->next; 
    while (x != NULL)
    {
        a[++cnt] = x->value;
        x = x->next;
    }
    sort(a + 1, a + cnt + 1);
    for (int i = 1; i <= cnt; i++)
    {
        cout << a[i] << endl;
    }
}

inline void Del(Node * x, Node * pre)
{
    pre->next = x->next;
}
inline void findDelOut(int key, Node * start)
{
    Node * x = start->next;
    Node * pre=  start;
    while (x != NULL)
    {
        if (x->value == key)
           Del(x, pre);
        x = x->next;
        pre = pre->next;
    }
    x = start;
    while (x != NULL)
    {
        cout << x->value <<endl;
        x = x->next;
    }
}
int main()
{
    Node * start = initList();
    outList(start);
    int qv;
    cin >>qv;
    findDelOut(qv, start);
    return 0;
}