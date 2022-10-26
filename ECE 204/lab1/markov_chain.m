function [v] = markov_chain(A, v0, eps_step, max_iterations)
    for j=1:size(A)%loop through check
		for i=1:size(A)
            if A(i,j)<0 || A(i,j)>1
                error("invalid argument exception")
            end
        end
    end
    
    size_matrix=size(A);
    size_=size_matrix(1);
    all_one=rand(size_,1);
    for z=1:size_
        all_one(z,1)=1;
    end
    
    col_sum = sum(A); %column sum
    col_sum_error_considered = all_one-col_sum;
    for k = 1:size(col_sum_error_considered)
        if abs(col_sum_error_considered(k)) >eps_step
           error("invalid argument exception ")
        end
    end
        v = A*v0;
        iterations=0;
    while norm(v-v0)> eps_step%norm
        v0=v;
        v = A*v0;
        iterations = iterations+1;
        
        if iterations == max_iterations+1
            error("out of range")
        end
    end
end
