#include<iostream>
using namespace std;
//���ò�������ʵ�� ��arr[]Ϊ��������,arrLen���鳤��,LΪ�ź�����L�����  
void insert(int arr[],int arrLen,int L){
	int nums=0;
	//����һ������ 
	for(int i=0;i<arrLen;i++){
		//����ǰ����λ�õ�����������ǰһλ���бȽ�ֱ���Ƚϵ�arr[0]Ϊֹ 
		for(int j=i;j!=0;j--){
			if(arr[j]<arr[j-1]){
				//��С��ǰһλ�����ݾͽ��н��� 
				nums=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=nums;
				
			}
		}
	}
	//�����L������ݣ�����������е�arrLen-Lλ��  
	cout<<"��"<<L<<"�����Ϊ"<<arr[arrLen-L];
} 
int main(){
	int a[]={4,2,5,7,34,35,26,50,48,12,34};
	int L=2;
	insert(a,sizeof(a)/sizeof(int),L);
	return 0;
}
