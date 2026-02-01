#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int i = low, j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int left = low; left <= high; left++)
    {
        arr[left] = temp[left - low];
    }
}

void mergesort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    vector<int> arr = {1, 5, 4, 3, 7, 8, 2, 1};
    int n = arr.size();
    mergesort(arr, 0, arr.size() - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}