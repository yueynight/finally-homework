#include<iostream> 
#include"Math.h"
#define Max 25000
using namespace std;
struct money{
	string name;
	int value;
	money(string n,int v){
		
		name=n;
		value=v;
	}
	Money(){
	name="";
	value=0;
	}
};

//kΪ�����moneyΪ����ָ�룬coinnumΪǮ�ҵ����� 
int paymoney(int payment, money *money, int moneyCount) { 
//��������dpArray[x][y]��xΪǮ�����࣬yΪ0~payment����� 
int** dpArray = new int*[moneyCount](); 
for (int i = 0; i < moneyCount; ++i) { 

dpArray[i] = new int[payment+1]; 

} 
//������Сʹ��Ǯ���� 
int minCount = Max; 
//����Ǯ������ 
for (int i = 0; i < moneyCount; i++) 

{ 
//�洢��ǰǮ������ 
int curMoney = money[i].value; 
//������0��ʼ������� 
for (int p = 1; p < (payment+1); p++) 

{ 
//��ʼ�� 
dpArray[i][p] = 0; 

if (p < curMoney && i > 0) { 

dpArray[i][p] = dpArray[i - 1][p]; 

} 

else { 
//�ж�ʹ�ö��ٵ�ǰ�����С��Ǯ�� 
dpArray[i][p] = p/curMoney; 
//����Ϊʣ�������Ӧ������֮ǰ�Ա������ 
int letfPayment = p%curMoney;
//����ǰ���Ǯ���޷�����֧��ʱ��ʣ���������������С��Ǯ����ɣ����Ǽ���dp[i][leftPayment]����Ӧ������Сʹ��Ǯ���� 
if (letfPayment > 0) { 
dpArray[i][p] += dpArray[i][letfPayment]; 
} 
} 

} 
//�����ս����ֵ 
if (minCount > dpArray[i][payment]) { 

minCount = dpArray[i][payment]; 

} 

} 
//�ͷ�����ռ� 
for (int i = 0; i < moneyCount; ++i) { 

delete [] dpArray[i]; 

} 

delete [] dpArray; 

return minCount; 

} 
int main(){
	int payment=14;
		money mon[]={
	money("һԪ",1),
	money("��Ԫ",2),
	money("��Ԫ",5),
	money("ʮԪ",10),
	money("��ʮԪ",20),
	money("��ʮԪ",50),
	money("һ��Ԫ",100)
	};
	int arrLen=sizeof(mon)/sizeof(money);
	int minCount=paymoney(payment,mon,arrLen);
	cout<<"ʹ����СǮ����Ϊ��
	}"<<minCount;
}
