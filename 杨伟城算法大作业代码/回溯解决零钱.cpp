#include<iostream> 
#include"Math.h"
using namespace std;
//����ȫ�ֱ�������Ǯ�ҵ�ʹ���� 
int i=1;
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
//���õݹ������� 
int mony(money a[],int arrLen,int k){
	//��ֹ���� 
if(a[arrLen-i].name=="һԪ"){
	cout<<"ʹ��"<<countmoney<<"��ֽ��";
return 0;
	}
	//�����������������鷶Χ��ʱ 
    else if(k>a[arrLen-i].nums&&k/a[arrLen-i].nums!=0&&i<8){
		countmoney+=k/a[arrLen-i].nums;
		cout<<"��Ҫ:" <<k/a[arrLen-i].nums<<"��"<<a[arrLen-i].name<<endl;
		k=k%a[arrLen-i].nums;
		i++;
		}
		//���򼴱����� 
	else{
	    countmoney+=k/a[arrLen-i].nums;
	    //��ʹ���˵�Ǯ�������δʹ�õ����� 
		if(k/a[arrLen-i].nums!=0&&i<8)
		cout<<"��Ҫ:"<<k/a[arrLen-i].nums<<"��"<<a[arrLen-i].name;
	   i++;
	}
	//�ݹ���� 
	return mony(a,arrLen,k);
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
	mony(mon,sizeof(mon)/sizeof(money),k);
	return 0;
}
