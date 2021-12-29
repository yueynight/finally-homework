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

//k为输入金额，money为数组指针，coinnum为钱币的种类 
int paymoney(int payment, money *money, int moneyCount) { 
//创建网格dpArray[x][y]，x为钱币种类，y为0~payment金额数 
int** dpArray = new int*[moneyCount](); 
for (int i = 0; i < moneyCount; ++i) { 

dpArray[i] = new int[payment+1]; 

} 
//定义最小使用钱币数 
int minCount = Max; 
//遍历钱币种类 
for (int i = 0; i < moneyCount; i++) 

{ 
//存储当前钱币数额 
int curMoney = money[i].value; 
//遍历从0开始遍历金额 
for (int p = 1; p < (payment+1); p++) 

{ 
//初始化 
dpArray[i][p] = 0; 

if (p < curMoney && i > 0) { 

dpArray[i][p] = dpArray[i - 1][p]; 

} 

else { 
//判断使用多少当前数额大小的钱币 
dpArray[i][p] = p/curMoney; 
//余数为剩余金额，而相应数组在之前以遍历完毕 
int letfPayment = p%curMoney;
//当当前最大钱币无法整额支付时，剩余余数便由数额更小的钱币完成，于是加上dp[i][leftPayment]即对应金额的最小使用钱币数 
if (letfPayment > 0) { 
dpArray[i][p] += dpArray[i][letfPayment]; 
} 
} 

} 
//将最终结果赋值 
if (minCount > dpArray[i][payment]) { 

minCount = dpArray[i][payment]; 

} 

} 
//释放数组空间 
for (int i = 0; i < moneyCount; ++i) { 

delete [] dpArray[i]; 

} 

delete [] dpArray; 

return minCount; 

} 
int main(){
	int payment=14;
		money mon[]={
	money("一元",1),
	money("二元",2),
	money("五元",5),
	money("十元",10),
	money("二十元",20),
	money("五十元",50),
	money("一百元",100)
	};
	int arrLen=sizeof(mon)/sizeof(money);
	int minCount=paymoney(payment,mon,arrLen);
	cout<<"使用最小钱币数为：
	}"<<minCount;
}
