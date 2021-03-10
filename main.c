//
//  main.c
//  dizionario
//
//  Created by Francesco D'apolito



/*
 Viene inclusa la libreria <<stdio.h>>  che sta per "standard input-output. header", è l'header file della libreria standard del C che contiene definizioni di macro, costanti e

 dichiarazioni di funzioni e tipi usati per le varie operazioni di input/output.
 */

#include <stdio.h>

/*
 Viene la libreria "funzioni.h", il nome del file è compreso tra doppi apici, quindi la ricerca del file avviene, all'interno della directory in cui sta avvenendo la compilazione,

 ovvero la directory in cui si trova il file di testo contenente il codice C, in questo file sono scritti tutti i prototipi delle funzioni create, ed usate nel programma.
 */

#include "funzioni.h"

int main() {
    
    /*
     
     Dichiarazione di quattro variabili di tipo intero.
     
     n     -- contiene il numero delle parole inserite nel dizionario.
     
     indice -- viene inizializzato a -1, perchè sarà passato come indirizzo ad una funzione, per poi essere derefernziato e cambiato di valore.
     
     scelta -- questa variabile è utilizzate per controllare la condizione del while, parte vera per permettere all'utente di inserire la parole, a runtime può cambiare valore
     
     i      -- variabile contatore ciclo iterativo
     
     */
    
    int n = 5,    indice = -1,    scelta=TRUE,   i;
   
    
    /*
     Tipo di dato strutturato che viene definito nell'header file "funzioni.h" attraverso la typedef prende il nome Parola, per un facile e più chiaro utilizzo nel programma.
    Abbiamo il puntatore a variabile Parole
     */
    
    Parola *parole;
    
    /*
     allocazione dinamica atta a contenere un valore di tipo Parola, la funzione malloc è utile per allocare un'area di memoria durante l'esecuzione del programma.
     Per evitare possibili problemi con i compilatori è consigliabile effettuare un'operazione di cast per adeguare il valore di ritorno al tipo di puntatore richiesto.
    */
    
    parole=(Parola *)malloc(sizeof(Parola));
    
    /*
     Viene effettuato un controllo nel caso il puntatore assume il valore NULL, è buona pratica effettuare un test.
     */
    if(parole == NULL)
    {
        printf("\nAllocazione fallita !");
        exit(0);
    }
    
    /*
     Variabile di tipo char , chiave --- serve proprio da array per contenere i caratteri della parola inserita dall'utente, la quale sarà poi ricercata nel dizionario.
     
     */
    
    char chiave[MAX_PAROLA];
     
    
    //presentazione
    
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t****************************\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t* BENVENUTI NEL DIZIONARIO *\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t****************************\n\n");
    
    /*
     E' stato inserito in questo caso un'istruzione post condizionale do-while.
     Ciclo do while, permette di eseguire le istruzioni contenute al suo interno, per poi effettuare una verifica, se l'espresione di controllo sia vera, in questo caso il controllo viene effettuato sul valore della variabile scelta.
    */
    
    do{
        
        
                        //la funzione definisci parole va a definire nel dizionario le parole contentute
        
                        definisci_parole(parole);
    
        
                       
                        //effettuando una funzione chiamata >>ord_ins_parole<< permette al nostro elenco di essere ordinato;
        
                        ord_ins_parole(parole,n);
        
                    //questa è la fase dove si va a video a chiedere all'utente di inserire la parola da ricercare
        
                    printf("\nParola da ricercare : ");
                    
                    //la funzione scanf : sintassi ("<Stringa di formato>", <Variabile>),consente di acquisire una sequenza di caratteri (lettere o cifre) dalla tastiera e di memorizzarli all'interno di opportune variabili.
        
                        scanf("%s",chiave);
                  
                        //Creo una nuova funzione chiamata <<lettere maiuscole>> nel caso in cui l'utente decide di ricercare una parola scrivendola alternando lettere maiuscole e minuscole, tale parole è contenuta nel dizionario ma non avendo omogeneità di caratteri può creare difficoltà al programma quando va a ricercare la parola, creo un algoritmo che permetti di trasformare tutti i caratteri inseriti in caratteri maiuscoli.
        
                    lettere_maiuscole(chiave);
        
                
                    
                    //la funzione prende come argomenti,la chiave,le parole del dizionario e l'indirizzo della variabile indice che come ho detto prima ,va ad essere dereferenziato successivamente, quando viene definita nel file funzoni.c ed n indica la lunghezza dell'array parole, ovvero l'array di struct formato dalle parole del dizionario
        
                    if(ricerca_chiave(chiave,parole,n,&indice) >0 )
                    {
                        
                        //due printf, il primo mostra a video nel caso di esito positivo dell'if, la parola cercata, il secondo il suo significato, l'indice assume la posizione della parola che l'utente ha cercato.
                        
                        printf("\nPAROLA CERCATA = %s\n\n",chiave);
                        printf("SIGNIFICATO = %s\n",parole[indice].significato);
                    
                    }
                    
                    else
                        //arriviamo all'else nel caso in cui la parola inserita non è contenuta nel dizionario, qui viene chiamata una funzione <<inserisci_parola>>, prende come argomenti l'array di parole e l'indirizzo della varibile n, nel caso in cui l'utente vuole inserire la parola, il valore della n va modifcato.
                        
                        n= inserisci_parola(parole,&n);
                    
                        //questa funzione permette di conoscere la parola contenuta nel dizionario avente più consonanti
        
                        consonanti(parole,n);

        //i valori contenuti nella variabile chiave vengono azzerati nel caso in cui l'utente successivamente ne vorrebbe inserire di nuovi, ad esempio se decide di inserire una nuova parola.
        
        for(i=0; i<=n; i++)
        chiave[i]= 0;
        
      // Viene chiesto all'utente se vuole inserire una nuova parola il valore di tale scelta viene inserito in una variabile chiamata scelta.
        
        printf("\nVuoi cercare una nuova parola ?\n1.SI\t2.NO\n");
        scanf("%d",&scelta);
        
        
        //in questo caso se in scelta è contenuto un valore diverso da 1, scelta assume il valore FALSO, e successivamente, quando si effettua l'espressione di controllo nel while, il ciclo termina la sua esecuzione.
        
        if(scelta != 1)
            scelta = FALSE;
        
      
    }while(scelta);

    
    
    return 0;
}

