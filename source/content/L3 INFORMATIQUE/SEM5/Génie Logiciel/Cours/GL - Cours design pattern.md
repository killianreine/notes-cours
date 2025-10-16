>[!cite] Définition
>On appelle **==design pattern==** un *modèle de conception* *(architecture générale)* permettant de répondre à une problématique récurrente.

# Design Pattern : **Façade**

## Principe

- **🎯 Objectif :** Fournir une **interface simplifiée** pour utiliser un système complexe.  
- **⚙️ Problème :** Un système peut offrir **trop de fonctionnalités**, alors qu’on n’a besoin que d’un **sous-ensemble** pour une utilisation spécifique.
La **façade** agit comme une **couche intermédiaire** :  
elle **masque la complexité** du système sous-jacent et **expose uniquement** les méthodes utiles à l’utilisateur.

## Exemple
On souhaite gérer une pile avec trois opérations simples :
- `empiler` (`push`)
- `depiler` (`pop`)
- `vider` (`clear`)

Cependant, la classe `java.util.ArrayDeque` de Java propose **plus d’une cinquantaine de méthodes**, bien au-delà de ce dont on a besoin.  
Pour simplifier l’utilisation, on crée une **classe Façade** appelée `Pile`, qui encapsule `ArrayDeque` et ne laisse accessibles que les opérations essentielles.
```java
import java.util.ArrayDeque;

public class Pile<T> {
    private ArrayDeque<T> elements = new ArrayDeque<>();

    public void empiler(T element) {
        elements.push(element);
    }

    public T depiler() {
        return elements.pop();
    }

    public void vider() {
        elements.clear();
    }

    public boolean estVide() {
        return elements.isEmpty();
    }
}
```

# Design Pattern : **Fabrique Abstraite**

## Principe
- **🎯 Objectif :** Fournir une **interface commune** pour créer des **familles d’objets liés** sans connaître leurs classes concrètes.  
- **⚙️ Problème :** On souhaite instancier des objets **compatibles entre eux** (ex : éléments d’une interface graphique Windows ou macOS) sans dépendre directement des classes spécifiques.

La **fabrique abstraite** agit comme une **super-fabrique** qui définit **plusieurs méthodes de création**.  
Chaque **fabrique concrète** implémente ces méthodes pour produire une **famille d’objets cohérente**.
## Exemple
On veut créer des composants graphiques (`Bouton`, `Menu`) pour deux environnements :
- **Windows**
- **MacOS**

On utilisera une **fabrique abstraite** pour créer les bons composants selon le système choisi.
```java
// --- Produits abstraits ---
interface Bouton {
    void afficher();
}

interface Menu {
    void afficher();
}

// --- Produits concrets : Windows ---
class BoutonWindows implements Bouton {
    public void afficher() {
        System.out.println("Affichage d’un bouton Windows");
    }
}

class MenuWindows implements Menu {
    public void afficher() {
        System.out.println("Affichage d’un menu Windows");
    }
}

// --- Produits concrets : MacOS ---
class BoutonMac implements Bouton {
    public void afficher() {
        System.out.println("Affichage d’un bouton MacOS");
    }
}

class MenuMac implements Menu {
    public void afficher() {
        System.out.println("Affichage d’un menu MacOS");
    }
}

// --- Fabrique abstraite ---
interface FabriqueGUI {
    Bouton creerBouton();
    Menu creerMenu();
}

// --- Fabriques concrètes ---
class FabriqueWindows implements FabriqueGUI {
    public Bouton creerBouton() {
        return new BoutonWindows();
    }

    public Menu creerMenu() {
        return new MenuWindows();
    }
}

class FabriqueMac implements FabriqueGUI {
    public Bouton creerBouton() {
        return new BoutonMac();
    }

    public Menu creerMenu() {
        return new MenuMac();
    }
}

// --- Code client ---
public class Application {
    private Bouton bouton;
    private Menu menu;

    public Application(FabriqueGUI fabrique) {
        bouton = fabrique.creerBouton();
        menu = fabrique.creerMenu();
    }

    public void afficher() {
        bouton.afficher();
        menu.afficher();
    }

    public static void main(String[] args) {
        FabriqueGUI fabrique = new FabriqueWindows(); // ou new FabriqueMac();
        Application app = new Application(fabrique);
        app.afficher();
    }
}
```

# Design Pattern : **Singleton**
## Principe

