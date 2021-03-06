int search(int arr[], int N, int X) 
{    
    // Pointer to traverse the array
    int i; 

    // Start traversing the array
    for (i = 0; i < N; i++) 
    {   
        // If a successful match is found,
        // return the index
        if (arr[i] == X) 
            return i; 
    }

    // If the element is not found,
    // and end of array is reached
    return -1; 
} 
