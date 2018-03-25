function c = main(Ne)
% Entr�e: Ne: nombre de points dans le maillage
%         fun: fonction f du second membre du probl�me
% Sortie: vecteur c, composantes de f dans la base phi

M = matricem(Ne);
F = vecteur(Ne);
R = matricer(Ne);
c = (R+M)\F; %fonction approch� uh
x=0:pi/Ne:pi;
plot(x,c,'b') 

hold on
x0=0:0.1:pi;
y = cosinu(x0); %fonction mod�le f
plot(x0,y,'r');
hold off
end