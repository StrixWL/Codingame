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
    bool checked = false;
    bool connected = false;
};

bool all_checked(vector<Pos> connections)
{
    for (Pos & i : connections) {
        if (!i.checked)
            return false; 
    }
    return true;
}

Pos get_right(Pos pos)
{
    pos.x += 1;
    return pos;
}

Pos get_left(Pos pos)
{
    pos.x = pos.x - 1;
    return pos;
}

Pos get_top(Pos pos)
{
    pos.y -= 1;
    return pos;
}

Pos get_bottom(Pos pos)
{
    pos.y += 1;
    return pos;
}

bool check_repitition(vector<Pos> connections, Pos pos)
{
    for (Pos & i : connections) {
        if (i.x == pos.x && i.y == pos.y)
            return true;
    }
    return false;
}

bool is_connected(Pos exit, Pos myPos, int w, int h, string map[])
{
    vector<Pos> connections;
    connections.push_back(exit);
    while (!all_checked(connections))
    {
        for (Pos & i : connections) {
            if (i.checked == true)
                continue;
            if (map[get_right(i).y][get_right(i).x] == '.')
                if (!check_repitition(connections, get_right(i)))
                    connections.push_back(get_right(i));
            if (map[get_left(i).y][get_left(i).x] == '.')
                if (!check_repitition(connections, get_left(i)))
                    connections.push_back(get_left(i));
            cerr << i.x << " " << i.y << endl;
            if (map[get_top(i).y][get_top(i).x] == '.')
                if (!check_repitition(connections, get_top(i)))
                    connections.push_back(get_top(i));
            if (map[get_bottom(i).y][get_bottom(i).x] == '.')
                if (!check_repitition(connections, get_bottom(i)))
                    connections.push_back(get_bottom(i));
            i.checked = true;
        }
    }
    if (check_repitition(connections, myPos))
        return true;
    return false;
}

int main()
{
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    Pos myPos;
    cin >> myPos.x >> myPos.y; cin.ignore();
    string map[h + 1];
    for (int i = 0; i < h; i++) {
        string r;
        getline(cin, r);
        map[i] = r;
    }
    //map[h] = "XDDDDDD";
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
    for (Pos & i : possibleExits) {
        if (is_connected(i, myPos, w, h, map))
            i.connected = true;
    }
    // for (int i = 0; i < h; i++) {
    //     cout << map[i] << endl;
    // }
}
//