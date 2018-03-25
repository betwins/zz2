function q = produitphiderp2(x,k,il,jl,n)
%Entree x valeur courante
%       k n° du maillage
%       il,jl  indice de la fonction à multiplier
%       n nombre d'intervalles
%Sortie  produit phi'J*phi'I

q=phibasederp2(x,k,il,n)*phibasederp2(x,k,jl,n);

end