//0 Based Indexing

#include<cstdio>
#include<iostream>
#include<cassert>
#include<cmath>
#include<cstring>
using namespace std;

#define MAXN 50
#define MAX

int mid(int i,int j)
{
    assert(i>=0);
    assert(j>=0);
    assert(i<=j);
    return (i+j)/2;
}

void print(int a[], int n)
{
    int i;
    cout<<"---------------------------------------------------------------------------\n";
    for(i=0;i<n;i++)
        cout<<i<<"\t";
    cout<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;\
}
int n;
void QuickSort(int a[], int low, int high)
{

    if(low>=high)
        return;
    int left=low, right= high,pivot = a[mid(low,high)];

    while(left<=right)
    {
        while(a[left]<pivot)
            left++;
        while(a[right]>pivot)
            right--;

        if(left <= right)
        {
            swap(a[left],a[right]);
            left++;
            right--;
        }
        print(a,n);

    }
    QuickSort(a,low,right);
    QuickSort(a,left,high);

}

int main()
{
    int i,j;

    cout<<"Enter max number of elements : ";
    cin>>n;
    cout<<"Enter "<<n<<" numbers\n";
    assert(n<MAXN);

    int *a = new int[n+1];
    for(i=0;i<n;i++)cin>>a[i];
    cout<<"---------------------------------------------------------------------------\n";
    for(i=0;i<n;i++)
        cout<<i<<"\t";
    cout<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;\
    cout<<"-----------------------------------------------------------------------------\n";
    cout<<"---------------------Sorting begins------------------------------------------\n";
    QuickSort(a,0,n-1);
    cout<<"---------------------Sorting ends------------------------------------------\n";

    cout<<"---------------------------------------------------------------------------\n";
    for(i=0;i<n;i++)
        cout<<i<<"\t";
    cout<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;


    return 0;
}
