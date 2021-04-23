#include <iostream>
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


int main()
{
    cout << "Binary Search" << endl;
    int arr[] = {3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47,
                48, 50};
    int arrSize = sizeof(arr) / sizeof(*arr);
    int searchedValue = 16;
    int i = BinarySearch(arr, 0, arrSize - 1, searchedValue);
 
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