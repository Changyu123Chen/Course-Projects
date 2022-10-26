function [fval] = evaluate(coeffs, degree, x)
    result=0;
    dgr=degree;

    while dgr>0
        result = coeffs(dgr)+x*result;
        dgr=dgr-1;
    end
    
    fval=result;
end