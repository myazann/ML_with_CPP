#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <set>


using json = nlohmann::json;

int main(){
    
    const std::string file_path = "/home/jovyan/Hands-On-Machine-Learning-with-CPP/Chapter02/data/reviews.json";
    json reviews;
    std::vector<std::string> decisions;
    
    std::ifstream reviews_file(file_path, std::ifstream::binary);
    reviews_file >> reviews;
    
    
    for(auto it: reviews["paper"]){
        auto dec = it["preliminary_decision"].get<std::string>();
        dec.erase(std::remove(dec.begin(), dec.end(), '"'), dec.end());
        decisions.push_back(dec);
    }
    
    std::set<std::string> s(decisions.begin(), decisions.end());
    
    for(auto elem:s)
        std::cout << elem << ": " << std::count(decisions.begin(), decisions.end(), elem) << '\n';
    
    return 0;
    
}