function [x, r, n, inc] = newton( F, dF, x0, tol, nmax )
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
r      = A COMPLETER;
diff   = tol + 1;    

while ( diff >= tol && n <= nmax )
    x(n+2) = A COMPLETER;
    inc(n+1) = A COMPLETER;
    diff = inc(n+1);
    r = A COMPLETER;
    n = n + 1;
end

if n > nmax
    fprintf(['Newton stopped without converging to the desired tolerance '...
             'because the maximum number of iterations was reached\n']);
end

end