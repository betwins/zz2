function M = matricem(Ne)
% Entree:  Ne nombre de mailles (intervalles)
%Sortie:   M  matrice de produit scalaire  de fonction de base

M=sparse(Ne+1,Ne+1);
X = pointmaillage(Ne);
for(k=1:Ne)
    for(iloc=1:2)
        ig = k+iloc-1;
        for(jloc=1:2)
            jg = k + jloc-1;
            M(ig,jg) = M(ig,jg) + simpson('produitphi',X(k),X(k+1),k,iloc,jloc,Ne);
        end
    end
end
end
