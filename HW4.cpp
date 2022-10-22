#include<iostream>
#include<stack>
#include<string>
using namespace std;

int priorty(string op);
void inToPost(string *in , string *po ,int len)
{
    stack<string> s;
    int i = 0, Polen = 0;

    while(i < len){
        if(*(in + i) == "1" || *(in + i) == "2" || *(in + i) == "3" || *(in + i) == "4" || *(in + i) == "5" || *(in + i) == "6" || *(in + i) == "7" || *(in + i) == "8" || *(in + i) == "9" ){
            *(po + Polen) = *(in + i);
            i++;
            Polen++;
        }
        else if(*(in + i) == "("){
            s.push(*(in + i));
            i++;
        }
        else if(*(in + i) == ")"){

            while(s.top() != "("){
               *(po + Polen) =  s.top();
               s.pop();
               Polen++;
            }
            s.pop();
            i++;
        }
        else{
            if(i + 2 > len){
                *(po + Polen) = *(in + i);
                Polen++; i++;
            }
            else if(priorty(*(in + i)) >= priorty(*(in + i + 2))){
                *(po + Polen) = *(in + i);
                Polen++; i++;
            }
            else{
                s.push(*(in + i));
                i++;
            }
        }
    }

}

int priorty(string op){
    if(op == "+" || op == "-"){
        return 1;
    }
    else if(op == "*" || op  == "/"){
        return 2;
    }
    else if(op == "(" || op == ")"){
        return 3;
    }
    else{
        return 0;
    }        
}

int main()
{
    int N;
    cin >> N;
    string s;
    getline(cin, s);
    for(int i = 0; i < N; i++){

        getline(cin, s);
        string infix[1000] ;
        string postfix[1000] ;
        int l = 0;

        while(1){
            if(s.find(' ') == -1){
                infix[l] = s.substr(0,1);
                l++;
                break;
            }
            else{
                infix[l] = s.substr(0,s.find(' '));
                s = s.substr(s.find(' ') + 1, s.length());
                l++;
            }
        }

        inToPost(infix, postfix, l);

        for(int i = 0; i < l; i++){
            cout << *(postfix + i) << " ";
        }
        cout << "\n";

    }


    return 0;
}