#include <stdio.h>


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
    {
      largest = right;
    }
    
    if (largest != i)
    {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
      heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
      printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
  int n,a[20];
  printf("\nEnter no. of students: ");
  scanf("%d",&n);
  
  for(int i=0;i<n;i++)
  {
    printf("\nEnter marks of student %d: ", i+1);
    scanf("%d",&a[i]);
  }
  
  heapSort(a,n);
  printf("\nThe Sorted Array Is:\n");
  printArray(a,n);
  return 0;
}

