#include<iostream>
#include<string>
#include<map>

using namespace std;

const int WIN = 1;
const int LOSE = 0;
const int DRAW = -1;
const int CHUI = 0;
const int JIAN = 1;
const int BU = 2;
const int result[][3] =
{
    {DRAW, WIN, LOSE},
    {LOSE, DRAW, WIN},
    {WIN, LOSE, DRAW}
};

class Player
{
private:
    int _win, _lose, _draw;
    int win_with[3];
public:
    Player() : _win (0), _lose (0), _draw (0)
    {
        win_with[CHUI] = win_with[JIAN] = win_with[BU] = 0;
    }
    void win (const int &i)
    {
        ++_win;

        switch (i)
        {
        case CHUI:
            ++win_with[CHUI];
            break;

        case JIAN:
            ++win_with[JIAN];
            break;

        default:
            ++win_with[BU];
            break;
        }
    }
    void lose()
    {
        ++_lose;
    }
    void draw()
    {
        ++_draw;
    }
    int getWin()
    {
        return _win;
    }
    int getLose()
    {
        return _lose;
    }
    int getDraw()
    {
        return _draw;
    }
    string getWinMost()
    {
        int temp = win_with[CHUI] >= win_with[JIAN] ? CHUI : JIAN;

        if (win_with[BU] >= win_with[temp])
            return "B";
        else
            return temp == CHUI ? "C" : "J";
    }
};

int main (void)
{
    int n;
    map<string, int> m;
    m.insert (make_pair ("C", CHUI) );
    m.insert (make_pair ("J", JIAN) );
    m.insert (make_pair ("B", BU) );

    while (cin >> n)
    {
        Player a, b;
        string aa, bb;

        while (n--)
        {
            cin >> aa >> bb;

            switch (result[m[aa]][m[bb]])
            {
            case WIN:
                a.win (m[aa]);
                b.lose();
                break;

            case LOSE:
                a.lose();
                b.win (m[bb]);
                break;

            default:
                a.draw();
                b.draw();
                break;
            }
        }

        cout << a.getWin() << " " << a.getDraw() << " " << a.getLose() << endl
             << b.getWin() << " " << b.getDraw() << " " << b.getLose() << endl
             << a.getWinMost() << " " << b.getWinMost() << endl;

    }

    return 0;
}
