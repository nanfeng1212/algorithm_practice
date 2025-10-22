#include<iostream>

int main(){
    int x = 10;
    int y = 5;
    int z = (x > y ? x : y) = 20;  // 歧义：编译器无法确定是否是条件运算符的赋值
    std::cout << z << '\n';
    return 0;
}