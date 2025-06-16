#include <stdio.h>
int main()
{
    int arr[50], size; 
    printf("give the size: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("enter values at position %d :  ", i + 1);
        scanf("%d", (arr + i)); // ( arr+i / &arr[i] )
    }
    // DELETION
    int pos;
    printf("Enter the positon : ");
    scanf("%d", &pos);
    
    if (pos <= 0 || pos > size + 1)
    {
        printf("Invalid!!");
    }
    else
    {
        for (int i = pos-1; i <size - 1; i++)
        {
            arr[i ] = arr[i+1];
            
        }
        // arr[pos - 1] = value;
        size--;
        for (int i = 0; i < size; i++)
        {
            printf("values are: %d \n", *(arr + i));
        }
    }
    
}
