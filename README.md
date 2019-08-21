# Ejercitaci ́on: uso de clases

### La ejercitaci ́on consiste en completar las funciones especificadas. Todos los ejer-

### cicios pueden resolverse editando el archivosrc/funciones.cpp. A continuaci ́on se

### presentan las especificaciones de las funciones. Los primeros ejercicios pueden

### resolverse usando los m ́odulosset,mapyvectorde la biblioteca standard. Lue-

### go ser ́a necesario usar m ́odulos de la c ́atedra. Especificaciones de referencia se

### encuentran al final del enunciado.

### En el paquete del taller se encuentran tests para las funciones a implementar.

### Los tests pueden compilarse usando el targettestsejercitacionen CLion.

### Los tests tambi ́en pueden compilarse y ejecutarse sin usar CLion. Para ello:

### 1. En una consola ubicarse en el directorio ra ́ız del proyecto. En este deber ́ıa

### haber un archivoCMakeLists.txt.

### 2. Ejecutar el comando$ > cmake .(incluyendo el punto al final). Esto gene-

### rar ́a un archivoMakefile.

### 3. Ejecutar el comando$ > make TTTdondeTTTes uno de los targets

### mencionados anteriormente. Esto crear ́a un ejecutable con el nombre del

### target en el directorio actual.

### 4. Ejecutar el comando$ > ./TTTsiendoTTTel nombre del target utilizado

### anteriormente. Esto correr ́a el ejecutable.

### Una vez que se hacen modificaciones en el programa, no es necesario volver a

### ejecutarcmake, basta con hacermake TTT && ./TTT.

## Ejercicio 1

### quitarrepetidos( in s : secu(int))→ res :secu(int)

### Pre ≡ {true}

### Post ≡ {

```
Mismos elementos: (∀x :int) (pertenece(x, res) ⇐⇒pertenece(x, s))
Sin repetidos res: (∀i, j: nat) (i, j≤long(res)⇒res[i] = res[j] ⇐⇒i = j)
```
}
**Descripci ́on:** Devuelve una secuencia con los mismos elementos pero sin repetidos.

## Ejercicio 2

Si al resolver el ejercicio 1 no usasteset, resolverlo nuevamente con este m ́odulo.


## Ejercicio 3

mismoselementos( **in** _a_ : secu(int), **in** _b_ : secu(int))→ _res_ :bool
**Pre** ≡ {true}
**Post** ≡ {res ⇐⇒ (∀x :int) (pertenece(x, a) ⇐⇒pertenece(x, b))}
**Descripci ́on:** Verifica si las dos secuencias tienen los mismos elementos, sin importar
el orden o la cantidad de apariciones.

## Ejercicio 4

Si al resolver el ejercicio 3 no usasteset, resolverlo nuevamente con este m ́odulo.

## Ejercicio 5

contarapariciones( **in** _s_ : secu(int))→ _res_ :dict(int,int)
**Pre** ≡ {true}
**Post** ≡ {

```
clave correctas: (∀x :int) (pertenece(x, s)⇐⇒ x∈claves(res))
apariciones correctas: (∀x :int) (x∈claves(res)⇒obtener(x, res) = canti-
dadapariciones(x, s)
```
}
**Descripci ́on:** Genera un diccionario donde cada elemento distinto que aparece en la
secuencia de entrada se asocia con la cantidad de apariciones del mismo, siempre y
cuando aparezca al menos una vez.

cantidadapariciones : _α_ x×secu( _α_ ) s −→ nat

cantidadapariciones(x, s) ≡ **if** long(s) = 0 **then**
0
**else
if** prim(s) = x **then** 1 **else** 0 **fi** + canti-
dadapariciones(x, fin(s))
**fi**

## Ejercicio 6

filtrarrepetidos( **in** _s_ : secu(int))→ _res_ :secu(int)
**Pre** ≡ {true}
**Post** ≡ {(∀x :int) (pertenece(x, res) ⇐⇒ pertenece(x, s)∧cantidadapariciones(x,
s) = 1)}
**Descripci ́on:** Elimina los elementos con m ́as de una aparici ́on de la lista de entrada.


## Ejercicio 7: For-range

Implementar la intersecci ́on de conjuntos.

interseccion( **in** _a_ : conj(int), **in** _b_ : conj(int))→ _res_ :conj( _α_ )
**Pre** ≡ {true}
**Post** ≡ {(∀x : _α_ ) (x∈res ⇐⇒x∈a∧x∈b)}
**Descripci ́on:** Intersecci ́on de los conjuntos a y b.

