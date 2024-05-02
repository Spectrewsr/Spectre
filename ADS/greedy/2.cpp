#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<cctype>
#include <unordered_map>
using namespace std;
struct gas
{
	double price;
	double dis;
};
bool comp(gas a, gas b){
	if(a.dis == b.dis){
		return a.price < b.price;
	}
	return a.dis < b.dis;
}
int main(int argc, char const *argv[])
{
	double cmax,d,davg,n;
	while(cin>>cmax>>d>>davg>>n){
		vector<gas> station(n+1);
		for (int i = 0; i < n; ++i)
		{
			cin>>station[i].price>>station[i].dis;
		}
		station[n].price = 0;			//将终点站也看成加油站
		station[n].dis = d;
		sort(station.begin(), station.end(),comp);
		// for (int i = 0; i <= n; ++i)
		// {
		// 	cout<<station[i].dis<<' '<<station[i].price<<endl;
		// }

		double maxrun = davg * cmax;
		double run = 0;		//总路程
		double cost = 0;		//总花费
		double fuel = 0;		//当前剩余油量
		for (int i = 0; i < n; ++i)
		{
			if((station[i+1].dis - station[i].dis) > maxrun){		//间距大于加满油能跑的最大距离
				printf("The maximum travel distance = %.2f\n", run+maxrun);
				break;
			}
			double nearest = i+1;
			double cheapest = i+1;

			for (int j = i+1; j <= n && (station[j].dis - station[i].dis) <= maxrun; ++j)			//只在前n个加油站中找最近比当前便宜的的加油站
			{
				//找整个阶段最便宜的加油站必须放在前面，如果放在后面cheapest可能来不及更新进入错误的分支
				if(station[j].price <= station[cheapest].price){		//如果都大于当前价格，找到较便宜的且尽量走得更远
					cheapest = j;
				}
				if((station[j].price <= station[i].price)){		//有比当前更便宜的加油站
					nearest = j;
					break;
				}
			}

			if(station[cheapest].price > station[i].price){	//都比当前的油价贵
				cost += station[i].price * (cmax - fuel);	//先加满
				fuel = cmax;
				run += station[cheapest].dis - station[i].dis;	//跑的路程
				fuel -= (station[cheapest].dis - station[i].dis)/davg;	//跑到下一个站消耗的油量
				i = cheapest-1;									//循环会再+1，所以先-1
			}else{											//比当前便宜
				if(fuel * davg < (station[nearest].dis - station[i].dis)){	//如果剩余的油不能跑到下一站
					cost += station[i].price * ((station[nearest].dis - station[i].dis)/davg - fuel);	//加油到能跑到下一站（因为下一站便宜所以尽量到下一站再加）
					fuel = (station[nearest].dis - station[i].dis)/davg;
				}
				//能够跑到下一站(>=)
				fuel -= (station[nearest].dis - station[i].dis)/davg;		//减去到下一站消耗的油量
				run += (station[nearest].dis - station[i].dis);				//加路程
				i = nearest - 1;
			}
            printf("%f\n",cost);
		}
		if(run == d)		//只有到达终点站才输出
			printf("%.2f\n", cost);
	}
	return 0;
}
