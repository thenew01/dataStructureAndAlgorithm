

//桶排序的算法1  

/*输入：4 5 2 6 8 3 6 3 1 8  
输出：1 2 3 3 4 5 6 6 8 8  
这道题的局限在于，比较适合于比较小的数字，对于更大一些的数字，这个算法则不太合理，但是对于小范围却数量极大的数字，则非常奏效。  
*/


#include<iostream>  
using namespace std;  
int main()  
{  
	int a[11] = {0,};
	int b[11] = {4,5,2,6,0,3,6,3,1,8};//在0～10里定义一个位置  
	int t;
	
	for(int i=0;i<10;i=i+1)  
	{  
		//cin>>t;  
		t = b[i];
		a[t]++;//输入某个某个数，这个数所对应的位置就＋1  
	}


	for(int j=0;j<10;j=j+1)  
		for(int k=0;k<a[j];k=k+1)  
			cout<<j<<" ";//按照次序输出，将for语句修改着可以倒叙输出  

	getch();
	return 0;  

}  
