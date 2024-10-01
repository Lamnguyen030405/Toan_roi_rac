#include <iostream>
#define MAX 100
using namespace std;
void Nhapmatran_lienthuoccohuong(int a[][MAX],int &m,int &n)
{
	cin>>m;
	cin>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
}
void Xuatmatran(int a[][MAX],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
}
bool Sosanh_cotbangnhau(int a[][MAX],int m, int col1, int col2)
{
    for (int i = 0; i < m;i++)
        if (a[i][col1] != a[i][col2])
            return false;
    return true;
}
bool Sosanh_cottrainhau(int a[][MAX],int m, int col1, int col2)
{
	bool flag=true;
    for (int i = 0; i < m;i++)
        if (a[i][col1] != -a[i][col2])
            return false;
    return true;
}
void Songsong_cunghuong(int a[][MAX],int m,int n)
{
	int i=0;
	int j=1;
	while(i<n)
	{
		if(Sosanh_cotbangnhau(a,m,i,j)==true&&i!=j)
			cout<<i<<" va "<<j<<" chua cap canh song song cung huong"<<endl;
		if(j==n-1)
		{
			i++;
			j=0;
		}
		j++;
	}
}
void Songsong_nguochuong(int a[][MAX],int m,int n)
{
	int i=0;
	int j=1;
	while(i<n)
	{
		if(Sosanh_cottrainhau(a,m,i,j)==true&&i!=j)
			cout<<i<<" va "<<j<<" chua cap canh song song nguoc huong"<<endl;
		if(j==n-1)
		{
			i++;
			j=0;
		}
		j++;
	}
}
int Nua_bac_ngoai(int a[][MAX],int i,int n)
{
	int cnt=0;
	for(int j=0;j<n;j++)
		if(a[i][j]==1)
			cnt++;
	return cnt;
}
int Nua_bac_trong(int a[][MAX],int i,int n)
{
	int cnt=0;
	for(int j=0;j<n;j++)
		if(a[i][j]==-1)
			cnt++;
	return cnt;
}
int main()
{
	int a[MAX][MAX],m,n;
	Nhapmatran_lienthuoccohuong(a,m,n);
	Xuatmatran(a,m,n);
	Songsong_cunghuong(a,m,n);
	Songsong_nguochuong(a,m,n);
	int b[MAX];
	int c[MAX];
	for(int i=0;i<m;i++)
	{
		b[i]=Nua_bac_trong(a,i,n);
		cout<<"dinh "<<i<<" co so nua bac trong bang "<<b[i]<<endl;;
	}
	for(int i=0;i<m;i++)
	{
		c[i]=Nua_bac_ngoai(a,i,n);
		cout<<"dinh "<<i<<" co so nua bac ngoai bac bang "<<c[i]<<endl;;
	}
	return 0;
}
