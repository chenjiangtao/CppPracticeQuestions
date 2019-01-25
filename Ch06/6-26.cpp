// 描述
// 编写一个矩阵转置的函数，矩阵的行数和列数在程序中由用户输入。

#include <iostream>
using namespace std;

class Matrix {
public: 
    Matrix(int _r, int _c, int *_p);
    ~Matrix() {};
    void transpose();
    void getMatrix();
private: 
    int row;
    int column;
    int *p;
};

Matrix :: Matrix(int _r, int _c, int *_p) {
    this->row = _r;
    this->column = _c;
    this->p = _p;
}

void Matrix :: transpose() {
    int temp;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < i; j++) {
            temp = *(p + i * column + j);
            *(p + i * column + j) = *(p + j * column + i);
            *(p + j * column + i) = temp;
        }
    }
    temp = row;
    row = column;
    column = temp;
}

void Matrix :: getMatrix() {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cout<<*(p + i * column + j)<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int r, c;
    int *p;
    cout<<"请输入行数：";
    cin>>r;
    cout<<"请输入列数：";
    cin>>c;
    p = new int [r * c];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout<<"请输入第"<<i + 1<<"行的第"<<j + 1<<"个数：";
            cin>>p[i * c + j];
        }
    }
    cout<<endl;
    Matrix m(r, c, p);
    cout<<"原矩阵为："<<endl;
    m.getMatrix();
    m.transpose();
    cout<<"转置矩阵为："<<endl;
    m.getMatrix();
    return 0;
}