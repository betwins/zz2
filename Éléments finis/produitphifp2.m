function pf = produitphifp2(x,k,il,n,fun)
%Entree x valeur courante
%       k numero du maillage
%       il indice de la fonction a multiplier
%       fun  appel de la fonction de maillage
%       n nombre d'intervalles
%Sortie  produit phiI * second membre de l'équation

f=feval(fun,x); %evaluation de la fonction f donnee
pf=phibasep2(x,k,il,n)*f; %produit scalaire

end