#include<iostream>
using namespace std;
struct node
{
    int coef;
    int exp;
    node* link = NULL;
};


struct linkedList
{
    node* head = NULL;
    node* rear = NULL;
    int size = 0;
};

void push(linkedList &q, int co, int exp)
{
    node *n = new node;
    n->coef = co; n->exp = exp;
    n->link = NULL;
    if(q.head == NULL){
        q.head = n;
        q.rear = n;
    }
    else{
        q.rear->link = n;
        q.rear = n;
    }
    q.size++;
}

void dequene(linkedList &q)
{
    if(q.head != NULL){
        q.head = q.head->link;
        q.size--;
    }
}

void print(linkedList &q)
{
    while (q.size > 0)
    {
        if(q.head->coef == 0){
            cout << q.head->coef << " " << q.head->exp << " ";
        }
        dequene(q);
    }
    
}

int main()
{
    //insert two polynomials
    linkedList L1, L2, ans;
    int len, tmpCo, tmpExp;//length of poly
    cin >> len;
    for(int i = 0; i < len; i++)
    {
        cin >> tmpCo; cin >> tmpExp;
        push(L1, tmpCo, tmpExp);
    }
    cin >> len;
    for(int i = 0; i < len; i++)
    {
        cin >> tmpCo; cin >> tmpExp;
        push(L2, tmpCo, tmpExp);
    }

    //相加
    while(L1.head != NULL || L2.head != NULL)
    {
        cout << L1.size << " " << L2.size  << " " << ans.size <<"\n";
        if(L1.head->exp > L2.head->exp){//L1次方大於L2
            push(ans, L1.head->coef, L1.head->exp);
            dequene(L1);
        }
        else if(L1.head->exp < L2.head->exp){//L2次方小於L1
            push(ans, L2.head->coef, L2.head->exp);
            dequene(L2);
        }
        else{//次方相等
            push(ans, L1.head->coef + L2.head->coef, L1.head->exp);
            dequene(L1);
            dequene(L2);
        }
    }
    cout << "test\n";
    print(ans);

    return 0;
}
