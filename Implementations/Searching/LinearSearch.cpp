#include <iostream>
using namespace std;

int LinearSearch(int arr[], int startIndex, int endIndex, int val)
{
    for (int i = startIndex; i < endIndex; i++)
        if(arr[i] == val)
            return i;
            
        return -1;
}



int main()
{
    cout << "Linear Search" << endl;
    int arr[] = {43, 21, 26, 38, 17, 30, 25, 18};
    int arrSize = sizeof(arr) / sizeof(*arr);
    int searchedValue = 30;
    int i = LinearSearch(arr, 0, arrSize - 1, searchedValue);

    if (i != -1)
    {
        cout << searchedValue << " is found in index ";
        cout << i << endl;
    }
    else
    {
        cout << "Could not find value " << searchedValue;
        cout << endl;
    }
    return 0;
}