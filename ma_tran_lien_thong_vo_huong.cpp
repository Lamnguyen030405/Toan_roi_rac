#include <iostream>
#define MAX 100
using namespace std;
void Nhapmatran_lienthuocvohuong(int a[][MAX],int &m,int &n)
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
bool Sosanh_cot(int a[][MAX],int m, int col1, int col2)
{
    for (int i = 0; i < m;i++)
        if (a[i][col1] != a[i][col2])
            return false;
    return true;
}
void Songsong(int a[][MAX],int m,int n)
{
	int i=0;
	int j=1;
	while(i<n)
	{
		if(i!=j&&Sosanh_cot(a,m,i,j)==true)
			cout<<"cot "<<i<<" va "<<"cot "<<j<<" chua cap canh song song"<<endl;
		if(j==n-1)
		{
			i++;
			j=0;
		}
		j++;
	}
}
int Bac(int a[][MAX],int i,int n)
{
	int cnt=0;
	for(int j=0;j<n;j++)
		if(a[i][j]!=0)
			cnt+=a[i][j];
	return cnt;
}
int Colap(int a[][MAX],int i,int n)
{
	for(int j=0;j<n;j++)
		if(a[i][j]!=0)
			return 0;
	return 1;
}
int main()
{
	int a[MAX][MAX],m,n;
	Nhapmatran_lienthuocvohuong(a,m,n);
	Xuatmatran(a,m,n);
	Songsong(a,m,n);
	for(int i=0;i<m;i++)
	{
		if(Colap(a,i,n))
			cout<<i<<" la co lap"<<endl;
	}
	int b[MAX];
	for(int i=0;i<m;i++)
	{
		b[i]=Bac(a,i,n);
		cout<<"dinh "<<i<<" co bac bang "<<b[i]<<endl;;
	}
	for(int i=0;i<m;i++)
	{
		if(b[i]==1)
			cout<<"dinh "<<i<<" la treo"<<endl;
	}
	return 0;
}
