//chay tren compiler tot hon
//test case
//8 12 1
//1 2
//1 3
//1 8
//2 1
//2 4
//2 8
//3 4
//3 6
//4 5
//5 6
//5 8
//6 7


#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100001;

int n, m, r;

vector<int> adj[maxn];

vector<int> chuaxet(maxn, 1);

vector<pair<int, int>> T;

void nhap()
{
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

}

void Tree_DFS(int v)
{
	chuaxet[v] = 0;
	for (int u : adj[v])
	{
		if (chuaxet[u] == 1)
		{
			T.push_back({ v,u });
			Tree_DFS(u);
		}
	}
}

int main()
{
	nhap();
	Tree_DFS(r);
	for (auto it : T)
	{
		cout << "(" << it.first << ", " << it.second << ")" << ";\t";
	}
	return 0;
}
