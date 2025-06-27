### 🧠 Gestion concurrente d’un stock avec threads

**Contexte :**  
Vous devez écrire un programme en langage C qui simule la gestion d’un stock de produits par plusieurs agents. Chaque agent est un thread. Le stock est représenté par un entier global partagé entre tous les threads.

**Consignes :**
1. Le stock initial est de 100 unités.
2. Il existe deux types de threads :
    - Les **producteurs** : ils ajoutent des unités au stock.
    - Les **consommateurs** : ils retirent des unités du stock.
3. Chaque thread doit exécuter sa tâche un certain nombre de fois (par exemple 10).
4. Le stock ne doit **jamais devenir négatif**.
5. Implémentez une **synchronisation adéquate** entre les threads pour éviter les accès concurrents non sécurisés au stock.