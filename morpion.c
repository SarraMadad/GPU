#include <stdio.h>

void print_table(char table[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("|");
        for (int j = 0; j < 3; j++)
        {
            printf(" %c |", table[i][j]);
        }
        printf("\n");
    }
}

int check_availability(char table[3][3], int x, int y)
{
    if (x < 0 || y < 0 || x > 2 || y > 2)
    {
        printf("Please enter a valid position ([0 <= x < 3][0 <= y < 3])\n");
        return 0;
    }
    if (table[x][y] != '.')
    {
        printf("This case is already taken, please choose somewhere else\n");
        return 0;
    }
    return 1;
}

int check_win_rec(char table[3][3], char c, int dir, int x, int y)
{
    if (x < 0 || y < 0 || x > 2 || y > 2 || table[x][y] != c)
        return 0;
    if (dir == 1 || dir == 2)
        x++;
    if (dir == 2 || dir == 3 || dir == 4)
        y++;
    if (dir == 4)
        x--;
    return 1 + check_win_rec(table, c, dir, x, y);
}

int check_win(char table[3][3], int player)
{
    char c = player == 1 ? 'X' : 'O';
    if (check_win_rec(table, c, 1, 0, 0) == 3)
        return 1;
    if (check_win_rec(table, c, 2, 0, 0) == 3)
        return 1;
    if (check_win_rec(table, c, 3, 0, 0) == 3)
        return 1;
    if (check_win_rec(table, c, 1, 1, 0) == 3)
        return 1;
    if (check_win_rec(table, c, 1, 2, 0) == 3)
        return 1;
    if (check_win_rec(table, c, 3, 0, 1) == 3)
        return 1;
    if (check_win_rec(table, c, 3, 0, 1) == 3)
        return 1;
    if (check_win_rec(table, c, 4, 0, 1) == 3)
        return 1;
    return 0;
}

void play(char table[3][3], int player)
{
    char c = player == 1 ? 'X' : 'O';
    int x;
    int y;
    do
    {
        printf("Please enter where you want to play\n");
        printf("x: ");
        if (!scanf("%d", &x))
            x = -1;
        else
        {
            printf("y: " );
            if (!scanf("%d", &y))
                y = -1;
        }
    }
    while (!check_availability(table, x, y));
    table[x][y] = c;
}

void party(void)
{
    char table[3][3] = { {'.', '.', '.' }, {'.', '.', '.' }, {'.', '.', '.' } };
    for (int i = 0; i < 9; i++)
    {
        int player = (i % 2) + 1;
        printf("Player %d turn\n", player);
        print_table(table);
        play(table, player);
        if (check_win(table, player))
        {
            printf("Player %d win!\n", player);
            print_table(table);
            return;
        }
        printf("\n");
    }
}

int main(void)
{
    party();
    return 0;
}
