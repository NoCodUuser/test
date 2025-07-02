#include <iostream>

#include <Tools.h>


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
            std::cout << "Player " << current_player << ", you are imbecile: your shit must be between 0 and 2" << std::endl << std::endl;
            continue;
        }

        if(field[index_x][index_y] != 0)
        {
            std::cout << "Player " << current_player << ", you are imbecile: this shit is already occupied" << std::endl << std::endl;
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
