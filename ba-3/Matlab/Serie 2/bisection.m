function [zero,res,nit] = bisection(fun,a,b,tol,nmax)
% BISECTION Find a zero of a nonlinear scalar function inside an interval.
%   XVECT=BISECTION(FUN,A,B,TOL,NMAX) finds a zero of the continuous 
%   function FUN in the interval [A,B] using the bisection method and returns
%   a number ZERO that is the zero of the function. 
%   FUN accepts real scalar input x and returns a real scalar value; 
%   FUN can also be an inline object. 
%   TOL is the tolerance on error allowed and NMAX the maximum number of iterations.
%   If the search fails an error message is displayed. 
%
%   [ZERO,RES,NIT]=BISECTION(FUN,...) returns also RES, that is the residual
%   evaluated at the last iterate, and NIT the number of iterations.
%
    zero = 0;
    res = 0;
    nit = 0;
    if (((fun(a) > 0) && (fun(b) > 0)) || ((fun(a) < 0) && (fun(b) < 0)))
        return;
    end
    
    %swap
    if((a>0) && (b<0))
        c = a + b;
        b = c - b;
        a = c - b;
    end
    positive = 1;
    if(fun(a)>0)
        positive = 0;
    end
        
    
    for n = 1:nmax
        nit = n;
        xn = (a+b)/2;
        yn = fun(xn);
        if(abs(yn) < tol)
            fprintf('Bisection found a point in %d steps\n',nit);
            zero = xn;
            res = yn;
            return;
        end
        if(yn < 0)
            if(positive)
                a = xn;
            else
                b = xn;
            end
        else
            if(positive)
                b = xn;
            else
                a = xn;
            end
        end
       
    end
    fprintf(['Bisection stopped without converging to the desired tolerance '...
             'because the maximum number of iterations was reached\n']);

return
