#include<iostream> 
#include"Math.h"
using namespace std;
//设置全局变量计算钱币的使用数 
int i=1;
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
//利用递归解决问题 
int mony(money a[],int arrLen,int k){
	//终止条件 
if(a[arrLen-i].name=="一元"){
	cout<<"使用"<<countmoney<<"张纸币";
return 0;
	}
	//单不被整除且在数组范围内时 
    else if(k>a[arrLen-i].nums&&k/a[arrLen-i].nums!=0&&i<8){
		countmoney+=k/a[arrLen-i].nums;
		cout<<"需要:" <<k/a[arrLen-i].nums<<"张"<<a[arrLen-i].name<<endl;
		k=k%a[arrLen-i].nums;
		i++;
		}
		//否则即被整除 
	else{
	    countmoney+=k/a[arrLen-i].nums;
	    //将使用了的钱币输出，未使用的隐藏 
		if(k/a[arrLen-i].nums!=0&&i<8)
		cout<<"需要:"<<k/a[arrLen-i].nums<<"张"<<a[arrLen-i].name;
	   i++;
	}
	//递归调用 
	return mony(a,arrLen,k);
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
	mony(mon,sizeof(mon)/sizeof(money),k);
	return 0;
}
