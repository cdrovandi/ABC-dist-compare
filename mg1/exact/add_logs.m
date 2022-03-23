% Compute log(A + B) where a = log(A), b = log(B)

function total = add_logs(a, b)

    if a > b

        total = a + log(1 + exp(b - a));

    else

        total = b + log(1 + exp(a - b));

    end

end