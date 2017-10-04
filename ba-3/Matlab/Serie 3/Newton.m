function [ xn, err, iter ] = Newton( x0, f, df, tol, nmax )
%NEWTON Summary of this function goes here
%   Detailed explanation goes here
    zero = 0;
    err = 10;
    iter = 0;
    n = 1;
    xn(n) = x0;
    while(iter < nmax)
        if(abs(err) < tol)
            return;
        end
        
        xn(n+1) = xn(n) - (f(xn(n))/df(xn(n)));
        
        err = xn(n+1) - xn(n);
        
        n = n + 1;
        iter = iter + 1;

    end

end

