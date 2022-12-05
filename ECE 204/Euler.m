function [err_a, err_b, integral_a, integral_b] = Euler(t_max, n)
    a = [];
    b = [];
    a_true = [];
    b_true = [];
    y_a_curr = 1;
    y_b_curr = 1;
    a_diff=0;
    b_diff=0;
    h = t_max / n;
    for k = 1:n
        i = k-1;
        %actual value
        y_a_actual = exp(-1.456*i*h);
        y_b_actual = 0.6131200387063277*cos(i*h) + 0.5459661965327940*sin(i*h)+ 0.3868799612936723*exp(-1.123*i*h);
        a_true = [a_true,y_a_actual];
        b_true = [b_true,y_b_actual];
        % a next
        y_a_next = y_a_curr + h*(-1.456 * y_a_curr);
        a_diff = a_diff+(y_a_actual-y_a_curr)^2;
        y_a_curr = y_a_next;
        a = [a,y_a_next];
        % b next
        y_b_next = y_b_curr + h*(1.2345*cos(i*h)-1.123*y_b_curr);
        b_diff = b_diff+(y_b_actual-y_b_curr)^2;
        y_b_curr = y_b_next;
        b = [b,y_b_next];

    end
    %err
    err_a = (a_diff*(1/(n+1)))^(1/2);
    err_b = (b_diff*(1/(n+1)))^(1/2);

    %simpson
    if (rem(n, 2) == 0)
        integral_a=0;
        integral_b=0;
        %simpson
        for k = 1:(n/2-1)
            index1=2*k;
            index2=2*k+1;
            index3=2*k+2;
            integral_a=integral_a+(2*h/6)*((a(index1)-a_true(index1))^(2)+ 4*(a(index2)-a_true(index2))^(2)+(a(index3)-a_true(index3))^2);
            integral_b=integral_b+(2*h/6)*((b(2*k)-b_true(2*k))^(2)+ 4*(b(2*k+1)-b_true(2*k+1))^(2)+(b(2*k+2)-b_true(2*k+2))^2);
        end
    else
        for k = 1:n-1
            integral_a=(h/2)*((a(k)-a_true(k))^(2)+(a(k+1)-a_true(k+1))^(2));
            integral_b=(h/2)*((b(k)-b_true(k))^(2)+(b(k+1)-b_true(k+1))^(2));
        end
        %trapezoidal
    end
%     err_a = ((1/t_max)*integral_a)^(1/2);
%     err_b = ((1/t_max)*integral_b)^(1/2);
end
