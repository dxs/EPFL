function [zero, res, iter] = pointfixe(f, x0, tol, nmax)
    phi = @(x) x + 0.25*f(x); 
    zero = 0;
    res = 10;
    iter = 0;
    
    x=x0;
    phix=phi(x);
    iter=0;
    err=1;
    while(err>tol)&&(iter<=nmax)
        iter=iter+1;
        err=abs(phix-x);
        x=phix;
        phix=phi(x);
    end
    zero=x;
    res=abs(err);
    fprintf('Pointfixe : found a zero in %d steps with residu of %f\n',iter,res);
return