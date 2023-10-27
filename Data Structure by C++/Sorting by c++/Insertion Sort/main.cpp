//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int sizeofarr,key, j;
    cout <<"Enter size of array : \n";
    cin>>sizeofarr;
    //int arr[sizeofarr];
    int arr[100];

    for (int i=0 ; i < sizeofarr ; i++)
    {
        cout <<"Enter "<<i+1<<" element in array : \n";
        cin>>arr[i];
    }
    for (int i = 1; i < sizeofarr; i++)
    {
        key = arr[i];
        j=i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < sizeofarr; i++)cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}
//khaled ibrahem