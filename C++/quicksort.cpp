#include <iostream>
using namespace std;
void quiksort(int a[], int left, int right)
{
    int l = left;
    int r = right;
    int temp = 0;
    int middle = a[(l + r) / 2];
    while (l < r)
    {
        while (a[l] < middle)
        {
            l++;
        }
        while (a[r] > middle)
        {
            r--;
        }
        if (l >= r)
        {
            break;
        }
        temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        if(a[l] == middle){
            r  -= 1;
        }
        if(a[r] == middle){
            l += 1;
        }
    }
    if(l == r){
        l += 1;
        r -= 1;
    }
    if(l < right){
        quiksort(a,l,right);
    }
    if(r > left){
        quiksort(a,left,r);
    }
}
int main()
{
    int a[7] = {0,7,3,8,6,5,4};
    quiksort(a,0,6);
    for(int i = 0;i <= 6;i++){
        cout<<a[i]<<" ";
    }
}