function pf = produitphif(x,k,il,n,fun)
%Entree x valeur courante
%       k n� du maillage
%       il indice de la fonction � multiplier
%       fun  appel de la fonction de maillage
%       n nombre d'intervalles
%Sortie  produit phiI * second membre de l'�quation

f=feval(fun,x); %�valuation de la fonction f donn�e
pf =phibase(x,k,il,n)*f; %produit scalaire

end