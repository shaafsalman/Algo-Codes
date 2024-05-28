#include<iostream>
using namespace std;

void Conquer(int arr[],int si,int mid,int ei)
{
    int merged[]=new int [si];
    int idx1=si;
    int idx2=mid+1;
    int x=0;
     
    while(idx1<=mid && idx2<=ei)
    {
        if(arr[idx1]<=arr[idx2])
        {
            merged[x++]=arr[idx1++];
        }
        else
        {
            merged[x++]=arr[idx2++];
        }
        while(idx1<=mid)
        {
            merged[x++]=arr[idx1++];
        }
        while(idx2<=ei)
        {
            
        }
    }



}
void Divide(int arr[],int si,int ei)
{
    if(si>=ei)
    {
        return;
    }
    int mid = si+(ei-si)/2;
    Divide(arr,si,mid);
    Divide (arr,mid+1,ei);
    Conquer(arr,si,mid,ei);

}


int main()
{
    int arr[10]={1,10,2,6,8,55,4,32,2};


    return 0;
}