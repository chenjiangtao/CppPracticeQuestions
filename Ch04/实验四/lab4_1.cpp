#include <iostream> 
using namespace std;

enum CPU_Rank {
    P1 = 1,
    P2,
    P3,
    P4,
    P5,
    P6,
    P7
};

class CPU {
protected: 
    CPU_Rank rank;
    int frequency;
    float voltage;
public: 
    CPU (CPU_Rank _rank, int _frequency, float _voltage): rank(_rank), frequency(_frequency), voltage(_voltage) {
        cout << "CPU constructor..." << endl;
    }
    ~CPU () {
        cout << "CPU destructor..." << endl;
    }
    CPU_Rank getRank() {
        return rank;
    }
    int getFrequency() {
        return frequency;
    }
    float getVoltage() {
        return voltage;
    }
    void setRank(CPU_Rank r) {
        rank = r;
    }
    void setFrequency(int f) {
        frequency = f;
    }
    void setVoltage(float v) {
        voltage = v;
    }
    void Run() {
        cout << "CPU starts running!" << endl;
    }
    void Stop() {
        cout << "CPU just finished running!" << endl;
    }
};

int main() {
    CPU a(P6, 300, 2.8);
    a.Run();
    a.Stop();
}