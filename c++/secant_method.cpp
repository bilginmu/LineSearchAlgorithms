#include <bits/stdc++.h>

#define MAX 99999

double func(double x){
    // Function to minimize, this can be changed to any function.
    // Parameters:
    //      :x: variable of function
    return x * x + 4 * cos(x);   
}


double dfunc(double x){
    // Derivative of minimized function
    return 2 * x - 4 * sin(x);
}


double secant(double xPrev){

    std::clock_t start;
    start = std::clock();

    int iter = 0;
    double eps = 0.0001; // epsilon value for derivation
    double xNew, error = MAX;

    while (error > exp10(-5)){

        double ddfunc = (dfunc(xPrev + eps) - dfunc(xPrev - eps)) / (2*eps); // centered difference approximation
        xNew = xPrev - dfunc(xPrev) / ddfunc;         
        error = fabs(xNew - xPrev);
        xPrev = xNew;
        iter++;
    }

    std::cout << "Secant Method" << std::endl;
    std::cout << "Iteration : " << iter << std::endl;
    std::cout << "Computation Time : "  << std::clock() - start << std::endl;
    std::cout << "Minimum point of function : " << "x = " << xNew  << ", f(x) = " << func(xNew) << std::endl; 

    return xPrev;
}


int main(){
    secant(1.00);



    return 0;
}