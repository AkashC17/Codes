#include<iostream>
using namespace std;

long long unsigned int fib(int n)
{
    if(n<=1)
        return n;
    else
        return fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    cout<<"enter n for finding nth fibonacci number : ";
    cin>>n;
    cout<<fib(n);
}

