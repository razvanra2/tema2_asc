tema 2 - asc
Razvan Radoi
331 CA
=======
## Explicatii realizare tema
	Varianta neoptimizata:
	
	Varianta neoptimizata implementeaza operatia ceruta, in modul clasic.
	Se aloca spatiu pt At, Bt, doua matrice auxiliare si matricea resultat.
	Se calculeaza matricele transpuse, apoi se fac inmultirile, apoi adunarea.
	Se determina matricea upper triangular si se face patratul ei.
	
	Varianta optimizata:

	Varianta optimizata urmareste scheletul celei neoptimizate (conform cerintei,
	complexitatea temporala este aceeasi - O(n^3)).
	Diferentele constau in faptul ca se folosesc pointeri care sa optimizeze accesul
	la memorie (pe linii/coloane) si de asemenea se foloseste tehnica register sum
	pentru inmultire, astfel incat nu se acceseaza mereu memoria din matrice, ci doar o data
	la n operatii.

	Varianta optimizata cu flags:

	Am ales sa folosesc -Ofast pentru compilare. Conform gcc.gnu.org, Ofast are toate
	optimizarile din O3 + --fast-math + --fstack-arrays.
	-Ofast nu este sigur pentru orice fel de operatii, insa in urma testarii, rezultatele
	au fost OK pentru toate cele 3 matrice (small/medium/large) asa ca am considerat ca 
	este intradevar cea mai buna varianta.

	Varianta BLAS:
	
	Pentru blas, am folosit functia dgemm.
	Pentru inmultirile cu matrice transpuse, am activat flag-ul de transpunere, apoi
	pentru rezultat am folosit aceeasi functie pentru ridicarea la patrat. 

## Analiza blas vs neopt vs opt_m vs opt_f

	Conform tabelelor disponibile aici[0]:
	
	Varianta blas a fost de departe cea mai rapida, data fiind optimizarea serioasa facuta pe inmultirea matricelor din biblioteca atlas.
	In mod evident, atat pe icc cat si pe gcc, varianta neoptimizata a fost cea mai lenta.
	In cazul opt_m vs opt_f, atat pe icc cat si pe gcc rezultatele sunt comparabile, pentru dimensiunile small si medium ale matricelor. Reala diferenta a compilarii cu -Ofast se vede in cazul large, unde opt_f este mult mai rapida (jumatate din timpul opt_m), pe gcc cat si pe icc.

## Analiza icc vs gcc:

	General, executabilele realizate de gcc au fost mai rapide decat cele realizate de icc. Spre exemplu, pentru opt_f, large, executabilul realizat de gcc este cu 3 secunde mai rapid decat cel realizat de icc. Acesta este un test foarte relevant, dat fiind faptul ca conteaza mai ales performanta in optimizare a compilatorului, cat si marimea inputului.

## Grafice:

Toate graficele sunt atasate in arhiva, fiind disponibile si aici[0].
https://docs.google.com/spreadsheets/d/1xGZ-OEh_86DZ8bXVxr54k5ONkI3sf3HCyWzu190mJVw/edit?usp=sharing
