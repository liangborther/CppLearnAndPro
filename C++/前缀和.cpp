#include <iostream>
using namespace std;
int n;
int a[205][205];
int maxans = 0;
int s[205][205];
int count = 0;
int main() {
    s[0][1] = 0;
    s[0][0] = 0;
    s[1][0] = 0;
    cin>>n;
    int size_t = n;
    for(int i=1;i<=size_t;i++)
    {
        string st;
        cin >> st;
        for(int j = 0;j<size_t;j++)
        {
            
            a[i][j+1] = st[j] -'0';
            if(a[i][j+1]==0){
            maxans--;
            }
            else{
            maxans++;
            }
        }
    }
    cout<<"0"<<endl;
    for(int i=1;i<=size_t;i++){
        for(int j=1;j<=size_t;j++){
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }
    for(int le = 2;le<size_t;le++)
    {
        count = 0;
        if((le*le)%2==1){
            cout<<count<<endl;
            continue;
        }
        for(int i = le;i<=size_t;i++){
            for(int j =le;j<=size_t;j++)
            {
                int temp = s[i][j] - s[i-le][j] - s[i][j-le] +s[i-le][j-le];
                if(temp == (le*le) - temp){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    if(maxans == 0){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
}

