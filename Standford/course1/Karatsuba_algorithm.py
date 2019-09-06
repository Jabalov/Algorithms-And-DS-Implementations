def karatsuba_algorithm(x, y):

    if(len(str(x)) < 2 or len(str(y))):
        return x*y

    else:
        n = max(len(str(y)), len(str(x)))
        m = n/2

        a = x / 10**(m)
        b = x % 10**(m)

        c = y / 10**(m)
        d = y % 10**(m)

        ac = karatsuba_algorithm(a, c)
        bd = karatsuba_algorithm(b, d)
        sm = karatsuba_algorithm(a+b, c+d) - ac - bd

        result = 10**(2*m) * ac + 10**(m) * sm + bd

        return result


print(karatsuba_algorithm(12345, 6789))
