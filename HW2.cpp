#include<iostream>
using namespace std;

class node
{
    public:
        int coef;
        int exp;
        node* link = NULL;
};

class linkedList
{
    public:
        node* head = NULL;
        node* reaf = NULL;
};

int main()
{
    linkedList L1, L2;
    int len;//length of poly
    cin >> len;
    for(int i = 0; i < len; i++){
        if(L1.head){
            node tmp;
            cin >> tmp.coef;
            cin >> tmp.exp;
            L1.reaf->link = &tmp;
            L1.reaf = &tmp;            
        }
        else{
            node tmp;
            cin >> tmp.coef;
            cin >> tmp.exp;
            L1.head = &tmp;
            L1.reaf = &tmp;
        }
        
    }


    for(int i = 0; i < 3; i++)
    {
        cout << L1.head->coef << " " << L1.head->exp << "\n";
        L1.head = L1.head->link;
    }

    cout << L1.reaf->link->link;
    return 0;
}