 f=@(x) 1./(1+x.^2); 
 
 
 
 
 
 
 K=[20 40 80 160]; 
 H=10./K; 
 x_fine = [-5:0.001:5];
 f_fine = f(x_fine); 
 for i=1:4 
     x = [-5:H(i):5]; 
     y = f(x); 
     y_fine = interp1(x,y,x_fine); 
     err1(i) = max(abs(f_fine - y_fine)); 
 end
 grid on;
 loglog(H,err1);
