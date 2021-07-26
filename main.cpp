#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int cmp(const pair<string, int> &x, const pair<string, int> &y)
{
    return x.second < y.second;
}

void split(map<string, int> expense)
{
    int invovlers = expense.size();

    int sum = 0;

    for (map<string, int>::iterator i = expense.begin(); i != expense.end(); i++)
        sum += i->second;

    int mean = sum / invovlers;

    for (map<string, int>::iterator i = expense.begin(); i != expense.end(); i++)
        i->second = i->second - mean;

    vector<pair<string, int>> vMap;
    for (map<string, int>::iterator i = expense.begin(); i != expense.end(); i++)
        vMap.push_back(make_pair(i->first, i->second));

    sort(vMap.begin(), vMap.end(), cmp);

    /*
    for (map<string,int>::iterator i = expense.begin(); i != expense.end(); i++)
    {   
        cout<< i->first << " " << i->second << endl;
    }

    for (vector<pair<string, int> >::iterator i = vMap.begin(); i != vMap.end(); i++)
    {
        cout<< i->first << " " << i->second << endl;
    }
    */

    int s = 0;
    int b = invovlers - 1;

    while (s != b + 1)
    {
        cout << vMap[s].second + vMap[b].second << endl;
        if ((vMap[s].second + vMap[b].second) > 0)
        {
            int price = -vMap[s].second;
            cout << vMap[s].first << " should pay " << vMap[b].first << " " << price << endl;
            vMap[b].second = vMap[s].second + vMap[b].second;
            //cout << s << " " << b << " then ";
            s++;
            //cout << s << " " << b << endl;
        }
        else if ((vMap[s].second + vMap[b].second) < 0)
        {
            int price = vMap[b].second;
            cout << vMap[s].first << " should pay " << vMap[b].first << " " << price << endl;
            vMap[s].second = vMap[s].second + vMap[b].second;
            //cout << s << " " << b << " then ";
            b--;
            //cout << s << " " << b << endl;
        }
        else if ((vMap[s].second + vMap[b].second) == 0)
        {
            int price = vMap[b].second;
            cout << vMap[s].first << " should pay " << vMap[b].first << " " << price << endl;
            //cout << s << " " << b << " then ";
            s++;
            b--;
            //cout << s << " " << b << endl;
        }
        sort(vMap.begin(), vMap.end(), cmp);
    }
}

void add_invovlers(map<string, int> &expense)
{
    /**
     * test case I
     * normal test cases
    **/

    /* 
    expense.insert(pair<string, int> ("A",122));
    expense.insert(pair<string, int> ("B",118));
    expense.insert(pair<string, int> ("C",160));
    expense.insert(pair<string, int> ("D",50));
    expense.insert(pair<string, int> ("E",150));
    */

    /**
     * test cases II
     * one person with no expense
    **/
   
    /*
    expense.insert(pair<string, int>("A", 0));
    expense.insert(pair<string, int>("B", 125));
    expense.insert(pair<string, int>("C", 125));
    expense.insert(pair<string, int>("D", 125));
    expense.insert(pair<string, int>("E", 125));
    */
}

int main()
{

    map<string, int> expense;

    add_invovlers(expense);
    split(expense);
}