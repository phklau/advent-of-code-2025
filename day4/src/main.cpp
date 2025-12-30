#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char** argv) 
{
    if (argc != 2)
    {
        std::cout << "No or wrong input provided" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file.is_open())
    {
        std::cout << "File " << argv[1] << "couldn't be opened" << std::endl;
        return 1;
    }

    cv::Mat grid;
    std::string line;
    while(getline(file, line))
    {
        // std::vector<int> row;
        cv::Mat row;
        for(auto c=line.begin(); c!=line.end(); c++)
        {
            switch (*c)
            {
                case '.':
                    row.push_back(static_cast<uint8_t>(0));
                    break;
                case '@':
                    row.push_back(static_cast<uint8_t>(1));
                    break;
                default:
                    return 1;
            }
        }
      //  for (auto const& c : row)
      //  std::cout << c << ' ';
      //  std::cout << std::endl;
        row = row.t();
    //    std::cout << cv::format(row, cv::Formatter::FMT_C     ) << std::endl;
        grid.push_back(row);
    }
    //std::cout << grid.at<int>(1,0) << std::endl;
    std::cout << grid.type() << std::endl;
    std::cout << grid.rows << std::endl;
    std::cout << grid.cols << std::endl;
    std::cout << cv::format(grid, cv::Formatter::FMT_C     ) << std::endl;


    cv::Mat kernel = (cv::Mat_<uint8_t>(3,3) << 1, 1, 1, 1, 10, 1, 1, 1, 1);
    cv::Mat filteredGrid;
    cv::filter2D(grid, filteredGrid, -1, kernel, cv::Point( -1, -1 ), 0, cv::BORDER_CONSTANT);
    std::cout << cv::format(filteredGrid, cv::Formatter::FMT_C     ) << std::endl;

    int pullableRolls = std::count_if(filteredGrid.begin<uint8_t>(), filteredGrid.end<uint8_t>(), [](uint8_t i) { return i >= 10 && i<14; });
    std::cout << "Part 1: " << pullableRolls << std::endl;
    return 0;
}