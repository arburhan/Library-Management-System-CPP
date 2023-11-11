// In the name of Allah, the most gracious, the most merciful
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int left = 0, right = size - 1, loc = 0;
    for (int i = right; i > left; i--)
    {
        while (arr[loc] <= arr[right])
        {
            right = right - 1;
        }
        if (loc == right)
            continue;
        if (arr[loc] > arr[right])
        {
            int temp = arr[loc];
            arr[loc] = arr[right];
            arr[right] = temp;
        }
    }
    for (int i = left; i < right; i++)
    {
        while (arr[left] <= arr[loc])
        {
            left += 1;
        }
        if (arr[left] > arr[loc])
            continue;
        if (arr[left] > arr[loc])
        {
            int temp = arr[loc];
            arr[loc] = arr[left];
            arr[left] = temp;
        }
    }

    cout << "sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}