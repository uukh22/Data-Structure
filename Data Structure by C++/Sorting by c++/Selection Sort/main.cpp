//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a=b;
    b=temp;
}

void selection_sort(int arr[], int sizeofarr)
{
    int minimum;
    for(int i = 0 ; i < sizeofarr-1 ; i++)
    {
        minimum = i;
        for(int j = i + 1 ; j < sizeofarr ; j++)
        {
            if(arr[j]<arr[minimum])
            {
                minimum = j;
            }
            Swap(arr[minimum], arr[i]);
        }
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
    selection_sort(arr,sizeofarr);

    for(int i=0 ; i< sizeofarr ; i++)cout<<arr[i]<<' ';

    return 0;
}
//khaled ibrahem
