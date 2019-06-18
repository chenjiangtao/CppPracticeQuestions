#include <fstream>
#include <string>

using std::string;
using std::fstream;
using std::ofstream;

int main(int argc, char* argv[]) {
    fstream in_file(argv[1]);
    ofstream cout(argv[2]); 
    string line;
    while (getline(in_file, line)) {
        cout << line << std::endl;
    }
    return 0;
}