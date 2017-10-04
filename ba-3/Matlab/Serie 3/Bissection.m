function [ zero, err, iter ] = Bissection(a, b, f, tol, nmax )
%BISSECTION function 
%   Detailed explanation goes here
    zero = 0;
    err = 10;
    iter = 0;
    
    fa = f(a);
    fb = f(b);
    
    if(sign(fa)*sign(fb) > 0)
        fprintf("Error doesn't cross the axis");
        return
    end
    
    positive = true;
    if(sign(fa) > 0)
        positive = false;
    end
    
    while(iter < nmax)
       iter=iter+1;
       c = (a + b)/2;  
       zero = f(c);
       if(abs(zero) < tol)
           err = zero;
           zero = c;
           return;
       end
       
       if(positive)
           if(zero > 0)
               b = c;
           else
               a = c;
           end
       else
           if(zero > 0)
               a = c;
           else
               b = c;
           end
       end 
    end
    
    

return

