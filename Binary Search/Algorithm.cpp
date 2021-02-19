// C++ program to implement recursive Binary Search 
#include <bits/stdc++.h> 
using namespace std; 
  
int binarySearch(int arr[], int l, int r, int x) 
{
    while (l <= r) { 
        int m = l + (r - l) / 2; 

        // Element found at mid
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
} 

int main(void) 
{ 
    int arr[] = {93, 81, 50, 60, 46, 5, 55, 87, 27, 90, 70, 64, 26, 67, 23}; 
    int x = 10; 
    int n = sizeof(arr) / sizeof(arr[0]); // 5
    int result = binarySearch(arr, 0, n - 1, x); 

    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result; 
    return 0; 
} 
