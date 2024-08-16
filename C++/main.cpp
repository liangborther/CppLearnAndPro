#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int x = 10;
    const int *p = &x;
    int t = 10;
    const int *p2 = &t;
    const int *const p3;
    p = p2;
    x = 20;
    cout<< *p<<endl;
}
int calPoints(vector<string>& operations) {
    string s[1005];
    int i = 0;
    for(auto temp = operations.begin(); temp !=operations.end() ; temp++)
    {
        if(*temp == "+")
        {
            s[i] = s[i-1] + s[i-2];
            i++;
        }
        
    }
}