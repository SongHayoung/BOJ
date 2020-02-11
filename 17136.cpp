#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <memory.h>
using namespace std;

#define MAXSIZE 11

int cnt=0;
int N;
int ans=987654321;
int used[6];
int arr[MAXSIZE][MAXSIZE];
int total = 0, temp = 0;
int found_x, found_y;
bool isPossible(int x, int y, int type)
{
    if ((x + type) > 11 || (y + type) > 11||x<=0||y<=0)
        return false;
    if (used[type] <= 0)
        return false;

    for (int i = x; i<x + type; i++)
        for (int j = y; j<y + type; j++)
            if (arr[i][j] == 0)
                return false;

    return true;
}
void cover(int x, int y, int type)
{
    for (int i = x; i<x + type; i++)
        for (int j = y; j<y + type; j++)
            arr[i][j] = 0;
}

void re_cover(int x, int y, int type)
{
    for (int i = x; i<x + type; i++)
        for (int j = y; j<y + type; j++)
            arr[i][j] = 1;
}

void find(int x, int y)
{
    found_x = 0; found_y = 0;
    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j <= 10; j++)
        {
            if (arr[i][j] == 1)
            {
                found_x = i; found_y = j;
                return;
            }
        }
    }
}

int dp(int x, int y, int type,int cur_total)
{

    if (!isPossible(x, y, type))
        return 987654321;
    if (total == cur_total)
    {
        return 1;
    }

    used[type]--;
    cover(x, y, type);

    int ret = 987654321;
    find(x, y);
    int new_x = found_x;
    int new_y = found_y;

    for (int i = 5; i >= 1; i--)
    {
        ret = min(ret, dp(new_x, new_y, i,cur_total+(i*i)));
    }

    re_cover(x, y, type);
    used[type]++;
    return 1 + ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            cin >> arr[i][j];
            total += arr[i][j];
        }
    for (int i = 1; i <= 5; i++)
        used[i] = 5;

    if (total == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    else if (total == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    else if (total == 100)
    {
        cout << "4" << endl;
        return 0;
    }
    else
    {
        for (int k = 5; k >= 1; k--) {
            find(1, 1);
            ans = min(ans, dp(found_x, found_y, k, k * k));
        }

        if (ans < 100)
            cout << ans << endl;
        else
            cout << "-1" << endl;
        return 0;
    }
}
