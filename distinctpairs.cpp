/*A sorting based program to count pairs with differnce K*/

#include <iostream>
#include <algorithm>
using namespace std;

/* Standard binary search function (recursive) */
int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low)
    {
        int mid = low + (high - low)/2;
        if (x == arr[mid])
            return mid;
        if (x > arr[mid])
            return binarySearch(arr, (mid + 1), high, x);
        else
            return binarySearch(arr, low, (mid -1), x);
    }
    return -1;
}

/* Returns count of pairs with difference k in arr[] of size n. */
int countPairsWithDiffK(int arr[], int n, int k)
{
    int dupArr[n];	//array holding the duplicates
    int count = 0, i;
    sort(arr, arr+n);	// Sort array elements from algorith library

    /* code to remove duplicates from arr[] */
    int index = 0;
    for(i=0; i<n-1;i++)
    {
        int pos = binarySearch(arr,i+1,n-1,arr[i]);
        if(pos!=-1)
        {
            dupArr[index++] = pos;
        }
    }

    // Pick a first element point
    index = 0;
    for (i = 0; i < n-1; i++)
    {
        if(i!=dupArr[index])
        {
            if (binarySearch(arr, i+1, n-1, arr[i] + k) != -1)
                count++;
        }
        else
            index++;
    }

    return count;
}

// Driver program
int main()
{
    int arr[] = {1, 1, 5, 3, 4 ,4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << "Count of pairs with given diff is "
        << countPairsWithDiffK(arr, n, k);
    return 0;
}
