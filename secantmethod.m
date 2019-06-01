clear all
clc

tic
% Functions
func = @(x) x^2 + 4 * cos(x);   % algorithm function
d_func = @(x) 2*x - 4 * sin(x); % derivative of function

% Secant Method Algorithm
eps = 10^(-4) ;
x_old = 1;
iter = 0;
error = 100;
while (error > 10^-5)
    
    dd_func = (d_func(x_old + eps) - d_func(x_old - eps))/(2*eps); % centered difference approximation
    x_new = x_old - d_func(x_old)/dd_func; % new x value
     
    error = abs(x_new - x_old); % tolarence 
    x_old = x_new;     % update x(i)       
    iter = iter + 1;   % update iteration number
      
end
time = toc;
% Print results
fprintf("\tSecant Method\n")
fprintf("Iteration : %d\n",iter);
fprintf("Computation time : %f\n",time);
fprintf("Minimum point of function : x = %f, f(x) = %f\n",x_new,func(x_new));
