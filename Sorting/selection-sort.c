#include<stdio.h>
int main()
{
  int a[100], i, j, n, t, f[100], s[1000];
  float Q1, Q2;
  
  printf("Enter the the size of array:- ");
	scanf("%d",&n);
	while(n<5 || n>100)
	{
	printf("\nsize should be in the range of 5-100");
	printf("\nEnter the the size of array again");
	scanf("%d",&n);
	}
	printf("Enter the numbers:\n");
	for(i=0; i<n; i++)
	{
	  scanf("%d",&a[i]);
        }
	for(i=0; i<n; i++)
	{
	  for(j=i+1; j<n; j++)
	  {
	    if (a[i]>a[j])
	    {
	    	t= a[i];
	    	a[i]= a[j];
	    	a[j]= t;
	    }
	  }
	}
	printf("The sorted array is: ");
	for(i=0; i<n; i++)
	{
          printf("%d  ", a[i]);
	}
	printf("\n");
	return 0;
}
