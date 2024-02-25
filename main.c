



______________________________________________________________________________________________________________
**************************************************************************************************************
 Ici Tu noteras de mani�re concise et facilement compr�hensible tout ce que tu auras appris sur le langage C
______________________________________________________________________________________________________________
**************************************************************************************************************

____________________________________________________________________________________________________________________________________________________________________________________________________
///PROGRAMATION MODULAIRE


Il y a deux types de fichiers diff�rents :

    .h : Les fichiers header, ils contiennent les prototypes des fonctions.
         Egalement les directive de pr�processeur pour les constante symbolique
         et macros (#define). Mais �galement les directives pour la compilation
         conditionnelle (#if,#ifdef,...)


    .c : Les fichiers source, ils contiennent les fonctions elles-m�mes.








____________________________________________________________________________________________________________________________________________________________________________________________________
///GITBASH / GITHUB


Lorsque tu cr�e ton clone sur ta machine il est ind�pendant de tout autre fichier local, si tu veux travailler dessus en local, copie colle
le dossier ailleurs et supprime le .git qui le relie au depot distant. Ensuite fait toi juste un git init en local pour enregistrer les evolutions
du projet. Et une fois satisfais re copie colle les fichiers modifier dans le dossier cloner pour les push sur le depot distant.

Ne confond pas ton travail en local et ton travail en distant (origin). Meme si tu as suprimmer une branche en local,
ca ne veut pas dire que c est effectif sur le depot distant. sert toi des commandes specifiques pour supprimer la branche � distance.



Sans sp�cification chaque branche est cr�� par d�faut � hauteur du dernier commit de la branche dans laquelle on se trouve.





(HEAD -> master)                       HEAD (bleu ciel) indique le dernier commit sur la branche ou tu te situe (ici master).

(origin/master)                        (en rouge) indique la place du dernier commit de ton fichier sur le depot distant (ici master).

(HEAD -> master, origin/master)        master (vert) indique ton dernier commit sur la branche, les commits locaux est distant sont aux meme niveaux ici.

(origin/branch2)                       (en rouge) indique la place du dernier commit de ton fichier sur le depot distant (ici branch2).

(branch2)                              (en vert) indique la position de ton dernier commit sur le depot local, ici tout les commits n'ont pas �t� push.






NAVIGUER DANS LES DOSSIER

pwd                 (Afficher position dans la memoire)

cd NomDuDossier     (Aller)

cd ..               (Retour)

ls                  (Afficher les fichier du dossie)

ls -la              (Affichage avanc�)






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

git checkout -b NomDeLaBranche "SHA 1"     (Nouvelle branche � partir d'un certain commit)

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

git push -u origin master               (O� master est la branche � pousser)

git push -f origin master               (Ecrase les fichiers distant)

git push --all --force origin           (envoie toutes les branches de force)








git fetch origin                 R�cup�re integralement toute les modifications du depot distant.

git pull                         R�cup�re les commits du depot distant de la branche sur laquelle on se trouve.











///Editeur rebase

Ouverture de l'editeur de rebase : git rebase -i master                          (pour gerer les commit ?)

                                   git rebase -i HEAD~1   pour modifier le dernier commit.    git rebase -i HEAD~3 pour modifier les 3 dernier commit.

Appuyez sur la touche Esc pour vous assurer que vous �tes en mode commande. ?

Appuyez sur la touche i pour �crire instruction.

Appuyez sur la touche :q! pour quitter l'�diteur sans sauvegarder les modifications.
                      :wq pour quitter l'editeur en ayant sauvegarder les modifications.


    Le : met l'�diteur en mode commande.
    q signifie quitter.
    w signifie write.
    ! signifie forcer, ce qui vous permet de quitter sans sauvegarder.














____________________________________________________________________________________________________________________________________________________________________________________________________
/// LES BIBLIOTHEQUES ET DIRECTIVE DE PREPROCESSEUR :


///Les Bibliotheques :

Les biblioth�ques comprennes les fonctions de base stocker avec L'IDE.

pour inclure un fichier.h dans le dossier ou est installer l'IDE on utilise < >

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stddef.h>







///Les Directives De Preprocesseur :

Les directives permettent de d�finirs les constantes et macros.

pour inclure un fichier.h dans le dossier de votre projet on utilise " "


#define taille_max 100
#define taille_mini 2

(#define) remplace par 100 toute les fonctions qui prennent taille_max comme argument !
Permet de fluidifi� le code et un meilleur controle �galement.




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


 Il est possible de mettre plusieurs lignes de code � la fois. Il suffit de placer un\  avant chaque nouvelle ligne.


 #define RACONTER_SA_VIE()   printf("Coucou, je m'appelle Brice\n"); \
                            printf("J'habite a Nice\n"); \
                            printf("J'aime la glisse\n");



 Il est possible aussi de cr�er une macro qui prend plusieurs param�tres.

 #define MAJEUR(age, nom) if (age >= 18) \
                    printf("Vous etes majeur %s\n", nom);

int main(int argc, char *argv[])
{
    MAJEUR(22, "Maxime")

    return 0;
}









///Les Conditions en Langage Pr�processeur

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

#ifndef FICHIER // Si la constante n'a pas �t� d�finie le fichier n'a jamais �t� inclus Alors :
#define FICHIER // On d�finit la constante pour que la prochaine fois le fichier ne soit plus inclus

/* Contenu de votre fichier .h (autres include, prototypes, define...) */

#endif








/// les constantes pr�d�finies par le processeur



    __LINE__ donne le num�ro de la ligne actuelle.

    __FILE__ donne le nom du fichier actuel.

    __DATE__ donne la date de la compilation.

    __TIME__ donne l'heure de la compilation.


Ca permet au programmeur de definir dans le code les endroids qui reste � deboguer. cela affichera � la lecture du code
le fichier, la ligne de code, et autres informations necessaire.


#include <stdio.h>

// D�finition de la macro DEBUG avec la valeur 1
#define DEBUG 1

// V�rifie si la macro DEBUG est d�finie (oui == 1)
#ifdef DEBUG
// Si DEBUG est d�finie, cette macro affichera les messages de d�bogage
#define debug_print(fmt, ...) \
            fprintf(stderr, "DEBUG: %s:%d: " fmt, __FILE__, __LINE__, __VA_ARGS__)
#else
// Si DEBUG n'est pas d�finie, cette macro sera vide
#define debug_print(fmt, ...) \
            do {} while (0)
#endif

int main() {
    int x = 10;
    // Appel � la macro debug_print pour afficher un message de d�bogage
    // Si DEBUG est d�finie, le message contiendra le num�ro de ligne et le nom du fichier.
    // ici on passe x comme argument juste pour montrer qu'on peut �galement prendre des variables en comptes.
    debug_print("x = %d\n\n", x);







____________________________________________________________________________________________________________________________________________________________________________________________________
/// MISE EN PAGE :


retour � la ligne : \n          /**"Vois comme c'est magique ! Aurai-tu d�couvert une nouvelle passion ? Ou serait-ce plus que �a...
                                    Tr�ve de plaisanterie !
                                    N'oublie pas les retours de ligne (\n) font planter la console si
 tabulation : \t                    tu les places apr�s les appels de variable (exemple : scanf("%lf \n", &nombre1); !!
                                    Cela t'a caus� bien des confusions, mon ami..." */












____________________________________________________________________________________________________________________________________________________________________________________________________
/// LES RACOURCIS :


ctrl+shift+c = tout ce qui est s�lectionner en commentaire d'une ligne









____________________________________________________________________________________________________________________________________________________________________________________________________
/// LES VARIALBES ET SPECIFICATEURS DE FORMAT (DRAPEAUX):



const : (VARIABLE_CONSTANTE_QUI_NE_SERA_JAMAIS_MODIFIABLE_APRES_INITIALISATION_!_A_ECRIRE_EN_MAJUSCULE);

static : A mentiionner devant la variable si on veut qu'elle existe que dans un seul fichier.

extern : A mentionner devant une variable qui � �t� initialis� dans un autre fichier !



int variable1, variable2, variable3; comment �crire plusieurs variables � la suite.


char(-128 � 127)||(0 � 255); %c (caract�res), %d (entiers);

short(-32,768 � 32,767)||(0 � 65,535); %hd (entiers courts), %hu (unsigned entiers),
                                        %d (entiers), %u (unsigned entiers);

int(-2,147Mds � 2,147Mds)||(0 � 4,294Mds); %d (entiers), %u (unsigned entiers);

long(-2,147Mds � 2,147Mds)||(0 � 4,294Mds); %ld (entiers longs), %lu (unsigned entiers);

float(�1.18E-38 � �3.4E38); (Pr�cision : ~7 chiffres); %f; nombre flottant 45.75 un point !! pas de virgule !!

 "%e" : Nombre � virgule flottante en notation scientifique (exponentielle).
 "%E" : Nombre � virgule flottante en notation scientifique (exponentielle), lettres majuscules.


double(�2.23E-308 � �1.8E308); (Pr�cision : ~15 chiffres); %lf;

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

   Le fait de caster une variable en C consiste � convertir son type en un autre en cr�ant
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
d�crementation(-1) : --
multplication = 5 * 5        racine carr�e(5) = sqrt(25)
division = 25 / 5

 les signes utilisable :    "==" est strictement �agal �          "+=" est �gal � : A = A + B.
                            ">"  est sup�rieur �                  tr�s utiles pour aditionner les valeurs
                            "<"  est inf�rieur �
      "!" est "est pas"     ">=" est sup�rieur ou �gal �
      "&&" est "et"         "<=" est inf�rieur ou �gal �
      "||" est "ou"         "!=" est diff�rent de

ATTENTION !! L'op�rateur = est utilis� pour attribuer une valeur � une variable !! A PAS UTILISER POUR TESTER UNE EGALITE !!


      pour les conditions en && et || retiens si je dis pas de connerie.. que pour les nombre compris entre 2 valeurs,
      on utilisera && et pour les nombres qui ne sont pas compris entre ces 2 valeurs on utilisera ||








____________________________________________________________________________________________________________________________________________________________________________________________________
/// LES CONDITIONS ET BOUCLES:

PRINTF("imprime du texte et appele des variable %d,%lf,%f",variable1,variable2,variable3);

SCANF("interoge l'operateur sur du texte et des nombres %d,%s",&nombre,&texte);



if(condition)              Pas de point-virgule apr�s la condition if sinon ca provoque une instruction vide,
{                          ce qui signifie que le bloc suivant entre {} est toujours ex�cut� ind�pendamment de la condition.
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
 case 2: printf("choix 2 \n");       N'oublie pas le break entre les cases sinon tu tombes � travers (fallthrough). ex: si tu selectionne le 1 et qu'il n'y a pas de break
         break;                      avant le 2, alors la case 2 sera elle aussi exectuter et ainsi de suite jusqu'au prochain break
 case 3: printf("choix 3 \n");       cela oppere en cascade, si tu selectionne le 2 le 1 lui ne sera pas �xecuter.
         break;
default: printf("choix par defaut \n");         Pas d'expression trop complexe dans les cases d'un switch !..
         break
}



do                                                        ON PEUT SORTIR DE N'IMPORTE QUELLES BOUCLE DE PREMATUREMENT EN UTILISANT BREAK !!
{
 printf("fais ca !!");                                    PLUS UTILE POUR LES DO-WHILE BIEN QUE PEUT UTILISER QUAND MEME..
}
while(condition sortie de boucle);


while(condition entr�e de boucle)
{
printf("fais ca !!");
}


for (; nombredeVies >0 && pointsforce>0; pointsforce--)   FOR est une boucle aussi, elle s'utilise majoritairement dans les cas ou on connait le nombre d'it�rations.
    {
    printf("%d",pointsforce);                             (1) L'initialisation : la ou les variables qui seront utilis�es. Dans ce cas precis nous n'en mettront pas, elles ont �t�
    }                                                         initialis�s plus haut. mais sinon il aurait fallu mettre machin = blabla et machin egale = blabla; tu connais
                                                          (2) La conndition de boucle : t'as capt� chacal jvais pas d�tailler ca
nombredeVies = 4;                                         (3) La mise � jour : action qui va modifi� la boucle � chaque fin de celle-ci. Elle est g�n�ralement utilis�e pour modifier la variable du compteur.
                                                              Mais nn peut �galement modifier un element exterieur : for (int i = 0; i < 5; i++, x += 1) ! ici la variable x.
















____________________________________________________________________________________________________________________________________________________________________________________________________
///CREATION D'UNE FONCTION :

double fonctionvolume(double longueur, double largeur, double profondeur)
{
    double resultatvolume = 0;                           Le resultatvolume est exploitable que dans la fonction fonctionvolume
                                                         (impossible de l'appel� ailleurs) c'est une variable interne � la fonction !

    resultatvolume = longueur*largeur*profondeur;        ici nous avons le calcul qu'effectue la fonction avec le noms des variables
                                                         internes � la fonction(qui lui indique �galement le type des variables).

    return resultatvolume;                               Le return ici t'indique qu'il va renvoyer la valeur de cette variable quand
}                                                        tu appeleras la fonction fonctionvolume plus loin dans le programme !!!

 la fonction est bien d�taill� mais tu peux juste �crire return suivis du calcul de la fonction !
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

autre �criture possible voir ci apres.

printf("le volume du cul de ta daronne est de :%lf",fonctionvolume(11,5,2));

printf("\n\n\n");





///autre exemple :

void aireRectangle(double largeur, double hauteur)   cr�ation d'une fonction vide qui va t'afficher un texte,
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

NiveauCritique = (compteur > 2) ? -20 : ((compteur > 1) ? -10 : +10); //ca c'est du ternaire !! un if else simplifi�
















____________________________________________________________________________________________________________________________________________________________________________________________________
/// CONDITION BOOLEENS
//Jusque la c'est la de la grosse merde jveux meme pas en parler

/*On dit qu'une variable � laquelle on fait prendre les valeurs 0 et 1 est un bool�en.
Et aussi que : 0 = faux ; 1 = vrai. */
//conditions de type vrai/faux avec LES BOOLEENS !!!

if (1)
{
    printf("C'est vrai\n");
}

//remplace par 0 ca te mettra que c'est faux. En gros on dirait
//La premi�re ligne est pour le positif (n'importe quel entier meme n�gatif)
//la deuxieme ligne est pour la condition n�gative (strictement 0)

else
{
    printf("C'est faux\n");
}
// l'API te traduit "VRAI/FAUX" par 0 ou 1 c'est sa mani�re de communiqu� !
///j'suis meme pas sur de celle la





____________________________________________________________________________________________________________________________________________________________________________________________________
///LES POINTEURS


Un pointeur est une variable qui stock l'adresse memoire d'une autre variable.
Cela permet le transfer, la modification et l'extraction de valeur dans des fonction qui prennent en compte des pointeurs.
Ce qui est impossible sans pointeur ! Au mieux return peut renvoyer qu'une seul valeur.


int nombre = 2;

int *PtrA = &nombre;                      // Oublie pas de d�clarer vers quelle adresse
                                          // Le pointeur dans doit renvoyer la valeur !

printf("nombre : %d \n", nombre);         // 2.
printf("nombre : %d \n",&nombre);         // Adresse de nombre (6422036).

void changementDeNombre(int *pointeur)    // Sans pointeur la valeur de nombre change uniquement DANS la fonction.
{
    *pointeur = 42;                       // Ici derefecement du pointeur pour acceder � la valeur sur laquelle il pointe.
                                          // Voir explication plus bas.
}

changementDeNombre(PtrA);

printf("nombre : %d \n", nombre);        // 42.
printf("nombre : %d \n",&PtrA);          // Adresse du pointeur (6422024).
printf("nombre : %d \n", PtrA);          // Adresse sur laquelle pointe le pointeur (6422036).
printf("nombre : %d \n",*PtrA);          // Valeur de l'adresse sur laquelle pointe le pointeur (42).


Initialiser un pointeur � NULL d�s le d�but, si on n'a pas d'autre valeur � lui donner, est fondamental !
Si vous ne le faites pas, vous augmentez consid�rablement le risque d'erreur par la suite.




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
nous d�r�f�ren�ons le pointeur ptrNombre, ce qui signifie que nous acc�dons
� la valeur stock�e � l'adresse m�moire point�e par ptrNombre.
Par exemple, dans les expressions *ptrNombre > 30 et *ptrNombre < 1,
nous comparons la valeur stock�e � cette adresse avec les valeurs 30 et 1 respectivement.

En revanche, dans scanf("%d", ptrNombre);, nous passons simplement l'adresse m�moire point�e
par ptrNombre � scanf, ce qui permet � scanf d'�crire la valeur saisie par l'utilisateur � cet emplacement m�moire.
Nous n'avons pas besoin de d�r�f�rencer ptrNombre car scanf
s'attend � recevoir une adresse m�moire o� stocker la valeur saisie, pas la valeur elle-m�me.






///pointeurs sur pointeurs


#include <stdio.h>

void ft_ultimate_ft(int *********nbr) {
    *********nbr = 42; // Affecte la valeur 42 � l'entier point� par nbr
}

int main() {
    int x; // D�clare une variable enti�re
    int *ptr1 = &x; // Pointeur vers x
    int **ptr2 = &ptr1; // Pointeur vers ptr1
    int ***ptr3 = &ptr2; // Pointeur vers ptr2
    int ****ptr4 = &ptr3; // Pointeur vers ptr3
    int *****ptr5 = &ptr4; // Pointeur vers ptr4
    int ******ptr6 = &ptr5; // Pointeur vers ptr5
    int *******ptr7 = &ptr6; // Pointeur vers ptr6
    int ********ptr8 = &ptr7; // Pointeur vers ptr7

    ft_ultimate_ft(&ptr8); // Appel de la fonction ft_ultimate_ft en passant l'adresse de ptr8

    printf("%d\n", ********ptr8); // Affiche la valeur de l'entier point� par ptr8 (devrait �tre 42)

    return 0;
}



Utiliser des pointeurs sur d'autres pointeurs permet d'acc�der � des donn�es de mani�re indirecte en r�f�ren�ant des adresses m�moire.
Chaque niveau de pointeur suppl�mentaire ajoute une indirection suppl�mentaire lors de l'acc�s aux donn�es.
Lors de la d�claration, chaque �toile (*) indique une indirection suppl�mentaire, et lors de l'utilisation,
il faut d�r�f�rencer le bon nombre de fois pour acc�der � la valeur souhait�e.




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

for (i=0; i<10; i++) cette boucle tu vas lutilis� souvent retient la bien !
{
    printf("%d\n", tableaudebg[i]); ici pour parcourir un tableau
}


printf("\n");

for (i=0; i<10; i++)
{
    tableaudebg[i] *= 3; tableaudebg[i] + 30; ici pour initialiser un tableau avec une boucle
}

int tableau2[4] = {0, 0, 0, 0}; Valeurs ins�r�es : 10, 23, 0, 0

int tableau3[4] = {0}; Toutes les cases du tableau seront initialis�es � 0

int tableau4[4] = {78,89}; les valeurs des deux premi�res adresses seront 78 et 89, le reste sera automatiquement 0!




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

/* +=: C'est l'op�rateur d'addition abr�g�. a += b est �quivalent � a = a + b.
     Dans ce cas, cela signifie que la valeur actuelle de somme est augment�e de la valeur de tableau[i].*/







double moyenneTableau(int tableau[], int tailleTableau) //Le changement de type de variable au sein d'une fonction, est appel� "cast" ou "conversion de type".
{                                                      //Plus pr�cis�ment, (double)somme et (double)tailleTableau sont des castings qui convertissent
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

//on utilise les apostrophes pour stocker des caracteres ! chaques caract�res � une valeur correspondante dans la table ASCII (prononcez � Aski �).

char lettre = 'A';   //char sert � stocker des caract�res �tant donn� sa faible plage d'utilisation !

printf("%c \n",lettre); //vois l'importance des drapeaux ! le %c pour afficher UN caract�re !

printf("%d \n",lettre); //le %d afficher un nombre Decimale ! ici sa valeur r�ferente dans la table ASCII !

//'a' n'est pas identique � 'A'  : l'ordinateur fait la diff�rence entre les majuscules et les minuscules (on dit qu'il "respecte la casse")

char lettre2;

scanf(" %c", &lettre2);    // En ajoutant un espace avant %c, comme dans scanf(" %c", &lettre2);,
                          //cela indique � scanf d'ignorer tous les caract�res blancs, y compris les retours � la ligne, avant de lire le caract�re.
printf("%c \n",lettre2); //Cela r�sout souvent les probl�mes de saisie lorsque vous m�langez la lecture de diff�rents types de donn�es.


char chaine[500];  //une chaine de caracteres "string" est semblable � un tableau dans la m�moire. mais il existe une autre m�thode bcp plus simple pour
                    //stocker une chaine de caracteres en m�moire !
chaine[0] = 'T';
chaine[1] = 'h';
chaine[2] = 'i';
chaine[3] = 'b';
chaine[4] = 'a';
chaine[5] = 'u';
chaine[6] = 't';
chaine[7] = '!';
chaine[8] = '\0'; //le \0 permet au programme de savoir quand s'arreter ! voit le tableau fait 14 adresse !! oublie pas de rajouter � chaque fois une ligne
                         //de plus dans ton tableau pour inclure ce caractere de fin !! tr�s important !!

printf("%s \n",chaine);   //important d'allouer la bon nombre d'adresse n�cessaire pour la chaine de caract�res ! sinon programme fais nimp !!
                          //ou sinon tu peux juste ne rien mettre ! pour une fois le programme le fais tr�s bien tout seul ! comme en dessous !

char chaine2[] = "Re bonjour gros bg \n"; //un caract�re unique sera entre apostrophes et une chaine de caract�res entre guillemet !!

  chaine2[10] = "wesh le s"; // ca ca ne marche pas !! seulement pour l'initialisation !

 printf("%s \n",chaine2);

 printf("insert un compliment ! \n\n ");

scanf(" %[^\n]",&chaine2);  // l'espace avant le %s n'est pas n�cessaire car %s ignore automatiquement les caract�res blancs avant de lire la cha�ne de caract�res.
                      //le scanf arrete sa lecture de caracteres au premier espace, tabulation ou autre je ne sais quoi ! du coup utilise _ pour les espace !
printf("%s \n",chaine2);      //ou utilise ceci : %[^\n]  par contre la tu dois mettre un espace avant le % !!!


///manipulation de chaine de caracteres



///Calculer la longueur d'une chaine avec "strlen" (string length)

size_t strlen(const char* chaine); //size_t est une fonction invent� qui donne la taille de truc..

strlen(chaine2);                                                                         les TABLEAU, LES POINTEURS ET LES CHAINES DE CARACTERES utilise tout les trois
                                                                                        le systeme de pointeur !!! voil� pourquoi les fonctions faisant appele � eux
printf("la chaine : %s fait %d caracteres de long \n",chaine2,strlen(chaine2));        prendron toujours en parametre des pointeurs !! RETIENS CA FDP !! au lieu de
                                                                                      casser les couilles a chatGPT !!!


// ce que fait la fonction strlen en d�tail stv mieux comprendre !
int longueurChaine(const char* chaine)
{
    int nombreDeCaracteres = 0;
    char caractereActuel = 0;

    do
    {
        caractereActuel = chaine[nombreDeCaracteres];
        nombreDeCaracteres++;
    }
    while(caractereActuel != '\0'); // On boucle tant qu'on n'est pas arriv� � l'\0

    nombreDeCaracteres--; // On retire 1 caract�re de long pour ne pas compter le caract�re \0

    return nombreDeCaracteres;
}
 printf("La chaine %s fait %d caracteres de long \n\n", chaine, longueurChaine(chaine));








///copier une chaine dans une autre avec strcpy (string copy)

char* strcpy(char* chainecoler, const char* chainecopier); //le second char est copi� dans le premier!
                                                              //copi� pas coup� !! jte vois venir
printf("chaine2 = %s \n",chaine2);

printf("chaine = %s \n",chaine);  //V�rifiez que la cha�ne copie est assez grande pour accueillir le contenu de chaine !

char chaine3[]= {0}; //version propre !!

strcpy(chaine3,chaine);

printf(" %s %s :",chaine,chaine3);








///Concat�nez deux cha�nes avec  stract (string catenate)

//mettre une chaine � la suite d'une autre.

char chaine45[100] = "wesh le s "; //prevoir l'espace n�cessaire pour l'incrementation de la 2nd chaine !
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

    if (strcmp(chaine443, chaine453) == 0) // Si cha�nes identiques
    {
        printf("Les chaines sont identiques\n");
    }      //ne prend pas les espaces en compte!
    else
    {
        printf("Les chaines sont differentes\n");
    }


///Rechercher un caract�re avec strchr (string cherche)



char* chaine785 = "Mais ou est donc partit le tresor de Kadafi ?";

char lettre23 ='K';

char* strchr(const char* chaine, int caracterachercher);
                            //ici dans la fonction le caractere est de type int !! Lettre = chiffre
                           //ca sera toujours ainsi pour le prototype, pas de diff voir table ASCII
char *chaine11 = strchr(chaine785,lettre23);

    if (chaine11 != NULL) // Si on a trouv� quelque chose
    {
        printf("Voici la lettre chercher : %s \n", chaine11); //chaine est un pointeur pas un car unqique ! voil� pq %s et pas %c
    }




///Rechercher le premier caractere d'une liste de caracteres avec strpbrk

char* strpbrk(const char* chaine, const char* lettresARechercher);


    // On cherche la premi�re occurrence de x, d ou s dans "Texte de test"
   char* suiteChaine = strpbrk("Texte de test", "xds");

    if (suiteChaine != NULL)
    {
        printf("Voici la fin de la chaine a partir du premier des caracteres trouves : %s", suiteChaine);
    }

/*Pour cet exemple, j'ai directement �crit les valeurs � envoyer � la fonction (entre guillemets).
 Rien ne nous oblige � employer une variable � tous les coups, on peut tr�s bien �crire la cha�ne directement.
 Il faut simplement retenir la r�gle suivante :

    si vous utilisez les guillemets ""  , cela signifie cha�ne ;

    si vous utilisez les apostrophes ''  , cela signifie caract�re.
*/


///Rechercher une chaine dans une autre avec strstr (string string)


char* strstr(const char* chaine17, const char* chaineachercher);


char texte[] = "Paul Atreides se rallie � Chani et aux Fremen tout en pr�parant sa revanche contre ceux qui ont d�truit sa famille. Alors qu'il doit faire un choix entre l'amour de sa vie et le destin de la galaxie, il devra n�anmoins tout faire pour emp�cher un terrible futur que lui seul peut pr�dire.";

const char chaine[] = "Chani";

char* resultat = strstr(texte,chaine); //recherche de chaine dans texte

size_t tailledutexte = strlen(texte); //calcul de la taille du texte

if (resultat != NULL)  //elle renvoie, comme les autres, un pointeur quand elle a trouv� ce qu'elle cherchait
                           //elle renvoie NULL si elle n'a rien trouv�
{

   int index = resultat - texte; //ici on sousstrait le resultat au texte (adresse la plus grande - la plus petite)
                                //ca nous donne la position de la chaine cherch�e dans le texte (index).


printf("taille du texte : %d caracteres\n",tailledutexte);

printf("mot trouve aux : %d caracteres\n",index);

printf("Les 20 caracteres suivants : %.20s\n",texte + index); //Si vous utilisez simplement index dans le printf cela ne fonctionnera pas correctement
                                                             // car index est un entier qui repr�sente la position de la cha�ne recherch�e dans texte.
                                                            // Cependant, %s attend un pointeur vers une cha�ne de caract�res (texte).

}
else
{
printf("rien trouve");
}



///Ecrire dans une autre chaine avec sprintf


char chaine1[1000];  //oublie pas de prevoir suffisament d'espace pour la m�moire de ta chaine !
char chaine2[]="salut grand genie il serait peut etre temps de ce reveiller";

int age = 27;         ///ATENTION SPRINTF REMPLACE LE TEXTE EXISTANT DANS LA CHAINE OU TU VAS ECRIRE (ICI CHAINE1)

sprintf(chaine1, "%s tu viens d'avoir %d",chaine2,age); //ici sprintf prend en compte la chaine (chaine1) dans laquellle il va �crire.
                                   //ensuite, comme dans un printf, tu peux y ajouter ce qu'il te chante !!
printf("%s",chaine1);




_________________________________________________________________________________________________________________________________________________________________________________
///LES STRUCTURES



//Les structures sont commes des fonctions, a l'exception qu'elles sont d�finie dans le dossier .h
//comme les prototypes.


/// .h

typedef struct Coordonnees Coordonnees; //Typedef est un alias de la structure. Evite le "struct" .
                                       //Sans alias la structure doit etre cr�e avec "struct" devant elle.

struct Coordonnees //Structure de type : coordonnees. N'oublie pas de lui donner un nom dans le main.
 {
 int x;  //Abscisses

 int y; //Ordonn�es

 };  //ATTENTION pas oublier le point virgule apr�s l'accolade


/// .c

 void initialiserCoordonnees(Coordonnees* pnt) //prend en compte un pointeur de type coordonnees,
{                                              // qui s'appele pnt DANS la fonction.
    pnt->x = 0;
    pnt->y = 0; //comment on utilise un pointeur  sur variable dans une structure.
}


/// main.c

int main(int argc, char *argv[])
 {


Coordonnees point = {0,0}; //Creation d'une variable de type coordonnees o� point est le nom de la structure.

printf("point x :%d\npoint y :%d\n",point.x,point.y); // x = 0 ; y = 0

point.x = 10; //le point permet l'acces � l'interieur de la structure.

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
  et sizeof(resident[0]) donne la taille d'un �l�ment individuel du tableau.
  En divisant la taille totale par la taille d'un �l�ment,
  vous obtenez le nombre total d'�l�ments dans le tableau.*/


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

Les �num�rations constituent une fa�on un peu diff�rente de cr�er ses propres types de variables.

Une �num�ration ne contient pas de sous-variables comme c'�tait le cas pour les structures.
C'est une liste de valeurs possibles pour une variable. Une �num�ration ne prend donc qu'une case en m�moire,
et cette case peut prendre une des valeurs que vous d�finissez (et une seule � la fois).
Utile pour les mois de l'ann�e ou les jours de la semaine par exemple.
Tu peux �galement le faire prendre des valeurs (optionnel) mais que des nombres entiers !!

Pour cr�er une �num�ration, on utilise le mot-cl� enum.


typedef enum Volume Volume;
enum Volume
{
    FAIBLE = 15, MOYEN = 50, FORT = 80, MAX = 100
};

Volume musique = MOYEN;

Un autre petit point � noter : si vous ne pr�cisez pas la valeur d�un �l�ment,
elle sera forc�ment �gale � la valeur de l'�l�ment pr�c�dent + 1.








____________________________________________________________________________________________________________________________________________________________________________________________________________
///LES UNIONS (a revoir plus tard ! un peu comme une structure mais qui utilise la memoir d'une autre mani�re)

// D�finition de l'�num�ration pour repr�senter l'�tat d'un appareil
typedef enum {
    OFF,
    ON
} Status;

// D�finition de l'union pour repr�senter l'�tat d'un appareil
union DeviceState {
    Status status;     // Membre de l'union repr�sentant l'�tat de l'appareil
    int batteryLevel;  // Membre de l'union repr�sentant le niveau de batterie de l'appareil
};

int main() {
    // Cr�ation d'une variable de type union DeviceState
    union DeviceState device;

    // Affectation de l'�tat de l'appareil � ON
    device.status = ON;

    // Affichage de l'�tat de l'appareil
    if (device.status == ON) {
        printf("L'appareil est allum�.\n");
    } else {
        printf("L'appareil est �teint.\n");
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

    "r"  : lecture seule. Vous pourrez lire le contenu du fichier, mais pas y �crire. Le fichier doit avoir �t� cr�� au pr�alable.

    "w"  : �criture seule. Vous pourrez �crire dans le fichier, mais pas lire son contenu. Si le fichier n'existe pas, il sera cr��.

    "a"  : mode d'ajout. Vous �crirez dans le fichier, en partant de la fin du fichier. Si le fichier n'existe pas, il sera cr��.

    "a+"  : ajout en lecture / �criture � la fin. Vous �crivez et lisez du texte � partir de la fin du fichier. Si le fichier n'existe pas, il sera cr��.

    "r+"  : lecture et �criture. Vous pourrez lire et �crire dans le fichier. Le fichier doit avoir �t� cr�� au pr�alable.

    "w+"  : lecture et �criture, avec suppression du contenu au pr�alable. Si le fichier n'existe pas, il sera cr��.



 ///Exemple



 int main() {

    char chaine[taille_max] = "";

    char *resultat;

    FILE* fichier = fopen("Exemple.txt", "r");                            Attention ca n'ouvre pas le fichier dans le notepad !
                                                                            Seulement ca l'ouvre pour que codeblocks puisse y avoir acces !

    if (fichier != NULL) {                                                    Important !! Permet de s'assurer que le fichier a �t� ouvert avec succ�s.

        int motTrouve = 0;                                                      Variable pour indiquer si le mot a �t� trouv� au moins une fois

        while (fgets(chaine, taille_max, fichier) != NULL) {                      Les fonctions de lecture lisent char par char et ligne par ligne !
                                                                                   Donc stv lire l'entieret�e du fichier, ne t'arreres pas temps qu'il est pas � NULL.
            resultat = strstr(chaine, mot);
                                                                                    Si tu dois mettre un message d'erreur fais le passer par une variable en interne,
                                                                                     Oublie pas ! compartimente ton code ! fais le taff de recherche dans un premier temps.
            if (resultat != NULL) {

                printf("%s\n\n", resultat);

                motTrouve = 1;                                                        Mettre motTrouve � 1 si le mot est trouv�

            }
        }
        long position = ftell(fichier);                                               Oublie pas de mettre la fonction � l'interieur de l'ouverture du fichier.

        printf("position curseur : %ld\n",position);

        if (!motTrouve) {

            printf("pas trouv�");
        }
        fclose(fichier);                                                            Ne pas oubli� de fermer le fichier apr�s utilisation. fonction : fclose
                                                                                   Prototype : int fclose(FILE* pointeurSurFichier);
      system("notepad Exemple.txt");
                                                                                 Ouvre le fichier avec notepads si fichier se trouve dans le meme dossier. Sinon :
    } else {                                                                    system("notepad \"C:\\chemin avec des espaces\\vers\\le\\fichier\\Exemple.txt\"");

        printf("Impossible d'ouvrir le fichier.\n");                          Toujours verifi� la r�ussite ou de l'ouverture du fichier. Evite les plantage.
    }

    return 0;
}


/// Les Fonctions



/// LIRE UN CARACTERE DANS FICHIER (fgetc)

int fgetc(FILE* pointeurDeFichier);

  int caractereActuel = 'A';

caractereActuel = fgetc(fichier);                         Si la fonction n'a pas pu lire de caract�re, elle retourne EOF.


/// LIRE UNE CHAINE DE CARACTERES DANS FICHIER (fgets)

char* fgets(char* chaine, int nbreDeCaracteresALire, FILE* pointeurSurFichier);     Fais pour lire une ligne de texte. s'arrete au moment le texte est coup�.

while (fgets(chaine, TAILLE_MAX, fichier) != NULL)                                   On lit le fichier tant qu'on ne re�oit pas d'erreur (NULL)

printf("%s", chaine);                                                                On affiche la cha�ne qu'on vient de lire


/// LIRE UN FICHIER COMPLET (fread)

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

(fread(chaine,1,taille_max,fichier)!=NULL)

ptr: Pointeur vers la zone de m�moire o� les donn�es lues seront stock�es.

size: Taille en octets de chaque �l�ment � lire.

nmemb: Nombre d'�l�ments � lire.

stream: Pointeur vers le flux � partir duquel les donn�es seront lues



/// LIRE UNE CHAINE FORMATER (fscanf)

int score[3] = {0};                                                Tableau des 3 meilleurs scores

fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]);

printf("Les scores sont : %d, %d et %d", score[0], score[1], score[2]);


/// ECRIRE UN CARACTERE DANS FICHIER (fputs)

int fputc(int caractere, FILE* pointeurSurFichier);

fputc('A', fichier);                                             �criture du caract�re A


/// ECRIRE UNE DE CARACTERES DANS FICHIER (fputs)

char* fputs(const char* chaine, FILE* pointeurSurFichier);                          Prend simplement une cha�ne de caract�res en entr�e.

fputs("Salut les bg !", fichier);                                                   Ne permet pas de sp�cifier de format pour les donn�es.

La fonction renvoie EOF s'il y a eu une erreur


/// ECRIRE UNE CHAINE FORMATER DANS FICHIER (fprintf)

char *name = "love";                                                                Utilis� pour �crire des donn�es format�es dans un fichier.

fprintf(fichier, "HELLO WORLD my name is %s ans", name);                            Prend un format sp�cifi� et une liste d'arguments.



/// Le curseurs

long ftell(FILE* pointeurSurFichier);                                                Renvoie la position actuelle du curseur.

void rewind(FILE* pointeurSurFichier);                                               Replace le curseur au d�but du fichier.

int fseek(FILE* pointeurSurFichier, long deplacement, int origine);                  Permet de d�placer le curseur.



Il est possible de mettre comme valeur � origine Une des trois constantes list�es ci-dessous :

    SEEK_SET  : indique le d�but du fichier.                   ex: fseek(fichier, 25, SEEK_SET);

    SEEK_CUR  : indique la position actuelle du curseur.       ex: fseek(fichier, -47, SEEK_CUR);

    SEEK_END  : indique la fin du fichier.                     ex: fseek(fichier, 0, SEEK_END);




