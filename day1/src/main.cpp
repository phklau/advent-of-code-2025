#include <iostream>
#include <fstream>
#include <vector>
#include <string>

const std::string filepath = "../input.txt";
// const std::string filepath = "../test.txt";
const int startPos = 50;

struct dialMovement
{
    uint turn;
    int direction;
};

long mod(long a, long b)
{ return (a%b+b)%b; }

int main()
{
    std::vector<dialMovement> movements;

    std::string line;
    std::ifstream file(filepath);

    if (file.is_open()) {
    // read in file input, struct?
            while (getline(file, line)) {
                dialMovement movement;
                if (char(line[0]) == 'R')
                {
                    movement.direction = 1;
                }
                if (char(line[0]) == 'L')
                {
                    movement.direction = -1;
                }

                line.erase(0,1);
                movement.turn = std::stoi(line);
                // std::cout << movement.turn << std::endl;
                movements.push_back(movement);
            }
        file.close();
    }
    else
    {
        std::cout << "File in "<< filepath << " not found!" << std::endl;
        return 1;
    }
    // iterate input: R=+, L=-, %100? 
        // if pos=0 count up
    int pos = startPos;
    int zeroPositions = 0;
    for (auto movement=movements.begin(); movement!=movements.end(); ++movement)
    {
        pos =  pos + ((*movement).direction * (*movement).turn);
        pos = mod(pos, 100);
        if(pos == 0)
        {
            zeroPositions++;
        }
        // std::cout << (*movement).direction * (*movement).turn << " pos: " << pos << std::endl;
    }
    std::cout << "Part1: " <<zeroPositions<< std::endl;
    return 0;
}