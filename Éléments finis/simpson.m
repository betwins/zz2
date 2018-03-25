function res = simpson(fun,a,b,varargin)
%Entree: x point courant
%        fun fonction formant le maillage
%        n nombre d'intervalles
%        varargin{:} arguments optionnels pour faire appel � d'autres
%        fonctions
%Sortie: res r�sultat de la m�thode de Simpson
    gch = feval(fun,a,varargin{:});
    mil = feval(fun,(a+b)/2,varargin{:});
    dte = feval(fun,b,varargin{:});
    res = (b-a)*(gch + dte + 4*mil)/6;    
    if (abs(res) <= 10^-14)
        res = 0;
    end
end