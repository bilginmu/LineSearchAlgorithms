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


double ddfunc(double x){
    // Second derivative of minimized function
    return 2 - 4 * cos(x);
}

double newtons(double xPrev){
    // Implementation of newtons method 
    // Parameters:
    //      :xPrev: initial value of x
    std::clock_t start;
    start = std::clock();

    int iter = 0;
    double xNew, error = MAX;

    while (error > exp10(-5)){
        xNew = xPrev - dfunc(xPrev) / ddfunc(xPrev);
        error = fabs(xNew - xPrev);
        xPrev = xNew;
        iter++;
    }
    
    std::cout << "Newton's Method" << std::endl;
    std::cout << "Iteration : " << iter << std::endl;
    std::cout << "Computation Time : "  << std::clock() - start << std::endl;
    std::cout << "Minimum point of function : " << "x = " << xNew << ", f(x) = " << func(xNew) << std::endl; 

    return xNew;
}


int main(){


    newtons(1);

    return 0;
}