function F = vecteur(Ne)
% Entree:  Ne nombre de mailles (intervalles
%Sortie:   F  matrice de produit scalaire de fonction de base*f

F=sparse(Ne+1,1);
X = pointmaillage(Ne);
for(k=1:Ne)
    for(iloc=1:2)
        ig = k+iloc-1;
        F(ig) = F(ig) + simpson('produitphif',X(k),X(k+1),k,iloc,Ne);
       
    end
end
end
