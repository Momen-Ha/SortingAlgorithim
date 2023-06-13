#include <bits/stdc++.h>
#include <stdio.h>
#include <chrono>
#include <sys/time.h>
using namespace std;


void SelectionSort(int a[], long length)
{
int min;
for (int i = 0; i < length - 1;i++)
{
	min=i;
	for (int j= i + 1; j < length;j++)
	  if (a[j]<a[min])
		     min=j;
      swap(a[i],a[min]);
}
}

void BubbleSort(int a[], long length)
{
	for (int i = 1; i < length; i++)
	{
		for (int j = 0; j < length - i; j++)
		{
			if (a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void InsertionSort(int a[], long length) {

  for (int i = 1; i < length; i++) {
    int key = a[i];
    int j = i - 1;

    while (key < a[j] && j >= 0) {
      a[j + 1] = a[j];
      --j;
    }
    a[j + 1] = key;
  }
}

void Merge(int a[], int p, int q, int r)
{
	int B[r];
	int s=p, t=q+1, k=p;
	while(s<=q && t<=r)
	{
		if (a[s]<=a[t] ) 
		{
			B[k]=a[s];
			s=s+1;
		}
		else
		{
			B[k]=a[t];
			t=t+1;
		}
		k=k+1;
	}
	if (s==q+1)
	{
		for (;k<=r;k++)
			B[k]=a[t++]	;	
	}
	else
	{
		for (;k<=r;k++)
			B[k]=a[s++];	
	}
	for (;p<=r;p++)
	{
		a[p]=B[p];
	}
}

void MergeSort(int a[], int low, int high)
{     
	if (low<high)
	{
		int mid=(low+high)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		Merge(a,low,mid, high);
	}
}           

void Split(int a[], int low, long high, int & w) 
{
	int i=low,j;
	long x=a[low];
	for (j=low+1;j<=high;j++)
		if (a[j] <=x)
		{
			i=i+1;
			if (i!= j) 
				swap(a[i], a[j]);
		}
	swap(a[low],a[i]);
	w=i;
}          
void QuickSort (int a[], int low, long high)
{
	int w;
	if (low<high)
	{
		Split (a, low, high, w);
		QuickSort (a,low, w-1);
		QuickSort (a, w+1, high);
	}
}


// To reset the array after being sorted.
void reset(int a[], int b[], int size)
{
	for(int i = 0; i < size; i++)
    {
        a[i] = b[i];
    }
}

// To initialize random values for the array.
void initialize(int b[], int size)
{
	// generating random numbers by using srand library.
	srand(time(NULL));
    for(int s=0; s<size; s++)
    {
    int no = rand()%10000;
    b[s]=no;
    }
}

int main ()
{	
	long size;
    cout<<"Enter number for array size: ";
    cin>> size;
    int b[size];
    int a[size];
    reset(a, b, size);

	// using chrono library to measure sorting time in nanoseconds.

	//measuring selection sort.
	// Begin counter
    auto begin = std::chrono::high_resolution_clock::now();

	// Start Selection sort.
    SelectionSort(a, size);

	// End counter
    auto end = std::chrono::high_resolution_clock::now();

	// Calculating time then printing the result.
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Selection Sort:\t %.9f seconds.\t\n", elapsed.count() * 1e-9);
    
	// reset the the array to apply the next sort.
    reset(a, b, size);
    

	// bubble sort measuring
    begin = std::chrono::high_resolution_clock::now();
    BubbleSort(a,size);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Bubble Sort:\t %.9f seconds.\t\n", elapsed.count() * 1e-9);

    reset(a, b, size);

	// Insertion sort measuring
    begin = std::chrono::high_resolution_clock::now();
    InsertionSort(a,size);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Insertion Sort:\t %.9f seconds.\t\n", elapsed.count() * 1e-9);

    reset(a, b, size);

	// Merge Sort.
    begin = std::chrono::high_resolution_clock::now();
    MergeSort(a,0,size-1);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Merge Sort:\t %.9f seconds.\t\n", elapsed.count() * 1e-9);

   	reset(a, b, size);

	// Quick Sort.
    begin = std::chrono::high_resolution_clock::now();
    QuickSort(a,0,size-1);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Quick Sort:\t %.9f seconds.\t\n", elapsed.count() * 1e-9);
    
	return 0;
}

