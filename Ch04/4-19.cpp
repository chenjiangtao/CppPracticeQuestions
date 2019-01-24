// 描述
// 编写一个名为 CPU 的类，描述一个 CPU 的以下信息：
// 时钟频率，最大不会超过3000MHz；
// 字长，可以是32位或64位；
// 核数，可以是单核、双核或四核；
// 是否支持超线程。
// 各项信息要求使用位域来表示。通过输出 sizeof(CPU) 来观察该类所占字节数。



#include <iostream>
using namespace std;

enum Words {bit32, bit64};
enum Core {single, dual, quad};
enum HyperThread {support, notsupport};

class CPU {
public: 
    CPU(unsigned frequence, Words length, Core CoreType, HyperThread mode)
        : frequence(frequence), length(length), CoreType(CoreType), mode(mode) {}
    void show() {
        cout<<"Time Frequence: "<<frequence<<" MHz"<<endl;
        cout<<"Core Type: ";
        switch(CoreType) {
            case single: cout<<"Single Core"<<endl; break;
            case dual: cout<<"Dual Core"<<endl; break;
            case quad: cout<<"Quad Core"<<endl; break;
        }
        cout<<"Word Length: ";
        switch(length) {
            case bit32: cout<<"32-bit"<<endl; break;
            case bit64: cout<<"64-bit"<<endl; break;
        }
        cout<<"Hyperthread: ";
        switch(mode) {
            case support: cout<<"support"<<endl; break;
            case notsupport: cout<<"not support"<<endl; break;
        }
    }
private: 
    unsigned frequence: 32;
    Core CoreType: 3;
    Words length: 2;
    HyperThread mode: 2;
};

int main()
{
    CPU cpu(3000, bit64, quad, support);
    cout<<"Size of CPU: "<<sizeof(CPU)<<endl;
    cpu.show();
    return 0;
}