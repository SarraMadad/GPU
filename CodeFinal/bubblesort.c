#include<stdio.h>

// Fonction d'échange
void swap(int *x, int *y)
{
      int temp = *x;
      *x = *y;
      *y = temp;
}

// fonction pour trier
void bubbleSort(int arr[], int size)
{
      int i,j;
      
      for(i = 0; i < size; i++)
      {
            for(j = 0; j < size-i-1; j++)
            {
                  if(arr[j] > arr[j+1])
                        swap(&arr[j], &arr[j+1]);
            }
      }
}

// Fonction pour afficher le tableau
void Array(int arr[], int size)
{
      int i;
      
      for(i = 0; i < size ; i++)
      {
              printf("%d",arr[i]);
      }
}      
          
int main()
{      
      int arr[] = {4,2,5,1,8,0,3,9,7,6};
      
      int n = sizeof(arr)/sizeof(arr[0]);
      
      bubbleSort(arr,n);
      printf("Tableau trié :\n");
      Array(arr,n);
      
      return 0;
}
       
  
