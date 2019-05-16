//1650
#include <iostream>
#include <bits/stdc++.h>
/**
 * amount - sorted set of cities. The top cities we can get in const.
 * Every change of place changes amount of money in the city (update is for log).
 *
 * Cities and people put in the map so we can get them in log.
 *
 */
struct city {
    std::string name;
    long long money;
    int days;
} ct[10000 + 50000];

struct pers {
    long long money;
    city *location;
} pr[10000];

std::map<std::string, pers *> hum;
std::map<std::string, city *> cities;
std::set<std::pair<long long, city *>, std::greater<>> amount;

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    int c = 0;
    for (int i = 0; i < n; ++i) {
        std::string name_p;
        std::string name_c;
        long long mon;
        std::cin >> name_p >> name_c >> mon;
        if (!cities[name_c]) {
            ct[c].name = name_c;
            ct[c].money = mon;
            cities[name_c] = &ct[c];
            c++;
        } else {
            cities[name_c]->money += mon;
        }
        pr[i].money = mon;
        pr[i].location = cities[name_c];
        hum[name_p] = &pr[i];
    }

    for (auto &item : cities) {
        amount.insert({item.second->money, item.second});
    }

    int m, k, today = 0;
    std::cin >> m >> k;

    for (int i = 0; i < k; ++i) {
        int day;
        std::string name_p, name_c;
        std::cin >> day >> name_p >> name_c;
        int count = day - today;
        today = day;
        auto it2 = amount.begin();
        auto it = it2++;
        if (it2 == amount.end() || it->first > it2->first) {
            it->second->days += count;
        }
        city *to_city = cities[name_c];
        pers *which_pers = hum[name_p];
        if (to_city == nullptr) {
            ct[c].name = name_c;
            cities[name_c] = &ct[c];
            c++;
            to_city = cities[name_c];
        }
        amount.erase({which_pers->location->money, which_pers->location});
        amount.erase({to_city->money, to_city});
        which_pers->location->money -= which_pers->money;
        amount.insert({which_pers->location->money, which_pers->location});
        which_pers->location = to_city;
        to_city->money += hum[name_p]->money;
        amount.insert({to_city->money, to_city});
    }

    int count = m - today;
    auto it2 = amount.begin();
    auto it = it2++;
    if (it2 == amount.end() || it->first > it2->first) {
        it->second->days += count;
    }

    for (auto &item : cities) {
        if (item.second->days > 0)
            std::cout << item.first << " " << item.second->days << "\n";
    }
    return 0;
}
