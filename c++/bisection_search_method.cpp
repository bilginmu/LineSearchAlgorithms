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


double bisection(double xLower, double xUpper){
    // Bisection search method to find minimum of function
    // Parameters:
    //      :xUpper: initial value of upper limit
    //      :xLower: initial value of lower limit

    std::clock_t start;
    start = std::clock();

    int itr = 0; 
    double xMid, error = MAX;
    while(error > exp10(-5)){
        xMid = (xUpper + xLower) / 2;

        if (dfunc(xMid) > 0){
            xUpper = xMid;
        }
        else{
            xLower = xMid;
        }
        itr++;
        error = fabs(xUpper - xLower);
    } 

    std::cout << "Bisection Search Method" << std::endl;
    std::cout << "Time : " << (std::clock() - start) / (double)CLOCKS_PER_SEC << std::endl;
    std::cout << "Iteration : " << itr << std::endl;
    std::cout << "Minimum point of function : " << "x = " << xMid << ", f(x) = " << func(xMid) << std::endl;

    return xMid;
}


int main(){
    double xLower = 1;
    double xUpper = 2;
    bisection(xLower, xUpper);

    return 0;
}