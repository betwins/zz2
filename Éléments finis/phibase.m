    function [y] = phibase(x,k,ilocal,n)
    %Entr�e: x point courant
    %        k n� du maillage
    %        ilocal : indice du point x courant (1 si droite, 2 si gauche)
    %        n : nombre d'intervalles
    %Sortie: fonction phi dans le maillage k

    % en dehors des intervalles (valeur nulle), inutile de d�finir les points
    % car nous ne les appellerons pas (int�grale sur un intervalle donn�e)

    X=feval(@pointmaillage,n);
    %tableau de maillage

    if (ilocal==2)%gauche
        y= (x-X(k))/(X(k+1)-X(k));
    elseif (ilocal==1)%droite
        y= (x-X(k+1))/(X(k)-X(k+1));
    end

end
