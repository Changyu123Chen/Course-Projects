function [root] = find_root(coeffs, degree)
    x_1 = (rand()*2000 - 1000) + (rand()*2000 - 1000)*1i;
    if abs(evaluate(coeffs, degree, x_1)) <=  (degree-1)*10^(-12)
        root = x_1;
    else
        x_2 = x_1 - (evaluate(coeffs, degree, x_1)/derivative(coeffs, degree, x_1));
    
        while (abs(evaluate(coeffs, degree, x_2)) >  (degree-1)*10^(-12))
            x_1 = x_2;
            x_2 = x_1 - (evaluate(coeffs, degree, x_1)/derivative(coeffs, degree, x_1));
        end
        root = x_2;
    end
end