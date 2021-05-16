#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

int main(){
    
    const std::string file_path = "/home/jovyan/Hands-On-Machine-Learning-with-CPP/Chapter02/data/reviews.json";
    json reviews;
    
    std::ifstream reviews_file(file_path, std::ifstream::binary);
    reviews_file >> reviews;
    
    std::cout << reviews << '\n';
    
    return 0;
    
}