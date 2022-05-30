#include <iostream>

using namespace std;

int partition(int *arr, int start, int end)
{
    int pIndex =start; 
    int pivot = arr[end];
    for(int i = start; i < end; i++)
    {
        if(arr[i] <= pivot){
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[end]);
    return pIndex;
}

void quickSort(int *arr, int start, int end)
{
    if(start < end)
    {
        int pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex-1);
        quickSort(arr, pIndex+1, end);
    }

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

    quickSort(arr, 0, n-1);

    for(int i =0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}