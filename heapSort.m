function A=heapSort(A)
tic
[A,sizeA]=BuildMaxHeap(A);
toc
tic
for i=length(A):-1:2
    t=A(1); A(1)=A(i); A(i)=t;
    sizeA=sizeA-1;
    A=MaxHeapify(A,1,sizeA);
end
toc
end

function [A,sizeA]=BuildMaxHeap(A)
sizeA=length(A);
for i= floor(length(A)/2):-1:1
    A=MaxHeapify(A,i,sizeA);    
end
end

function A=MaxHeapify(A,i,sizeA)
l=2*i;
r=2*i+1;
if l<=sizeA && A(l)>A(i)
    largest=l;
else
    largest=i;
end

if r<=sizeA && A(r)>A(largest)
    largest=r;
end

if largest~=i
    t=A(i); A(i)=A(largest); A(largest)=t;
    A=MaxHeapify(A,largest,sizeA);
end
end