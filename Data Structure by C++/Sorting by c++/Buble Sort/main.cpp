#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int sizeofarr,temp,counter=0;
    bool flag = true;
    cin>>sizeofarr;
    //int arr[n];
    int arr[100];

    for(int i=0 ; i < sizeofarr ; i++)cin>>arr[i];
    for(int i=0 ; i < sizeofarr ; i++)
    {
        for(int j=i+1 ; j < sizeofarr ; j++)
        {
            if(arr[i]>arr[j])
            {
                //swap(arr[i],arr[j]);
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                flag = false;
            }
            counter++;
        }
        if(flag)break;
    }
    for(int i=0 ; i < sizeofarr ; i++)cout<<arr[i]<<' ';
    cout<<"Number of round : "<<counter<<'\n';

    return 0;
}
//khaled ibrahem
