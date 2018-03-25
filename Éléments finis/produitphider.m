function q = produitphider(x,k,il,jl,n)
%Entree x valeur courante
%       k n° du maillage
%       il,jl  indice de la fonction à multiplier
%       n nombre d'intervalles
%Sortie  produit phi'J*phi'I

q=phibaseder(x,k,il,n)*phibaseder(x,k,jl,n);

end