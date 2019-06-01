clear;
clc;
tic % for computation time
format long

%% Initial values
a_lower = 1;  % lower limit
b_upper = 2;  % upper limit
eps = b_upper - a_lower;

%% Assign initial value
a_old = a_lower;
b_old = b_upper;
iter = 0; % 

k = 2;
N = 17;
%% Fibonacci Search Algorithm
func = @(x) x^2 + 4*cos(x); 
while(eps > 10^-5)
    iter   = iter + 1;
    
    k = k + 1;
    ro = 1 - fibonacci(N - k)/fibonacci(N - k + 1);
    
    a_new = a_old + abs(b_old - a_old)*ro; % new lower limit
    b_new = b_old - abs(b_old - a_old)*ro; % new upper limit
    
    if (func(b_new) > func(a_new))
        b_old = b_new;       
    elseif (func(b_new) < func(a_new))
        a_old = a_new;
    end
    
    eps = abs(b_old - a_old);  
    
end

timeElapsed = toc;
fprintf("Average number of iteration : %d, Average computation time : %f\n",iter,timeElapsed);
fprintf("Minimum point of function : (%f,%f)\n",a_new,func(a_new));