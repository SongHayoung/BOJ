#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
bool stair[1000001] = {false,};
int F, S, G, U, D, t;
int main(void){
    queue<int> q;
    scanf("%d %d %d %d %d",&F,&S,&G,&U,&D);
    stair[S] = true;
    q.push(S);
    if(S==G) {
        printf("0");
        exit(0);
    }
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; ++i){
            int s = q.front();
            q.pop();
            if(s+U<=F&&!stair[s+U]){
                if(s+U==G) {printf("%d",t+1); exit(0);}
                stair[s+U] = true;
                q.push(s+U);
            }
            if(s-D>=1&&!stair[s-D]){
                if(s-D==G) {printf("%d",t+1); exit(0);}
                stair[s-D] = true;
                q.push(s-D);
            }
        }
        t++;
    }
    printf("use the stairs");
}
