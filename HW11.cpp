#include<iostream>
using namespace std;

struct element
{
    string name;
    int score;
};


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
    int pivot = list[left].score , i , j;
    if(left < right){
        i = left; j = right; pivot = list[left].score;

        do{
            do i++; while(list[i].score < pivot);
            do j--; while(list[j].score > pivot);
            if(i < j)swap(list[i], list[j]);

        }while(i < j);

        cout << "The index of the " << ++count << "-th pivot is " << j << "."<< endl;
        swap(list[left], list[j]);
        quickSort(list,left,j-1);
        quickSort(list,right,j+1);
    }
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