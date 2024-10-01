#include <iostream>
#define MAX 100
using namespace std;
void Nhapmatran_kevohuong(int a[][MAX],int &m)
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
			if(i!=j&&a[i][j]>=2&&a[i][j]==a[j][i])
				cout<<i<<"//"<<j<<endl;
	}
}
int Bac(int a[][MAX],int i,int m)
{
	int cnt=0;
	for(int j=0;j<m;j++)
		if(a[i][j]!=0)
			cnt+=a[i][j];
	return cnt;
}
int Colap(int a[][MAX],int i,int m)
{
	for(int j=0;j<m;j++)
		if(a[i][j]!=0)
			return 0;
	return 1;
}
int main()
{
	int a[MAX][MAX],m;
	Nhapmatran_kevohuong(a,m);
	Xuatmatran(a,m);
	Songsong(a,m);
	for(int i=0;i<m;i++)
	{
		if(Colap(a,i,m))
			cout<<i<<" la co lap"<<endl;
	}
	int b[MAX];
	for(int i=0;i<m;i++)
	{
		b[i]=Bac(a,i,m);
		cout<<"dinh "<<i<<" co bac bang "<<b[i]<<endl;;
	}
	for(int i=0;i<m;i++)
	{
		if(b[i]==1)
			cout<<"dinh "<<i<<" la treo"<<endl;
	}
	return 0;
}
