#include<iostream>
#include<algorithm>
#include<sstream>

using namespace std;

char names[][5] = {
        "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
        "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou",
};

int get(string word)
{
    for (int i = 0; i < 25; i ++ )
        if (word == names[i])
        {
            if (i < 13) return i;
            else return (i - 12) * 13;
        }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    getchar();

    while(n -- )
    {
        string line;
        getline(cin, line);

        stringstream ssin(line);  // 从字符串里读

        if (line[0] <= '9') // 说明是个数字
        {
            int v;
            ssin >> v;
            if (v < 13) cout << names[v % 13] << endl;
            else
            {
                if (v % 13 == 0) cout << names[v / 13 + 12] << endl;
                else cout << names[v / 13 + 12] << ' ' << names[v % 13] << endl;
            }
        }
        else
        {
            int res = 0;
            string word;
            while(ssin >> word) res += get(word);
            cout << res << endl;
        }
    }

    return 0;
}
