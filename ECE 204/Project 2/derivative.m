function [dfval] = derivative(coeffs, degree, x)
    dfval = 0;
    for i= 1:(degree)
        dfval = dfval + coeffs(i) * (i-1) * (x^(i-2));
    end
end