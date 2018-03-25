function X = pointmaillage(n)
  %MAILLAGE 
  %Entrée: nombre d'intervalles souhaité
  %Sortie: liste des intervalles
  h=pi/n;
  X=zeros(1,n);
  dep = 0;
  for (i=0:n)
    X(i+1) = dep + i*h;
  end
end

