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
    // Insertion
    int pos, value;
    printf("Enter the positon : ");
    scanf("%d", &pos);
    printf("Enter the value : ");
    scanf("%d", &value);
    if (pos <= 0 || pos > size + 1)
    {
        printf("Invalid");
    }
    else
    {
        for (int i = size; i >= pos - 1; i--)
        {
            arr[i + 1] = arr[i];
            
        }
        arr[pos - 1] = value;
        size++;
        for (int i = 0; i < size; i++)
        {
            printf("values are: %d \n", *(arr + i));
        }
    }
    
}
