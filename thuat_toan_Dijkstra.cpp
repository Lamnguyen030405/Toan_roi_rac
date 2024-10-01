//chay tren compiler khac

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using ll = long long;

const int maxn = 100001;
int n, m, s;								//n la so dinh, m la so canh, s la dinh ban dau
vector<pair<int, int> > adj[maxn];

//void xoa(priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& T, int s) 
//{
//	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> temp;
//
//	while (!T.empty()) 
//	{
//		pair<int,int> top = T.top();
//		T.pop();
//		int u= top.second;
//		int kc = top.first;
//		if (u != s) 
//		{
//			temp.push({kc,u});
//		}
//	}
//	T = temp;
//}

void nhap()
{
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;						//tu dinh x den dinh y co trong so w
		cin >> x >> y >> w;				
		adj[x].push_back({ y,w });
	}

}

const int INF = 1e10;
void dijkstra(int s)
{
	//mang luu khoang cach duong di
	vector<ll> d(n + 1, INF);
	vector<int> trc(n + 1);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> T;
	//{khoang cach,dinh}
	
	//for (auto it : adj[s])
	//{
	//	int v = it.first;
	//	int w = it.second;
	//	d[v] = w;
	//	trc[v] = s;
	//}

	d[s] = 0;
	for (auto it : adj[s])
	{
		int v = it.first;
		trc[v] = s;
	}
	
	/*for (int i = 1; i <= n; i++)
	{
		for (auto it : adj[i])
		{
			int v = it.first;
			int w = it.second;
			T.push({ w,v });
		}
	}
	xoa(T, s);*/
	
	T.push({ 0,s });

	while (!T.empty())
	{
		//chon ra dinh co khoang cach tu s nho nhat
		pair<int, int> top = T.top();
		T.pop();
		int u = top.second;	
		int kc = top.first;
		if (kc > d[u]) 
			continue;	//co nghia da duoc cap nhat khoang cach ngan nhat tu s den u khong can phai xet nua
		//cap nhat khoang cach tu s cho toi moi dinh ke voi u
		for (auto it : adj[u])
		{
			int v = it.first;
			int w = it.second;
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				trc[v] = u;
				T.push({ d[v],v });
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << "(" << d[i] << ", " << trc[i] << ")" << ";\t";
	}

}

int main()
{
	nhap();
	dijkstra(s);
	return 0;
}
