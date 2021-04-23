#include <iostream>
using namespace std;

int TernarySearch(int arr[], int startIndex, int endIndex, int val)
{

    if(startIndex <= endIndex)
    {
        int middleLeftIndex = startIndex + (endIndex - startIndex) / 3;
        int middleRightIndex = middleLeftIndex + (endIndex - startIndex) / 3;

        if(arr[middleLeftIndex] == val)
            return middleLeftIndex;
        
        else if(arr[middleRightIndex] == val)
            return middleRightIndex;

        else if(arr[middleLeftIndex] > val)
            return TernarySearch(arr, startIndex, middleLeftIndex - 1, val);
        
        else if(arr[middleRightIndex] < val)
            return TernarySearch(arr, middleRightIndex + 1, endIndex, val);
        
        else
            return TernarySearch(arr, middleLeftIndex + 1, middleRightIndex - 1, val);

        return -1;
    }
                
}




int main()
{
    cout << "Ternary Search" << endl;
    // Initialize a new array
    int arr[] = {3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47,
                 48, 50};
    int arrSize = sizeof(arr)/sizeof(*arr);
    int searchedValue = 16;
    int i = TernarySearch(arr, 0, arrSize - 1, searchedValue);

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