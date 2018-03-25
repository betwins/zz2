function pf = produitphifCL(x,k,il,n,fun,u0)
    %Entree x valeur courante
    %       k n° du maillage
    %       il indice de la fonction à multiplier
    %       fun  appel de la fonction de maillage
    %       n nombre d'intervalles
    %       u0 CL en 0
    %       uL CL en L
    %Sortie  produit phiI * second membre de l'équation

    f=feval(fun,x); %évaluation de la fonction f donnée
    if (k==1)
        res=(f-u0)*phibase(x,1,2,n); %membre de droite de l'équation, complété par le terme du bord - CL en 0
    else
        res=f*phibase(x,k,il,n);
    end
    pf =phibase(x,k,il,n)*res; %produit scalaire

end