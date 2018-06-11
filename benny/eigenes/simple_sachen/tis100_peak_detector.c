/*Author: Benjamin Brandtner
 * 	Reads input and outputs the minimum and maximum of a 0 terminated sequence */

#include <stdio.h>

int main (void)
{
	int array[39]={14,73,58,0,21,87,11,56,0,50,71,60,0,98,60,18,76,0,20,28,98,0,83,34,11,0,50,84,53,58,0,92,52,83,24,88,0,76,0};
	
	int min;
	int max;

	int i;

	printf("Minimum Maximum\n");
	
	min=array[0];
	max=array[0];

	for(i=0;i<39;i++)
	{
		if(array[i]!=0)
		{
			if(array[i]<min){min=array[i];}
			if(array[i]>max){max=array[i];}
		}
		else
		{
			printf("%3i %3i\n", min, max);

			min=array[i+1];
			max=array[i+1];
		}
	}



	return 0;
}//end main
