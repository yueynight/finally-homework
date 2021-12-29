#include<iostream>
using namespace std;
//利用插入排序实现 ，arr[]为无序数组,arrLen数组长度,L为排好序后第L大的数  
void insert(int arr[],int arrLen,int L){
	int nums=0;
	//遍历一遍数组 
	for(int i=0;i<arrLen;i++){
		//将当前数组位置的数据与数据前一位进行比较直到比较到arr[0]为止 
		for(int j=i;j!=0;j--){
			if(arr[j]<arr[j-1]){
				//若小于前一位的数据就进行交换 
				nums=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=nums;
				
			}
		}
	}
	//输出第L大的数据，即输出数组中第arrLen-L位数  
	cout<<"第"<<L<<"大的数为"<<arr[arrLen-L];
} 
int main(){
	int a[]={4,2,5,7,34,35,26,50,48,12,34};
	int L=2;
	insert(a,sizeof(a)/sizeof(int),L);
	return 0;
}
