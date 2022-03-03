# include <bits/stdc++.h>

using namespace std;

set <pair <int, int>> rows[50001], cols[50001];

void merge()
{
    pair <int, int> temp = *rows[0].begin();
    for (auto i : rows[0])
    {
        int fa = temp.first, sa = temp.second;
        int fb = i.first, sb = i.second;
        if (sa == fb)
        {
            pair <int, int> ins = make_pair(fa, sb);
            rows[0].erase(temp);
            rows[0].erase(i);
            rows[0].insert(ins);
        }
        temp = i;
    }
}

pair <int, int> get(pair <int, int> res)
{
    int r = res.first, c = res.second;

    pair <int, int> ans;
    for (auto i : rows[r])
    {
        if (i.first <= r and r <= i.second)
        {
            ans = i;
            return ans; 
        }
    }

    for (auto i : rows[0])
    {
        if (i.second + 1 == r)
        {
            ans = i;
            ans.second++;
            rows[0].erase(i);
            rows[0].insert(ans);
            merge();
            break;
       }
    }

    for (auto i : rows[0])
    {
        if (i.first - 1 == r)
        {
            ans = i;
            ans.first--;
            rows[0].erase(i);
            rows[0].insert(ans);
            merge();
            break;
        }
    }

    return ans;
}

int helper()
{
    rows[0].insert(make_pair(0, 1));
    rows[0].insert(make_pair(6, 8));
    rows[0].insert(make_pair(3, 4));
    rows[0].insert(make_pair(10, 11));
    rows[0].insert(make_pair(12, 12));


    pair <int, int> res = make_pair(5, 5);
    pair <int, int> ans = get(res);
    res = make_pair(2, 2);
    ans = get(res);

    cout << ans.first << ' ' << ans.second << endl;
    cout << endl;
    for (auto i : rows[0])
    {
        cout << i.first << ' ' << i.second << endl;
    }
}

void solve()
{
    int n, r, c, sr, sc;
    cin >> n >> r >> c >> sr >> sc;

    pair <int, int> res = make_pair(sr, sc);
    rows[sr].insert(make_pair(sc, sc));
    cols[sc].insert(make_pair(sr, sr));

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        int d = 0;

        if (c == 'N')
        {
            res = get(res);
            cout << res.first << endl;
        }

        else if (c == 'E')
        {
            
        }

        else if (c == 'S')
        {
            
        }
    }

}   

int main()
{

}