- **🎯 Objectif :** Garantir qu’une **classe ne possède qu’une seule instance** dans toute l’application, et fournir un **point d’accès global** à cette instance.
- **⚙️ Problème :** Dans certains cas (ex. gestion d’une configuration, connexion à une base de données, journalisation...), il est **inutile ou dangereux** de créer plusieurs objets identiques.  
    Le **Singleton** assure qu’il n’existe **qu’un seul objet** de cette classe, et qu’il est **partagé** partout où on en a besoin.
## Exemple
On souhaite créer une classe `Journal` qui centralise l’écriture des messages de log.  
On veut éviter d’avoir **plusieurs journaux différents**, donc on applique le **pattern Singleton** :
```java
public class Journal {
    private static Journal instance = null;
    
    private Journal() {
        System.out.println("📘 Journal initialisé");
    }

    public static Journal getInstance() {
        if (instance == null) {
            instance = new Journal();
        }
        return instance;
    }

    public void ecrire(String message) {
        System.out.println("[LOG] " + message);
    }
}
```

# Design Pattern : **Adaptateur** (Adapter)
## Principe

- **🎯 Objectif :** Permettre à deux **interfaces incompatibles** de **collaborer**.
- **⚙️ Problème :** On souhaite **réutiliser une classe existante**, mais son interface **ne correspond pas** à celle attendue par le code client.  
    L’**adaptateur** agit comme un **convertisseur** :  
    il **traduit** les appels de l’interface attendue vers celle de la classe existante, **sans modifier** cette dernière.
## Exemple
On veut créer un système de **lecture audio**.  
Notre code s’attend à travailler avec une **interface simple** `LecteurAudio` :
- `lire(String fichier)`

Mais on dispose d’une **bibliothèque externe** qui lit les fichiers via une classe `AdvancedPlayer` utilisant une méthode différente :
- `playFile(String filePath)`

Pour éviter de modifier la bibliothèque, on crée un **adaptateur** qui fait le lien entre les deux.
```java
// 🎵 Interface attendue par notre application
public interface LecteurAudio {
    void lire(String fichier);
}
```
```java
// 🎧 Classe existante (par exemple issue d'une bibliothèque externe)
public class AdvancedPlayer {
    public void playFile(String filePath) {
        System.out.println("Lecture du fichier audio : " + filePath);
    }
}
```
```java
public class AdaptateurAudio implements LecteurAudio {
    private AdvancedPlayer lecteurAvance;

    public AdaptateurAudio(AdvancedPlayer lecteurAvance) {
        this.lecteurAvance = lecteurAvance;
    }

    @Override
    public void lire(String fichier) {
        lecteurAvance.playFile(fichier);
    }
}
```

# Design Pattern : **Composite**
## Principe
- **🎯 Objectif :** **Uniformiser** le traitement des **objets simples** et des **compositions d’objets**.
- **⚙️ Problème :** Lorsqu’on manipule des structures **hiérarchiques** (ex. dossiers/fichiers, formes graphiques, menus, etc.),  
    on veut pouvoir traiter **un élément individuel** ou **un groupe d’éléments** de la même manière.

Le **pattern Composite** permet de **représenter une hiérarchie d’objets** sous forme d’arbre, où **chaque nœud** (composite) et **chaque feuille** (élément simple) **partagent la même interface**.
## Exemple

On veut modéliser une **structure de fichiers** contenant :
- des **fichiers simples** (`Fichier`)
- des **dossiers** (`Dossier`) qui peuvent contenir d’autres fichiers ou dossiers.

L’objectif : pouvoir appeler la méthode `afficher()` sur un fichier **ou** sur un dossier **sans se soucier du type réel**.
```java
import java.util.ArrayList;
import java.util.List;

public interface Element {
    void afficher(String indentation);
}
```
```java
public class Fichier implements Element {
    private String nom;

    public Fichier(String nom) {
        this.nom = nom;
    }

    @Override
    public void afficher(String indentation) {
        System.out.println(indentation + "- " + nom);
    }
}
```
```java
public class Dossier implements Element {
    private String nom;
    private List<Element> enfants = new ArrayList<>();

    public Dossier(String nom) {
        this.nom = nom;
    }

    public void ajouter(Element e) {
        enfants.add(e);
    }

    @Override
    public void afficher(String indentation) {
        System.out.println(indentation + "+ " + nom);
        for (Element e : enfants) {
            e.afficher(indentation + "  ");
        }
    }
}
```

# Design Pattern : **Décorateur** (Decorator)
## Principe
- **🎯 Objectif :** **Ajouter dynamiquement** des fonctionnalités à un objet **sans modifier sa classe d’origine**.
- **⚙️ Problème :** Hériter d’une classe pour lui ajouter un comportement conduit à une **multiplication des sous-classes**.  
    Le **Décorateur** permet d’**enrichir un objet à la volée**, en l’**enveloppant** dans un autre objet qui ajoute des fonctionnalités.

