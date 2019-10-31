import re
import sys

def racine(a):
    c = a
    w = 0
    rac = 1.0
    while w < 100:
        rac = (rac + c)/2
        if rac == 0:
            c = a
        else :
            c = a/rac
        w = w + 1
    return (rac)

def partis(equation):
    av = re.compile(".*=")
    ap = re.compile("=.*")
    recup = re.compile("\-?[0-9]+\.?[0-9]*\^[0-9]+\.?[0-9]*")
    equation = equation.replace(" ", "")
    equation = equation.replace("X", "")
    equation = equation.replace("*", "")
    equation = equation.replace("--", "+")
    equation = equation.replace("+-", "-")
    equation = equation.replace("-+", "-")
    equation = equation.replace("++", "+")
    avant = "".join(av.findall(equation))
    avant = avant.replace("=", "")
    apres = "".join(ap.findall(equation))
    apres = apres.replace("-", "|")
    apres = apres.replace("=", "+")
    apres = apres.replace("+|", "|")
    apres = apres.replace("++", "+")
    apres = apres.replace("+", "-")
    apres = apres.replace("|", "+")
    avant = recup.findall(avant)
    apres = recup.findall(apres)
    list = avant + apres
    return (list)

def solver(a, b, c, deg):
    if deg == 0:
        if c == 0:
            print "\033[0;35mil y a une infinite de solutions\033[0;0m"
        else:
            print "\033[0;35mil n'y a aucune solution\033[0;0m"
    else:
        if deg == 1:
            res = -1 * (c / b)
            print "\033[0;35mil existe une unique solution : \033[0;0mX =" , res
        else:
            delta = (b * b) - (4 * a * c)
            if delta == 0:
                print "\033[0;34mdelta est nul, \033[0;0mdelta =", delta
                res = (-1 * b) / (2 * a)
                print "\033[0;35mil existe une unique solution :\033[0;0m X =", res
            else:
                if delta > 0:
                    print "\033[0;34mdelta est strictement positif,\033[0;0m delta =", delta
                    x1 = ((-1 * b) - racine(delta)) / (2 * a)
                    x2 = ((-1 * b) + racine(delta)) / (2 * a)
                    print "\033[0;35mil existe deux solutions, \033[0;0mX1 =", x1, "\033[0;35met \033[0;0mX2 =", x2
                else:
                    print "\033[0;34mdelta est strictement negatif, \033[0;0mdelta =", delta
                    xr = (-1 * b) / (2 * a)
                    x1i = (-1 * racine(-1 * delta)) / (2 * a)
                    x2i = (racine(-1 * delta)) / (2 * a)
                    aff = "\033[0;35mil existe deux solution imaginaire,\033[0;0m X1 = " + str(xr) + " + " + str(x1i) + "i " + "\033[0;35met \033[0;0mX2 = " + str(xr) + " + " + str(x2i) + "i"
                    aff = aff.replace("+ -", "- ")
                    print aff
    return (1)

def resolve(list):
    i = {}
    l = 0
    ver = re.compile("\-?[0-9]+\.?[0-9]*\^[0-9]+\.?[0-9]*")
    i[0] = 0
    i[1] = 0
    i[2] = 0
    list.append("fin")
    while ver.search(list[l]):
        term = list[l].split("^")
        k = float(term[1])
        j = float(term[0])
        try:
            i[k] = i[k] + j
        except:
            i[k] = 0
            i[k] = i[k] + j
        l = l + 1
    deg = degres(i)
    compt = 0
    result = ""
    while compt <= deg:
        try:
            if i[compt] != 0:
                if result == "":
                    result = result + str(i[compt]) + " * X^" + str(compt)
                else:
                    result = result + " + " + str(i[compt]) + " * X^" + str(compt)
            compt = compt + 1
        except:
            compt = compt + 1
    result = result.replace("+ -", "- ")
    if result == "":
        result = "0 * X^0"
    print "\033[0;32mla forme reduite est :\033[0;0m", result, "= 0"
    if deg == 0 or deg == 1 or deg == 2:
        print "\033[1;34mequation gerer de degres :\033[0;0m", deg
        solver(i[2],i[1],i[0],deg)
    else:
        print "\033[0;31mequation non gerer de degres :\033[0;0m", deg
    return (result)

def degres(dic):
    do = 0
    for cle,valeur in dic.items():
        if valeur != 0 and cle > do:
            do = cle
    return(do)

equ = ""
long = 1
if len(sys.argv) > 1:
    while long < len(sys.argv):
        print "\033[1;33mresolution de l'equation numero :\033[0;0m", long
        resolve(partis(sys.argv[long]))
        long = long + 1
    try:
        retry = input("voulez vous me donnez une autre equation a resoudre ? (\"o\"/\"n\") : ")
    except:
        print "\033[0;31mpas de nouvelle essay\033[0;0m"
        retry = "n"
    while retry == "o":
        while equ == "":
            try:
                equ = input("donnez votre equation "" : ")
            except:
                print "\033[0;31mequation mal entrer\033[0;0m"
                equ = ""
        resolve(partis(equ))
        try:
            retry = input("voulez vous me donnez une autre equation a resoudre ? (o/n) mettez votre reponse "" : ")
        except:
            print "\033[0;31mpas de nouvelle essay\033[0;0m"
            retry = "n"
else:
    print "\033[0;31mVeuillez passer au moin un argument!\033[0;0m"

