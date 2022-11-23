#include<iostream>
using namespace std;

long long unsigned int fib(int n)
{
    if(n<=1) return n;
    int a=0, b=1, c;
    while(n>1){
        c = a+b;
        a = b;
        b = c;
        n--;
    }
    return c;

}

int main()
{
    int n;
    cout<<"enter n for finding nth fibonacci number : ";
    cin>>n;
    cout<<fib(n);
}
