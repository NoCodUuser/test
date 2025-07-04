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

bool is_line_winning(int cell_0, int cell_1, int cell_2)
{
    if(cell_0 != 0 && cell_0 == cell_1 && cell_0 == cell_2)
    {
        return true;
    }

    return false;
}

bool has_someone_won(int field[3][3])
{
    if(is_line_winning(field[0][0], field[1][0], field[2][0]))
    {
        return true;
    }
    else if(is_line_winning(field[0][1], field[1][1], field[2][1]))
    {
        return true;
    }
    else if(is_line_winning(field[0][2], field[1][2], field[2][2]))
    {
        return true;
    }
    else if(is_line_winning(field[0][0], field[0][1], field[0][2]))
    {
        return true;
    }
    else if(is_line_winning(field[1][0], field[1][1], field[1][2]))
    {
        return true;
    }
    else if(is_line_winning(field[2][0], field[2][1], field[2][2]))
    {
        return true;
    }
    else if(is_line_winning(field[0][2], field[1][1], field[2][0]))
    {
        return true;
    }
    else if(is_line_winning(field[2][2], field[1][1], field[0][0]))
    {
        return true;
    }
    return false;
}
