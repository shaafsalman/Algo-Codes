#include<iostream>
using namespace std;

void Conquer(int arr[],int si,int mid,int ei)
{

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
    Conquer(arr,si,mid,ei)

}


int main()
{
    int arr[10]={1,10,2,6,8,55,4,32,2};


    return 0;
}