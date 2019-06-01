clear;
clc;

tic
format long
% Initial values
a_lower = 1;  % lower limit
b_upper = 2;  % upper limit
ro = (3 - sqrt(5))/2; % constant step size (golden number)
eps = b_upper - a_lower;

% Assign initial value
a_old = a_lower;
b_old = b_upper;
iter = 0; % 

% Golden Section Algorithm
func = @(x) x^2 + 4*cos(x);  % you can change the 
while(eps > 10^-5)
   
    a_new = a_old + (b_old - a_old)*ro; % new lower limit
    b_new = b_old - (b_old - a_old)*ro; % new upper limit
    
    if (func(b_new) > func(a_new))
        b_old = b_new;       
    elseif (func(b_new) < func(a_new))
        a_old = a_new;
    end
    eps = b_old - a_old;
    iter = iter + 1;
    
end
timeElapsed = toc;

fprintf("\tGolden Search Method\n")
fprintf("Iteration : %d\nAverage computation time : %f\n",iter,timeElapsed);
fprintf("Minimum point of function : x = %f, f(x) = %f\n",a_new,func(a_new));
