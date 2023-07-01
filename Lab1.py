from math import sqrt
l1 = int(input("Unesite prvi koeficijent λ_1 rekurzivne relacije: "))
l2 = int(input("Unesite drugi koeficijent λ_2 rekurzivne relacije: "))
a0 = int(input("Unesite vrijednost nultog clana niza a_0: "))
a1 = int(input("Unesite vrijednost prvog clana niza a_1: "))
n = int(input("Unesite redni broj n trazenog clana niza: "))

def rek(l1, l2, a0, a1, n):
    if n == 1: return a1
    if n == 0: return a0
    return l1*rek(l1,l2,a0,a1,n-1) + l2*rek(l1,l2,a0,a1,n-2)

def formula(l1, l2, a0, a1, n):
    x1 = float; x2 = float; alfa = float; beta = float
    x1 = (l1 + sqrt(l1*l1+4*l2)) / 2
    x2 = (l1 - sqrt(l1*l1+4*l2)) / 2
    if n == 1: return a1
    elif n == 0: return a0
    elif x1 == 0 and x2 == 0: return 0
    elif x1 == x2:
        alfa = a0
        beta = (a1 - alfa * x1) / x1
        return alfa * x1**n + beta * n * x1**n
    elif x1 == 0: beta = a0; alfa = 0
    elif x2 == 0: beta = 0 ;alfa = a0
    else:
        beta = (a1 - a0*x1) / (x2 - x1)
        alfa = a0 - beta
        return alfa * x1**n + beta * x2**n

print("Vrijednost n-tog clana niza pomocu formule:", int(formula(l1,l2,a0,a1,n)))
print("Vrijednost n-tog clana niza iz rekurzije:", rek(l1,l2,a0,a1,n))
    
