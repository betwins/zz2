function pf = produitphif(x,k,il,n,fun)
%Entree x valeur courante
%       k n° du maillage
%       il indice de la fonction à multiplier
%       fun  appel de la fonction de maillage
%       n nombre d'intervalles
%Sortie  produit phiI * second membre de l'équation

f=feval(fun,x); %évaluation de la fonction f donnée
pf =phibase(x,k,il,n)*f; %produit scalaire

end