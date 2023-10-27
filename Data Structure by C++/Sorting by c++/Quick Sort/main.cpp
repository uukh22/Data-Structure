//#include<bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

int P(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j)
    {

        if (arr[j] <= pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    return i + 1;
}


void Quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivo = P(arr, low, high);
        Quick_sort(arr, low, pivo - 1);
        Quick_sort(arr, pivo + 1, high);
    }
}

int main()
{
    int sizeofarr;
    cout <<"Enter size of array : \n";
    cin>>sizeofarr;
    //int arr[sizeofarr];
    int arr[100];

    for (int i=0 ; i < sizeofarr ; i++)
    {
        cout <<"Enter "<<i+1<<" element in array : \n";
        cin>>arr[i];
    }

    Quick_sort(arr,0,sizeofarr-1);

    for(int i=0; i<sizeofarr; i++) cout<<arr[i]<<' ';

    return 0;
}
//khaled ibrahem