#include <iostream>
#include <cstdint>
using namespace std;

int main() {
  int divNum = 3;
  // 使用 int64_t 确保固定大小
  int64_t nc = (int64_t(1) << 31) - ((int64_t(1) << 31) % divNum) - 1;
  int64_t p = 32;
  
  // 防止 UB：使用 int64_t 避免整数溢出
  while ((int64_t(1) << p) <= nc * (divNum - ((int64_t(1) << p) % divNum))) {
      if (p >= 63) break; // 防止过度移位
      p++;
  }
  
  int64_t m = (((int64_t(1) << p) + divNum - ((int64_t(1) << p) % divNum)) / divNum);
  
  // 修复点：模拟 Java 无符号位提取
  uint64_t tmp = static_cast<uint64_t>(m);
  int64_t n = static_cast<int64_t>(tmp & 0xFFFFFFFF);
  
  cout << nc << ' ' << m << ' ' << n << ' ' << p << endl;
  return 0;
}