/*Dijkstra�㷨������Դ���·���㷨��ͨ����ʵ���ɳ�*/   
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


	//��ʼ��dis���飬1�ŵ���������ĳ�ʼ·��  
	for(i=1;i<=n;i++)  
		dis[i]=e[1][i];  

	for(i=1;i<=n;i++)  
		book[i]=0;  
	book[1]=1;  

	//Dijkstra�����㷨  
	for(i=1;i<=n-1;i++)  
	{  
		//�ҵ���1�Ŷ�������Ķ���  
		min=inf;  
		for(j=1;j<=n;j++)  
		{  
			if(book[j]==0 && dis[j]<min)  
			{  
				min=dis[j];  
				u=j;  
			}  
		}  
		book[u]=1; //��һ��©�ˣ�һ��Ҫ��ס�߹��Ķ���һ��Ҫ���   
		for(v=1;v<=n;v++)  
		{  
			if(e[u][v]<inf) //�Լ�����ʱ�򣬻���������һ�� �Ƿ�Ӧ�øĳ�if(book[v]==0 && e[u][v]<inf)  
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