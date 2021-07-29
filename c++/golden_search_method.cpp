#include <bits/stdc++.h>

#define GR ((3 - sqrt(5))/2) // golden ratio

double func(double x){
    // Function to minimize, this can be changed to any function.
    // Parameters:
    //      :x: variable of function
    return x * x + 4 * cos(x);   
}


double goldensection(double aLower, double bUpper){
    // Implementation of golden section search method
    // Parameters:
    //      :aLower: lower limit
    //      :bUpper: upper limit

    int itr = 0;

    std::clock_t start;
    start = std::clock();
    
    double error = bUpper - aLower;
    double aPrev = aLower;
    double bPrev = bUpper;

    double aNew, bNew;
    while (error > exp10(-5)){
        aNew = aPrev + (bPrev - aPrev) * GR; // New lower limit
        bNew = bPrev - (bPrev - aPrev) * GR;

        if (func(bNew) > func(aNew)){
            bPrev = bNew; 
        }
        else if (func(bNew) < func(aNew)){
            aPrev = aNew;
        }

        error = fabs(bPrev - aPrev);
        itr++;
    }

    std::cout << "Golden Section Method" << std::endl;
    std::cout << "Iteration : " << itr << std::endl;
    std::cout << "Computation Time : "  << std::clock() - start << std::endl;
    std::cout << "Minimum point of function : " << "x = " << aNew  << ", f(x) = " << func(aNew) << std::endl; 
    
    return aNew;

}


int main(){


    goldensection(1,2);

    return 0;
}