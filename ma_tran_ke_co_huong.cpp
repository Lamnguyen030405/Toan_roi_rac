#include <iostream>
#define MAX 100
using namespace std;
void Nhapmatran_kecohuong(int a[][MAX],int &m)
{
	cin>>m;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	}
}
void Xuatmatran(int a[][MAX],int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
}
void Songsong(int a[][MAX],int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i!=j&&a[i][j]>=1&&a[j][i]!=0)
			{
				if(a[i][j]!=a[j][i])
					cout<<i<<" va "<<j<<" // cung huong."<<endl;
				else
					cout<<i<<" va "<<j<<" // nguoc huong."<<endl;
			}
		}
	}
}
int Nua_bac_ngoai(int a[][MAX],int i,int m)
{
	int cnt=0;
	for(int j=0;j<m;j++)
		if(a[i][j]!=0)
			cnt+=a[i][j];
	return cnt;
}
int Nua_bac_trong(int a[][MAX],int i,int m)
{
	int cnt=0;
	for(int j=0;j<m;j++)
		if(a[j][i]!=0)
			cnt+=a[j][i];
	return cnt;
}
int main()
{
	int a[MAX][MAX],m;
	Nhapmatran_kecohuong(a,m);
	Xuatmatran(a,m);
	Songsong(a,m);
	int b[MAX];
	int c[MAX];
	for(int i=0;i<m;i++)
	{
		b[i]=Nua_bac_trong(a,i,m);
		cout<<"dinh "<<i<<" co so nua bac trong bang "<<b[i]<<endl;;
	}
	for(int i=0;i<m;i++)
	{
		c[i]=Nua_bac_ngoai(a,i,m);
		cout<<"dinh "<<i<<" co so nua bac ngoai bac bang "<<c[i]<<endl;;
	}
	return 0;
}
