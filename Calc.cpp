#include <iostream>

using namespace std;

// Permet de déclarer un objet simple
struct Complexe {
    // Variable de cet objet
    double re; // Nombre réel
    double im; // Nombre imaginaire
};

Complexe saisirComplexe() {
    Complexe c;
    cout << "Saisir la partie reelle : ";
    // Ajout dans la varibale 're' l'entrée de l'utilisateur
    cin >> c.re;
    cout << "Saisir la partie imaginaire : ";
    // Ajout dans la varibale 'im' l'entrée de l'utilisateur
    cin >> c.im;
    return c; // Renvoie l'objet
}

void afficherComplexe(Complexe c) {
    cout << c.re << " + " << c.im << "i" << endl;
}

Complexe addition(Complexe a, Complexe b) {
    // Créer un nouvel objet Complexe pour les transfères de variable
    Complexe c;
    // Addition avec les varaibles des quatres demandes des utilisateurs
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

Complexe soustraction(Complexe a, Complexe b) {
    // Créer un nouvel objet Complexe pour les transfères de variable
    Complexe c;
    // Soustraction avec les varaibles des quatres demandes des utilisateurs
    c.re = a.re - b.re;
    c.im = a.im - b.im;
    return c;
}

Complexe multiplication(Complexe a, Complexe b) {
    // Créer un nouvel objet Complexe pour les transfères de variable
    Complexe c;
    // Multiplication avec les varaibles des quatres demandes des utilisateurs
    c.re = a.re * b.re - a.im * b.im;
    c.im = a.re * b.im + a.im * b.re;
    return c;
}

Complexe division(Complexe a, Complexe b) {
    // Créer un nouvel objet Complexe pour les transfères de variable
    Complexe c;
    // Division avec les varaibles des quatres demandes des utilisateurs
    double denominateur = b.re * b.re + b.im * b.im;
    c.re = (a.re * b.re + a.im * b.im) / denominateur;
    c.im = (a.im * b.re - a.re * b.im) / denominateur;
    return c;
}

int main() {
    // Création de 3 Complexe,
    Complexe a, b, c; // 'c' servira à afficher le résultat
    // Variable pour le type d'opération
    char choix;

    cout << "Calculatrice de nombres complexes" << endl;

    // Permet d'avoir les 4 entrées utilisateur
    a = saisirComplexe();
    b = saisirComplexe();

    cout << "Selectionner l'operation à effectuer :" << endl;
    cout << "+ : Addition" << endl;
    cout << "- : Soustraction" << endl;
    cout << "* : Multiplication" << endl;
    cout << "/ : Division" << endl;
    cout << "Votre choix : ";
    cin >> choix;

    switch (choix) {
        case '+':
            c = addition(a, b);
            break;
        case '-':
            c = soustraction(a, b);
            break;
        case '*':
            c = multiplication(a, b);
            break;
        case '/':
            c = division(a, b);
            break;
        default:
            cout << "Operation invalide" << endl;
            return 0;
    }

    cout << "Le resultat est : ";
    afficherComplexe(c);

    return 0;
}
