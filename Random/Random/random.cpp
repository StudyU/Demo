#include <iostream>
#include <stdlib.h>                        //rand()，srand()函数在这个头文件中
#include <time.h>                         //time(0)在这个头文件中
#define MAX 5
//const int MAX=5;
using namespace std;

int main()
{  
	int arr[MAX];  
	int i=0; 
	srand((unsigned)time(NULL));  
	while(1)
	{   
		bool ret=false; 
		arr[i]=rand()%MAX+1;  
		for(int j=0;j< i;j++)

		{      
			if(arr[j]==arr[i]) 
			{
				ret=true; 
			}
		}   
		if(!ret)    
		{      
			i++; 
		}  
		if(i==5)
		{     
			break;   
		}
	}  
	for (int j = 0; j < 5; j++)
	{
		cout<< arr[j]<< " ";
	}
	return 0;
}
