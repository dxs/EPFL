function [  ] = Interpo( f, a, b, n ,rangeOut,printerror)
%INTERP Summary of this function goes here
%   Detailed explanation goes here
    xval = linspace(a,b,n);
    yval = f(xval);
    p = polyfit(xval, yval, n-1);
    
    xnewval = rangeOut;
    ynewval = polyval(p,xnewval);
    if(printerror == 0)
        plot(xnewval, ynewval);
    else
        ynormal = f(rangeOut);
        err = abs(ynormal - ynewval);
        plot(xnewval,err);
    end
end

