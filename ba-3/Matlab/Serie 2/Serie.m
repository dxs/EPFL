%exo 1
nmax = 1000;
tol = 1e-8;
f = @(x) sin(2*x) - 1 + x;

a = -3; 
b = 3; 
x=a:0.1:b;
figure('Name', 'Exo 1')
plot(x,f(x)); 
grid on;
hold on;
[zero,res,niter] = bisection(f,a,b,1e-8,nmax);
plot(zero,f(zero),'mo');
hold off;

%Exo 2 a
f = @(x) 0.5*sin(pi*x*0.5) + 1 - x;
df = @(x) pi/4*cos(pi*x*0.5) - 1;

a = 0;
b = 2;
x=a:0.1:b;
grid on;
[zero, res, niter] = bisection(f,a,b,tol,1000);

%Exo 2 b
x0 = 1;
figure('Name', 'Exo 2')
plot(x,f(x)); 
grid on;
hold on;
[res, r, n, inc] = newton( f, df, x0, tol, nmax );
plot(res(n+1),f(res(n+1)),'mo');
hold off;
fprintf('Newton found point in %d steps with residu of %f\n',n,abs(r));

%Exo 3
a = 0;
b = 1;

g = @(x) exp(-x) - x.^2;
x1=a:0.1:b;

figure('Name', 'Exo 3');
plot(x1,g(x1));
grid on;
hold on;
[zero,res,niter] = bisection(g,a,b,1e-10,nmax);
plot(zero, g(zero),'mo');


%Exo 3 point fixe
x0 = 0.0001;
[zero, res, iter] = pointfixe(g,x0,1e-10,nmax);
plot(zero, g(zero), 'mx');
hold off;


