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

void init(int Node,int low,int high,int st[],int a[])
{
    if(low==high)
    {
        st[Node]=low;
        //cout<<"Node : "<<Node<<"Low : "<<low<<" High : "<<high<<" Ans : "<<st[Node]<<endl;
    }
    else
    {
        init(2*Node,low,mid(low,high),st,a);
        init(2*Node+1,mid(low,high)+1,high,st,a);
        if(a[st[2*Node]]<=a[st[2*Node+1]])st[Node]=st[2*Node];
        else st[Node]=st[2*Node+1];
        //cout<<"Node : "<<Node<<"Low : "<<low<<" High : "<<high<<" Ans : "<<st[Node]<<endl;
    }
}

int query(int Node,int low,int high,int st[],int a[],int i,int j)
{
    assert(i<=j);
    cout<<"Call Node : "<<Node<<" Low High "<<low<<" "<<high<<endl;
    //if(low==high)return st
    if(i>high || j<low){
            //cout<<"Node : "<<Node<<" i j : "<<i<<" "<<j<<"low high : "<<low<<" "<<high<<" Returning -1"<<endl;
            return -1;
    }
    if(i<=low && j>=high )
    {
        //cout<<"Low : "<<low<<" High : "<<high<<" Ans : "<<st[Node]<<endl;
        //cout<<"Node : "<<Node<<" i j : "<<i<<" "<<j<<"low high : "<<low<<" "<<high<<" Ans "<<st[Node]<<endl;
        return st[Node];
    }
    int p1,p2;

    p1=query(2*Node,low,mid(low,high),st,a,i,j);
    p2=query(2*Node+1,mid(low,high)+1,high,st,a,i,j);

    //return the position where the overall minimum is
    if (p1 == -1)
        st[Node] = p2;
    if (p2 == -1)
        st[Node] = p1;
    if (a[p1] <= a[p2])
        st[Node] = p1;
    else st[Node] = p2;
    //cout<<"Low : "<<low<<" High : "<<high<<" Ans : "<<st[Node]<<endl;
    cout<<"Node : "<<Node<<" i j : "<<i<<" "<<j<<"low high : "<<low<<" "<<high<<" Ans "<<st[Node]<<endl;
    return st[Node];

}

int main()
{
    int x = (int)(ceil(log2(MAXN))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *st = new int[max_size];

    int n,i,j;

    cout<<"Enter max number of elements : ";
    cin>>n;
    cout<<"Enter "<<n<<" numbers\n";
    assert(n<MAXN);
    int *a = new int[n+1];
    for(i=0;i<n;i++)cin>>a[i];
    memset(st,0,max_size*sizeof(int));
    init(1,0,n-1,st,a);
    cout<<"-----------------------------------------------------------------------------\n";
    //Test code
    for(int k=0;k<=5;k++)
    {
        cin>>i>>j;
        int index = query(1,0,n-1,st,a,i,j);
        cout<<index<<" : "<<a[index];
    }

    return 0;
}
