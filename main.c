



______________________________________________________________________________________________________________
**************************************************************************************************************
 Ici Tu noteras de manière concise et facilement compréhensible tout ce que tu auras appris sur le langage C
______________________________________________________________________________________________________________
**************************************************************************************************************

____________________________________________________________________________________________________________________________________________________________________________________________________
///PROGRAMATION MODULAIRE


Il y a deux types de fichiers différents :

    .h : Les fichiers header, ils contiennent les prototypes des fonctions.
         Egalement les directive de préprocesseur pour les constante symbolique
         et macros (#define). Mais également les directives pour la compilation
         conditionnelle (#if,#ifdef,...)


    .c : Les fichiers source, ils contiennent les fonctions elles-mêmes.








____________________________________________________________________________________________________________________________________________________________________________________________________
///GITBASH / GITHUB


Lorsque tu crée ton clone sur ta machine il est indépendant de tout autre fichier local, si tu veux travailler dessus en local, copie colle
le dossier ailleurs et supprime le .git qui le relie au depot distant. Ensuite fait toi juste un git init en local pour enregistrer les evolutions
du projet. Et une fois satisfais re copie colle les fichiers modifier dans le dossier cloner pour les push sur le depot distant.

Ne confond pas ton travail en local et ton travail en distant (origin). Meme si tu as suprimmer une branche en local,
ca ne veut pas dire que c est effectif sur le depot distant. sert toi des commandes specifiques pour supprimer la branche à distance.



Sans spécification chaque branche est créé par défaut à hauteur du dernier commit de la branche dans laquelle on se trouve.





(HEAD -> master)                       HEAD (bleu ciel) indique le dernier commit sur la branche ou tu te situe (ici master).

(origin/master)                        (en rouge) indique la place du dernier commit de ton fichier sur le depot distant (ici master).

(HEAD -> master, origin/master)        master (vert) indique ton dernier commit sur la branche, les commits locaux est distant sont aux meme niveaux ici.

(origin/branch2)                       (en rouge) indique la place du dernier commit de ton fichier sur le depot distant (ici branch2).

(branch2)                              (en vert) indique la position de ton dernier commit sur le depot local, ici tout les commits n'ont pas été push.






NAVIGUER DANS LES DOSSIER

pwd                 (Afficher position dans la memoire)

cd NomDuDossier     (Aller)

cd ..               (Retour)

ls                  (Afficher les fichier du dossie)

ls -la              (Affichage avancé)






LES BRANCHES ET COMMITS

git diff            (Afficher les modifications entre les commits)

git status          (Afficher l'etat du dossier sur la branche)

git log             (Afficher les commits du dossier)

git log --all       (Affiche tout les commits de toutes les branches ! y compris celle dans origin(distant) meme si elles sont suprimer en local)




git reset --hard HEAD~1                    (supprime dernier commit, marche aussi pour un merge)

git reset --hard                           (Annule le fichier en preparation)

git reset --hard "SHA 1"                   (Suprime le commit choisi)




git branch                                 (Afficher les differentes branches)

git checkout NomDeLaBranche                (Naviguer dans les branches)

git branch NomDeLaBranche                  (Nouvelle branche)

git checkout -b NomDeLaBranche "SHA 1"     (Nouvelle branche à partir d'un certain commit)

git branch -d NomDeLaBranch                (Supprime la branche en locale)

git push origin --delete NomDeLaBranche    (Supprime la branche dans le depot distant)




CREATION DU COMMIT DANS DOSSIER

git init                                (initialise un depot local)

git clone URLduDossier                  (clone un depot distant)




PREPARER LE FICHIER AVANT COMMIT

git add NomDuFichier                    (Selectionne le fichier)

git add .                               (Selectionne tout les fichier)



CREATION DU COMMIT

git commit -m "Commentaire"              (Ecrire un commentaire entre guillemet est oligatoir)



ENVOIE SUR DEPOT DISTANT

git push -u origin master               (Où master est la branche à pousser)

git push -f origin master               (Ecrase les fichiers distant)

git push --all --force origin           (envoie toutes les branches de force)








git fetch origin                 Récupère integralement toute les modifications du depot distant.

git pull                         Récupère les commits du depot distant de la branche sur laquelle on se trouve.











///Editeur rebase

Ouverture de l'editeur de rebase : git rebase -i master                          (pour gerer les commit ?)

                                   git rebase -i HEAD~1   pour modifier le dernier commit.    git rebase -i HEAD~3 pour modifier les 3 dernier commit.

Appuyez sur la touche Esc pour vous assurer que vous êtes en mode commande. ?

Appuyez sur la touche i pour écrire instruction.

Appuyez sur la touche :q! pour quitter l'éditeur sans sauvegarder les modifications.
                      :wq pour quitter l'editeur en ayant sauvegarder les modifications.


    Le : met l'éditeur en mode commande.
    q signifie quitter.
    w signifie write.
    ! signifie forcer, ce qui vous permet de quitter sans sauvegarder.














____________________________________________________________________________________________________________________________________________________________________________________________________
/// LES BIBLIOTHEQUES ET DIRECTIVE DE PREPROCESSEUR :


///Les Bibliotheques :

Les bibliothèques comprennes les fonctions de base stocker avec L'IDE.

pour inclure un fichier.h dans le dossier ou est installer l'IDE on utilise < >

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stddef.h>







///Les Directives De Preprocesseur :

Les directives permettent de définirs les constantes et macros.

pour inclure un fichier.h dans le dossier de votre projet on utilise " "


#define taille_max 100
#define taille_mini 2

(#define) remplace par 100 toute les fonctions qui prennent taille_max comme argument !
Permet de fluidifié le code et un meilleur controle également.




///Exemple

#define COUCOU() printf("Coucou");
#define AirDuCaree (taille_max * taille_mini)

int main(int argc, char *argv[]) //equivalent de int main ()

int fonction (int longeur, int largeur)
   {
    return longeur * largeur;
   }

 COUCOU()

 printf("la valeur de l*L = %d",fonction(taille_max,taille_mini));




///Autres Exemples


 Il est possible de mettre plusieurs lignes de code à la fois. Il suffit de placer un\  avant chaque nouvelle ligne.


 #define RACONTER_SA_VIE()   printf("Coucou, je m'appelle Brice\n"); \
                            printf("J'habite a Nice\n"); \
                            printf("J'aime la glisse\n");



 Il est possible aussi de créer une macro qui prend plusieurs paramètres.

 #define MAJEUR(age, nom) if (age >= 18) \
                    printf("Vous etes majeur %s\n", nom);

int main(int argc, char *argv[])
{
    MAJEUR(22, "Maxime")

    return 0;
}









///Les Conditions en Langage Préprocesseur

Elles permettent differentes compilations selon certaine conditions.

#if
    conditon1
#elif              //lire elseif
    condition2
#endif



#define WINDOWS



#ifdef WINDOWS
    /* Code source pour Windows */
#endif

#ifdef LINUX
    /* Code source pour Linux */
#endif

#ifdef MAC
    /* Code source pour Mac */
#endif


Eviter les inclusions infinies avec :

#ifndef FICHIER // Si la constante n'a pas été définie le fichier n'a jamais été inclus Alors :
#define FICHIER // On définit la constante pour que la prochaine fois le fichier ne soit plus inclus

/* Contenu de votre fichier .h (autres include, prototypes, define...) */

#endif








/// les constantes prédéfinies par le processeur



    __LINE__ donne le numéro de la ligne actuelle.

    __FILE__ donne le nom du fichier actuel.

    __DATE__ donne la date de la compilation.

    __TIME__ donne l'heure de la compilation.


Ca permet au programmeur de definir dans le code les endroids qui reste à deboguer. cela affichera à la lecture du code
le fichier, la ligne de code, et autres informations necessaire.


#include <stdio.h>

// Définition de la macro DEBUG avec la valeur 1
#define DEBUG 1

// Vérifie si la macro DEBUG est définie (oui == 1)
#ifdef DEBUG
// Si DEBUG est définie, cette macro affichera les messages de débogage
#define debug_print(fmt, ...) \
            fprintf(stderr, "DEBUG: %s:%d: " fmt, __FILE__, __LINE__, __VA_ARGS__)
#else
// Si DEBUG n'est pas définie, cette macro sera vide
#define debug_print(fmt, ...) \
            do {} while (0)
#endif

int main() {
    int x = 10;
    // Appel à la macro debug_print pour afficher un message de débogage
    // Si DEBUG est définie, le message contiendra le numéro de ligne et le nom du fichier.
    // ici on passe x comme argument juste pour montrer qu'on peut également prendre des variables en comptes.
    debug_print("x = %d\n\n", x);







____________________________________________________________________________________________________________________________________________________________________________________________________
/// MISE EN PAGE :


retour à la ligne : \n          /**"Vois comme c'est magique ! Aurai-tu découvert une nouvelle passion ? Ou serait-ce plus que ça...
                                    Trêve de plaisanterie !
                                    N'oublie pas les retours de ligne (\n) font planter la console si
 tabulation : \t                    tu les places après les appels de variable (exemple : scanf("%lf \n", &nombre1); !!
                                    Cela t'a causé bien des confusions, mon ami..." */












____________________________________________________________________________________________________________________________________________________________________________________________________
/// LES RACOURCIS :


ctrl+shift+c = tout ce qui est sélectionner en commentaire d'une ligne









____________________________________________________________________________________________________________________________________________________________________________________________________
/// LES VARIALBES ET SPECIFICATEURS DE FORMAT (DRAPEAUX):



const : (VARIABLE_CONSTANTE_QUI_NE_SERA_JAMAIS_MODIFIABLE_APRES_INITIALISATION_!_A_ECRIRE_EN_MAJUSCULE);

static : A mentiionner devant la variable si on veut qu'elle existe que dans un seul fichier.

extern : A mentionner devant une variable qui à été initialisé dans un autre fichier !



int variable1, variable2, variable3; comment écrire plusieurs variables à la suite.


char(-128 à 127)||(0 à 255); %c (caractères), %d (entiers);

short(-32,768 à 32,767)||(0 à 65,535); %hd (entiers courts), %hu (unsigned entiers),
                                        %d (entiers), %u (unsigned entiers);

int(-2,147Mds à 2,147Mds)||(0 à 4,294Mds); %d (entiers), %u (unsigned entiers);

long(-2,147Mds à 2,147Mds)||(0 à 4,294Mds); %ld (entiers longs), %lu (unsigned entiers);

float(±1.18E-38 à ±3.4E38); (Précision : ~7 chiffres); %f; nombre flottant 45.75 un point !! pas de virgule !!

 "%e" : Nombre à virgule flottante en notation scientifique (exponentielle).
 "%E" : Nombre à virgule flottante en notation scientifique (exponentielle), lettres majuscules.


double(±2.23E-308 à ±1.8E308); (Précision : ~15 chiffres); %lf;

int test = 555;

printf("%d \n",test); affichage en decimale
printf("%x \n",test); affichage en hexadecimale
printf("%X \n",test); affichage en hexadecimale (lettres majuscules)
printf("%o \n",test); affichage en octale (base 8)



Taille de int : 4 octets                     printf("Taille de int : %lu octets\n", sizeof(int));
Taille de long : 4 octets                    printf("Taille de long : %lu octets\n", sizeof(long));
Taille de long long : 8 octets               printf("Taille de long long : %lu octets\n", sizeof(long long));
Taille de short : 2 octets                   printf("Taille de short : %lu octets\n", sizeof(short));
Taille de char : 1 octets                    printf("Taille de char : %lu octets\n", sizeof(char));
Taille de float : 4 octets                   printf("Taille de float : %lu octets\n", sizeof(float));
Taille de double : 8 octets                  printf("Taille de double : %lu octets\n", sizeof(double));
Taille de long double : 16 octets            printf("Taille de long double : %lu octets\n", sizeof(long double));







   ///Caster une variable

   Le fait de caster une variable en C consiste à convertir son type en un autre en créant
   une nouvelle variable avec le nouveau type voulu


    float nombreFloat = 3.14;
    int nombreEntier = (int)nombreFloat;

    printf("Float : %f\n", nombreFloat);
    printf("Entier : %d\n", nombreEntier);



cast explicit                Cast implicite

double x = 3.14;             int x = 10;
int y = (int)x;              double y = x;


____________________________________________________________________________________________________________________________________________________________________________________________________
/// LES CALCULS ET SYMBOLE :

adition = 5 + 5              modulo(0) = 10 % 5;  modulo(5) = 25 % 10;
incrementation(+1) : ++
soustraction = 10 - 5        puissance(125) = pow(5,3); //(base,exposant);
décrementation(-1) : --
multplication = 5 * 5        racine carrée(5) = sqrt(25)
division = 25 / 5

 les signes utilisable :    "==" est strictement éagal à          "+=" est égal à : A = A + B.
                            ">"  est supérieur à                  très utiles pour aditionner les valeurs
                            "<"  est inférieur à
      "!" est "est pas"     ">=" est supérieur ou égal à
      "&&" est "et"         "<=" est inférieur ou égal à
      "||" est "ou"         "!=" est différent de

ATTENTION !! L'opérateur = est utilisé pour attribuer une valeur à une variable !! A PAS UTILISER POUR TESTER UNE EGALITE !!


      pour les conditions en && et || retiens si je dis pas de connerie.. que pour les nombre compris entre 2 valeurs,
      on utilisera && et pour les nombres qui ne sont pas compris entre ces 2 valeurs on utilisera ||








____________________________________________________________________________________________________________________________________________________________________________________________________
/// LES CONDITIONS ET BOUCLES:

PRINTF("imprime du texte et appele des variable %d,%lf,%f",variable1,variable2,variable3);

SCANF("interoge l'operateur sur du texte et des nombres %d,%s",&nombre,&texte);



if(condition)              Pas de point-virgule après la condition if sinon ca provoque une instruction vide,
{                          ce qui signifie que le bloc suivant entre {} est toujours exécuté indépendamment de la condition.
 printf("fais ca !!");
}

else if(condition)
{
 printf("sinon fais ca !!");
}

else(tout le reste)
{
 printf ("sinon fais ca !!")
}




switch(choix)                       Tu peux appeler une fonction (simple de preference : int ou char) dans un switch, la valeur que renvera la fonction sera le choix.
{
 case 1: printf("choix 1 \n");      PAR CONTRE : PAS DE RETURN DANS UN SWITCH NI DINITIALISATION DE VARIABLE! CA NE RENVOIE RIEN
         break;
 case 2: printf("choix 2 \n");       N'oublie pas le break entre les cases sinon tu tombes à travers (fallthrough). ex: si tu selectionne le 1 et qu'il n'y a pas de break
         break;                      avant le 2, alors la case 2 sera elle aussi exectuter et ainsi de suite jusqu'au prochain break
 case 3: printf("choix 3 \n");       cela oppere en cascade, si tu selectionne le 2 le 1 lui ne sera pas éxecuter.
         break;
default: printf("choix par defaut \n");         Pas d'expression trop complexe dans les cases d'un switch !..
         break
}



do                                                        ON PEUT SORTIR DE N'IMPORTE QUELLES BOUCLE DE PREMATUREMENT EN UTILISANT BREAK !!
{
 printf("fais ca !!");                                    PLUS UTILE POUR LES DO-WHILE BIEN QUE PEUT UTILISER QUAND MEME..
}
while(condition sortie de boucle);


while(condition entrée de boucle)
{
printf("fais ca !!");
}


for (; nombredeVies >0 && pointsforce>0; pointsforce--)   FOR est une boucle aussi, elle s'utilise majoritairement dans les cas ou on connait le nombre d'itérations.
    {
    printf("%d",pointsforce);                             (1) L'initialisation : la ou les variables qui seront utilisées. Dans ce cas precis nous n'en mettront pas, elles ont été
    }                                                         initialisés plus haut. mais sinon il aurait fallu mettre machin = blabla et machin egale = blabla; tu connais
                                                          (2) La conndition de boucle : t'as capté chacal jvais pas détailler ca
nombredeVies = 4;                                         (3) La mise à jour : action qui va modifié la boucle à chaque fin de celle-ci. Elle est généralement utilisée pour modifier la variable du compteur.
                                                              Mais nn peut également modifier un element exterieur : for (int i = 0; i < 5; i++, x += 1) ! ici la variable x.
















____________________________________________________________________________________________________________________________________________________________________________________________________
///CREATION D'UNE FONCTION :

double fonctionvolume(double longueur, double largeur, double profondeur)
{
    double resultatvolume = 0;                           Le resultatvolume est exploitable que dans la fonction fonctionvolume
                                                         (impossible de l'appelé ailleurs) c'est une variable interne à la fonction !

    resultatvolume = longueur*largeur*profondeur;        ici nous avons le calcul qu'effectue la fonction avec le noms des variables
                                                         internes à la fonction(qui lui indique également le type des variables).

    return resultatvolume;                               Le return ici t'indique qu'il va renvoyer la valeur de cette variable quand
}                                                        tu appeleras la fonction fonctionvolume plus loin dans le programme !!!

 la fonction est bien détaillé mais tu peux juste écrire return suivis du calcul de la fonction !
 alors le resultat ne sera pas stocker Dans la fonction il sera directement envoyer
 la ou tu souhaite que la fonction serve sont resultat !


int main(int argc, char *argv[])
{
double volume = 0;
double longueur257 = 11;
double largeur257 = 5;
double profondeur257 = 2;

volume = fonctionvolume(longueur257,largeur257,profondeur257);

printf("le volume du cul de ta daronne est de :%lf",volume);

autre écriture possible voir ci apres.

printf("le volume du cul de ta daronne est de :%lf",fonctionvolume(11,5,2));

printf("\n\n\n");





///autre exemple :

void aireRectangle(double largeur, double hauteur)   création d'une fonction vide qui va t'afficher un texte,
{                                                    et le resultat de sont calcul en fonction des valeurs que tu
    double aire = 0;                                 lui a donner quand tu vas l'appeler dans la fonction principal

    aire = largeur * hauteur;

    printf("Rectangle de largeur %lf et hauteur %lf. Aire = %lf\n", largeur, hauteur, aire);
}
                                                   pas de return 0 ici la fonction ne r'envoie pas resultat

int main(int argc, char *argv[])
{
 int blabla = aireRectangle(5, 10);
 int blibli = aireRectangle(2.5, 3.5);
 int blublu = aireRectangle(4.2, 9.7);

    return 0;
}












____________________________________________________________________________________________________________________________________________________________________________________________________
/// ECRITURE TERNAIRE

NiveauCritique = (compteur > 2) ? -20 : ((compteur > 1) ? -10 : +10); //ca c'est du ternaire !! un if else simplifié
















____________________________________________________________________________________________________________________________________________________________________________________________________
/// CONDITION BOOLEENS
//Jusque la c'est la de la grosse merde jveux meme pas en parler

/*On dit qu'une variable à laquelle on fait prendre les valeurs 0 et 1 est un booléen.
Et aussi que : 0 = faux ; 1 = vrai. */
//conditions de type vrai/faux avec LES BOOLEENS !!!

if (1)
{
    printf("C'est vrai\n");
}

//remplace par 0 ca te mettra que c'est faux. En gros on dirait
//La première ligne est pour le positif (n'importe quel entier meme négatif)
//la deuxieme ligne est pour la condition négative (strictement 0)

else
{
    printf("C'est faux\n");
}
// l'API te traduit "VRAI/FAUX" par 0 ou 1 c'est sa manière de communiqué !
///j'suis meme pas sur de celle la





____________________________________________________________________________________________________________________________________________________________________________________________________
///LES POINTEURS


Un pointeur est une variable qui stock l'adresse memoire d'une autre variable.
Cela permet le transfer, la modification et l'extraction de valeur dans des fonction qui prennent en compte des pointeurs.
Ce qui est impossible sans pointeur ! Au mieux return peut renvoyer qu'une seul valeur.


int nombre = 2;

int *PtrA = &nombre;                      // Oublie pas de déclarer vers quelle adresse
                                          // Le pointeur dans doit renvoyer la valeur !

printf("nombre : %d \n", nombre);         // 2.
printf("nombre : %d \n",&nombre);         // Adresse de nombre (6422036).

void changementDeNombre(int *pointeur)    // Sans pointeur la valeur de nombre change uniquement DANS la fonction.
{
    *pointeur = 42;                       // Ici derefecement du pointeur pour acceder à la valeur sur laquelle il pointe.
                                          // Voir explication plus bas.
}

changementDeNombre(PtrA);

printf("nombre : %d \n", nombre);        // 42.
printf("nombre : %d \n",&PtrA);          // Adresse du pointeur (6422024).
printf("nombre : %d \n", PtrA);          // Adresse sur laquelle pointe le pointeur (6422036).
printf("nombre : %d \n",*PtrA);          // Valeur de l'adresse sur laquelle pointe le pointeur (42).


Initialiser un pointeur à NULL dès le début, si on n'a pas d'autre valeur à lui donner, est fondamental !
Si vous ne le faites pas, vous augmentez considérablement le risque d'erreur par la suite.




///Autre exemple (voir JEU_DU_PENDU)


 void choixdunombre(int* ptrNombre)
    {
     do {
        scanf("%d", ptrNombre);

        if (*ptrNombre > 30 || *ptrNombre < 1)
           {
            printf("Veuillez selectionner un nombre entre 1 et 30 \n\n");
           }

    } while (*ptrNombre >30 || *ptrNombre <1);
   }


Dans la fonction choixdunombre, lorsque nous utilisons *ptrNombre,
nous déréférençons le pointeur ptrNombre, ce qui signifie que nous accédons
à la valeur stockée à l'adresse mémoire pointée par ptrNombre.
Par exemple, dans les expressions *ptrNombre > 30 et *ptrNombre < 1,
nous comparons la valeur stockée à cette adresse avec les valeurs 30 et 1 respectivement.

En revanche, dans scanf("%d", ptrNombre);, nous passons simplement l'adresse mémoire pointée
par ptrNombre à scanf, ce qui permet à scanf d'écrire la valeur saisie par l'utilisateur à cet emplacement mémoire.
Nous n'avons pas besoin de déréférencer ptrNombre car scanf
s'attend à recevoir une adresse mémoire où stocker la valeur saisie, pas la valeur elle-même.






///pointeurs sur pointeurs


#include <stdio.h>

void ft_ultimate_ft(int *********nbr) {
    *********nbr = 42; // Affecte la valeur 42 à l'entier pointé par nbr
}

int main() {
    int x; // Déclare une variable entière
    int *ptr1 = &x; // Pointeur vers x
    int **ptr2 = &ptr1; // Pointeur vers ptr1
    int ***ptr3 = &ptr2; // Pointeur vers ptr2
    int ****ptr4 = &ptr3; // Pointeur vers ptr3
    int *****ptr5 = &ptr4; // Pointeur vers ptr4
    int ******ptr6 = &ptr5; // Pointeur vers ptr5
    int *******ptr7 = &ptr6; // Pointeur vers ptr6
    int ********ptr8 = &ptr7; // Pointeur vers ptr7

    ft_ultimate_ft(&ptr8); // Appel de la fonction ft_ultimate_ft en passant l'adresse de ptr8

    printf("%d\n", ********ptr8); // Affiche la valeur de l'entier pointé par ptr8 (devrait être 42)

    return 0;
}



Utiliser des pointeurs sur d'autres pointeurs permet d'accéder à des données de manière indirecte en référençant des adresses mémoire.
Chaque niveau de pointeur supplémentaire ajoute une indirection supplémentaire lors de l'accès aux données.
Lors de la déclaration, chaque étoile (*) indique une indirection supplémentaire, et lors de l'utilisation,
il faut déréférencer le bon nombre de fois pour accéder à la valeur souhaitée.




___________________________________________________________________________________________________________________________________________________________________________________________________
///LES TABLEAUX !


int tableaudebg[10];
                            ///les tableaux sont comme des pointeurs
tableaudebg[0] = 110;
tableaudebg[1] = 120;
tableaudebg[2] = 130;
tableaudebg[3] = 140;
tableaudebg[4] = 150;
tableaudebg[5] = 160;
tableaudebg[6] = 170;
tableaudebg[7] = 180;
tableaudebg[8] = 190;
tableaudebg[9] = 200;

printf("tableau colone 5 = %p \n",&tableaudebg[5]); adresse de la case 5
printf("tableau colone 5 = %d \n",tableaudebg[5]); valeur de la case 5
printf("tableau colone 5 = %d \n",tableaudebg); adresse du tableau
printf("tableau colone 5 = %d \n",*tableaudebg); premiere valeur du tableau


int i;

for (i=0; i<10; i++) cette boucle tu vas lutilisé souvent retient la bien !
{
    printf("%d\n", tableaudebg[i]); ici pour parcourir un tableau
}


printf("\n");

for (i=0; i<10; i++)
{
    tableaudebg[i] *= 3; tableaudebg[i] + 30; ici pour initialiser un tableau avec une boucle
}

int tableau2[4] = {0, 0, 0, 0}; Valeurs insérées : 10, 23, 0, 0

int tableau3[4] = {0}; Toutes les cases du tableau seront initialisées à 0

int tableau4[4] = {78,89}; les valeurs des deux premières adresses seront 78 et 89, le reste sera automatiquement 0!




///fonnction affichage tableau

void affichertableaudebg(int* tableau, int tailledutableau) la fonction qui affiche un tableau doit prendre deux choses en parametres :
{                                                           le nom du tableau et la taille de celui-ci !
  int i;

for (i=0; i < tailledutableau; i++)
  {
    printf("%d\n", tableau[i]);
  }
}

affichertableaudebg(tableaudebg,10);




///fonnction affichage d'un calcul sur tableau avec un return


int sommetableau(int tableau1[], int tailletableau)
{
    float somme;
    int i= 0;

    for (; i<tailletableau; i++)
    {
     somme += tableau1[i];
    }

  return somme;
}

printf("la somme des valeurs du tableau est de : %d \n",sommetableau(tableaudebg,10));

/* +=: C'est l'opérateur d'addition abrégé. a += b est équivalent à a = a + b.
     Dans ce cas, cela signifie que la valeur actuelle de somme est augmentée de la valeur de tableau[i].*/







double moyenneTableau(int tableau[], int tailleTableau) //Le changement de type de variable au sein d'une fonction, est appelé "cast" ou "conversion de type".
{                                                      //Plus précisément, (double)somme et (double)tailleTableau sont des castings qui convertissent
                                                      //la valeur de somme et tailleTableau en valeurs de type double. tres utiles pour la division notament !
    int somme = 0;
    for(int i = 0; i < tailleTableau; i++)
    {
        somme += tableau[i];
    }
    return (double)somme/(double)tailleTableau;         la fonction doit toujours renvoyer le meme type de variable que la fonction elle meme !
}
printf("la moyenne des valeurs du tableau est de : %lf \n",moyenneTableau(tableaudebg,10));



















_______________________________________________________________________________________________________________________________________________________________________________________________________________________
///LES CHAINES DE CARACTERES

//on utilise les apostrophes pour stocker des caracteres ! chaques caractères à une valeur correspondante dans la table ASCII (prononcez « Aski »).

char lettre = 'A';   //char sert à stocker des caractères étant donné sa faible plage d'utilisation !

printf("%c \n",lettre); //vois l'importance des drapeaux ! le %c pour afficher UN caractère !

printf("%d \n",lettre); //le %d afficher un nombre Decimale ! ici sa valeur réferente dans la table ASCII !

//'a' n'est pas identique à 'A'  : l'ordinateur fait la différence entre les majuscules et les minuscules (on dit qu'il "respecte la casse")

char lettre2;

scanf(" %c", &lettre2);    // En ajoutant un espace avant %c, comme dans scanf(" %c", &lettre2);,
                          //cela indique à scanf d'ignorer tous les caractères blancs, y compris les retours à la ligne, avant de lire le caractère.
printf("%c \n",lettre2); //Cela résout souvent les problèmes de saisie lorsque vous mélangez la lecture de différents types de données.


char chaine[500];  //une chaine de caracteres "string" est semblable à un tableau dans la mémoire. mais il existe une autre méthode bcp plus simple pour
                    //stocker une chaine de caracteres en mémoire !
chaine[0] = 'T';
chaine[1] = 'h';
chaine[2] = 'i';
chaine[3] = 'b';
chaine[4] = 'a';
chaine[5] = 'u';
chaine[6] = 't';
chaine[7] = '!';
chaine[8] = '\0'; //le \0 permet au programme de savoir quand s'arreter ! voit le tableau fait 14 adresse !! oublie pas de rajouter à chaque fois une ligne
                         //de plus dans ton tableau pour inclure ce caractere de fin !! très important !!

printf("%s \n",chaine);   //important d'allouer la bon nombre d'adresse nécessaire pour la chaine de caractères ! sinon programme fais nimp !!
                          //ou sinon tu peux juste ne rien mettre ! pour une fois le programme le fais très bien tout seul ! comme en dessous !

char chaine2[] = "Re bonjour gros bg \n"; //un caractère unique sera entre apostrophes et une chaine de caractères entre guillemet !!

  chaine2[10] = "wesh le s"; // ca ca ne marche pas !! seulement pour l'initialisation !

 printf("%s \n",chaine2);

 printf("insert un compliment ! \n\n ");

scanf(" %[^\n]",&chaine2);  // l'espace avant le %s n'est pas nécessaire car %s ignore automatiquement les caractères blancs avant de lire la chaîne de caractères.
                      //le scanf arrete sa lecture de caracteres au premier espace, tabulation ou autre je ne sais quoi ! du coup utilise _ pour les espace !
printf("%s \n",chaine2);      //ou utilise ceci : %[^\n]  par contre la tu dois mettre un espace avant le % !!!


///manipulation de chaine de caracteres



///Calculer la longueur d'une chaine avec "strlen" (string length)

size_t strlen(const char* chaine); //size_t est une fonction inventé qui donne la taille de truc..

strlen(chaine2);                                                                         les TABLEAU, LES POINTEURS ET LES CHAINES DE CARACTERES utilise tout les trois
                                                                                        le systeme de pointeur !!! voilà pourquoi les fonctions faisant appele à eux
printf("la chaine : %s fait %d caracteres de long \n",chaine2,strlen(chaine2));        prendron toujours en parametre des pointeurs !! RETIENS CA FDP !! au lieu de
                                                                                      casser les couilles a chatGPT !!!


// ce que fait la fonction strlen en détail stv mieux comprendre !
int longueurChaine(const char* chaine)
{
    int nombreDeCaracteres = 0;
    char caractereActuel = 0;

    do
    {
        caractereActuel = chaine[nombreDeCaracteres];
        nombreDeCaracteres++;
    }
    while(caractereActuel != '\0'); // On boucle tant qu'on n'est pas arrivé à l'\0

    nombreDeCaracteres--; // On retire 1 caractère de long pour ne pas compter le caractère \0

    return nombreDeCaracteres;
}
 printf("La chaine %s fait %d caracteres de long \n\n", chaine, longueurChaine(chaine));








///copier une chaine dans une autre avec strcpy (string copy)

char* strcpy(char* chainecoler, const char* chainecopier); //le second char est copié dans le premier!
                                                              //copié pas coupé !! jte vois venir
printf("chaine2 = %s \n",chaine2);

printf("chaine = %s \n",chaine);  //Vérifiez que la chaîne copie est assez grande pour accueillir le contenu de chaine !

char chaine3[]= {0}; //version propre !!

strcpy(chaine3,chaine);

printf(" %s %s :",chaine,chaine3);








///Concaténez deux chaînes avec  stract (string catenate)

//mettre une chaine à la suite d'une autre.

char chaine45[100] = "wesh le s "; //prevoir l'espace nécessaire pour l'incrementation de la 2nd chaine !
const char* chaine44 = "comment ca va ?";



char* strcat(char* chainefinal, const char* chaineainserrer);

printf("chaine45 : %s \n",chaine45);

printf("chaine44 : %s \n",chaine44);

//scanf("%s",chaine45);

strcat(chaine45,chaine44);

printf("%s",chaine45);




///Comparer deux chaines avec strcmp (string compare)


const char* chaine443 = "Hello World!";
const char* chaine453 = "Hello World!";

int strcmp(const char* chaine475, const char* chaine485);
//strcmp renvoie 0 pour deux chaines identiques.
int resultat0587 = strcmp(chaine443,chaine453);

printf("%d \n",resultat0587);

    if (strcmp(chaine443, chaine453) == 0) // Si chaînes identiques
    {
        printf("Les chaines sont identiques\n");
    }      //ne prend pas les espaces en compte!
    else
    {
        printf("Les chaines sont differentes\n");
    }


///Rechercher un caractère avec strchr (string cherche)



char* chaine785 = "Mais ou est donc partit le tresor de Kadafi ?";

char lettre23 ='K';

char* strchr(const char* chaine, int caracterachercher);
                            //ici dans la fonction le caractere est de type int !! Lettre = chiffre
                           //ca sera toujours ainsi pour le prototype, pas de diff voir table ASCII
char *chaine11 = strchr(chaine785,lettre23);

    if (chaine11 != NULL) // Si on a trouvé quelque chose
    {
        printf("Voici la lettre chercher : %s \n", chaine11); //chaine est un pointeur pas un car unqique ! voilà pq %s et pas %c
    }




///Rechercher le premier caractere d'une liste de caracteres avec strpbrk

char* strpbrk(const char* chaine, const char* lettresARechercher);


    // On cherche la première occurrence de x, d ou s dans "Texte de test"
   char* suiteChaine = strpbrk("Texte de test", "xds");

    if (suiteChaine != NULL)
    {
        printf("Voici la fin de la chaine a partir du premier des caracteres trouves : %s", suiteChaine);
    }

/*Pour cet exemple, j'ai directement écrit les valeurs à envoyer à la fonction (entre guillemets).
 Rien ne nous oblige à employer une variable à tous les coups, on peut très bien écrire la chaîne directement.
 Il faut simplement retenir la règle suivante :

    si vous utilisez les guillemets ""  , cela signifie chaîne ;

    si vous utilisez les apostrophes ''  , cela signifie caractère.
*/


///Rechercher une chaine dans une autre avec strstr (string string)


char* strstr(const char* chaine17, const char* chaineachercher);


char texte[] = "Paul Atreides se rallie à Chani et aux Fremen tout en préparant sa revanche contre ceux qui ont détruit sa famille. Alors qu'il doit faire un choix entre l'amour de sa vie et le destin de la galaxie, il devra néanmoins tout faire pour empêcher un terrible futur que lui seul peut prédire.";

const char chaine[] = "Chani";

char* resultat = strstr(texte,chaine); //recherche de chaine dans texte

size_t tailledutexte = strlen(texte); //calcul de la taille du texte

if (resultat != NULL)  //elle renvoie, comme les autres, un pointeur quand elle a trouvé ce qu'elle cherchait
                           //elle renvoie NULL si elle n'a rien trouvé
{

   int index = resultat - texte; //ici on sousstrait le resultat au texte (adresse la plus grande - la plus petite)
                                //ca nous donne la position de la chaine cherchée dans le texte (index).


printf("taille du texte : %d caracteres\n",tailledutexte);

printf("mot trouve aux : %d caracteres\n",index);

printf("Les 20 caracteres suivants : %.20s\n",texte + index); //Si vous utilisez simplement index dans le printf cela ne fonctionnera pas correctement
                                                             // car index est un entier qui représente la position de la chaîne recherchée dans texte.
                                                            // Cependant, %s attend un pointeur vers une chaîne de caractères (texte).

}
else
{
printf("rien trouve");
}



///Ecrire dans une autre chaine avec sprintf


char chaine1[1000];  //oublie pas de prevoir suffisament d'espace pour la mémoire de ta chaine !
char chaine2[]="salut grand genie il serait peut etre temps de ce reveiller";

int age = 27;         ///ATENTION SPRINTF REMPLACE LE TEXTE EXISTANT DANS LA CHAINE OU TU VAS ECRIRE (ICI CHAINE1)

sprintf(chaine1, "%s tu viens d'avoir %d",chaine2,age); //ici sprintf prend en compte la chaine (chaine1) dans laquellle il va écrire.
                                   //ensuite, comme dans un printf, tu peux y ajouter ce qu'il te chante !!
printf("%s",chaine1);




_________________________________________________________________________________________________________________________________________________________________________________
///LES STRUCTURES



//Les structures sont commes des fonctions, a l'exception qu'elles sont définie dans le dossier .h
//comme les prototypes.


/// .h

typedef struct Coordonnees Coordonnees; //Typedef est un alias de la structure. Evite le "struct" .
                                       //Sans alias la structure doit etre crée avec "struct" devant elle.

struct Coordonnees //Structure de type : coordonnees. N'oublie pas de lui donner un nom dans le main.
 {
 int x;  //Abscisses

 int y; //Ordonnées

 };  //ATTENTION pas oublier le point virgule après l'accolade


/// .c

 void initialiserCoordonnees(Coordonnees* pnt) //prend en compte un pointeur de type coordonnees,
{                                              // qui s'appele pnt DANS la fonction.
    pnt->x = 0;
    pnt->y = 0; //comment on utilise un pointeur  sur variable dans une structure.
}


/// main.c

int main(int argc, char *argv[])
 {


Coordonnees point = {0,0}; //Creation d'une variable de type coordonnees où point est le nom de la structure.

printf("point x :%d\npoint y :%d\n",point.x,point.y); // x = 0 ; y = 0

point.x = 10; //le point permet l'acces à l'interieur de la structure.

point.y = 15;

printf("point x :%d\npoint y :%d\n",point.x,point.y); // x = 10 ; y = 15

initialiserCoordonnees(&point);

printf("point x :%d\npoint y :%d\n",point.x,point.y); // x = 0 ; y = 0



///Autre exemple


struct Date {
    int jour;
    int mois;
    int annee;
};


struct Personne
{
char nom[20];

char prenom[20];

struct Date date_de_naissance; //exemple d'une structure dans une structure
};

comment y acceder :

personne1.date_naissance.jour = 15;
personne1.date_naissance.mois = 6;
personne1.date_naissance.annee = 1990;

//petit exercisse de remplissage

struct Personne resident[3];

int taille_tableau = sizeof(resident) / sizeof(resident[0]);
/*Ici, sizeof(resident) donne la taille totale du tableau en octets,
  et sizeof(resident[0]) donne la taille d'un élément individuel du tableau.
  En divisant la taille totale par la taille d'un élément,
  vous obtenez le nombre total d'éléments dans le tableau.*/


printf("taille du tableau : %d \n\n", taille_tableau);

for (int i=0;taille_tableau>i;i++){

    printf("resident %d :",i);

    scanf("%s",resident[i].nom);
}


for (int j=0;taille_tableau>j;j++){

    printf("Nom resident %d %s \n",j,resident[j].nom);
}




_____________________________________________________________________________________________________________________________________________________________________________________________________________
///LES ENUMERATIONS

Les énumérations constituent une façon un peu différente de créer ses propres types de variables.

Une énumération ne contient pas de sous-variables comme c'était le cas pour les structures.
C'est une liste de valeurs possibles pour une variable. Une énumération ne prend donc qu'une case en mémoire,
et cette case peut prendre une des valeurs que vous définissez (et une seule à la fois).
Utile pour les mois de l'année ou les jours de la semaine par exemple.
Tu peux également le faire prendre des valeurs (optionnel) mais que des nombres entiers !!

Pour créer une énumération, on utilise le mot-clé enum.


typedef enum Volume Volume;
enum Volume
{
    FAIBLE = 15, MOYEN = 50, FORT = 80, MAX = 100
};

Volume musique = MOYEN;

Un autre petit point à noter : si vous ne précisez pas la valeur d’un élément,
elle sera forcément égale à la valeur de l'élément précédent + 1.








____________________________________________________________________________________________________________________________________________________________________________________________________________
///LES UNIONS (a revoir plus tard ! un peu comme une structure mais qui utilise la memoir d'une autre manière)

// Définition de l'énumération pour représenter l'état d'un appareil
typedef enum {
    OFF,
    ON
} Status;

// Définition de l'union pour représenter l'état d'un appareil
union DeviceState {
    Status status;     // Membre de l'union représentant l'état de l'appareil
    int batteryLevel;  // Membre de l'union représentant le niveau de batterie de l'appareil
};

int main() {
    // Création d'une variable de type union DeviceState
    union DeviceState device;

    // Affectation de l'état de l'appareil à ON
    device.status = ON;

    // Affichage de l'état de l'appareil
    if (device.status == ON) {
        printf("L'appareil est allumé.\n");
    } else {
        printf("L'appareil est éteint.\n");
    }




_____________________________________________________________________________________________________________________________________________________________________________________________________________________________
/// MANIPULER DES FICHIER A L'AIDE DE FONCTIONS


Placer par avance le fichier dans le dossier sur lequel vous travailler.
Il est possible aussi de l'ouvrir depuis n'importe ou sur le disque.
Mais si vous deplacer le dossier sur une autre machine alors le fichier ne suivra pas.



FILE* fopen(const char* nomDuFichier, const char* modeOuverture);     FILE est une structure.

fichier = fopen("C:\\Program Files\\Notepad++\\readme.txt", "r+");


int fclose(FILE* pointeurSurFichier);                                 Pour fermer le fichier.

int rename(const char* ancienNom, const char* nouveauNom);            Pour renomer le fichier.

int remove(const char* fichierASupprimer);                            Pour suprimer le fichier.




Les principaux modes d'ouverture possibles :

    "r"  : lecture seule. Vous pourrez lire le contenu du fichier, mais pas y écrire. Le fichier doit avoir été créé au préalable.

    "w"  : écriture seule. Vous pourrez écrire dans le fichier, mais pas lire son contenu. Si le fichier n'existe pas, il sera créé.

    "a"  : mode d'ajout. Vous écrirez dans le fichier, en partant de la fin du fichier. Si le fichier n'existe pas, il sera créé.

    "a+"  : ajout en lecture / écriture à la fin. Vous écrivez et lisez du texte à partir de la fin du fichier. Si le fichier n'existe pas, il sera créé.

    "r+"  : lecture et écriture. Vous pourrez lire et écrire dans le fichier. Le fichier doit avoir été créé au préalable.

    "w+"  : lecture et écriture, avec suppression du contenu au préalable. Si le fichier n'existe pas, il sera créé.



 ///Exemple



 int main() {

    char chaine[taille_max] = "";

    char *resultat;

    FILE* fichier = fopen("Exemple.txt", "r");                            Attention ca n'ouvre pas le fichier dans le notepad !
                                                                            Seulement ca l'ouvre pour que codeblocks puisse y avoir acces !

    if (fichier != NULL) {                                                    Important !! Permet de s'assurer que le fichier a été ouvert avec succès.

        int motTrouve = 0;                                                      Variable pour indiquer si le mot a été trouvé au moins une fois

        while (fgets(chaine, taille_max, fichier) != NULL) {                      Les fonctions de lecture lisent char par char et ligne par ligne !
                                                                                   Donc stv lire l'entieretée du fichier, ne t'arreres pas temps qu'il est pas à NULL.
            resultat = strstr(chaine, mot);
                                                                                    Si tu dois mettre un message d'erreur fais le passer par une variable en interne,
                                                                                     Oublie pas ! compartimente ton code ! fais le taff de recherche dans un premier temps.
            if (resultat != NULL) {

                printf("%s\n\n", resultat);

                motTrouve = 1;                                                        Mettre motTrouve à 1 si le mot est trouvé

            }
        }
        long position = ftell(fichier);                                               Oublie pas de mettre la fonction à l'interieur de l'ouverture du fichier.

        printf("position curseur : %ld\n",position);

        if (!motTrouve) {

            printf("pas trouvé");
        }
        fclose(fichier);                                                            Ne pas oublié de fermer le fichier après utilisation. fonction : fclose
                                                                                   Prototype : int fclose(FILE* pointeurSurFichier);
      system("notepad Exemple.txt");
                                                                                 Ouvre le fichier avec notepads si fichier se trouve dans le meme dossier. Sinon :
    } else {                                                                    system("notepad \"C:\\chemin avec des espaces\\vers\\le\\fichier\\Exemple.txt\"");

        printf("Impossible d'ouvrir le fichier.\n");                          Toujours verifié la réussite ou de l'ouverture du fichier. Evite les plantage.
    }

    return 0;
}


/// Les Fonctions



/// LIRE UN CARACTERE DANS FICHIER (fgetc)

int fgetc(FILE* pointeurDeFichier);

  int caractereActuel = 'A';

caractereActuel = fgetc(fichier);                         Si la fonction n'a pas pu lire de caractère, elle retourne EOF.


/// LIRE UNE CHAINE DE CARACTERES DANS FICHIER (fgets)

char* fgets(char* chaine, int nbreDeCaracteresALire, FILE* pointeurSurFichier);     Fais pour lire une ligne de texte. s'arrete au moment le texte est coupé.

while (fgets(chaine, TAILLE_MAX, fichier) != NULL)                                   On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)

printf("%s", chaine);                                                                On affiche la chaîne qu'on vient de lire


/// LIRE UN FICHIER COMPLET (fread)

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

(fread(chaine,1,taille_max,fichier)!=NULL)

ptr: Pointeur vers la zone de mémoire où les données lues seront stockées.

size: Taille en octets de chaque élément à lire.

nmemb: Nombre d'éléments à lire.

stream: Pointeur vers le flux à partir duquel les données seront lues



/// LIRE UNE CHAINE FORMATER (fscanf)

int score[3] = {0};                                                Tableau des 3 meilleurs scores

fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]);

printf("Les scores sont : %d, %d et %d", score[0], score[1], score[2]);


/// ECRIRE UN CARACTERE DANS FICHIER (fputs)

int fputc(int caractere, FILE* pointeurSurFichier);

fputc('A', fichier);                                             Écriture du caractère A


/// ECRIRE UNE DE CARACTERES DANS FICHIER (fputs)

char* fputs(const char* chaine, FILE* pointeurSurFichier);                          Prend simplement une chaîne de caractères en entrée.

fputs("Salut les bg !", fichier);                                                   Ne permet pas de spécifier de format pour les données.

La fonction renvoie EOF s'il y a eu une erreur


/// ECRIRE UNE CHAINE FORMATER DANS FICHIER (fprintf)

char *name = "love";                                                                Utilisé pour écrire des données formatées dans un fichier.

fprintf(fichier, "HELLO WORLD my name is %s ans", name);                            Prend un format spécifié et une liste d'arguments.



/// Le curseurs

long ftell(FILE* pointeurSurFichier);                                                Renvoie la position actuelle du curseur.

void rewind(FILE* pointeurSurFichier);                                               Replace le curseur au début du fichier.

int fseek(FILE* pointeurSurFichier, long deplacement, int origine);                  Permet de déplacer le curseur.



Il est possible de mettre comme valeur à origine Une des trois constantes listées ci-dessous :

    SEEK_SET  : indique le début du fichier.                   ex: fseek(fichier, 25, SEEK_SET);

    SEEK_CUR  : indique la position actuelle du curseur.       ex: fseek(fichier, -47, SEEK_CUR);

    SEEK_END  : indique la fin du fichier.                     ex: fseek(fichier, 0, SEEK_END);




