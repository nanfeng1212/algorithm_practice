#include <stdio.h>
#include <math.h>   // 添加 fabsf 用于浮点数绝对值计算
#include <stdlib.h> // 添加 exit 用于错误处理

// 浮点常量定义（显式声明类型）
const float RADIUS = 5.5f;
const float PI = 3.141592653589793f;
const float EPS = 1e-6f;

// 十六进制浮点常量
const float PI_HEX = 0x1.921fb6p+1f;
const float HEX2 = 0x.AP-3f;  // 等价于 0.078125f

// 表达式计算的常量
const float FACT = -33000.0f; // -.33E+5 的实际值
const float EVAL1 = PI * RADIUS * RADIUS;         // 圆面积
const float EVAL2 = 2.0f * PI_HEX * RADIUS;       // 圆周长
const float EVAL3 = PI * 2.0f * RADIUS;            // 等价于 EVAL2

// 隐式类型转换常量
const float CONV1 = 233.0f;
const float CONV2 = 0xfff;     // 十六进制整型转 float (4095.0f)
const int MAX = 1000000000;   // 1e9 的整型表示
const int TWO = 2;            // 2.9 截断为 2
const int THREE = 3;           // 3.2 截断为 3
const int FIVE = TWO + THREE; // 2 + 3 = 5

// 浮点绝对值函数
float float_abs(float x) {
    return (x < 0) ? -x : x;
}

// 整型半径计算圆面积
float circle_area(int radius) {
    float r = (float)radius;  // 整型转浮点
    return (PI * r * r);
}

// 浮点数近似相等判断
int float_eq(float a, float b) {
    return (float_abs(a - b) < EPS) ? 1 : 0;
}

// 简化错误和成功输出函数
void error() {
    fprintf(stderr, "error\n");
    exit(1);  // 出错时退出程序
}

void ok() {
    printf("ok\n");
}

// 断言函数
void assert(int cond) {
    cond ? ok() : error();
}

void assert_not(int cond) {
    cond ? error() : ok();
}

int main() {
    // 测试用例
    assert_not(float_eq(HEX2, FACT));         // 0.078125 != -33000
    assert_not(float_eq(EVAL1, EVAL2));        // 面积 != 周长
    assert(float_eq(EVAL2, EVAL3));            // 两种周长计算应相等
    assert(float_eq(circle_area((int)RADIUS),  // 整型半径计算面积
                   circle_area(FIVE)));        // FIVE=5, 面积应相同
    assert_not(float_eq(CONV1, CONV2));        // 233.0f != 4095.0f

    // 浮点条件表达式测试
    if (1.5f) ok();            // 非零为真
    if (!!3.3f) ok();          // 双重否定仍为真
    if (0.0f && 3) error();    // 0.0 为假
    if (0 || 0.3f) ok();       // 0.3f 为真

    // 替换非标准输入输出函数
    float arr[10] = {1.0f, 2.0f}; // 显式初始化
    int len = 10;                  // 假设数组长度

    for (int p = 0; p < len; ++p) {
        float input;
        if (scanf("%f", &input) != 1) error(); // 标准输入读取浮点

        float area = PI * input * input;
        float area_trunc = circle_area((int)input); // 整型半径

        arr[p] += input; // 更新数组元素

        printf("%f ", area);       // 标准输出浮点
        printf("%d\n", (int)area_trunc); // 浮点转整型输出
    }

    // 输出数组内容
    for (int i = 0; i < len; ++i) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}