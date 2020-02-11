#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;

int print(){
    int arr[10]={0, };
    queue<pair<string,int>> q;
    int doc;
    for(int i=0;i<N;i++){
        cin>>doc;
        arr[doc] += 1;
        if(i==M)
            q.push(make_pair("this",doc));
        else
            q.push(make_pair("",doc));
    }
    int cnt = 1;
    bool flag;
    while(1){
        int priority = q.front().second;
        string s = q.front().first;
        q.pop();
        flag = true;
        for(int i=priority+1;i<=9;i++){
            if(arr[i]!=0){
                flag = false;
                break;
            }
        }
        if(!flag){
            q.push(make_pair(s,priority));
        }
        else{
            if(s=="this")
                break;
            cnt++;
            arr[priority] -= 1;
        }
    }
    return cnt;
}
int main(void){
    int test_case;
    cin>>test_case;
    for(int i=0;i<test_case;i++){
        cin>>N>>M;
        cout<<print()<<endl;
    }
}
