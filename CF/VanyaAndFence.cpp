#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <string.h>
#include <assert.h>

using namespace std;

int main()
{
    int num, fence_height;
    cin >> num >> fence_height;

    int width = 0;
    int boy_height;
    
    for (int i = 0; i < num; i++)
        cin >> boy_height,
        width += (boy_height <= fence_height) ? 1 : 2;

    cout << width;
}