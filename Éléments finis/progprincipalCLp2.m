function c = progprincipalCLp2(Ne,fun,u0,uderL)

X=feval(@pointmaillage,Ne); %tableau contenant tous les points du maillage

% Construction de la matrice M et R
M=sparse(2*Ne+1,2*Ne+1);
R=M;
for(k=1:Ne)
    for(iloc=1:3)
        ig = 2*k+iloc-2;
        for(jloc=1:3)
            jg = 2*k + jloc-2;
            M(ig,jg) = M(ig,jg) + simpson('produitphip2',X(k),X(k+1),k,iloc,jloc,Ne); % 'produitphip2' =@produitphip2
            R(ig,jg) = R(ig,jg) + simpson('produitphiderp2',X(k),X(k+1),k,iloc,jloc,Ne);
        end
    end
end

F=sparse(2*Ne+1,1);
for(k=1:Ne)
    for(iloc=1:3)
        ig = 2*k+iloc-2;
        F(ig) = F(ig) + simpson('produitphifp2',X(k),X(k+1),k,iloc,Ne,fun);
    end
end

A=R+M;
A;
%Condition de Dirichlet a gauche
Fd=F-u0*A(:,1); %on ajoute la condition de Dirichlet  
Fd=Fd(2:2*Ne+1);
A=A(2:2*Ne+1,2:2*Ne+1); %on enleve la premiere ligne qui a ete ajoutee au second membre (par la condition de Dirichlet)

%Condition de Neumann a droite uderL, avec prise en compte de Dirichlet

Fd(2*Ne) = Fd(2*Ne) + uderL; %on ne multilplie pas par le phi de droite car il vaut 1 au 2*Ne ieme point


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%   Graphe   %%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%c2 = M\F; %approximation de la fonction
%c = (R+M)\F; %courbure
d(1) = u0;
[L,U]=lu(A); % matrice pas forcement inversible
d(2:2*Ne+1)= U\(L\Fd); % avec condition de Dirichlet
plot(X(1:Ne+1),d(1:2:2*Ne+1),'b') 
hold on
x0 = linspace(0,pi,50);
y0 = feval(fun,x0);
plot(x0,y0,'r')
hold off

end