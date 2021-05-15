#include "/dlib/dlib/matrix.h"
#include <eigen3/Eigen/Dense>
#include <filesystem>
#include <regex>
#include <ctime>
#include <sstream>

namespace fs = std::filesystem;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Eigen_DynMat;

int main() {
    
    std::cout << "Trying matrix implementations of different libraries. \n";
    
    auto m1 = dlib::identity_matrix <double> (3);
    auto m2 = dlib::randm(3, 1);

    std::cout << "Dlib Matrix:" << '\n';
    std::cout << "First matrix: \n" << m1 << "\nSecond matrix: \n" << m2 << "\nMultiplication: \n" <<  m1*m2 << '\n';

    Eigen::Matrix<double, 3, 3> e1 = Eigen::Matrix<double, 3, 3>::Random();
    Eigen::Matrix<double, 3, 3> e2 = Eigen::Matrix<double, 3, 3>::Identity();

    std::cout << "Eigen Matrix:" << '\n';
    std::cout << "First matrix: \n" << e1 << "\nSecond matrix: \n" << e2 << "\nMultiplication: \n" << 
                                                                             e1.array()*e2.array() << '\n';
    
    
    const fs::path file_name("/home/jovyan/Hands-On-Machine-Learning-with-CPP/Chapter02/data/iris.csv");
    
    std::cout << "Reading the Iris dataset: \n";
    
    if(fs::exists(file_name)){
     
        std::cout << "File Exists!\n";
        std::ifstream file(file_name);
        
        if (!file.is_open()) {
            std::cerr << "cannot open inputFile.txt\n";
            return -1;
        }
        
        std::string tp;
        std::string temp;
        
        clock_t begin_time;
        float wif_time{0};
        float if_time{0};
        
        dlib::matrix<double> data;
        std::stringstream str_stream;
        
        while(getline(file, tp)){
            
            std::cout << tp << "\n";

            begin_time = std::clock();
            
            temp = std::regex_replace(tp, std::regex("Iris-setosa"), "1");
            temp = std::regex_replace(tp, std::regex("Iris-versicolor"), "2");
            temp = std::regex_replace(tp, std::regex("Iris-virginica"), "3");
            
            wif_time += float(std::clock() - begin_time)/CLOCKS_PER_SEC;
            

            begin_time = std::clock();
            if(tp.find("Iris-setosa") != std::string::npos)
                temp = std::regex_replace(tp, std::regex("Iris-setosa"), "1");
            else if(tp.find("Iris-versicolor") != std::string::npos)
                temp = std::regex_replace(tp, std::regex("Iris-versicolor"), "2");
            else
                temp = std::regex_replace(tp, std::regex("Iris-virginica"), "3"); 
            
            if_time += float(std::clock() - begin_time)/CLOCKS_PER_SEC;
            
            str_stream << temp + '\n';
                      
          }
        
        file.close();              
        std::cout << "Without If: " << wif_time << '\n';
        std::cout << "With If: " << if_time << '\n'; 
        
        str_stream >> data;
        dlib::matrix<double> x_data = dlib::subm(data, 0, 0, data.nr()-1, data.nc());

        std::cout << data;
        std::cout << "Row num: " << data.nr() << " Col num: " << data.nc() << '\n';
    }
    
    else
        std::cout << "File not found!" << '\n';

    return 0;
    
}