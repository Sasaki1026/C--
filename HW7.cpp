#include<iostream>
using namespace std;

struct node
{
    string work;
    int priorty;
};

node heap[1000100];
int last = 0;

void exchange(node temp[], int index)
{
    node extemp = temp[index];
    temp[index] = temp[index / 2];
    temp[index / 2] = extemp;
}

void adjup(node h[], int index)
{
    while (index > 1)
    {
        if (h[index].priorty <= h[index / 2].priorty){
            break;
        } 
        else {
            exchange(h, index);
            index /= 2;
        }
    }    
}

void adjdown(node h[],int index){
        
    node data = h[index];
    int index_temp=index*2;
    while(index_temp <= last){
        
        if((index_temp < last) && h[index_temp].priorty < h[index_temp+1].priorty)
            index_temp++;
        if(h[index_temp].priorty <= h[index_temp/2].priorty)
            break;
        else{
            h[index_temp/2] = h[index_temp];
            index_temp *= 2;
        }
            
    }
    h[index_temp/2] = data;        
}

void insert()
{
    cin >> heap[++last].work;
    cin >> heap[last].priorty;
    adjup(heap, last);
}

void pop()
{
    cout << heap[1].work << "\n";
    heap[1] = heap[last--];
    adjdown(heap,1);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        insert();
    }

    cout << "First three things to do:\n";

    for(int i = 0; i < 3; i++){
        pop();
    }

    return 0;
}