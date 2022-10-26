function [remainder, coeffs_q] = divide(coeffs, degree, r) % r是root
    coeffs_q = zeros(1, degree);
    coeffs_q(degree) = NaN;
    coeffs_q(degree-1) = coeffs(degree);

    for i = degree-2:-1:1
            coeffs_q(i) = r*coeffs_q(i+1) + coeffs(i+1);
    end

    remainder = r*coeffs_q(1) + coeffs(1);



end