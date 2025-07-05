#include <tic_tac_toe.h>
#include <iostream>

void reset_field(int field[3][3])
{
    for(int i = 0; i < 3; ++i)
    {
        for(int i2 = 0; i2<3; ++i2)
        {
            field[i][i2] = 0;
        }
    }
}

void print_field(int field[3][3])
{
    for(int y = 2; y > -1; --y)
    {
        for(int x = 0; x < 3; ++x)
        {
            std::cout << field[x][y] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void switch_player(int& current_player)
{
    if(current_player == 1)
    {
        current_player = 2;
    }
    else
    {
        current_player = 1;
    }
}

bool should_break(int field[3][3])
{
    for(int i = 0; i < 3; ++i)
    {
        for(int i2 = 0; i2 < 3; ++i2 )
        {
            if(field[i][i2] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

