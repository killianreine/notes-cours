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