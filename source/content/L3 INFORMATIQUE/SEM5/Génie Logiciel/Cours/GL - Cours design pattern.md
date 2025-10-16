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