// c++_algo.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include <iostream>
#include <string>

using namespace std;

#define MAXSIZE 50
string word[MAXSIZE];
bool use[26];
int answer=0;
int N, K;
void answer_func(int alpa, int left)
{
    int ans=0;
    bool in;
    
    if(left==0)
    {
        for(int i=0; i<N; i++)
        {
            in=true;
            for(int j=0; j<word[i].size(); j++)
            {
                if(!use[word[i][j]-'a'])
                {
                    in = false;
                    break;
                }
            }
            if(in)
                ans++;
        }
        answer = max(ans,answer);
        return ;
    }
    
    for(int i=alpa; i<26; i++)
    {
        if(!use[i])
        {
            use[i] = true;
            answer_func(i,left-1);
            use[i] = false;
        }
    }
}
int main(void)
{
    cin>>N>>K;
    
    if(K<5)
    {
        cout<<'0'<<endl;
        return 0;
    }
    if(K==26)
    {
        cout<<N<<endl;
        return 0;
    }
    
    for(int i=0; i<26; i++)
        use[i] = false;
    
    use['a'-'a'] = true;
    use['n'-'a'] = true;
    use['t'-'a'] = true;
    use['i'-'a'] = true;
    use['c'-'a'] = true;
    
    for(int i=0; i<N; i++)
    {
        cin>>word[i];
        word[i]=word[i].substr(0,word[i].size()-4);
        word[i]=word[i].substr(4,word[i].size());
    }
    
    answer_func(0,K-5);
    cout<<answer<<endl;
}
