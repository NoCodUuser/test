#include <iostream>

int switch_players(int _current_player)
{
    if(_current_player == 1)
        return 2;
    else
        return 1;
}

char get_players_symbol(int _player_number)
{
    if(_player_number == 1)
        return 'X';
    else if(_player_number == 2)
        return 'O';
    else
        return ' ';
}

void fill_field_with(int _field[3][3], int _value)
{
    for(unsigned int x = 0; x < 3; ++x)
    {
        for(unsigned int y = 0; y < 3; ++y)
        {
            _field[x][y] = _value;
        }
    }
}

void print_field(int _field[3][3])
{
    std::cout << "   +-----+-----+-----+" << std::endl;
    for(unsigned int x = 0; x < 3; ++x)
    {
        std::cout << "   |     |     |     |" << std::endl;
        std::cout << 2 - x << "  |";
        for(unsigned int y = 0; y < 3; ++y)
        {
            std::cout << "  " << get_players_symbol(_field[y][2 - x]) << "  |";
        }
        std::cout << std::endl;
        std::cout << "   |     |     |     |" << std::endl;
        std::cout << "   +-----+-----+-----+" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "      0     1     2   " << std::endl;
    std::cout << std::endl;
}

int which_player_won(int _field[3][3])
{
    for(unsigned int x = 0; x < 3; ++x)
    {
        bool all_same = true;
        int player = _field[x][0];
        if(player == 0)
            continue;

        for(unsigned int y = 1; y < 3; ++y)
        {
            if(_field[x][y] == player)
                continue;

            all_same = false;
            break;
        }

        if(all_same)
            return player;
    }

    for(unsigned int y = 0; y < 3; ++y)
    {
        bool all_same = true;
        int player = _field[0][y];
        if(player == 0)
            continue;

        for(unsigned int x = 1; x < 3; ++x)
        {
            if(_field[x][y] == player)
                continue;

            all_same = false;
            break;
        }

        if(all_same)
            return player;
    }

    bool all_same = true;
    int player = _field[0][0];

    for(unsigned int index = 1; index < 3; ++index)
    {
        if(_field[index][index] == player)
            continue;

        all_same = false;
        break;
    }

    if(all_same)
        return player;


    all_same = true;
    player = _field[0][2];

    for(unsigned int index = 1; index < 3; ++index)
    {
        if(_field[index][2 - index] == player)
            continue;

        all_same = false;
        break;
    }

    if(all_same)
        return player;

    return 0;
}
