#include<iostream>
#include"Math.h"
using namespace std;
//设置全局变量计算钱币的使用数 
int countmoney=0;
//定义结构体 并初始化 
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
//定义函数 
void getmoney(money a[],int arrLen,int k){	
	//countmoney初始化 
	countmoney=0;
	//以金额数从大到小遍历 
	for(int i=1;i<=arrLen;i++){
		//如果不能整除 
	if(k%a[arrLen-i].nums!=0){
		//金额为0，或遍历完成 
		if(k>a[arrLen-i].nums && k/a[arrLen-i].nums==0){
		cout<<"需要" <<k/a[arrLen-i].nums<<"张一元";

		}
		//若求余不为0，则结果便是当前金额所需数，将其输出并使countmoney++ 
		else if(k>a[arrLen-i].nums){
		countmoney+=k/a[arrLen-i].nums;
		cout<<"需要" <<k/a[arrLen-i].nums<<"张"<<a[arrLen-i].name<<endl;
		k=k%a[arrLen-i].nums;
		
		}
	}
	//若输入金额可以被整除 
	else{
	    countmoney+=k/a[arrLen-i].nums;
		cout<<"需要"<<k/a[arrLen-i].nums<<"张"<<a[arrLen-i].name<<endl;
		break;
	}
	
}
cout<<"共使用"<<countmoney<<"张钱币";
 
}

int main(){
	money mon[]={
	money("一元",1),
	money("二元",2),
	money("五元",5),
	money("十元",10),
	money("二十元",20),
	money("五十元",50),
	money("一百元",100)
	};
	int k=48;

	getmoney(mon,sizeof(mon)/sizeof(money),k);
	return 0;
}
 
