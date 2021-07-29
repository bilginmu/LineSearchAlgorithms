clear all
clc
tic
% Functions
func    = @(x) x ^ 2 + 4 * cos(x);   % function
d_func  = @(x) 2 * x - 4 * sin(x); % derivative of function
dd_func = @(x) 2 - 4 * cos(x);  % second derivative of function

% Newton's Method Algorithm
x_old = 1; 
iter = 0;
error = 100; % initial value for while loop
while (error > 10^-5) 
    
    x_new = x_old - d_func(x_old)/dd_func(x_old); % update x value
    error = abs(x_new - x_old); % tolarence
    
    x_old = x_new;   % update old x value
    iter = iter + 1; % iteration number
    
    
end
time = toc;
% Print results
fprintf("\tNewton's Method\n")
fprintf("Iteration : %d\n",iter);
fprintf("Computation time : %f second\n",time)
fprintf("Minimum point of functin : x = %f f(x) = %f\n",x_new,func(x_new));