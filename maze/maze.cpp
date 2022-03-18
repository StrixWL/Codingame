#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Pos {
  public:
    int x;
    int y;
    bool connected;
};

int main()
{
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    Pos myPos;
    cin >> myPos.x >> myPos.y; cin.ignore();
    string map[h];
    for (int i = 0; i < h; i++) {
        string r;
        getline(cin, r);
        map[i] = r;
    }
    vector<Pos> possibleExits;
    for (int i = 0; i < w; i++) {
        if (map[0][i] == '.')
        {
            Pos possibleExit;
            possibleExit.x = i;
            possibleExit.y = 0;
            possibleExits.push_back(possibleExit);
        }
    }
    // upper exits number
    for (int i = 0; i < w; i++) {
        if (map[h - 1][i] == '.')
        {
            Pos possibleExit;
            possibleExit.x = i;
            possibleExit.y = h - 1;
            possibleExits.push_back(possibleExit);
        }
    }
    // bottom exits number
    for (int i = 1; i < h - 1; i++) {
        if (map[i][0] == '.')
        {
            Pos possibleExit;
            possibleExit.x = 0;
            possibleExit.y = i;
            possibleExits.push_back(possibleExit);
        }
    }
    // left exits number
    for (int i = 1; i < h - 1; i++) {
        if (map[i][w - 1] == '.')
        {
            Pos possibleExit;
            possibleExit.x = w - 1;
            possibleExit.y = i;
            possibleExits.push_back(possibleExit);
        }
    }
    // right exits number
    cout << possibleExits.size() << endl;
    for (Pos & i : possibleExits) {
        cout << i.x << " ";
        cout << i.y << endl;
    }

    // for (int i = 0; i < h; i++) {
    //     cout << map[i] << endl;
    // }
}
