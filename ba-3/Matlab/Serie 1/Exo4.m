
function [ ] = Exo4(  )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    %part 1
    deb=1;
    fin=20;
    x1 = linspace(deb,fin,10);
    x1 = x1';
    x2 = linspace(deb,fin,20);
    x3 = linspace(deb,fin,100);
    
    f = @(x) x.^2/2.*sin(x);
    y1 = f(x1);
    y2 = f(x2);
    y3 = f(x3);
    plot(x1, y1);
    grid;
    hold on;
    plot(x2,y2);
    plot(x3,y3);
    hold off;
    figure;    
    g = @(x) x.^3./6.*cos(sin(x)).*exp(-x) + (1./(1+x)).^2;
    
    y1 = g(x1);
    y2 = g(x2);
    y3 = g(x3);
    plot(x1,y1);
    grid;
    hold on;
    plot(x2,y2);
    plot(x3,y3);
    hold off;

end

