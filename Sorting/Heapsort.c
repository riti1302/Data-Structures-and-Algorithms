#include<stdio.h>

void Build_max_heap(int *Array, int size);
void Heapify(int *Array, int start, int end);
void swap(int *i, int *j);

int main()
{
	int array[50], size, i, sorted_array[50];
	printf("Enter the size of the array: ");
	scanf("%d", &size);
    
  printf("Enter the elements in the array:\n");
	for(i = 0; i < size; i++)
		scanf("%d",&array[i]);

  int n = size; 
  for(i = 0; i < n; i++)
   {
   	  Build_max_heap(array, size);       
      swap(&array[0], &array[size-1]);              // Swapping the first element to the last element in the array
      sorted_array[i] = array[size-1];  
      size--;                                    // Removing the last element from the array 
   }

   for(i = 0; i < n ; i++)
     printf("%d ", sorted_array[i]);
	return 0;
}

void Build_max_heap(int *Array, int n)
{
	int end  = n-1;                  // End index of the array
	int start = (end-1)/2;           // Index of the last parent node

	while(start >= 0)
	{
        Heapify(Array, start, end-1);
        start--;
	}
}


void Heapify(int *Array, int start, int end)
{
	 int root = start;

        while((2 * root + 1)  <= (end + 1))       // While the root has atleast one child 
        {
            int child = 2 * root + 1;

            if(child <= end   && Array[child] < Array[child +1] )   //Compares the two child  
            	child = child +1;                                         //Points to the greater child


            if(Array[root] < Array[child])                         // Checks if parent is greater than the greater child
            {
                swap(&Array[root], &Array[child]);                             // Swaps the  parent node with the greater child

                root = child;                                       // Checks the same for its children
            }      

            else 
              return;                       
        }
}


void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

