#ifndef _VECTOR_HPP
#define _VECTOR_HPP

#include <iostream>

template <typename T>
class vector {
public:
    vector();                                   // 构造函数声明
    ~vector();                                  // 析构函数声明
    vector(const vector& vec);                  // 拷贝构造函数声明
    vector& operator=(const vector& vec);       // 赋值运算符重载函数声明
    T& operator[](size_t index);                // []运算符重载函数声明
    bool operator==(const vector& vec) const;   // ==运算符重载函数声明
    void push_back(T val);                      // 在容器尾部增加元素声明
    void pop_back();                            // 删除容器尾部的元素声明
    void insert(size_t index, T val);           // 在指定位置插入元素声明
    void erase(size_t index);                   // 删除指定位置的元素声明
    T front() const;                            // 取出第一个元素声明
    T back() const;                             // 取出最后一个元素声明
    T* begin();                                 // 获取元素首地址声明
    T* end();                                   // 获取元素末尾地址声明
    size_t size() const;                        // 获取元素个数声明
    size_t capacity() const;                    // 获取容器容量声明
    bool empty() const;                         // 判断容器是否为空声明
    void print() const;                         // 打印容器元素声明
    void clear();                               // 清空容器并释放内存声明

private:
    T* data;
    size_t size_;
    size_t capacity_;
    void expandCapacity();                      // 扩展容器容量声明
};

//#include "E:/vector/src/vector.cpp"



template class vector<int>;
#endif
