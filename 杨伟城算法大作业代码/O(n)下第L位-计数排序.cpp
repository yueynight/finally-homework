#include <iostream> 
#include <math.h> 
using namespace std; 
//���ü�������arr[]Ϊ��������,arrLen���鳤��,LΪ�ź�����L����� 
bool coutingSort(int arr[], int arrLen,int L) { 

//������鳤�ȣ����С��2��ֱ����� 

if (arrLen < 2) { 
return true; 
} 
//���������Сֵ���趨��Χ 
int max = arr[0]; 
int min = arr[0]; 
//�ҳ���Сֵ 
for (int i = 1; i < arrLen; ++i) 
{ 

if (min > arr[i]) { 

min = arr[i]; 

} 

//�ҳ����ֵ 

else if (max < arr[i]) { 
max = arr[i]; 
} 
} 

//Ϊ���α����ռ�counting�����ڴ� 

int *counting = new int[max - min + 1](); 

//��¼Ԫ�س��ִ��� 

for (int j = 0; j < arrLen; ++j) 

{ 

++counting[arr[j] - min]; 

} 

//��������Ԫ�س��ִ�������Եõ��������ݵ�����λ�� 

for (int k = 1; k < (max - min + 1); ++k) 

{ 

counting[k] += counting[k-1]; 

} 

//Ϊ���α����ռ�tempArray�����ڴ� 

int *tempArray = new int[arrLen](); 

//��ԭ����Ԫ�ذ�����counting���������Ӧλ�ô��� 

for (int l = arrLen - 1; l >= 0; --l) 

{ 

tempArray[--counting[arr[l] - min]] = arr[l]; 

} 

//��temp���鸴�Ƶ�arr�� 

for (int m = 0; m < arrLen; ++m) 

{ 

arr[m] = tempArray[m]; 

} 

//�ͷ��ڴ� 

delete [] counting; 

delete [] tempArray;  
//����L�������� ������������е�arrLen-Lλ�� 
cout << "�����е�"<<L<<"�������Ϊ��"<<arr[arrLen-L] ; 
return true; 




} 
int main(){
	//�������� 
	int a[]={4,5,3,8,9,24,74,34,71,39};
	//�����l����� 
	int l=3;
	coutingSort(a,sizeof(a)/sizeof(int),l);
	return 0;
}
