#include "stdafx.h"


int min0 = 99999999;
int book[101];
int n;
int e[101][101];

void dfs(int cur, int distance)
{
	int j;
	if( distance > min0 ) return;

	if(cur == n)
	{
		if( distance < min0 ) min0 = distance;
		return;
	}

	for ( j=1;j<=n; j++)
	{
		if( e[cur][j] != min0 && book[j] == 0 )
		{
			book[j] = 1;
			dfs( j, distance + e[cur][j] );
			book[j] = 0;
		}
	}

	return;
}




int main()
{

	int i,j,m,a, b, c;

	FILE* file = fopen("dfs.txt", "r");
	fscanf(file, "%d %d", &n, &m );	

	for ( i = 1;i<=n;i++) //城市数，组成一个二维方形矩阵
	{
		for ( j = 1;j<=n;j++)
		{
			if( i == j ) e[i][j] = 0;
			else e[i][j] = min0;
		}
	}


	for ( i = 0;i<m; i++) //路数
	{
		fscanf(file, "%d %d %d", &a, &b, &c);
		e[a][b] = c;
	}

	book[1] = 1;
	dfs(1, 0);

	printf("%d", min0);
	getch();
	return 0;
}