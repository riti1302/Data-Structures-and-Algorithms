#include<stdio.h>
int main()
{
	int a[100], i, n, j, temp;
	
	printf("Enter the the size of array:- ");
	scanf("%d",&n);
	while(n<5 || n>100)
	{
	printf("\nsize should be in the range of 5-100");
	printf("\nEnter the the size of array again");
	scanf("%d",&n);
	}
	
	printf("Enter the elements in the array:\n");
	for(i=0; i<n; i++)
	{
	  scanf("%d",&a[i]);
        }
        
        for(i=0; i<n-1; i++)
        {
        for(j=0; j<(n-1)-i; j++)
	  {
	    if(a[j]>a[j+1])
	    {
	      temp=a[j];
	      a[j]=a[j+1];
	      a[j+1]=temp;	   
	     }
	  }
        }	
	
	  
	printf("\nThe sorted array is: ");
	for(i=0; i<n; i++)
	{
		printf("%d ",a[i]);
     }
     printf("\n");
      return 0;
}
