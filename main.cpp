#include <bits/stdc++.h>
using namespace std;
char grid[3][3];
void Fill_the_grid()
{
    char ch = '1';
    for (short i = 0; i < 3; i++)
    {
        for (short ii = 0; ii < 3; ii++)
        {
            grid[i][ii] = ch;
            ch++;
        }
    }
}
bool Check_if_the_place_is_free(short num, string sy)
{
    for (short i = 0; i < 3; i++)
    {
        for (short ii = 0; ii < 3; ii++)
        {
            if (grid[i][ii] - '0' == num)
            {
                if (sy == "x" || sy == "o")
                    grid[i][ii] = sy[0] - 32;
                else
                    grid[i][ii] = sy[0];
                return 1;
            }
        }
    }
    return 0;
}
bool Check_Win()
{
    if (grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X' ||
        grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X' ||
        grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X' ||
        grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X' ||
        grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X' ||
        grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X' ||
        grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X' ||
        grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X')
        return 1;
    if (grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O' ||
        grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O' ||
        grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O' ||
        grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O' ||
        grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O' ||
        grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O' ||
        grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O' ||
        grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O')
        return 1;
    return 0;
}
bool Check_Symbol(string sy)
{
    if (sy == "X" || sy == "x" || sy == "O" || sy == "o")
        return 1;
    return 0;
}
void Print_grid(string sy1, string sy2)
{
    // Color the grid in lime and X in black and O in yellow.
    for (short i = 0; i < 3; i++)
    {
        cout << "-------------\n";
        for (short ii = 0; ii < 3; ii++)
        {
            cout << '|' << " ";
            if (grid[i][ii] >= '1' && grid[i][ii] <= '9')
                cout << grid[i][ii];
            else if (grid[i][ii] == 'X')
            {
                if (sy1[0] == 'x' || sy2[0] == 'x')
                    cout << 'x';
                else
                    cout << 'X';
            }
            else
            {
                if (sy1[0] == 'o' || sy2[0] == 'o')
                    cout << 'o';
                else
                    cout << 'O';
            }
            cout << " ";
        }
        cout << "|\n";
    }
    cout << "-------------\n";
}
void Main_System()
{
    while (1)
    {
        string winner = "", p1 = "", p2 = "";
        short choice = 0, pl = 0;
        bool flag = 1;
        cout << "\033[34mWelcome to Tic-Tac-Toe game!\033[37m\n\nPlease enter one of the following options:\n\n";
        // "\033[34m" => sets the statement to color blue.
        // "\033[37m"  => reset the rest of the statements to default.
        Fill_the_grid();
        cout << "1. Play with a friend\n2. Play with the computer\n";
        cin >> choice;
        if (cin.fail())
        {
            cout << "Invalid input.Please try again.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            if (choice == 1) // Human VS Human.
            {
                cout << "\033[33mChoose your character 'X' or 'O' !\033[37m\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            a:
                while (1)
                {
                    cout << "1. Player 1: ";
                    getline(cin, p1);
                    if (p1.size() != 1)
                        cout << "Invalid input.Please try again.\n\n";
                    else
                        break;
                }
                if (Check_Symbol(p1) == 0)
                {
                    cout << "Incorrect symbol.Please try again.\n\n";
                    goto a;
                }
            b:
                while (1)
                {
                    cout << "2. Player 2: ";
                    getline(cin, p2);
                    if (p2.size() != 1)
                        cout << "Invalid input.Please try again.\n\n";
                    else
                        break;
                }
                if (Check_Symbol(p2) == 0)
                {
                    cout << "Incorrect symbol.Please try again.\n\n";
                    goto b;
                }
                if (p2 == p1 || p1[0] == p2[0] - 32 || p1[0] == p2[0] + 32)
                {
                    cout << "This symbol is already taken, please choose another symbol.\n\n";
                    goto b;
                }
                for (short i = 1; i <= 9; i++)
                {
                    Print_grid(p1, p2);
                    if (flag)
                    {
                    c:
                        cout << "\nPlayer 1:\nEnter the place you want to play: ";
                        cin >> pl;
                        if (cin.fail())
                        {
                            cout << "Invalid input.Please try again.\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            goto c;
                        }
                        else
                        {
                            if (pl < 1 || pl > 9)
                            {
                                cout << "Invalid place.Please choose right one.\n";
                                goto c;
                            }
                            else
                            {
                                if (Check_if_the_place_is_free(pl, p1) == 0)
                                {
                                    cout << "The place you have chosen is already taken, please choose another place.\n";
                                    goto c;
                                }
                                if (Check_Win())
                                {
                                    winner = "Player 1";
                                    break;
                                }
                            }
                        }
                        flag = 0;
                    }
                    else
                    {
                    d:
                        cout << "\nPlayer 2:\nEnter the place you want to play: ";
                        cin >> pl;
                        if (cin.fail())
                        {
                            cout << "Invalid input.Please try again.\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            goto d;
                        }
                        else
                        {
                            if (pl < 1 || pl > 9)
                            {
                                cout << "Invalid place.Please choose right one.\n";
                                goto d;
                            }
                            else
                            {
                                if (Check_if_the_place_is_free(pl, p2) == 0)
                                {
                                    cout << "The place you have chosen is already taken, please choose another place.\n";
                                    goto d;
                                }
                                if (Check_Win())
                                {
                                    winner = "Player 2";
                                    break;
                                }
                            }
                        }
                        flag = 1;
                    }
                }
                Print_grid(p1, p2);
            }
            else if (choice == 2) // Human VS Computer.
            {
                short r = 0;
                char ch[2] = {'0', '0'}; // The array that contain the remaining characters where the computer will choose randomly from.
                srand(time(0));          // To change the random value choosen by computer every time the user runs the program.
                cout << "\033[33mChoose your character 'X' or 'O' !\033[37m\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            x:
                while (1)
                {
                    cout << "Player 1: ";
                    getline(cin, p1);
                    if (p1.size() != 1)
                        cout << "Invalid input.Please try again.\n\n";
                    else
                        break;
                }
                if (Check_Symbol(p1) == 0)
                {
                    cout << "Incorrect symbol.Please try again.\n\n";
                    goto x;
                }
                if (p1 == "x" || p1 == "X")
                    ch[0] = 'o', ch[1] = 'O';
                else
                    ch[0] = 'x', ch[1] = 'X';
                r = rand() % 2; // Choose numbers randomly between [0,1].
                p2.push_back(ch[r]);
                for (short i = 1; i <= 9; i++)
                {
                    if (flag)
                    {
                        Print_grid(p1, p2);
                    y:
                        cout << "\nPlayer 1:\nEnter the place you want to play: ";
                        cin >> pl;
                        if (cin.fail())
                        {
                            cout << "Invalid input.Please try again.\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            goto y;
                        }
                        else
                        {
                            if (pl < 1 || pl > 9)
                            {
                                cout << "Invalid place.Please choose right one.\n";
                                goto y;
                            }
                            else
                            {
                                if (Check_if_the_place_is_free(pl, p1) == 0)
                                {
                                    cout << "The place you have chosen is already taken, please choose another place.\n";
                                    goto y;
                                }
                                if (Check_Win())
                                {
                                    winner = "Player 1";
                                    break;
                                }
                            }
                        }
                        flag = 0;
                    }
                    else
                    {
                    z:
                        pl = rand() % 9 + 1; // Choose numbers randomly between [1,9].
                        if (Check_if_the_place_is_free(pl, p2) == 0)
                            goto z;
                        if (Check_Win())
                        {
                            winner = "Computer";
                            break;
                        }
                        flag = 1;
                    }
                }
                Print_grid(p1, p2);
            }
            else
            {
                cout << "Invalid choice.Please try again.\n\n";
                continue;
            }
            // Print here the message who is winner.
            if (winner == "")
                cout << "\033[35m\nDraw.No Winner This Time!\033[37m";
            else if (winner == "Computer")
                cout << "\033[32mArtificial Intelligence Dominates!\033[34m Computer is the winner!\033[37m\n";
            else
                cout << "\033[32m\nCongratulations\033[37m the winner is \033[34m" + winner;
            cout << "\033[31m\n\nGame over.\033[37m";
        e:
            cout << "\n1. Play again!\n2. Exit\n";
            cin >> choice;
            if (cin.fail())
            {
                cout << "Invalid input.Please try again.\n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                goto e;
            }
            else if (choice == 1)
                continue;
            else if (choice == 2)
            {
                cout << "\033[34mThank you for using our Tic-Tac-Toe game app.We hope you enjoyed.See you soon!\n\033[37m";
                // "\033[34m" => sets the statement to color red.
                // "\033[37m"  => reset the rest of the statements to default.
                break;
            }
            else
            {
                cout << "Invalid choice.Please try again.\n\n";
                goto e;
            }
        }
    }
}
int main()
{
    Main_System();
    return 0;
}