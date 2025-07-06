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
    for(int y = 2; y > 0; --y)
    {
        for(int x = 0; x < 2; ++x)
        {
            std::cout << " " << convert_field_element(field[x][y]) << " " << "|";
        }
        std::cout  << " " << convert_field_element(field[2][y]) << std::endl;
        std::cout << "---+---+---" << std::endl;
    }
    for(int x = 0; x < 2; ++x)
    {
        std::cout << " " << convert_field_element(field[x][0]) << " " << "|";
    }
    std::cout  << " " << convert_field_element(field[2][0]) << std::endl;
    std::cout << std::endl;
}

std::string error_message(int coordinate_x, int coordinate_y, int field[3][3])
{
    if(!(coordinate_x >= 0 && coordinate_x <= 2))
    {
        return "you entered wrong coordinate";
    }
    else if(!(coordinate_y >= 0 && coordinate_y <= 2))
    {
        return "you entered wrong coordinate";
    }
    else if(field[coordinate_x][coordinate_y] != 0)
    {
        return "cell is occupied. choose another";
    }
    else
    {
        return "";
    }
}

char convert_field_element(int cell)
{
    if(cell == 0)
    {
        return ' ';
    }
    else if(cell == 1)
    {
        return 'x';
    }
    else
    {
        return 'o';
    }
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

