#include<bits/stdc++.h>
using namespace std;

int total_number_orders = 0;
int total_revenue = 0;
map<string, int> revenue_of_shop;
map<string, map<string, int>> total_consume_of_customer_shop;
map<int, int> total_revenue_in_period;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);      // improve the performance or I/O function 
    
    string CustomerID, ProductID, ShopID, TimePoint;
    int price;

    while(1) {
        cin >> CustomerID; 
        if(CustomerID == "#") break;
        cin >> ProductID >> price >> ShopID >> TimePoint;

        ++total_number_orders;
        total_revenue += price;
        revenue_of_shop[ShopID] += price;
        total_consume_of_customer_shop[CustomerID][ShopID] += price;

         int time = (TimePoint[7] - '0') + (TimePoint[6] - '0') * 10 
                  + (TimePoint[4] - '0') * 60 + (TimePoint[3] - '0') * 600
                  + (TimePoint[1] - '0') * 3600 + (TimePoint[0] - '0') * 36000;
        total_revenue_in_period[time] += price;
    }

    // Create prefix sum
    auto pre = total_revenue_in_period.begin();
    auto it = total_revenue_in_period.begin();
    for(it++; it != total_revenue_in_period.end(); it++) {
        it->second += pre->second;
        pre++;
    }

    string order;
    while(1) {
        cin >> order;
        if(order == "#") break;
        else if(order == "?total_number_orders") cout << total_number_orders << endl;
        else if(order == "?total_revenue") cout << total_revenue << endl;
        else if(order == "?revenue_of_shop") {
            cin >> ShopID;
            cout << revenue_of_shop[ShopID] << endl;
        }
        else if(order == "?total_consume_of_customer_shop") {
            cin >> CustomerID >> ShopID;
            cout << total_consume_of_customer_shop[CustomerID][ShopID] << endl;
        }
        else if(order == "?total_revenue_in_period") {
            cin >> TimePoint;
            int fromTime = (TimePoint[7] - '0') + (TimePoint[6] - '0') * 10 
                         + (TimePoint[4] - '0') * 60 + (TimePoint[3] - '0') * 600
                         + (TimePoint[1] - '0') * 3600 + (TimePoint[0] - '0') * 36000;

            cin >> TimePoint;
            int toTime = (TimePoint[7] - '0') + (TimePoint[6] - '0')*10 
                       + (TimePoint[4] - '0') * 60 + (TimePoint[3] - '0') * 600
                       + (TimePoint[1] - '0') * 3600 + (TimePoint[0] - '0') * 36000;

            auto itFromTime = total_revenue_in_period.lower_bound(fromTime);
            auto itToTime = total_revenue_in_period.upper_bound(toTime);
            cout << (--itToTime)->second - (--itFromTime)->second << endl;
        }
    }

    return 0;
}