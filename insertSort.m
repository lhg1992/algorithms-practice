
function A = insertSort(A)
    for i=2:length(A)
        key=A(i);
%-------------------        
        j=i-1;
        while j>0 && A(j)>key
            A(j+1)=A(j);
            j=j-1;            
        end        
        A(j+1)=key;        
%-------------------
        
% %--------------------------  Less efficient syntax, Same idea       
%         for j=i-1:-1:1 % -1 can't be omitted
%             if A(j)>key               
%                 A(j+1)=A(j);               
%                 if (j==1)
%                     A(j)=key;
%                 end
%             else                
%                 A(j+1)=key;
%                 break;
%             end            
%         end
% %---------------------
    end
end