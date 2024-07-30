#include <vector>
#include <iostream>
using namespace std;
int main()
{
    
}
int calPoints(vector<string>& operations) {
    string s[1005]="";
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