#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const string opening("(["), closing(")]");
    while(1){
        string str;
        getline(cin,str);
        if(str.length()==1&&str[0]=='.'){
            return 0;
        }
        bool flag = true;
        stack<char> s;

        for(int i=0;i<str.length();i++){
            if(str[i]=='('||str[i]=='['||str[i]==')'||str[i]==']'){
                if(opening.find(str[i])!=-1){
                    s.push(str[i]);
                }
                else{
                    if(s.empty()){
                        flag = false;
                        break;
                    }

                    if(opening.find(s.top())!=closing.find(str[i])){
                        flag = false;
                        break;
                    }

                    s.pop();
                }
            }
        }
        if(!flag||!s.empty())
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
}
