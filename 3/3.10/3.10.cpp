unsigned long long factorialIte(unsigned int n)
{
    unsigned long long result = 1;

    for (unsigned int i = 2; i <= n; i++)
        result *= i;

    return result;
}

unsigned long long factorialRec(unsigned int n)
{
    if (n < 2)
        return 1;

    return n * factorialRec(n - 1);
}
