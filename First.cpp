#include "/dlib/dlib/matrix.h"
#include <eigen3/Eigen/Dense>
#include <filesystem>

namespace fs = std::filesystem;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Eigen_DynMat;

int main() {
    
    auto m1 = dlib::identity_matrix <double> (3);
    auto m2 = dlib::randm(3, 1);

    std::cout << "Dlib Matrix:" << '\n';
    std::cout << "First matrix: \n" << m1 << "\nSecond matrix: \n" << m2 << "\nMultiplication: \n" <<  m1*m2 << '\n';

    Eigen::Matrix<double, 3, 3> e1 = Eigen::Matrix<double, 3, 3>::Random();
    Eigen::Matrix<double, 3, 3> e2 = Eigen::Matrix<double, 3, 3>::Identity();

    std::cout << "Eigen Matrix:" << '\n';
    std::cout << "First matrix: \n" << e1 << "\nSecond matrix: \n" << e2 << "\nMultiplication: \n" << 
                                                                             e1.array()*e2.array() << '\n';
    
    const fs::path file_name("home/jovyan/Hands-On-Machine-Learning-with-CPP/Chapter02/data/iris.csv");
    
    if(fs::exists(file_name)){
     
        std::cout << "File Exists!" << '\n';
        std::ifstream file(file_name);
        dlib::matrix<double> data;

        file >> data;
        std::cout << data << '\n';
    }
    
    else
        std::cout << "File not found!" << '\n';

    return 0;
    
}