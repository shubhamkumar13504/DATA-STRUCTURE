#include <stdio.h>
int main()
{
    int arr[50], size; //size
    printf("give the size: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("enter values at position %d :  ", i + 1);
        scanf("%d", (arr + i)); // ( arr+i / &arr[i] )
    }
    // Traversing
    for (int i = 0; i < size; i++)
    
    {
        printf("values are: %d \n", arr[i]);
    }
    
}
