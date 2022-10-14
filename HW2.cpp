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

void push(linkedList q, int co, int exp)
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

void dequene(linkedList q)
{
    if(q.head == NULL){
        cout << "QueneNullException" << endl;
    }
    else{
        q.head = q.head->link;
        q.size--;
    }
}

int topCoef(linkedList q)
{
    if(q.head == NULL){
        cout << "QueneNullException" << endl;
        return -10000;
    }
    else{
        return q.head->coef;
    }
}

int topExp(linkedList q)
{
    if(q.head == NULL){
        cout << "QueneNullException" << endl;
        return -10000;
    }
    else{
        return q.head->exp;
    }
}

int main()
{
    linkedList L1, L2;
    int len;//length of poly
    cin >> len;

    return 0;
}