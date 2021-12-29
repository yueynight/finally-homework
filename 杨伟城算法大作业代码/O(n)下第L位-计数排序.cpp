#include <iostream> 
#include <math.h> 
using namespace std; 
//利用计数排序，arr[]为无序数组,arrLen数组长度,L为排好序后第L大的数 
bool coutingSort(int arr[], int arrLen,int L) { 

//检测数组长度，如果小于2则直接输出 

if (arrLen < 2) { 
return true; 
} 
//定义最大最小值来设定范围 
int max = arr[0]; 
int min = arr[0]; 
//找出最小值 
for (int i = 1; i < arrLen; ++i) 
{ 

if (min > arr[i]) { 

min = arr[i]; 

} 

//找出最大值 

else if (max < arr[i]) { 
max = arr[i]; 
} 
} 

//为整形变量空间counting分配内存 

int *counting = new int[max - min + 1](); 

//记录元素出现次数 

for (int j = 0; j < arrLen; ++j) 

{ 

++counting[arr[j] - min]; 

} 

//将数组内元素出现次数相加以得到最终数据的排序位置 

for (int k = 1; k < (max - min + 1); ++k) 

{ 

counting[k] += counting[k-1]; 

} 

//为整形变量空间tempArray分配内存 

int *tempArray = new int[arrLen](); 

//将原数组元素按照在counting中算出的相应位置存入 

for (int l = arrLen - 1; l >= 0; --l) 

{ 

tempArray[--counting[arr[l] - min]] = arr[l]; 

} 

//将temp数组复制到arr中 

for (int m = 0; m < arrLen; ++m) 

{ 

arr[m] = tempArray[m]; 

} 

//释放内存 

delete [] counting; 

delete [] tempArray;  
//将第L大的数输出 ，即输出数组中第arrLen-L位数 
cout << "数组中第"<<L<<"大的数据为："<<arr[arrLen-L] ; 
return true; 




} 
int main(){
	//创建数组 
	int a[]={4,5,3,8,9,24,74,34,71,39};
	//输出第l大的数 
	int l=3;
	coutingSort(a,sizeof(a)/sizeof(int),l);
	return 0;
}
