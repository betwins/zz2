function c = progprincipalCL(Ne,fun,u0,uderL)

X=feval(@pointmaillage,Ne); %tableau de maillage

% Construction de la matrice M et R
M=sparse(Ne+1,Ne+1);
R=M;
for(k=1:Ne)
    for(iloc=1:2)
        ig = k+iloc-1;
        for(jloc=1:2)
            jg = k + jloc-1;
            M(ig,jg) = M(ig,jg) + simpson('produitphi',X(k),X(k+1),k,iloc,jloc,Ne);
            R(ig,jg) = R(ig,jg) + simpson('produitphider',X(k),X(k+1),k,iloc,jloc,Ne);
        end
    end
end

F=sparse(Ne+1,1);
for(k=1:Ne)
    for(iloc=1:2)
        ig = k+iloc-1;
        F(ig) = F(ig) + simpson('produitphif',X(k),X(k+1),k,iloc,Ne,fun);
    end
end

A=R+M;
%Condition de Dirichlet a gauche
Fd=F-u0*A(:,1); %on ajoute la condition de Dirichlet
Fd=Fd(2:Ne+1);
A=A(2:Ne+1,2:Ne+1); %on enleve la premiere ligne qui a ete ajoutee au second membre (par la condition de Dirichlet)

%Condition de Neumann a droite uderL

F(Ne+1) = F(Ne+1) + uderL %on ne multilplie pas par le phi de droite car il vaut 1 au Ne+1 ieme point


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%   Graphe   %%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%c2 = M\F; %approximation de la fonction
%c = (R+M)\F; %courbure
d(1) = u0;
d(2:Ne+1) = A\Fd; % avec condition de Dirichlet
plot(X(1:Ne+1),d(1:2:2*Ne+1,'b')
axis([0 4 -2 15])
hold on
x0 = linspace(0,pi,50);
y0 = feval(fun,x0);
plot(x0,y0,'r')
%plot(X,c,'g')
hold off


end