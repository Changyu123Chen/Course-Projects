function [roots] = all_roots(coeffs)
    degree = length(coeffs);
    roots = NaN(1,degree-1);
    i = 1;
    while degree ~= 1
        roots(i) = find_root(coeffs, degree);
        [~, coeffs] = divide(coeffs, degree, roots(i));
        x = isnan(coeffs);
        coeffs(x) = [];
        degree = length(coeffs);
        i = i+1;
    end
end