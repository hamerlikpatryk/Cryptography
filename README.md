# Kryptography
Umieszczam tu wykonane zadania z Kryptografii (w języku C++)

Niech p = 191 i q = 523 (p i q odpowiednio 43 oraz 99 z kolei liczbą pierwszą)(należy wpisać którą liczbą jest czyli 43  99). Wtedy:
n = pq = 99893
m= (p−1)(q−1) = 99180
Należy „wylosować” etakie, że NWD(e, m) = 1, np. e= 601
Wykorzystując rozszerzony algorytm Euklidesa, sprawdzając, że
N W D(e, m) = 1 wyznacza się liczbę x= 6601.
Ponieważ
x > 0 to poszukiwana d=x
Otrzymuje się klucz publiczny (99893,601) oraz prywatny (99893,6601)
