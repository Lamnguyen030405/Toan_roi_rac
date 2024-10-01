//Testcase
//8 11 3
//1 5 
//1 6
//2 5
//2 6
//3 5
//3 6
//4 5
//4 6
//4 7
//4 8
//8 7


#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#define maxn 10001
using namespace std;


vector<int > adj[maxn];

int n, m, u;

void Nhap()
{
	cin >> n >> m >> u;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

stack<int > S;

stack<int > CE;

int main()
{
	Nhap();
	S.push(u);
	while (!S.empty())
	{
		int x = S.top();
		if (!adj[x].empty())
		{
			int y = adj[x].front();
			S.push(y);
			vector<int > :: iterator it1 = find(adj[x].begin(), adj[x].end(), y);
			vector<int > :: iterator it2 = find(adj[y].begin(), adj[y].end(), x);
			if(it1!=adj[x].end())
				adj[x].erase(it1);
			if(it2!=adj[y].end())
				adj[y].erase(it2);
		}
		else
		{
			CE.push(x);
			S.pop();
		}
	}
	while (!CE.empty())
	{
		int num = CE.top();
		CE.pop();
		cout << num << ", ";
	}
}
