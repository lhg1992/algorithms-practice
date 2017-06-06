function A = bubbleSort(A)
    for i=1:length(A)-1
        for j=1:length(A)-i
            if A(j)>A(j+1)
                t=A(j); A(j)=A(j+1); A(j+1)=t; %switch
            end
        end
    end
end