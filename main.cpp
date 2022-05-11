#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
#include <list>
#include <math.h>
#include<bits/stdc++.h>
#include <C:\Users\vladu\My Drive\Teme\LFTA\generare fisier\gen_file.h>
using namespace std;
void printare(int x[],int n);
void insert_s(int x[],int n);
void select(int x[],int n);
void heap_s(int x[],int n);
void heapify(int x[], int n,int i);
void bubble(int x[],int n);
void merge_s(int x[],int n,int st, int dr);
void merge_2(int x[],int n,int st, int dr);
void quick(int x[],int n,int st, int dr);
int quick_2(int x[],int n,int st, int dr);
void radix(int x[], int n,const int mx=3);
void timSort(int arr[],int n);
void merge(int arr[], int l, int m, int r);
void insertionSort(int arr[], int left, int right);
void verif(int x[],int n);
void InsertionSort(int arr[], int *begin, int *end);
void Introsort(int arr[], int *begin, int *end);
void IntrosortUtil(int arr[], int * begin,int * end, int depthLimit);
int *MedianOfThree(int * a, int * b, int * c);
int* Partition(int arr[], int low, int high);
void swapValue(int *a, int *b);


int main()
{
    int p=1;
    long int n=10;
    char *s;
    s=(char*)calloc(25,sizeof(char));
    for(; p<=6; p++,n*=10)
    {
        s=generare(p);
        ofstream fout("rezulate_merge.txt",fstream::app);
        cout<<p;
        for(int i=10; i>0; i--)
        {
            if(p==6)
                i=1;
            ifstream fin(s);
            int*x;
            x=(int *)calloc(n,sizeof(int));
            for(int i=0; i<n; i++)
                fin>>x[i];
            auto start = chrono::steady_clock::now();
          //verif(x,n);
            //insert_s(x,n);
            //select(x,n);
            //heap_s(x,n);
            //bubble(x,n);
            merge_s(x,n,0,n-1);
            //quick(x,n,0,n-1);
            //radix(x,n,3);
            //Introsort(x, x, x+n-1);
            //timSort(x,n);
            //printare(x,n);
            //verif(x,n);
            auto end = chrono::steady_clock::now();

            fout << chrono::duration_cast<chrono::microseconds>(end - start).count()<< ",";
            free(x);
            fin.close();
        }
        fout<<'\n';
    }
    return 0;
}
void verif(int x[],int n)
{
    int ok=1;
    for(int i=0; i<n-1; i++)
        if(x[i]>x[i+1])
            ok=0;
    if(ok)
        cout<<"este ordonat";
    else
        cout<<"nu este ordonat";
    cout<<endl;
}



