#include<iostream>
using namespace std;

void swap (int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int *arr,int *arr2 ,int l, int m, int r) 
{ 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    int L[n1], R[n2];
    int X[n1], Y[n2]; 
  
    for(int i = 0; i < n1; i++)
    { 
        L[i] = arr[l + i];
        X[i] = arr2[l+1];
    } 
    for(int j = 0; j < n2; j++) 
    {
        R[j] = arr[m + 1 + j];
        Y[j] = arr2[m + 1 + j];
    }  
    int i = 0;  

    int j = 0;  

    int k = l; 
      
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j])  
        { 
            arr[k] = L[i];
            arr2[k] = X[i]; 
            i++; 
        } 
        else 
        { 
            arr[k] = R[j];
            arr2[k] = Y[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1)  
    { 
        arr[k] = L[i];
        arr2[k] = X[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) 
    { 
        arr[k] = R[j];
        arr2[k] = Y[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int *arr, int* arr2, int l, int r) 
{ 
    if (l < r) 
    { 
          
        int m = l + (r - l) / 2; 

        mergeSort(arr,arr2, l, m); 
        mergeSort(arr,arr2, m + 1, r); 
  
        merge(arr,arr2, l, m, r); 
    } 
} 

int main()
{
    cout<<"Enter 'n' :"<<endl;
    int n ;
    cin>>n;
    int *start = new int [n];
    int *end = new int [n];
    int s,e;
    int f =n;
    for (int i=0;i<n;i++)
    {
        cin>>s>>e;
        if(s>=0 && e <= 24)
        {
            start[i] = s;
            end[i] = e;
        }
        else {
            f--;
        }
    }
    mergeSort(end,start,0,f-1);

    int time = end[0];
    int i, ans;
    i =1; 
    if(n>0){
        ans = 1;
        while(time<=24&&i<f)
        {
            if(start[i]>=time && i<f)
            {
                ans++;
                time = end[i];
            }
            i++;
        }
        cout<<ans;
    }
    else cout<<0;
    return 0;

}



























