#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

void compare(vector<float> A, int i, int j)
{
    if (A[i] > A[j])
    {
        swap(A[i],A[j]);
    }
}

void sorting(vector<float> arr, int n)  
{  
    int i,j;
    float key;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        for(j=i-1; j>=0; j--)
        {
            
            if(arr[j]>key)
            {
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        } 
        arr[j + 1] = key;  
    }  
}  

void bucket(float A[], int n)
{
    vector<float> *b;
    b = new vector<float>[n];
    int i;

    for(i=0; i<n; i++)
    {
        int t = n*A[i];
        b[t].push_back(A[i]);
    }

    for(i=0; i<n; i++)
    {
        // if (!(b[i].size() == 0))
        // {
        //     sorting(b[i], b[i].size());
        // }
        sort(b[i].begin(), b[i].end());
    }
    
    int m =0;
    for(i=0; i<n; i++)
    {
        for(int j=0; j<b[i].size(); j++)
        {
            A[m]=b[i][j];
            m++;
        }
        
    }
}

int main(int argc, char* argvp[])
{
    int size =0;
    cin>>size;

    float arr[size];

    for (int i =0; i<size; i++)
    {
        cin>>arr[i];
    }

    bucket(arr, size);

    for (int i =0; i<size; i++)
    {
        cout<<arr[i]<<"\n";
    }

    return 0;
}