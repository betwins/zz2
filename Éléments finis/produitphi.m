function p = produitphi(x,k,il,jl,n)
%Entree x valeur courante
%       k n° du maillage
%       il,jl  indice de la fonction à multiplier
%       n nombre d'intervalles
%Sortie  produit phiI*phiJ

p=phibase(x,k,il,n)*phibase(x,k,jl,n);

end