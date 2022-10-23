#include<iostream>
#include<stack>
#include<string>
#include<map>
using namespace std;


map<string,int> priorty = {
{"+",2},{"-",2},{"*",3},{"/",3},{"(",20},{")",0}
};
map<string,int> priorty2 = {
{"+",2},{"-",2},{"*",3},{"/",3},{"(",1},{")",0}
};

void inToPost(string *in , string *po ,int len)
{
    stack<string> s;
    int inID = 0;
    int postID = 0;
    while(inID < len)
    {
        if(priorty.count(*(in + inID))){
            if(s.empty()){//
                s.push(*(in + inID++));
            }
            else{
                while (!s.empty() && priorty2[s.top()] >= priorty[*(in + inID)])
                {
                    if(s.top()!="("){
                        *(po + postID++) = s.top();
                    }
                    if(s.top()=="(" and *(in + inID)==")"){
                        s.pop();
                        inID++;
                        break;
                    }
                    s.pop();
                }
                if(*(in + inID) != ")"){
                    s.push(*(in + inID++));
                };
            }
        }
        else{
            *(po + postID++) = *(in + inID++);
        }
    }
    while (!s.empty())
    {
        *(po + postID++) = s.top();
        s.pop();
    }

    for(int i = 0; i < postID - 1; i++){
        cout << *(po+i) << " ";
    }
    cout << endl;    
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

    }


    return 0;
}