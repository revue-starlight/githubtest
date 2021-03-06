#include <iostream>
using namespace std;

int tower[500500],dp[500500];

int trans(int i, int j)
{
	return i*(i+1)/2+j;
}

int main()
{
	 freopen("data.in","r",stdin);
	 freopen("data1.out","w",stdout);
	int hei;
	while(cin>>hei)
	{
		for(int i=0;i<(1+hei)*hei/2;i++)
			cin>>tower[i];
		for(int i=0;i<hei;i++)
			dp[trans(hei-1,i)] = tower[trans(hei-1,i)];
		for(int i=hei-2;i>=0;i--)
			for(int j=0;j<i+1;j++)
				dp[trans(i,j)] = tower[trans(i,j)] + ((dp[trans(i+1,j)]>dp[trans(i+1,j+1)])?dp[trans(i+1,j+1)]:dp[trans(i+1,j)]);
		cout<<dp[0]<<endl;
	}
	return 0;
}