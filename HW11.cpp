#include<iostream>
using namespace std;

struct element
{
    string name;
    int score;
};

bool great(element a, element b){
    if(a.score > b.score)return true;
    else if(a.score < b.score)return false;
    return a.name < b.name;
}


void swap(element* a, element* b)
{
    element temp;
    *a = temp;
    *a = *b;
    *b = temp; 
}

int count = 0;

void quickSort(element* list, int left, int right)
{
    if(left >= right)return;
    int i = left, j = right+1, pivot = list[left].score;

    do{
        do i++; while(great(list[left],list[i]) && i < right);
        do j--; while(great(list[j],list[left]) && j >left);
        if(i < j)swap(list[i], list[j]);

    }while(i < j);

    cout << "The index of the " << ++count << "-th pivot is " << j << "."<< endl;
    swap(list[left], list[j]);
    quickSort(list,left,j-1);
    quickSort(list,j+1,right);    
}

element L[1000001];

int main()
{
    int n;
    cin >> n;
    for(int t = 0; t < n; t++){
        cin >> L[t].name;
        cin >> L[t].score;
    }

    quickSort(L,0,n-1);

    for(int t = 0; t < n; t++){
        cout << L[t].name << " " << L[t].score << endl;
    }

    return 0;
}