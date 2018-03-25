function c = main(Ne)
% Entrée: Ne: nombre de points dans le maillage
%         fun: fonction f du second membre du problème
% Sortie: vecteur c, composantes de f dans la base phi

M = matricem(Ne);
F = vecteur(Ne);
R = matricer(Ne);
c = (R+M)\F; %fonction approché uh
x=0:pi/Ne:pi;
plot(x,c,'b') 

hold on
x0=0:0.1:pi;
y = cosinu(x0); %fonction modèle f
plot(x0,y,'r');
hold off
end