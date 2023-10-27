//#include<bits/stdc++.h>
#include <iostream>

using namespace std;

void merge_s(int arr[],int left,int mid,int right)
{
    int i,j,k;
    int sizeofarr1=mid-left+1;
    int sizeofarr2=right-mid;

    int arr1[sizeofarr1], arr2 [sizeofarr2];

    for(int i=0; i<sizeofarr1; i++) arr1[i]=arr[left+i];
    for(int j=0; j<sizeofarr2; j++) arr2[j]=arr[mid+1+j];

    i=j=0;
    k=left;

    while(i<sizeofarr1&&j<sizeofarr2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k]=arr1[i];
            i++;
        }
        else
        {
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }

    while(i<sizeofarr1)
    {
        arr[k]=arr1[i];
        i++;
        k++;
    }


    while(j<sizeofarr2)
    {
        arr[k]=arr2[j];
        j++;
        k++;
    }
}

void Merge_sort(int arr[],int left,int right)
{
    if(left<right)
    {
        int mid=left+(right-left)/2;
        Merge_sort(arr,left,mid);
        Merge_sort(arr,mid+1,right);
        merge_s(arr,left,mid,right);
    }
}
void print(int arr[],int sizeofarr)
{
    for(int i=0; i<sizeofarr; i++)cout<<arr[i]<<' ';
    cout<<'\n';
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

    Merge_sort(arr,0,sizeofarr-1);
    print(arr,sizeofarr);

    return 0;
}
//khaled ibrahem