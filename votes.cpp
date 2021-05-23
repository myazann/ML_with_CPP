//g++ votes.cpp -std=c++17 -larmadillo -lmlpack -lstdc++fs -fopenmp


#include <iostream>
#include <mlpack/core.hpp>
#include <mlpack/methods/kmeans/kmeans.hpp>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;
using namespace mlpack;
using namespace mlpack::data;
using namespace mlpack::kmeans;

typedef arma::mat mat;

int main(){
    
    const std::string file_name("/home/jovyan/elections/votes.csv");
    mat dataset;
    mlpack::data::DatasetInfo info;
    std::stringstream str_stream;
    
    std::ifstream file(file_name);
    
    if (!file.is_open()) {
        std::cerr << "cannot open inputFile.txt\n";
        return -1;
    }
    
    std::string first_row, col;
    std::map<int, std::string> col_names;
    
    getline(file, first_row);
    str_stream << first_row;
    int i = 0;
        
    
    while(str_stream.good()){
        getline(str_stream, col, ',');
        //std::cout << col << '\n';
        col_names.insert({i, col});
        ++i;
        
    }
    
    for(auto elem:col_names)
        std::cout << elem.first << ": " << elem.second << '\n'; 
    
    Load(file_name, dataset, info, true, false);
    
    std::cout << dataset.n_rows << '\n';

    
    return 0;
}