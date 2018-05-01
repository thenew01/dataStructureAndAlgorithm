/*Dijkstra算法，即单源最短路径算法：通过边实现松弛*/   
#include<stdio.h>  

int main()  
{  
	int i,j,n,m,u,v,t1,t2,t3,min;  
	int dis[10];  
	int e[10][10];  
	int book[10];  
	int inf=99999999;  

	FILE* file = fopen("dijkstra.txt", "r");	
	fscanf(file, "%d %d",&n,&m);  

	for(i=1;i<=n;i++)  
	{
		for(j=1;j<=n;j++)  
		{
			if(i==j) e[i][j]=0;  
			else e[i][j]=inf;  
		}
	}

	for(i=1;i<=m;i++)  
	{  
		fscanf(file, "%d %d %d",&t1,&t2,&t3);  
		e[t1][t2]=t3;  
	}  
	fclose(file);


	//初始化dis数组，1号到各个顶点的初始路程  
	for(i=1;i<=n;i++)  
		dis[i]=e[1][i];  

	for(i=1;i<=n;i++)  
		book[i]=0;  
	book[1]=1;  

	//Dijkstra核心算法  
	for(i=1;i<=n-1;i++)  
	{  
		//找到离1号顶点最近的顶点  
		min=inf;  
		for(j=1;j<=n;j++)  
		{  
			if(book[j]==0 && dis[j]<min)  
			{  
				min=dis[j];  
				u=j;  
			}  
		}  
		book[u]=1; //这一步漏了，一定要记住走过的顶点一定要标记   
		for(v=1;v<=n;v++)  
		{  
			if(e[u][v]<inf) //自己做的时候，还少了以这一步 是否应该改成if(book[v]==0 && e[u][v]<inf)  
			{  
				if(dis[v]>dis[u]+e[u][v])  
					dis[v]=dis[u]+e[u][v];  
			}  
		}  
	}  
	for(i=1;i<=n;i++)  
		printf("%5d",dis[i]);  

	getchar();getchar();  
	return 0;  
}   