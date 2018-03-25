function p = produitphip2(x,k,il,jl,n)
%Entree x valeur courante
%       k numero de la maille(element, intervalle)
%       il,jl  indice de la fonction a multiplier
%       n nombre d'intervalles
%Sortie  produit phiI*phiJ

p=phibasep2(x,k,il,n)*phibasep2(x,k,jl,n);

end