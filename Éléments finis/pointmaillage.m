function X = pointmaillage(n)
  %MAILLAGE 
  %Entr�e: nombre d'intervalles souhait�
  %Sortie: liste des intervalles
  h=pi/n;
  X=zeros(1,n);
  dep = 0;
  for (i=0:n)
    X(i+1) = dep + i*h;
  end
end

