function liste_inter = maillage(n)
%MAILLAGE 
%Entrée: nombre d'intervalles souhaité
%Sortie: liste des intervalles
h=pi/n;
liste_inter=zeros(1,n);
dep = 0;
for (i=0:n)
    liste_inter(i+1) = dep + i*h;
end

end

