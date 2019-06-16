class Animal {
public: 
    int age;
public: 
    Animal (int _age): age(_age) {}
    ~Animal() {};
};

class dog : public Animal {
public: 
    void setAge (int n) {
        age = n;
    }
};