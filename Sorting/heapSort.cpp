#include <iostream>

using namespace std;

void heapify(int *arr, int n, int i)
{
    int largest = i;

    int left = i*2+1;
    int right = i*2+2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }

}

void heapSort(int *arr, int n)
{

    // BUild heap
    for(int i = n/2-1; i >=0; i--)
    {
        heapify(arr, n, i);
    }

    //Heapify to sort
    for(int i = n-1; i >=0; i--)
    {
        swap(arr[i], arr[0]); // Move the max heap root(max) to end 
        heapify(arr,i, 0); // Heapify the array from start to the one less than alreay found largest element
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

    heapSort(arr, n);

    for(int i =0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}