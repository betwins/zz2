function c = progprincipal(Ne,fun)

X=feval(@pointmaillage,Ne); %tableau de maillage

% Construction de la matrice M
M=sparse(Ne+1,Ne+1);
for(k=1:Ne)
    for(iloc=1:2)
        ig = k+iloc-1;
        for(jloc=1:2)
            jg = k + jloc-1;
            M(ig,jg) = M(ig,jg) + simpson('produitphi',X(k),X(k+1),k,iloc,jloc,Ne);
        end
    end
end

% Construction du vecteur F
F=sparse(Ne+1,1);
for(k=1:Ne)
    for(iloc=1:2)
        ig = k+iloc-1;
        F(ig) = F(ig) + simpson('produitphif',X(k),X(k+1),k,iloc,Ne,fun);
       
    end
end

% Construction de la matrice R
R=sparse(Ne+1,Ne+1);
for(k=1:Ne)
    for(iloc=1:2)
        ig = k+iloc-1;
        for(jloc=1:2)
            jg = k + jloc-1;
            R(ig,jg) = R(ig,jg) + simpson('produitphider',X(k),X(k+1),k,iloc,jloc,Ne);
        end
    end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%   Graphe   %%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

c2 = M\F; %approximation de la fonction
c = (R+M)\F; %courbure
plot(X,c2,'b')
hold on
x0 = linspace(0,pi,50);
y0 = feval(fun,x0);
plot(x0,y0,'r')
plot(X,c,'g')
hold off


end