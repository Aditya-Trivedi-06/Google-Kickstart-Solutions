# include <bits/stdc++.h>

using namespace std;

int main()
{
    set <int> s1, s2;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    s1.insert(6);
    s2.insert(5);
    s2.insert(3);
    s2.insert(10);
    s2.insert(9);
    s2.insert(8);
    s2.insert(14);
    s2.insert(2);
    s2.insert(11);
    vector <int> v;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(v));
    for (auto i : v)
        cout << i << ' ';
    cout << endl;
}