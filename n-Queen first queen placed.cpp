#include<iostream>
using namespace std;

int n;
int **arr;
bool nQueen(int, int);

bool isSafe(int x, int y)
{
    int i, j;

    i=x; j=y;
    while(i>=0){
        if(arr[i][j]==1) return false;
        i--;
    }

    i=x; j=y;
    while(i>=0 && j>=0){
        if(arr[i][j]==1) return false;
        i--; j--;
    }

    i=x; j=y;
    while(i>=0 && j<n){
        if(arr[i][j]==1) return false;
        i--; j++;
    }

    return true;
}

bool nQueen(int x)
{
    if(x>=n) return true;
    int y=0;
    while(y<n){
        if(isSafe(x, y)){
            arr[x][y]=1;
            if(nQueen(x+1)){
                return true;
            }
            arr[x][y]=0;;
        }
        y++;
    }
    return false;
}

int main()
{
    cout<<"Enter the dimension of chess board : ";
    cin>>n;
    int col;
    cout<<"Enter the column number for first row where the first queen is to be placed (index starting from 1) : ";
    cin>>col;

    arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) arr[i][j]=0;
    }
    arr[0][col-1]=1;

    if(nQueen(1)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
