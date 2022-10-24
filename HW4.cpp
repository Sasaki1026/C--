#include<iostream>
#include<stack>
#include<string>
#include<map>
#include<bits/stdc++.h>
using namespace std;


map<string,int> priorty = {
{"+",2},{"-",2},{"*",3},{"/",3},{"(",20},{")",0}
};
map<string,int> priorty2 = {
{"+",2},{"-",2},{"*",3},{"/",3},{"(",1},{")",0}
};

void inToPost()
{
    stack<string> s;
    int index =0 ;
    string infix;
    getline(cin,infix);
    stringstream chr(infix);
    string ans[1000];

    while(chr >> infix)
    {
        if(priorty.count(infix)){
            if(s.empty()){//
                s.push(infix);
            }
            else{
                while (!s.empty() && priorty2[s.top()] >= priorty[infix])
                {
                    if(s.top()!="("){
                        ans[index++] = s.top();
                    }
                    if(s.top()=="(" and infix ==")"){
                        s.pop();
                        break;
                    }
                    s.pop();
                }
                if(infix != ")"){
                    s.push(infix);
                };
            }
        }
        else{
            ans[index++] = infix;
        }
    }
    while (!s.empty())
    {
        ans[index++] = s.top();
        s.pop();
    }

    for(int i = 0; i < index; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;    
}

int main()
{
    int N;
    cin >> N;
    string s;
    getline(cin, s);
    for(int t = 0; t < N; t++){

        inToPost();
    }


    return 0;
}