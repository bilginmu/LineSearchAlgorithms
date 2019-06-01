clear all
clc
tic 

% Initial Values
x_lower = 1;
x_upper = 2;
eps = 100;
iter = 0; % iteration number

% Bisection Algorithm
func = @(x) x^2 + 4*cos(x);   
d_func = @(x) 2*x - 4*sin(x); % derivative of function
while (eps > 10^-5)
    
    x_mid = (x_lower + x_upper)/2; 
    
    if (d_func(x_mid) > 0)
        x_upper = x_mid; 
    elseif(d_func(x_mid) < 0)
        x_lower = x_mid;
    end
    
    iter = iter + 1; 
    eps = x_upper - x_lower; 
end

timeElapsed = toc;

fprintf("\tBisection Search Method\n")
fprintf("Iteration : %d\n",iter);
fprintf("Computation time : %f\n",timeElapsed);
fprintf("Minimum point of function : x = %f, f(x) = %f\n",x_mid,func(x_mid));
