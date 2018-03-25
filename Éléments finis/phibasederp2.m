function [y] = phibasederp2(x,k,ilocal,n)
    % Entree: x: point courant
    %         k: numero du maillage
    %         ilocal: indice du point x courant (1 si droite, 2 si gauche)
    %         n: nombre d'intervalles
    % Sortie: fonction derivee de phi dans le maillage k

    % en dehors des intervalles (valeur nulle), inutile de definir les points
    % car nous ne les appellerons pas (integrale sur un intervalle donnee)

    X=feval(@pointmaillage,n);
    %tableau de maillage
    mil= (X(k)+X(k+1))/2;
    if (ilocal==3)%gauche
         y= ((x-X(k+1))+((x-mil)))/((X(k)-mil)*(X(k)-X(k+1)));
    elseif (ilocal==1)%droite
         y= ((x-X(k))+(x-mil))/((X(k+1)-mil)*(X(k+1)-X(k))); 
    elseif(ilocal==2) %milieu
        y= ((x-X(k))+(x-X(k+1)))/((mil-X(k))*(mil-X(k+1))); 
    end
end