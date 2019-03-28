#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Equation{
private:
    int _a, _b, _c;
public:
    Equation(int a, int b, int c){
    	_a = a;
    	_b = b;
    	_c = c;
    }
    void solve(){
    	if (_a == 0) {
    		if (_b != 0 ) {
    			cout << "6" << endl;
    			double res = -_c/_b;
    			cout << fixed << setprecision(2) << res;
    			return;
			}
    		if (_c == 0) {
    			cout << "5" << endl;
    			return;
			}
			cout << "4" << endl;
			return;
		}
		double d2 = _b * _b - 4 * _a * _c;
		if (d2 < 0) {
			cout << "3" << endl;
			return;
		}
		if (d2 == 0) {
			cout << "2" << endl;
			double res = -_b / (2 * _a);
			cout << fixed << setprecision(2) << res;
			return;
		}
		cout << "1" << endl;
		double res1, res2;
		res1 = (-_b + sqrt(d2)) / (2 * _a);
		res2 = (-_b - sqrt(d2)) / (2 * _a);
		cout << fixed << setprecision(2) << min(res1, res2) << " " << max(res1, res2) << endl;
		return;
    }
};
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    Equation tmp(a, b, c);
    tmp.solve();
}