## Exemple simple
On veut afficher un **texte**.  
De base, il est **simple**, mais on souhaite parfois :
- l’afficher **en majuscules**
- ou l’afficher **avec des étoiles autour**

Au lieu de créer plusieurs sous-classes (`TexteMajuscules`, `TexteAvecDecoration`, etc.), on utilise le **pattern Décorateur**.
```java
public interface Texte {
    void afficher();
}
```
```java
public class TexteSimple implements Texte {
    private String contenu;

    public TexteSimple(String contenu) {
        this.contenu = contenu;
    }

    @Override
    public void afficher() {
        System.out.println(contenu);
    }
}
```
```java
public abstract class TexteDecorateur implements Texte {
    protected Texte texte; // référence vers le texte à décorer

    public TexteDecorateur(Texte texte) {
        this.texte = texte;
    }
}
```
```java
public class TexteMajuscules extends TexteDecorateur {
    public TexteMajuscules(Texte texte) {
        super(texte);
    }

    @Override
    public void afficher() {
        System.out.print("→ ");
        texte.afficher(); // on appelle le texte d’origine
        System.out.println("(en MAJUSCULES)");
    }
}
```
```java
public class TexteAvecEtoiles extends TexteDecorateur {
    public TexteAvecEtoiles(Texte texte) {
        super(texte);
    }

    @Override
    public void afficher() {
        System.out.print("★ ");
        texte.afficher();
        System.out.println("★");
    }
}
```

# Design Pattern : **Commande** (Command)
## Principe
- **🎯 Objectif :** **Encapsuler une action** (commande) dans un objet, afin de **découpler** celui qui émet la demande (le client) de celui qui l’exécute (le receveur).
- **⚙️ Problème :** Si un bouton ou un menu appelle directement une méthode, il devient **fortement couplé** à la classe exécutante.  
    Le **pattern Commande** permet de :
    - stocker les actions sous forme d’objets,
    - **annuler**, **répéter**, ou **différer** une action très facilement.

## Exemple simple
On veut créer une **télécommande** pour **une lumière** avec deux actions :
- **Allumer**
- **Éteindre**

Au lieu d’appeler directement `lumiere.allumer()`, on va créer des **commandes** indépendantes représentant ces actions.
```java
public interface Commande {
    void executer();
}
```
```java
public class Lumiere {
    public void allumer() {
        System.out.println("💡 La lumière est allumée");
    }

    public void eteindre() {
        System.out.println("🌑 La lumière est éteinte");
    }
}
```
```java
public class CommandeAllumer implements Commande {
    private Lumiere lumiere;

    public CommandeAllumer(Lumiere lumiere) {
        this.lumiere = lumiere;
    }

    @Override
    public void executer() {
        lumiere.allumer();
    }
}
```
```java
public class CommandeEteindre implements Commande {
    private Lumiere lumiere;

    public CommandeEteindre(Lumiere lumiere) {
        this.lumiere = lumiere;
    }

    @Override
    public void executer() {
        lumiere.eteindre();
    }
}
```
```java
public class Telecommande {
    private Commande commande;

    public void setCommande(Commande commande) {
        this.commande = commande;
    }

    public void appuyerBouton() {
        if (commande != null) {
            commande.executer();
        }
    }
}
```

# Design Pattern : **Itérateur** (avec `Iterable`)
## Principe
- **🎯 Objectif :** Permettre de **parcourir une collection d’objets** sans exposer sa structure interne.
- **⚙️ En Java :** L’interface `Iterable` définit une méthode `iterator()` qui retourne un **objet `Iterator`**,  
    lequel fournit deux méthodes principales :
    - `hasNext()` → indique s’il reste un élément
    - `next()` → renvoie l’élément suivant

Cela permet d’utiliser la **boucle `for-each`** (`for (...)`) directement sur ta collection !

## Exemple simple
On veut créer une **classe `ListeEtudiants`** qui contient des noms d’étudiants et qu’on puisse **parcourir avec un `for-each`** comme une collection standard.
```java
import java.util.Iterator;
import java.util.ArrayList;
import java.util.List;

public class ListeEtudiants implements Iterable<String> {
    private List<String> etudiants = new ArrayList<>();

    public void ajouter(String nom) {
        etudiants.add(nom);
    }

    @Override
    public Iterator<String> iterator() {
        return etudiants.iterator();
    }
}
```
