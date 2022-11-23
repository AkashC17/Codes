#include<iostream>
#include<cmath>
using namespace std;
int comp = 0;

void swapp(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int arr[], int low, int high)
{
    comp++;
    if(low < high){
        int i = low-1;
        int pivot = arr[high];
        comp++;
        for(int j=low; j<high; j++)
        {
            comp += 2;
            if(pivot > arr[j])
            {
                i++;
                swapp(&arr[i], &arr[j]);
            }
        }
        swapp(&arr[i+1], &arr[high]);
        quicksort(arr, low, i);
        quicksort(arr, i+2, high);
    }
}

int main()
{
    int arr[10];
    for(int i=0; i<10; i++)
        cin>>arr[i];
    quicksort(arr, 0, 9);
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    if(comp == 10*log2((double)10))
        cout<<"Best case";
    else if(comp == 100)
        cout<<"Worst case";
    else
        cout<<"Average case";
}
