#include <stdio.h>
int dp[40];
char buf[41];
int len;
int dfs(int c){
    if(c==len)
        return 1;
    if(dp[c]!=-1) return dp[c];
    if('1'<=buf[c] && buf[c]<='2'){
        if(c+1<len){
            if(buf[c+1]=='0')  dp[c] = dfs(c+2);
            else dp[c] = dfs(c+1) + dfs(c+2);
        }
        else dp[c] = dfs(c+1);
    }
    else if(buf[c]=='3'){
        if(c+1<len&&buf[c+1]=='0'){
            dp[c] = dfs(c+2);
        }
        else if(c+1<len&&'1'<=buf[c+1]&&buf[c+1]<='4'){
            dp[c] = dfs(c+1) + dfs(c+2);
        }
        else
            dp[c] = dfs(c+1);
    }
    else if('4'<=buf[c]&&buf[c]<='9')
        dp[c] = dfs(c+1);
    else dp[c] = 0;
    return dp[c];
}
int main(void) {
    scanf("%s",buf);
    len = strlen(buf);
    memset(dp,-1,sizeof(dp));
    printf("%d", dfs(0));
}
