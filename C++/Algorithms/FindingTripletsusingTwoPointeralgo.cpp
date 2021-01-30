// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h> 
using namespace std; 

bool sumofnum(int a[],int x,int i,int n);

bool triplets(int a[],int n,int sum)
{
            sort(a,a+n);

    for(int i=0;i<n-2;i++)
    {
        if(sumofnum(a,-a[i],i+1,n))
        {
            return true;
        }
    }
    return false;
}

bool sumofnum(int a[],int x,int i,int n)
{
    int j=n-1;;
    while(i<j){
        if(a[i]+a[j]>x)
        j--;
        else if(a[i]+a[j]<x)
        i++;
        else
        return true;
        
    }
    return false;
}

int main() {
    // Write C++ code here
        int arr[] = {-5, 1, 3, 4, 7}; 
        int n = sizeof arr / sizeof arr[0]; 
        int sum=12;
        cout<<triplets(arr,n,sum);

    return 0;
}