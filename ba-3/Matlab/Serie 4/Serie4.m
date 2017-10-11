%interpol
x = 0:pi/100:3*pi;
f = @(x) sin(x) + x;

figure('Name', 'Interpolation');
plot(x,f(x));

hold on;
grid on;
Interpo(f,0,3*pi,2,x,0);
Interpo(f,0,3*pi,3,x,0);
Interpo(f,0,3*pi,4,x,0);
Interpo(f,0,3*pi,5,x,0);
Interpo(f,0,3*pi,6,x,0);

lgd = legend('sin(x) + x', 'n = 2','n = 3','n = 4', 'n = 5', 'n = 6');
legend('Location', 'best');
hold off;

figure('Name', 'Interpolation error');
hold on;
grid on;
Interpo(f,0,3*pi,2,x,1);
Interpo(f,0,3*pi,3,x,1);
Interpo(f,0,3*pi,4,x,1);
Interpo(f,0,3*pi,5,x,1);
Interpo(f,0,3*pi,6,x,1);

legend('n = 2','n = 3','n = 4', 'n = 5', 'n = 6');
legend('Location', 'best');
hold off;

figure('Name', 'Exo 2');
x = 0:3*pi/1001:3*pi;
f = @(x) sin(x);
plot(x,f(x));

hold on;
grid on;
Interpo(f,0,3*pi,1,x,0);
Interpo(f,0,3*pi,2,x,0);
Interpo(f,0,3*pi,3,x,0);
Interpo(f,0,3*pi,4,x,0);
Interpo(f,0,3*pi,5,x,0);
Interpo(f,0,3*pi,6,x,0);
Interpo(f,0,3*pi,7,x,0);
ldg = legend('sin(x)', 'n=1', 'n=2','n=3','n=4','n=5','n=6','n=7');
legend('Location', 'best');

figure('Name', 'Interpolation error');
hold on;
grid on;
Interpo(f,0,3*pi,1,x,1);
Interpo(f,0,3*pi,2,x,1);
Interpo(f,0,3*pi,3,x,1);
Interpo(f,0,3*pi,4,x,1);
Interpo(f,0,3*pi,5,x,1);
Interpo(f,0,3*pi,6,x,1);
Interpo(f,0,3*pi,7,x,1);

lgd = legend('n=1','n=2','n=3','n=4', 'n=5', 'n=6', 'n=7');
legend('Location', 'best');
hold off;
