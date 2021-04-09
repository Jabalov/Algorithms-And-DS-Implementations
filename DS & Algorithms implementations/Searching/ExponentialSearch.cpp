#include <iostream>
#include <math.h>
using namespace std;

int BinarySearch(int arr[], int startIndex, int endIndex, int val)
{
    if(startIndex <= endIndex)
    {
        int middleIndex = startIndex + (endIndex - startIndex) / 2;

        if (arr[middleIndex] == val)
            return middleIndex;
        
        else if (arr[middleIndex] > val)
            return BinarySearch(arr, startIndex, middleIndex - 1, val);

        else
            return BinarySearch(arr, middleIndex + 1, endIndex, val);

        return -1;
    }
}

int ExponentialSearch(int arr[], int arrSize, int val)
{
    if(arrSize <= 0)
        return -1;

    int blockIndex = 1;

    while(blockIndex < arrSize && arr[blockIndex] < val)
        blockIndex *= 2;

    return BinarySearch(arr, blockIndex / 2 , min(blockIndex, arrSize), val);
}

int main()
{
    cout << "Exponential Search" << endl;
    int arr[] = {8, 15, 23, 28, 32, 39, 42, 44, 47, 48};
    int arrSize = sizeof(arr)/sizeof(*arr);
    int searchedValue = 39;
    int i = ExponentialSearch(arr, arrSize, searchedValue);

    if(i != -1)
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