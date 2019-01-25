// 描述
// 编写一个矩阵转置的函数，矩阵的行数和列数在程序中由用户输入。

#include <iostream>
#include <stdlib.h>
using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))

class Matrix {
public: 
    Matrix(int _r, int _c, int **_p);
    ~Matrix() {};
    void input();
    void transpose();
    void retrive();
private: 
    int row;
    int column;
    int **p;
};

Matrix :: Matrix(int _r, int _c, int **_p) {
    this->row = _r;
    this->column = _c;
    this->p = _p;
}

void Matrix :: input() {
    int max = max(row, column);
    p = new int * [max];
    for(int i = 0; i < max; i++) {
        p[i] = new int [max];
    }
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cout<<"请输入第"<<i + 1<<"行的第"<<j + 1<<"个数：";
            cin>>p[i][j];
        }
    }
}

void Matrix :: transpose() {
    int temp;
    int max = max(row, column);
    for(int i = 0; i < max; i++) {
        for(int j = 0; j < i; j++) {
            temp = p[i][j];
            p[i][j] = p[j][i];
            p[j][i] = temp;
        }
    }
    temp = row;
    row = column;
    column = temp;
}

void Matrix :: retrive() {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int r, c;
    int **p;
    cout<<"请输入行数：";
    cin>>r;
    cout<<"请输入列数：";
    cin>>c;
    Matrix m(r, c, p);
    m.input();
    cout<<"原矩阵为："<<endl;
    m.retrive();
    m.transpose();
    cout<<"转置矩阵为："<<endl;
    m.retrive();
    return 0;
}