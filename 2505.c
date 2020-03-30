#include <stdio.h>
#include <memory.h>
short buf[10001];
int ans[4]= {1,1,1,1};
int swap(int from, int end,int last){
    short _buf[10001], f = from, e = end;
    memcpy(_buf,buf,sizeof(_buf));
    while(f<e){
        _buf[f]^=_buf[e]^=_buf[f]^=_buf[e];
        ++f, --e;
    }
    for(int i = from; i <= last; ++i){
        if(_buf[i]!=i) break;
        if(i==last) return -1;
    }
    f = from;
    int ret;
    while(_buf[f]==f) ++f;
    ret = f;
    e = last;
    while(_buf[e]==e) --e;
    int _ans = e;
    while(f<e){
        _buf[f]^=_buf[e]^=_buf[f]^=_buf[e];
        ++f, --e;
    }
    for(int i = from; i <= last; ++i)
        if(_buf[i]!=i) return 0;
    ans[2] = ret,ans[3] = _ans;
    return ret;
}
int swap2(int from, int end, int first){
    short _buf[10001], f = from, e = end;
    memcpy(_buf,buf,sizeof(_buf));
    while(f<e){
        _buf[f]^=_buf[e]^=_buf[f]^=_buf[e];
        ++f, --e;
    }
    for(int i = first; i <= end; ++i){
        if(_buf[i]!=i) break;
        if(i==end) return -1;
    }
    e = end;
    int ret;
    while(_buf[e]==e) --e;
    ret = e;
    f = first;
    while(_buf[f]==f) ++f;
    int _ans = f;
    while(f<e){
        _buf[f]^=_buf[e]^=_buf[f]^=_buf[e];
        ++f, --e;
    }
    for(int i = first; i <= end; ++i)
        if(_buf[i]!=i) return 0;
    ans[2] = _ans, ans[3] = ret;
    return ret;
}
int main(void) {
    int N;
    scanf("%d",&N);
    for(int i = 1; i <= N; ++i)
        scanf("%d",&buf[i]);
    int s = 1, e = N;
    while(buf[s]==s) ++s;
    while(buf[e]==e) --e;
    if(e==-1){
        printf("1 1\n1 1");
        return 0;
    }
    int minv = s, maxv = e;
    while(buf[minv]!=s) ++minv;
    while(buf[maxv]!=e) --maxv;
    int ret = swap(s,minv,e);
    if(ret){
        if(ret==-1)
            printf("%d %d\n1 1",s,minv);
        else
            printf("%d %d\n%d %d",s,minv,ans[2],ans[3]);
    }
    else{
        ret = swap2(maxv,e,s);
        if(ret==-1)
            printf("%d %d\n1 1",s,minv);
        else
            printf("%d %d\n%d %d",maxv,e,ans[2],ans[3]);
    }
    return 0;
}
