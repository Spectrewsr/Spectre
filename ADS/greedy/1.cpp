#include <iostream>
#include<algorithm>
#include <utility>

std::pair<double, int> gas[1000];

bool compare(std::pair<double, int> a, std::pair<double, int> b)
{
	if(a.second == b.second){
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main()
{
    int caption, dis, avg, num_sta;
    std::cin >> caption >> dis >> avg >> num_sta;

    int max_dis = caption * avg;

    for ( int i = 0; i < num_sta; ++i )
    {
        std::cin>>gas[i].first >> gas[i].second;
    }
    gas[num_sta].second = dis;
    std::sort(gas, gas+num_sta+1, compare);

    if (gas[0].second != 0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    bool achieve = true;
    double distance = 0;
    double cost = 0;
    double oil = 0.00;
    int i = 0;
    
    while(i < num_sta)
    {
        int next_station = i+1;
        int choice = i+1;

        if ( gas[i+1].second - gas[i].second > max_dis )
        {
            printf("The maximum travel distance = %.2f\n", distance + max_dis);
			return 0;
        }

        for ( int j = i+1; j < num_sta && gas[j].second - gas[i].second <= max_dis; ++j )
        {
            if (gas[j].first < gas[choice].first)
            {
                choice = j;
            }

            if (gas[i].first >= gas[j].first)
            {
                next_station = j;
                break;
            }
        }

        if (gas[choice].first > gas[i].first)
        {
            cost += gas[i].first * (caption - oil);
            oil = caption - (double)(gas[choice].second - gas[i].second)/avg;
            distance += gas[choice].second - gas[i].second;
            i = choice;
        }
        else
        {
            if (oil * avg < (gas[next_station].second - gas[i].second))
            {
                cost += gas[i].first* ((double)(gas[next_station].second - gas[i].second)/avg - oil) ;
                //printf("  %d   %d  %f  %f\n",gas[next_station].second , gas[i].second,gas[i].first,cost);
                oil += (gas[next_station].second - gas[i].second)/avg - oil;
            }

            oil -= (gas[next_station].second - gas[i].second)/avg;
            distance += (gas[next_station].second - gas[i].second);
            i = next_station;
        }
        //printf("%f  %f\n",gas[i].first,cost);
    }

    if(!achieve)
    {
        printf("The maximum travel distance = %.2f\n", distance + max_dis);
		return 0;
    }
    else
    {
        printf("%.2f\n", cost);
    }
    return 0;
}