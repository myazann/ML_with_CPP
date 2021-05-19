//g++ code.cpp -larmadillo -lmlpack -fopenmp


#include <iostream>
#include <mlpack/core.hpp>

using namespace mlpack;
using namespace mlpack::data;

int main(){
    
    arma::mat dataset;
    mlpack::data::DatasetInfo info;

    const std::string file_name("/home/jovyan/Hands-On-Machine-Learning-with-CPP/Chapter02/data/iris.csv");
    
    Load(file_name, dataset, info);
    dataset = dataset.t();
        
    std::cout << dataset.col(dataset.n_cols-1) << '\n';
        
    return 0;

}