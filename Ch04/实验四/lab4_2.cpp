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

class RAM {
public: 
    RAM () {
        cout << "RAM constructor..." << endl;
    }
    ~RAM () {
        cout << "RAM destructor..." << endl;
    }
    void Run() {
        cout << "RAM starts running!" << endl;
    }
    void Stop() {
        cout << "RAM just finished running!" << endl;
    }
};

class CDROM {
public: 
    CDROM () {
        cout << "CDROM constructor..." << endl;
    }
    ~CDROM () {
        cout << "CDROM destructor..." << endl;
    }
    void Run() {
        cout << "CDROM starts running!" << endl;
    }
    void Stop() {
        cout << "CDROM just finished running!" << endl;
    }
};

class Computer {
private: 
    CPU cpu;
    RAM ram;
    CDROM cdrom; 
public: 
    Computer (CPU _cpu, RAM _ram, CDROM _cdrom): cpu(_cpu), ram(_ram), cdrom(_cdrom) {
        cout << "Computer constructor..." << endl;
    }
    ~Computer () {
        cout << "Computer destructor..." << endl;
    }
    void Run() {
        cout << "Computer starts running!" << endl;
        cpu.Run();
        ram.Run();
        cdrom.Run();
    }
    void Stop() {
        cpu.Stop();
        ram.Stop();
        cdrom.Stop();
        cout << "Computer just finished running!" << endl;
    }
};

int main() {
    CPU a(P6, 300, 2.8);
    RAM b;
    CDROM c;
    Computer comp(a, b, c);
    comp.Run();
    comp.Stop();
    return 0;
}

// CPU constructor...
// RAM constructor...
// CDROM constructor...
// Computer constructor...
// CDROM destructor...
// RAM destructor...
// CPU destructor...
// Computer starts running!
// CPU starts running!
// RAM starts running!
// CDROM starts running!
// CPU just finished running!
// RAM just finished running!
// CDROM just finished running!
// Computer just finished running!
// Computer destructor...
// CDROM destructor...
// RAM destructor...
// CPU destructor...
// CDROM destructor...
// RAM destructor...
// CPU destructor...