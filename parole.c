//  parole.c
//  dizionario
//  
//  Created by Francesco D'apolito
//
#include <stdio.h>
#include "funzioni.h"
#include <string.h>





//questa funzione in modo molto semplice va a definire le parole che vogliamo inserire nel dizionario

void definisci_parole(Parola *parole)
{
 
    strcpy(parole[0].nome,"ALGORITMO");
    strcpy(parole[0].significato,"s. m. [dal lat. mediev. algorithmus o algorismus, dal nome d’origine, al-Khuwārizmī, del matematico arabo Muḥammad ibn Mūsa del 9° sec. (così chiamato perché nativo di Khwarizm, regione dell’Asia Centrale)]. – 1. Termine che indicò nel medioevo i procedimenti di calcolo numerico fondati sopra l’uso delle cifre arabiche. Nell’uso odierno, anche con riferimento all’uso dei calcolatori, qualunque schema o procedimento matematico di calcolo; più precisamente, un procedimento di calcolo esplicito e descrivibile con un numero finito di regole che conduce al risultato dopo un numero finito di operazioni, cioè di applicazioni delle regole. In partic., a. euclideo, metodo per determinare il massimo comune divisore di due numeri interi a e b, basato su divisioni successive. 2. In informatica, insieme di istruzioni che deve essere applicato per eseguire un’elaborazione o risolvere un problema. 3. In logica matematica, qualsiasi procedimento «effettivo» di computo di una funzione o di decisione di un insieme (o predicato), cioè qualsiasi procedimento che consenta, con un numero finito di passi eseguiti secondo un insieme finito di regole esplicite, di ottenere il valore della funzione per un dato argomento, o di decidere se un dato individuo appartiene all’insieme (o soddisfa il predicato).");
    
    
    strcpy(parole[1].nome,"INSERIMENTO");
    strcpy(parole[1].significato,"s. m. [der. di inserire]. – L’atto di inserire, di essere inserito dentro un altro oggetto o in mezzo ad altri oggetti; in senso proprio, indica propriam. il fatto materiale di inserire (con usi quindi meno ampî di inserzione, che indica anche l’effetto, il trovarsi inserito, e la cosa stessa inserita): l’i. dei nuovi dati nel computer, delle tavole fuori testo in un volume o in una segnatura (come operazione di legatoria), di nuove voci nelle bozze di un vocabolario; l’i. della spina nella presa di corrente; riscrivere un elenco per l’i. di nuovi nominativi. Più frequente in senso fig., con riferimento a persone o gruppi di persone: l’i. dell’individuo nella società; l’i. dei diversamente abili nel mondo del lavoro; l’i. di un partito nella maggioranza di governo.");
    
    
    
    strcpy(parole[2].nome,"DEDIZIONE");
    strcpy(parole[2].significato,"s. f. [dal lat. deditio -onis, der. di dedĕre; v. dedito]. – 1. ant. L’arrendersi al nemico, per capitolazione o per volontaria sottomissione: gli assediati si appropinquavano alla necessità della d. (Guicciardini). 2. fig. Il dedicarsi interamente e con spirito di sacrificio a una persona, a un’attività, a un ideale: far d. di sé alla famiglia, alla patria; amare con d. assoluta; combattere con d. per il trionfo di una causa.");
    
    strcpy(parole[3].nome,"MATEMATICA");
    strcpy(parole[3].significato,"s. f. La scienza che in origine e a livello elementare si occupa di problemi relativi ai numeri ( aritmetica ) e alle figure ( geometria ); attualmente è suddivisa in diverse branche ( algebra, analisi, topologia, m. applicate, ecc.), tutte caratterizzate da rigorosi metodi di formalizzazione, di calcolo e di deduzione.");
    
    
   
    
    strcpy(parole[4].nome,"BINARIO");
    strcpy(parole[4].significato,"agg. [dal lat. tardo binarius, der. di bini «due per volta»]. – 1. Composto di due unità, di due elementi: divisione b., nell’esercito, la divisione composta da due reggimenti di fanteria; stelle b., sinon. di stelle doppie. 2. Con sign. più tecnici: a. In biologia, divisione b., uno dei principali tipi di riproduzione asessuale o agamica dei protozoi per cui il citosoma si divide in due parti approssimativamente eguali. b. In chimica, composto b., costituito da due elementi (per es., cloruro di sodio, NaCl); sistema b., insieme di due componenti nella stessa fase (liquido-liquido) o in fasi diverse (liquido-solido, liquido-gas, ecc.).");
   
}
