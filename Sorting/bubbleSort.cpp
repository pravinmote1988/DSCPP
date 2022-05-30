#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n]; // This works with gcc only using the compiler extension
    for(int i =0; i < n; i++)
    {
        cin >> arr[i];
    }

    int counter = n-1;
    while(counter >=0)
    {
        for(int i=0; i < counter; i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
            }
        }
        counter--;
    }

    for(int i =0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}