void printare(int x[],int n)
{
    // system("Cls");
    for(int i=0; i<n; i++)
        cout<<x[i]<<' ';
    cout<<'\n';
    // system("Pause");
}
//bubble sort
void bubble(int x[],int n)
{
    int t,m,aux;
    t=n-1;
    while(t)
    {
        m=t;
        t=0;
        for(int i=0; i<m; i++)
            if(x[i]>x[i+1])
            {
                swap(x[i],x[i+1]);
                t=i;
            }
    }
}
//heap sort
void heap_s(int x[],int n)
{
    for (int i = n / 2 -1; i >= 0; i--)
        heapify(x, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(x[0], x[i]);
        heapify(x, i, 0);
    }
}
void heapify(int x[], int n,int i)
{
    int mx,c1,c2,aux;
    c1=i*2+1;
    c2=c1+1;
    mx=i;
    if(c1<n&&x[c1]>x[mx])
        mx=c1;
    if(c2<n&&x[c2]>x[mx])
        mx=c2;

    if(i!=mx)
    {
        swap(x[i],x[mx]);
        heapify(x,n,mx);
    }
}
//select sort
void select(int x[],int n)
{
    int aux,k;
    for(int i=0; i<n-1; i++)
    {
        k=i;
        for(int j=i+1; j<n; j++)
            if(x[k]>x[j])
                k=j;
        if(k!=i)
        {
            swap(x[i],x[k]);
        }
    }
}
//insert sort
void insert_s(int x[],int n)
{
    int aux,j;
    for(int i=1; i<n; i++)
    {
        aux=x[i];
        j=i-1;
        while(j>=0&&aux<x[j])
        {
            x[j+1]=x[j];
            j--;
        }
        x[j+1]=aux;
    }
}
//merge sort
void merge_s(int x[],int n,int st, int dr)
{
    int mij,i,j;
    if(st<dr)
    {
        mij=(st+dr)/2;
        merge_s(x,n,st,mij);
        merge_s(x,n,mij+1,dr);
        merge_2(x,n,st,dr);
    }
}
void merge_2(int x[],int n,int st, int dr)
{
    int i,j,k,*a,mij;
    a=(int*)calloc(n,sizeof(int));
    i=st;
    mij=(st+dr)/2;
    k=0;
    j=mij+1;
    while(i<=mij&&j<=dr)
    {
        if(x[i]<x[j])
            a[k++]=x[i++];
        else
            a[k++]=x[j++];
    }
    while(i<=mij)
        a[k++]=x[i++];
    while(j<=dr)
        a[k++]=x[j++];
    for(int i=st; i<=dr; i++)
        x[i]=a[i-st];
        free(a);
}
//quicksort
void quick(int x[],int n,int st, int dr)
{
    int q;
    if(st<dr)
    {
        q=quick_2(x,n,st,dr);
        quick(x,n,st,q-1);
        quick(x,n,q+1,dr);
    }
}
int quick_2(int x[],int n,int st, int dr)
{
    int v, i,j;
    v=x[dr];
    i=st-1;
    j=dr;
    while(i<j)
    {
        i++;
        while(!(x[i]>=v))
            i++;
        j--;
        while(!(x[j]<=v))
            j--;
        if(i<j)
            swap(x[i],x[j]);
    }
    swap(x[i],x[dr]);
    return i;
}
//radix sort
void radix(int x[], int n,int mx)
{
    int i, j, m, p = 1, index, temp, count = 0;
    list<int> pocket[10];
    for(i = 0; i< mx; i++)
    {
        m = pow(10, i+1);
        p = pow(10, i);
        for(j = 0; j<n; j++)
        {
            temp = x[j]%m;
            index = temp/p;
            pocket[index].push_back(x[j]);
        }
        count = 0;
        for(j = 0; j<10; j++)
        {
            while(!pocket[j].empty())
            {
                x[count] = *(pocket[j].begin());
                pocket[j].erase(pocket[j].begin());
                count++;
            }
        }
    }
}
//tim sort
const int RUN = 32;
void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
void merge(int arr[], int l, int m, int r)
{
    int len1 = m - l + 1, len2 = r - m;
    int *left, *right;
    left=(int*)calloc(len1,sizeof(int));
    right=(int*)calloc(len2,sizeof(int));
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}
void timSort(int arr[], int n)
{
    for (int i = 0; i < n; i+=RUN)
        insertionSort(arr, i, min((i+RUN-1),(n-1)));
    for (int size = RUN; size < n;size = 2*size)
    {
        for (int left = 0; left < n;left += 2*size)
        {
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),(n-1));
            if(mid < right)
                merge(arr, left, mid, right);
        }
    }
}
//intro sort
void swapValue(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
    return;
}
void InsertionSort(int arr[], int *begin, int *end)
{
    int left = begin - arr;
    int right = end - arr;

    for (int i = left+1; i <= right; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j >= left && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}
int* Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {            i++;

            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (arr + i + 1);
}

int *MedianOfThree(int * a, int * b, int * c)
{
    if (*a < *b && *b < *c)
        return (b);

    if (*a < *c && *c <= *b)
        return (c);

    if (*b <= *a && *a < *c)
        return (a);

    if (*b < *c && *c <= *a)
        return (c);

    if (*c <= *a && *a < *b)
        return (a);

    if (*c <= *b && *b <= *a)
        return (b);
}
void IntrosortUtil(int arr[], int * begin,
                   int * end, int depthLimit)
{
    int size = end - begin;
    if (size < 16)
    {
        InsertionSort(arr, begin, end);
    }
    if (depthLimit == 0)
    {
        make_heap(begin, end+1);
        sort_heap(begin, end+1);
    }
    int * pivot = MedianOfThree(begin, begin+size/2, end);
    swapValue(pivot, end);
    int * partitionPoint = Partition(arr, begin-arr, end-arr);
    IntrosortUtil(arr, begin, partitionPoint-1, depthLimit - 1);
    IntrosortUtil(arr, partitionPoint + 1, end, depthLimit - 1);
}

void Introsort(int arr[], int *begin, int *end)
{
    int depthLimit = 2 * log(end-begin);
    IntrosortUtil(arr, begin, end, depthLimit);
}
