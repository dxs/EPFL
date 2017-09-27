function [x, r, n, inc] = newton( f, df, x0, tol, nmax )
% NEWTON Find the zeros of a nonlinear equations.
%   [X] = NEWTON(F,DF,X0,TOL,NMAX) tries to find the zero X of the 
%   continuous and differentiable function F nearest to X0 using 
%   the Newton method. DF is a function which take X and return the derivative of F.
%   If the search fails an error message is displayed.
%   
%   [X,R,N,INC] = NEWTON(F,DF,X0,TOL,NMAX) returns the value of the 
%   residual R in X,the number of iterations N required for computing X and
%   INC the increments computed by Newton.

n      = 0; 
x(n+1) = x0; 
r      = 10;
diff   = tol + 1;    

while ( diff >= tol && n <= nmax )
    x(n+2) =x(n+1) - (f(x(n+1))/df(x(n+1))) ;
    inc(n+1) = x(n+2) - x(n+1);
    diff = inc(n+1);
    r = inc(n+1);
    n = n + 1;
end

if n > nmax
    fprintf(['Newton stopped without converging to the desired tolerance '...
             'because the maximum number of iterations was reached\n']);
end

end