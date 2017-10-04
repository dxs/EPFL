f = @(x) x/2 - sin(x) + pi/6 - sqrt(3)/2;
df = @(x) 0.5 - cos(x);
a = 1;
b = 3;

[zero, err, iter] = Bissection(a,b,f,1e-8,1000);

x=a:0.01:b;
figure('Name', 'Serie 3');
subplot(2,2,1);
plot(x,f(x));
hold on;
grid on;
plot(zero,f(zero), 'mo');
hold off;
title('Bissection');
legend('',sprintf('%d',iter));

x=1:0.01:3;
subplot(2,2,2);
plot(x,f(x));
hold on;
grid on;
x0 = pi;
[xn,err,iter] = Newton(x0,f,df,1e-8,1000);
plot(xn(iter),f(xn(iter)),'mo');
hold off;
title('Newton x0 = pi');
legend('',sprintf('%d',iter));

x=-1.5:0.01:0;
subplot(2,2,3);
plot(x,f(x));
hold on;
grid on;
x0 = -pi/2;
[xn,err,iter] = Newton(x0,f,df,1e-8,1000);
plot(xn(iter),f(xn(iter)),'mo');
hold off;
title('Newton x0 = -pi/2');
legend('',sprintf('%d',iter));

x=-1.5:0.01:3;
subplot(2,2,4);
plot(x,f(x));
hold on;
grid on;
x0 = pi;
phi = @(x) sin(x) + x/2 - (pi/6 -sqrt(3)/2);
[p, iter] = fixedpoint(phi,x0,1e-8,1000);
plot(p,f(p),'mo');
hold off;
title('Fixed Point');
legend('',sprintf('%d',iter));



