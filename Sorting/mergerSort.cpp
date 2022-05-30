#include <iostream>

using namespace std;

void merge(int *array, int* left, int leftCount, int *right, int rightCount)
{
    int i =0, j = 0, k = 0;

    while(i < leftCount && j < rightCount)
    {
        if(left[i] < right[j]) array[k++] = left[i++];
        else array[k++] = right[j++];
    }

    while(i < leftCount) array[k++] = left[i++];
    while(j < rightCount) array[k++] = right[j++];

}

void mergeSort(int *arr, int len)
{
    if(len < 2)
        return;

    int mid = len/2;
    int *left = new int[mid];
    int *right = new int[len-mid];

    for(int i = 0; i <mid; i++) left[i] = arr[i];
    for(int i = mid; i <len; i++) right[i-mid] = arr[i];

    mergeSort(left, mid);
    mergeSort(right, len-mid);

    merge(arr, left, mid, right, len-mid);
    delete left;
    delete right;
}

int main()
{
    int n;
    cin >> n;

    int arr[n]; // This works with gcc only using the compiler extension
    
    for(int i =0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, n);

    for(int i =0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}