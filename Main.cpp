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

int main()
{
    int field[3][3];
    fill_field_with(field, 0);
    print_field(field);

    int current_player = 1;

    unsigned int moves_made = 0;
    bool game_is_finished = false;
    while(!game_is_finished)
    {
        int index_x = 0;
        int index_y = 0;

        std::cout << "Player number " << current_player << ", enter your shit (column, row): ";
        std::cin >> index_x >> index_y;
        std::cout << std::endl;

        if(index_x < 0 || index_x > 2 || index_y < 0 || index_y > 2)
        {
            std::cout << "Player " << current_player << ", you are imbecile: cell index must be between 0 and 2" << std::endl << std::endl;
            continue;
        }

        if(field[index_x][index_y] != 0)
        {
            std::cout << "Player " << current_player << ", you are imbecile: cell is already occupied" << std::endl << std::endl;
            continue;
        }

        ++moves_made;

        field[index_x][index_y] = current_player;

        print_field(field);

        int winner = which_player_won(field);
        if(winner == 1 || winner == 2)
        {
            std::cout << "Player " << winner << " won!" << std::endl << std::endl;
            break;
        }

        if(moves_made == 9)
        {
            std::cout << "Draw!" << std::endl << std::endl;
            break;
        }

        current_player = switch_players(current_player);
    }

    std::string wait_input;
    std::cin >> wait_input;
    if(wait_input != "poshel_nahui")
        return 0;

    std::cout << "sam poshel nahui" << std::endl;
    std::cin >> wait_input;
    std::cout << std::endl;

    return 0;
}
