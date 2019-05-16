#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comaratorByFirst(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

bool comaratorBySecond(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    int m, n, k, res = 0;

    cin >> m >> n >> k;

    vector<pair<int, int>> point;
    vector<pair<int, int>> sq;

    for (int i = 0; i < k; ++i) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        p.first--;
        p.second--;
        point.push_back(p);
    }

    for (int i = 0; i < m; ++i) {
        pair<int, int> p = {i, -1};
        pair<int, int> p2 = {i, n};
        point.push_back(p2);
        point.push_back(p);
    }

    for (int i = 0; i < n; ++i) {
        pair<int, int> p = {-1, i};
        pair<int, int> p2 = {m, i};
        point.push_back(p2);
        point.push_back(p);
    }

    sort(point.begin(), point.end(), comaratorByFirst);

    for (int i = 0; i < point.size() - 1; ++i) {
        if (point[i].first == point[i + 1].first) {
            if (point[i + 1].second - point[i].second - 1 > 1) {
                res++;
            } else if (point[i + 1].second - point[i].second - 1 == 1) {
                pair<int, int> p(point[i].first, point[i].second + 1);
                sq.push_back(p);
            }
        }
    }

    sort(point.begin(), point.end(), comaratorBySecond);
    sort(sq.begin(), sq.end(), comaratorBySecond);

    for (int i = 0; i < point.size() - 1; ++i) {
        if (point[i].second == point[i + 1].second) {
            if (point[i + 1].first - point[i].first - 1 > 1) {
                res++;
            } else if (point[i + 1].first - point[i].first - 1 == 1) {
                pair<int, int> p(point[i].first + 1, point[i].second);
                sq.push_back(p);
            }
        }
    }

    sort(sq.begin(), sq.end(), comaratorByFirst);

    if (sq.size() > 1) {
        int i = 0;
        while (i < sq.size() - 1) {
            if (sq[i] == sq[i + 1]) {
                res++;
                i++;
            }
            i++;
        }
    }

    cout << "\n\n" << res;

    return 0;
}
