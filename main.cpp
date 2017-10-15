#include <iostream>
#include <functional>
#include <math.h>

using namespace std;

double cube(double x) {
    return x * x * x;
}

function<double (double)> derive(function<double (double)> fn) {
    function<double (double)> derivative = [fn](double x) {
        double result = (fn(x + 0.00001) - fn(x)) / 0.00001;
        return result;
    };

    return derivative;

}

int main(int argc, char *argv[]) {
    // auto derivative_sin = derive(static_cast<double(*)(double)>(sin));
    auto derivative = derive(cube);

    cout << derivative(atoi(argv[1])) << endl;
}