## Ejercicio 8

agruparporunidades( **in** _s_ : secu(int))→ _res_ :dict(int, conj(int))
**Pre** ≡ {Sin repetidos: (∀i, j : nat) (i, j _<_ long(s)⇒s[i] = s[j] ⇐⇒i = j)}
**Post** ≡ {

```
Est ́an todos los elementos: (∀x :int) (pertence(x, s) ⇐⇒ (∃y :int) (def?(y,
res)∧x∈obtener(y, res)) )
Est ́an en la definici ́on correcta: (∀k :int) (k∈claves(res)⇒(∀s :int) (perte-
nece(s, obtener(k, res))⇒s mod 10 = k) )
No hay grupos vac ́ıos: (∀k :int) (k∈claves(res)⇒ ¬ ∅?(obtener(k, res)))
```
}
**Descripci ́on:** Agrupa los elementos de la secuencia seg ́un el d ́ıgito menos significativo.

## Ejercicio 9

traducir( **in** _tr_ : secu(tupla(char,char)), **in** _str_ : secu(char))→ _res_ :secu(char)
**Pre** ≡ {Sin claves repetidas: (∀i, j : nat) (i, j _<_ long(tr)⇒ _π_ 1 (tr[i]) = _π_ 1 (tr[j]) ⇐⇒
i = j)}
**Post** ≡ {

```
Mismos elementos: long(res) = long(str)
Traducci ́on: (∀i : nat) (i < long(str)⇒
(∃j : nat) ( j < long(tr)∧ π 1 (tr[j]) = str[i]∧res[i] = π 2 (tr[j]) )∨
(∀j : nat) ( j < long(tr)∧ π 1 (tr[j]) 6 = str[i]∧str[i] = res[i])
)
```
}
**Descripci ́on:** Traduce el stringstrcaracter por caracter usando las asociaciones en
tr. Sitrno tiene ninguna asociaci ́on, el caracter queda igual.

## Ejercicio 10: Algobot

En Algoritmos y Estructuras de Datos 2 los talleres y TPs se entregan por mail. En
el mail se pone como asunto la lista de libretas universitarias separadas por;. Por
ejemplo, un equipo de dos personas pondr ́ıa como asunto:103/92;05/04. Adem ́as, el
mail tiene como adjunto los archivos de la entrega.


Quien se encarga de procesar estos mails es _el algobot_. Entre sus capacidades, el al-
gobot puede conectarse al gmail de la materia y bajar los mails sin leer que hayan
llegado. Una vez bajados estos mails es necesario procesarlos. En los siguientes ejerci-
cios vamos a implementar algunos de estos procesos. Para ello, vamos a modelar parte
del procesamiento de mails usando tres TADs: _Mail_ , _Fecha_ y _LU_. Para cada uno de los
TADs vamos a tener una implementaci ́on en C++ que vamos a utilizar en los ejercicios
siguientes. En el ap ́endice de este enunciado se encuentran los TADs y las interfaces
de los m ́odulos en C++ (ver al final).

Una de las primeras tareas que realiza el algobot con los mails con las entregas de
TPs, es revisar que no haya ning ́un integrante que participe en m ́as de un grupo.
Considerando que cada mail tiene un conjunto de LUs en su asunto, tenemos que
revisar que estas no se repitan. No obstante, un mismo grupo puede env ́ıar varias
entregas antes del horario de entrega, por lo que las libretas pueden repetirse pero
siempre en conjuntos iguales. El problema a resolver es decidir si, dado una lista de
mails, hay alg ́un integrante que haya aparecido en m ́as de un grupo.

integrantesrepetidos( **in** _s_ : secu(Mail))→ _res_ :bool
**Pre** ≡ {(∀m : Mail) (pertenece(m, s)⇒asuntovalido(m))}
**Post** ≡ {res =¬(∀i, j : nat) (i, j _<_ long(s)∧i 6 = j⇒
libretas(s[i]) = libretas(s[j])∨libretas(s[i])∩libretas(s[j]) =∅)}
**Descripci ́on:** Devuelve true si entre los mails hay dos grupos distintos con integrantes
en com ́un.

## Ejercicio 11

