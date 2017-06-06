function A=mergeSort(A,p,r)
if ~isscalar(r)||~isscalar(p)
    disp('Invalid input. p,r should be scalar')
    A=-1;
    return 
else if p<r
   q=floor((p+r)/2);
   A=mergeSort(A,p,q);
   A=mergeSort(A,q+1,r);
   A=MERGE(A,p,q,r);
    end
end
end

function A=MERGE(A,p,q,r)
n1=q-p+1;
n2=r-q;
L=zeros(1,n1+1);
for i=1:n1
    L(i)=A(p+i-1);
end
L(n1+1)=Inf;

R=zeros(1,n2+1);
for j=1:n2
    R(j)=A(q+j);
end    
R(n2+1)=Inf;

i=1;j=1;
for k=p:r
    if L(i)<R(j)
        A(k)=L(i);
        i=i+1;
    else
        A(k)=R(j);
        j=j+1;
    end
end
end