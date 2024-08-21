#include <iostream>
using namespace std;
void merger(int arr[], int left, int mid, int right, int temp[])
{
    int i = left;
    int j = mid + 1;
    int t = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            temp[t] = arr[i];
            i++;
            t++;
        }
        else
        {
            temp[t] = arr[j];
            j++;
            t++;
        }
    }
    while (i <= mid)
    {
        temp[t] = arr[i];
        t++;
        i++;
    }
    while (j <= right)
    {
        temp[t] = arr[j];
        t++;
        j++;
    }
    t = 0;
    int leftind = left;
    while (leftind <= right)
    {
        arr[leftind] = temp[t];
        t++;
        leftind++;
    }
}
void mergersort(int arr[], int left, int right, int temp[])
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergersort(arr, left, mid, temp);
        mergersort(arr, mid + 1, right, temp);
        merger(arr, left, mid, right, temp);
    }
}
int main()
{
    int a[7] = {0, 7, 3, 8, 6, 5, 4};
    int temp[7];
    mergersort(a, 0, 6, temp);
    for (int i = 0; i <= 6; i++)
    {
        cout << a[i] << " ";
    }
}