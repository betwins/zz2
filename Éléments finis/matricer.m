function R = matricer(Ne)
% Entree:  Ne nombre de mailles (intervalles)
%Sortie:   M  matrice de produit scalaire  de fonction de base

R=sparse(Ne+1,Ne+1);
X = pointmaillage(Ne);
for(k=1:Ne)
    for(iloc=1:2)
        ig = k+iloc-1;
        for(jloc=1:2)
            jg = k + jloc-1;
            R(ig,jg) = R(ig,jg) + simpson('produitphider',X(k),X(k+1),k,iloc,jloc,Ne);
        end
    end
end
end