Por motivos varios, es com ́un que los grupos entreguen los TPs varias veces antes del
horario final. Por ejemplo, entre la primera y la ́ultima entrega encuentran errores,
los corrigen y env ́ıan un nuevo mail. Otro error com ́un es enviar el mail sin archivos
adjuntos y luego mandar otro mail que s ́ı tiene la entrega. Considerando esto, podr ́ıa
pasar que haya primero un mail del grupo con la entrega con errores, luego un mail
sin adjuntos y luego el mail con la entrega corregida. Por este motivo, el algobot, al
procesar todos los mails con entregas, debe quedarse con el ́ultimo mail de cada grupo
que tiene adjuntos. Esto nos da la siguiente especificaci ́on.

entregasfinales( **in** _s_ : secu(Mail))→ _res_ :dicc(conj(LU), Mail)
**Pre** ≡ {(∀m : Mail) (pertenece(m, s)⇒asuntovalido(m))}
**Post** ≡ {

```
Est ́an los grupos con entregas: (∀g : conj(LU)) (g∈claves(res)⇐⇒ (∃i : nat)
(i < long(s)∧libretas(s[i]) = g∧adjunto(s[i])))
El mail asociado es el ́ultimo con adjunto: (∀g : conj(LU)) (g∈claves(res)⇒
(∀i : nat) (i < long(s)⇒(¬adjuntos(s[i])∨libretas(s[i]) 6 = g)∨(fecha(s[i])≤
fecha(obtener(g, res))) ) )
```
}
**Descripci ́on:** Devuelve un diccionario que asocia, a cada grupo que haya hecho alguna
entrega con adjuntos, el ́ultimo mail que envi ́o con alg ́un adjunto.


# Ap ́endice

## TADs

**TAD** Mail

```
g ́eneros mail
```
```
igualdad observacional
```
```
(∀ m 1 ,m 2 : mail)
```
###      

```
m 1 =obs m 2 ⇐⇒
```
###      

```
asunto( m 1 ) =obs
asunto( m 2 ) ∧L
fecha( m 1 ) =obs
fecha( m 2 ) ∧L
adjuntos( m 1 ) =
adjuntos( m 2 )
```
###      

###      

```
observadores b ́asicos
```
```
asunto : mail −→ string
```
```
fecha : mail −→ fecha
```
```
adjuntos : mail −→ bool
```
```
generadores
```
```
nuevoMail : string asunto×fecha fecha×bool adjuntos −→ mail
```
```
otras operaciones
```
```
asuntovalido : mail −→ bool
```
```
libretas : mail m −→ conj(LU) {asuntovalido(m)}
```
```
axiomas ∀ s,f,b : string,fecha,bool
asunto(nuevoMail(s,f,b)) ≡ s
```
```
fecha(nuevoMail(s,f,b)) ≡ f
```
```
adjuntos(nuevoMail(s,f,b))≡ b
```
Por simplicidad y falta de relevancia para el enunciado, no escribimos la axioma-
tizaci ́on de las operacioneslibretasyasuntovalido

**Fin TAD**

#### TAD LU

```
g ́eneros lu
```
```
igualdad observacional
```

```
(∀ lu 1 ,lu 2 : lu)
```
### (

```
lu 1 =obs lu 2 ⇐⇒
```
### (

```
numero( lu 1 ) =obs
numero( lu 2 ) ∧L
a ̃no( lu 1 ) =obsa ̃no( lu 2 )
```
### ))

```
observadores b ́asicos
numero : lu −→ nat
```
```
a ̃no : lu −→ nat
```
```
generadores
nuevaLU : nat num×nat a −→ lu
```
```
otras operaciones
```
- =•: lu×lu −→ bool

```
axiomas ∀ n,a,l 1 ,l 2 : nat,nat,lu,lu
numero(nuevaLU(n,a)) ≡ n
```
```
a ̃no(nuevaLU(n,a))≡ a
lu 1 = lu 2 ≡ numero( lu 1 ) = numero( lu 2 )∧a ̃no( lu 1 ) = a ̃no( lu 2 )
```
**Fin TAD**

**TAD** Fecha

```
g ́eneros fecha
```
```
otras operaciones
```
- _<_ • : fecha −→ bool
Por simplicidad y falta de relevancia para el enunciado, consideramos Fecha como
un tad que representa un momento en el tiempo y puede compararse con el operador
_<_.

**Fin TAD**

## Clases C++

### Mail

**class Mail** {
**public** :
string asunto();
Fecha fecha();
**bool** adjunto();
_// PRE: El asunto tiene un formato v ́alido para extraer libretas_
set<LU> libretas();
};


### LU

**class LU** {
**public** :
**int** numero();
**int** anio();
};

### Fecha

**class Fecha** {
**public** :
_// Operador para comparar tiempos._
**bool operator** <(Fecha otro);
};


