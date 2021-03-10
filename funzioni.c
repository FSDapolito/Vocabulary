//
//  funzioni.c
//  dizionario
//
//  Created by Francesco D'apolito

//bisogna includere l'header file funzioni.h perchè in tale file sono inclusi tutti i prototipi delle funzioni chiamanti, le quali sono definte proprio  in questo file <funzioni.c>

#include "funzioni.h"

//vado ad includere una libreria chiamata string.h perchè in questo modo posso sfruttare alcune funzioni al suo interno per poter lavorare sulle stringhe

#include <string.h>

//per poter lavorare con una funzione _toupper la quale permette di trasformare ogni carattere minuscolo in maiuscolo vado ad includere questa libreria

#include <ctype.h>



//la function parola_consonanti ritorna un valore di tipo intero , prende come argomenti l'array di tipo struct che rappresenta l'intero dizionario e la dimensione n, la funzione viene chiamata nel main se l'utente chiede di voler conoscere la parola con più consonanti contenuta nel dizionario

int parola_consonanti(Parola parole[], int n)
{
    
    unsigned long m;
    int i,j,punteggio=0, punteggio_max = 0,indice = 0;

    for(i=0; i<=n; i++)
    {
        
        m = strlen(parole[i].nome);

        
        for(j=0; j<m; j++)
        {
            if(parole[i].nome[j] != 'A' && parole[i].nome[j] != 'E' && parole[i].nome[j] != 'I' && parole[i].nome[j] != 'O' && parole[i].nome[j] != 'U')
                punteggio++;
        }
       
        
        if(punteggio > punteggio_max)
        {
            punteggio_max = punteggio;
            indice = i;
        }
        m=0;
        punteggio = 0;
        
    }
        
    return indice;
}


//anche se le parole vengono inserite in modo casuale, questa funzione permette di ordinare attarverso un algoritmo di ordinamento per inserimento, l'elenco di parole in ordine alfabetico

void ord_ins_parole(Parola *parole,int n)
{
    int i,j;
    
    Parola el_da_ins;
    
    for(i=1; i<n; i++)
    {
        el_da_ins = parole[i];
        j=i-1;
        
        
        while( j>=0  &&  strcmp(el_da_ins.nome,parole[j].nome) < 0 )
        {
            parole[j+1] = parole [j];
            j--;
        }
        
        parole[j+1] = el_da_ins;
    }
}



//questa funzione permette di potere trasformare la parola da ricercare inserita dall'utente, in una parola formata solo da caratteri maiuscoli, si evitano problemi di ricerca nel caso l'utente inserisca una parola avente non omogeneità di caratteri ma tale parola è contenuta nel dizionario.


char *lettere_maiuscole( char *chiave)
{
    unsigned char *p = (unsigned char *) chiave;
    
    while (*p) {
        *p= _toupper((unsigned char )*p);
        p++;
    }
    
    return chiave;
}


//la function ricerca chiave, ritorna un valore di tipo intero, prende come argomenti la chiave che corrisponde alla parola inserita dall'utente, l'array di tipo Parola, che corrisponde alle parole del dizionario, la dimensione che corrisponde alla variabile n, e l'indirizzo dell'indice da ritornare che poi va ad essere dereferenziato per poter accedere al valore di tale variabile e nel caso modificarlo


int ricerca_chiave(char chiave[] ,Parola parole[],int n,int *indice)
{
    int i;
    
    //attraverso un ciclo for vado a controllare se nell'array di tipo struct è inserita la parola richiesta
    
    for(i=0; i<=n; i++)
    
    //la function strcmp, definita nella libreria string.h va ad effettuare un confronto tra stringhe e restituisce 0 se le due stringhe confrontato sono uguali
    
        if(strcmp(chiave,parole[i].nome)==0)
        {
            *indice = i;
                return 1;
        }
    
  return 0;
}



//questa funzione permette nel caso in cui la parola inserita non sia contenuta nel dizionario, di poterla inserire, riceve in chiamata  l'array intero di parole e l'indirizzo della dimensione, viene effettuata la dereferenziazione perchè bisogna accedere a tale variabile e modificarne il valore ( incrementandolo ogni volta che viene chiamata la funzione)


int inserisci_parola(Parola parole[],int *n)
{
    int inserire = 0;
    char parola[MAX_PAROLA], significato[MAX_SIGNIFICATO];
        
        printf("\nLa parola inserita non c'e' nel dizionario\n\n");
        printf("\nVuoi inserire la parola nel dizionario ?\n1.SI\t2.NO\n");
        scanf("%d",&inserire);
    
        
        if(inserire == 1)
        {
            *n= *n + 1;
            printf("\n\nDigita la parola che vuoi inserire: ");
            scanf("%s",parola);
            
            
            lettere_maiuscole(parola);
           
            
            strcpy(parole[*n].nome,parola);
       
            
            printf("\nInserisci il significato : ");
            fflush(stdin);
            fgets(significato,MAX_SIGNIFICATO,stdin);
            
                             
            strcpy(parole[*n].significato,significato);
   
            
        }

    
    return *n;
}


//questa funzione permette di visualizzare a display la parola contenuta nel dizionario avente più consonanti

void consonanti(Parola parole[], int n)
{
    
    int conson = 0;
    
    printf("\n\nVuoi visualizzare la parola che contiene più consonanti: 1.SI\t2.NO\n");
    scanf("%d",&conson);

    if(conson == 1)
        //la funzione << parola_consonanti >> è stata inserita come indice, all'interno dell'array di parole, proprio perchè tale funzione prende come argomenti di chiamata l'array di parole ed il suo size e va a ritornare un valore intero che corrisponde all'indice con la parola con più consonanti, e tale valore ci permette di accedere alla variabile che conterrà il nome di tale parola, il quale andrà ad essere poi stampato in output grazie ad una printf
        printf("\n[%s]  e'la parola che contiene più consonanti nel dizionario\n\n\n",parole[parola_consonanti(parole,n)].nome);
}



