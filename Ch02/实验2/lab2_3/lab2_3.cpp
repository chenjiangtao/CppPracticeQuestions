#include <iostream> 
using namespace std;

const float PI = 3.1416;

int main() {
    int iType;
    float area;
    cout << "图形的类型为？（1-圆形 2-长方形 3-正方形）";
    cin >> iType;
    switch (iType) {
        case 1: 
            cout << "请输入半径：";
            float r;
            cin >> r;
            area = r * r * PI;
            cout << "面积为：" << area << endl;
            break;
        case 2:
            float a, b;
            cout << "矩阵的长为：";
            cin >> a;
            cout << "矩阵的宽为：";
            cin >> b;
            area = a * b;
            cout << "面积为：" << area << endl;
            break;
        case 3:
            cout << "正方形的边长为：";
            float n;
            cin >> n;
            area = n * n;
            cout << "面积为：" << area << endl;
            break;
        default: 
            cout << "不是合法输入值！" << endl;
    }
    return 0;
}