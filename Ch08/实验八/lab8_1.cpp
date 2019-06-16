class Point {
private: 
    int _x;
    int _y;
public: 
    Point (int x, int y) : _x(x), _y(y) {}
    ~Point () {}
    void operator ++() {
        _x++;
        _y++;
    }
    void operator --() {
        _x--;
        _y--;
    }
};