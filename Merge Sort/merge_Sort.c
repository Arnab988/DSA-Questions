#include <stdio.h>

void merge(int arr[], int s, int mid, int e)
{
    int i, j, main_index;
    int n1 = mid - s + 1;
    int n2 = e - mid;

    // Create temporary arrays
    int s_half[n1], e_half[n2];

    // Copy data to temporary arrays s_half[] and e_half[]
    for (i = 0; i < n1; i++)
        s_half[i] = arr[s + i];
    for (j = 0; j < n2; j++)
        e_half[j] = arr[mid + 1 + j];

    // Merge the temporary arrays bac into arr[s...e]
    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    main_index = s; // Initial index of merged sub-array

    while (i < n1 && j < n2)
    {
        if (s_half[i] <= e_half[j])
        {
            arr[main_index] = s_half[i];
            i++;
        }
        else
        {
            arr[main_index] = e_half[j];
            j++;
        }
        main_index++;
    }

    // Copy the remaining elements of s_half[], if there are any
    while (i < n1)
    {
        arr[main_index] = s_half[i];
        i++;
        main_index++;
    }

    // Copy the remaining elements of e_half[], if there are any
    while (j < n2)
    {
        arr[main_index] = e_half[j];
        j++;
        main_index++;
    }
}

void merge_sort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }

    // Same as (s+e)/2, but avoids overflow for large s and e
    int mid = s + (e - s) / 2;

    // Sort first and second halves
    merge_sort(arr, s, mid);
    merge_sort(arr, mid + 1, e);

    // Merge the sorted halves
    merge(arr, s, mid, e);
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    merge_sort(arr, 0, arr_size - 1);

    printf("Sorted array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
