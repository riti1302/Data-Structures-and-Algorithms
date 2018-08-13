#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "sys/time.h" 

void random_list(int *array, int size);
int partition(int *array, int down, int up);
void quicksort(int *array, int down, int up);

struct timeval time_start, time_end;
                             struct timezone tz; 
                             long int cpu_time=0;
                             int t1=0,t2=0;


int main()
{
	int size, Array[100000]= {}, i;

	printf("Enter the size of the list: ");
	scanf("%d", &size);

    srand(time(0));
	random_list(Array, size);

	printf("The random list is:\n");
	for(i = 0; i < size; i++)
		printf("%d\n", Array[i]);

	t1=gettimeofday(&time_start,&tz); 

	quicksort(Array, 0, size-1);
    
    t2=gettimeofday(&time_end,&tz); 
                            
    cpu_time= ((time_end.tv_sec*1000000)+ time_end.tv_usec)-((time_start.tv_sec*1000000)+time_start.tv_usec);
    
	printf("\nThe sorted list is:\n");
	for(i = 0; i < size; i++)
		printf("%d\n", Array[i]);

	printf("\nCPU time for quicksort = %ld microsecs.= %9.6f secs.\n",cpu_time,(float)cpu_time/1000000);


	return 0;
}


void random_list(int *array, int size)
{
	int i;

	for(i = 0; i < size; i++)
		array[i] = rand();
}

int partition(int *array, int down, int up)
{
   int pivot = array[down];
   int i = down;
   int j = up+1;

  do
  {
  	do
  	{ 
  		i++ ;
  	}while(array[i]< pivot && i<=up);

  	do
  	{
  		j--;
  	}while(array[j] > pivot);

  	if(i < j)
  	{
  		int temp = array[i];
  		array[i] = array[j];
  		array[j] = temp;
  	}
  }while(i < j);

  array[down] = array[j];
  array[j] = pivot;
  return (j);
}


void quicksort(int *array, int down, int up)
{
	if(down < up)
	{
       int pivot = partition(array, down, up);
       quicksort(array, down, pivot-1);
       quicksort(array, pivot+1, up);
	}
   
}