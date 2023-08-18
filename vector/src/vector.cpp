#include "E:/vector/include/vector.hpp"

// 构造函数实现
template <typename T>
vector<T>::vector() : data(nullptr), size_(0), capacity_(0) {}

// 析构函数实现
template <typename T>
vector<T>::~vector() {
    clear();
}

// 拷贝构造函数实现
template <typename T>
vector<T>::vector(const vector& vec) : data(nullptr), size_(vec.size_), capacity_(vec.capacity_) {
    if (capacity_ > 0) {
        data = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data[i] = vec.data[i];
        }
    }
}

// 拷贝赋值运算符实现
template <typename T>
vector<T>& vector<T>::operator=(const vector& vec) {
    if (this != &vec) {
        clear();
        size_ = vec.size_;
        capacity_ = vec.capacity_;
        if (capacity_ > 0) {
            data = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                data[i] = vec.data[i];
            }
        }
    }
    return *this;
}


// []运算符重载函数实现
template <typename T>
T& vector<T>::operator[](size_t index) {
    return data[index];
}

// ==运算符重载函数实现
template <typename T>
bool vector<T>::operator==(const vector& vec) const {
    if (size_ != vec.size_) {
        return false;
    }

    for (size_t i = 0; i < size_; ++i) {
        if (data[i] != vec.data[i]) {
            return false;
        }
    }

    return true;
}

// 在容器尾部增加元素实现
template <typename T>
void vector<T>::push_back(T val) {
    if (size_ >= capacity_) {
        expandCapacity();
    }
    data[size_] = val;
    ++size_;
}

// 删除容器尾部的元素实现
template <typename T>
void vector<T>::pop_back() {
    if (size_ > 0) {
        --size_;
    }
}

// 在指定位置插入元素实现
template <typename T>
void vector<T>::insert(size_t index, T val) {
    if (size_ >= capacity_) {
        expandCapacity();
    }

    for (size_t i = size_; i > index; --i) {
        data[i] = data[i - 1];
    }

    data[index] = val;
    ++size_;
}

// 删除指定位置的元素实现
template <typename T>
void vector<T>::erase(size_t index) {
    for (size_t i = index; i < size_ - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size_;
}

// 取出第一个元素实现
template <typename T>
T vector<T>::front() const {
    return data[0];
}

// 取出最后一个元素实现
template <typename T>
T vector<T>::back() const {
    return data[size_ - 1];
}

// 获取元素首地址实现
template <typename T>
T* vector<T>::begin() {
    return data;
}

// 获取元素末尾地址实现
template <typename T>
T* vector<T>::end() {
    return data + size_;
}

// 获取元素个数实现
template <typename T>
size_t vector<T>::size() const {
    return size_;
}

// 获取容器容量实现
template <typename T>
size_t vector<T>::capacity() const {
    return capacity_;
}

// 判断容器是否为空实现
template <typename T>
bool vector<T>::empty() const {
    return size_ == 0;
}

// 打印容器元素实现
template <typename T>
void vector<T>::print() const {
    std::cout << "Elements:";
    for (size_t i = 0; i < size_; ++i) {
        std::cout << " " << data[i];
    }
    std::cout << std::endl;
    std::cout << "Size: " << size_ << std::endl;
}

// 清空容器并释放内存实现
template <typename T>
void vector<T>::clear() {
    if (data) {
        delete[] data;
    }
    data = nullptr;
    size_ = 0;
    capacity_ = 0;
}

// 扩展容器容量实现
template <typename T>
void vector<T>::expandCapacity() {
    size_t newCapacity = capacity_ == 0 ? 1 : capacity_ * 2;
    T* newData = new T[newCapacity];

    for (size_t i = 0; i < size_; ++i) {
        newData[i] = data[i];
    }

    if (data) {
        delete[] data;
    }

    data = newData;
    capacity_ = newCapacity;
}
