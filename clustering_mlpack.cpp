//g++ clustering_mlpack.cpp -larmadillo -lmlpack -fopenmp


#include <iostream>
#include <mlpack/core.hpp>
#include <mlpack/methods/kmeans/kmeans.hpp>

using namespace mlpack;
using namespace mlpack::data;
using namespace mlpack::kmeans;

typedef arma::mat mat;

int main(){
    
    const std::string file_name("/home/jovyan/Hands-On-Machine-Learning-with-CPP/Chapter02/data/iris.csv");
    
    mat dataset;
    mlpack::data::DatasetInfo info;
    KMeans<> k;
    arma::Row<size_t> assignments;
    const size_t clusters = 3;
    arma::mat centroids;

    Load(file_name, dataset, info);
    dataset = dataset.t();
    
    k.Cluster(dataset.t(), clusters, assignments, centroids);
    
    
    mat x = dataset.cols(0, dataset.n_cols-2);
    mat y = dataset.col(dataset.n_cols-1);
    
    mat pred_clusters = arma::conv_to<mat>::from(assignments).t();
    
    pred_clusters.replace(1.0, 3.0);
    pred_clusters.replace(2.0, 1.0);
    pred_clusters.replace(3.0, 2.0);
    
        
    mat res = arma::join_rows(y, pred_clusters);
    
    std::cout << "Predicted Clusters vs Real Labels: \n" << res << '\n';
    
    
    //std::cout << arma::join_rows(res, arma::diff(res).col(1)) << '\n';
    
    //arma::join_cols(data, assignments);
    
    //std::cout << centroids << '\n';
        
    //std::cout << dataset.col(dataset.n_cols-1) << '\n';
    
    
        
    return 0;

}