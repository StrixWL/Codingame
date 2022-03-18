#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int fc(string line, char c)
{
    int i = 0;
    int res = 0;
    while (line[i]) {
        if (line[i] == c)
            res++;
        i++;
    }
    return res;
}

int print(string lines[])
{
    for (int i = 0; i < 3; i++)
        cout << lines[i] << endl;
    return (0);
}

string fill(string line)
{
    int i = 0;
    while (line[i] != '.')
        i++;
    line[i] = 'O';
    return (line);
}

int rotate(string lines_h[], string lines_v[])
{
    for (int i = 0; i < 3; i++) {
        lines_v[i] = lines_h[i];
        for (int j = 0; j < 3; j++)
            lines_v[i][j] = lines_h[j][i];
    }
    return 0;
}

int main()
{
    string lines_h[3];
    for (int i = 0; i < 3; i++) {
        string line;
        getline(cin, line);
        lines_h[i] = line;
    }
    for (int i = 0; i < 3; i++) {
        if (fc(lines_h[i], 'O') == 2 && fc(lines_h[i], 'X') == 0)
        {
            lines_h[i] = fill(lines_h[i]);
            return (print(lines_h));
        }
    }
    // horizontal
    string lines_v[3];
    rotate(lines_h, lines_v);
    for (int i = 0; i < 3; i++) {
        if (fc(lines_v[i], 'O') == 2 && fc(lines_v[i], 'X') == 0)
        {
            lines_v[i] = fill(lines_v[i]);
            string lines_vn[3];
            for (int i = 0; i < 3; i++) {
                lines_vn[i] = lines_v[i];
            }
            rotate(lines_vn, lines_v);
            return (print(lines_v));
        }
    }
    // vertical
    string lines_d[2];
    lines_d[0] = lines_h[0];
    lines_d[1] = lines_h[0];
    for (int i = 0; i < 3; i++)
        lines_d[0][i] = lines_h[i][i];
    for (int i = 0, j = 2; i < 3; i++)
        lines_d[1][i] = lines_h[i][j--];
    if (fc(lines_d[0], 'O') == 2 && fc(lines_d[0], 'X') == 0)
    {
        for (int i = 0; i < 3; i++)
            lines_h[i][i] = 'O';
        return (print(lines_h));
    }    
    if (fc(lines_d[1], 'O') == 2 && fc(lines_d[1], 'X') == 0)
    {
        for (int i = 0, j = 2; i < 3; i++)
            lines_h[i][j--] = 'O';
        return (print(lines_h));
    }
    // diagonal
    cout << "false" << endl;
    // no win
}
