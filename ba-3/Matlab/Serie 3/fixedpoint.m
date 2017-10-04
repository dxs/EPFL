function [ p, iter ] = fixedpoint( phi, x0, tol, nmax )
%FIXEDPOINT Summary of this function goes here
%   Detailed explanation goes here
    p = 0;
    iter = 0;
    err = 1;
    
    x = x0;
    phix = phi(x);
    while(err >tol) && (iter <=nmax)
        iter = iter + 1;
        err = abs(phix - x);
        x = phix;
        phix = phi(x);
    end
    p = x;

end

