#include<iostream>
using namespace std;
void mergetwosortedarray(int arr1[], int s, int e)
{	
	int mid =(s+e)/2;
	int temp[1000];
	int i=s;
	int j=mid+1;
	int k=s;
	while(j<=e and i<=mid)
	{
		if (arr1[i]<arr1[j])
		{
			temp[k]=arr1[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=arr1[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		temp[k]=arr1[i];
		i++;
		k++;
	}
	while(j<=e)
	{
		temp[k]=arr1[j];
		j++;
		k++;
	}
	for (int l = 0; l < k; ++l)
	{
		arr1[l]=temp[l];
	}
}

void mergesort(int arr1[],int s, int e)
{	
	//base case
	if (s==e)
	{
		return;
	}
	//divide through mid
	int mid = (s+e)/2;

	//merge two sorted array
	mergesort(arr1,s,mid);
	mergesort(arr1,mid+1,e);

	//result
	mergetwosortedarray(arr1, s, e);

}
int main()
{	
	int n1;
	cin>>n1;
	
	int arr1[n1];
	for (int i = 0; i < n1; ++i)
	{
		cin>>arr1[i];
	}
	mergesort(arr1, 0, n1-1);
	for (int i = 0; i < n1; ++i)
	{
		cout<<arr1[i]<<" ";
	}
	cout<<endl;
	return 0;
}
