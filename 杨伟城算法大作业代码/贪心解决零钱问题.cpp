#include<iostream>
#include"Math.h"
using namespace std;
//����ȫ�ֱ�������Ǯ�ҵ�ʹ���� 
int countmoney=0;
//����ṹ�� ����ʼ�� 
struct money{
	string name;
	int nums;
	money(string n,int v){
		name=n;
		nums=v;
	}
	Money(){
	name="";
	nums=0;
	}
};
//���庯�� 
void getmoney(money a[],int arrLen,int k){	
	//countmoney��ʼ�� 
	countmoney=0;
	//�Խ�����Ӵ�С���� 
	for(int i=1;i<=arrLen;i++){
		//����������� 
	if(k%a[arrLen-i].nums!=0){
		//���Ϊ0���������� 
		if(k>a[arrLen-i].nums && k/a[arrLen-i].nums==0){
		cout<<"��Ҫ" <<k/a[arrLen-i].nums<<"��һԪ";

		}
		//�����಻Ϊ0���������ǵ�ǰ��������������������ʹcountmoney++ 
		else if(k>a[arrLen-i].nums){
		countmoney+=k/a[arrLen-i].nums;
		cout<<"��Ҫ" <<k/a[arrLen-i].nums<<"��"<<a[arrLen-i].name<<endl;
		k=k%a[arrLen-i].nums;
		
		}
	}
	//����������Ա����� 
	else{
	    countmoney+=k/a[arrLen-i].nums;
		cout<<"��Ҫ"<<k/a[arrLen-i].nums<<"��"<<a[arrLen-i].name<<endl;
		break;
	}
	
}
cout<<"��ʹ��"<<countmoney<<"��Ǯ��";
 
}

int main(){
	money mon[]={
	money("һԪ",1),
	money("��Ԫ",2),
	money("��Ԫ",5),
	money("ʮԪ",10),
	money("��ʮԪ",20),
	money("��ʮԪ",50),
	money("һ��Ԫ",100)
	};
	int k=48;

	getmoney(mon,sizeof(mon)/sizeof(money),k);
	return 0;
}
 
