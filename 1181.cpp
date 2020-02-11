#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 600

vector <string> arr;
string temp;
int N;


bool compare(const string &a,const string &b)
{
	if (a.length()==b.length())
		return a<b;
	else
		return a.length()<b.length();
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(),compare);

	arr.erase(unique(arr.begin(), arr.end()),arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
}
