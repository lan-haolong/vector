#include "vector.hpp"
#include <iostream>

int main() {
    vector<int> v;

    // 测试push_back,size函数和capacity函数
    v.push_back(1);
    std::cout<<"capacity:"<<v.capacity()<<std::endl;
    v.push_back(2);
    std::cout<<"capacity:"<<v.capacity()<<std::endl;
    v.push_back(3);
    std::cout<<"capacity:"<<v.capacity()<<std::endl;
    std::cout<<"size:"<<v.size()<<std::endl;
    std::cout << "Elements:";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << " " << v[i];
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // 测试= ==运算符
    vector<int> v1;
    v1 = v;
    v1.print();
    if (v1 == v) {
        std::cout << "Correct" << std::endl;
    }else {std::cout << "Wrong" << std::endl;}
    v1.push_back(4);
    if (v1 == v) {
        std::cout << "Correct" << std::endl;
    }else {std::cout << "Wrong" << std::endl;}
    std::cout << std::endl;

    // 测试[]运算符
    if (v[0] == 1 && v[1] == 2 && v[2] == 3) {
        std::cout << "Correct" << std::endl;
    }else {std::cout << "Wrong" << std::endl;}

    if (v[0] == 3 && v[1] == 2 && v[2] == 3) {
        std::cout << "Correct" << std::endl;
    }else {std::cout << "Wrong" << std::endl;}
    std::cout << std::endl;


    // 测试front和back函数
    if (v.front() == 1 && v.back() == 3) {
        std::cout << "Correct" << std::endl;
    }else {std::cout << "Wrong" << std::endl;}
    std::cout << std::endl;

    // 测试pop_back函数
    v.print();
    v.pop_back();
    v.print();
    std::cout << std::endl;

    // 测试insert函数
    v.insert(1, 4);
    v.print();
    std::cout << std::endl; 

    // 测试erase函数
    v.erase(0);
    v.print();
    std::cout << std::endl;

    // 测试empty函数
    if (!v.empty()) {
        std::cout << "Not empty" << std::endl;
    }else {
        std::cout << "Empty" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Over" << std::endl;
    system("pause");
    return 0;
}
