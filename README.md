# 🐚 my_shell — A Minimal Unix Shell in C

## Description

**my_shell** est un interpréteur de commandes UNIX minimaliste développé en C dans le cadre du module **B-PSU-200** à EPITECH. Le but de ce projet est de recréer un shell fonctionnel à partir de zéro, en implémentant progressivement des fonctionnalités inspirées de **TCSH**.

Ce projet inclut :
- L'exécution de commandes simples
- La gestion des variables d'environnement
- Des fonctions internes (`cd`, `env`, `setenv`, `unsetenv`, `exit`)
- Des fonctionnalités avancées comme les redirections (`>`, `<`, `>>`, `<<`), les pipes (`|`) et les séparateurs (`;`)

> _“THIS ISN’T FLYING. THIS IS FALLING WITH STYLE!”_

## ▶️ Lancement

```bash
make
./mysh
```

Ensuite, vous pouvez entrer des commandes comme dans un shell classique :

```bash
$> ls -l | grep .c > sources.txt
$> cat < sources.txt | wc -l
$> cd test ; ls -a ; echo "done"
```

## 🧠 Fonctionnalités

### 🛠️ Fonctionnalités de base
- Affichage d’un prompt (`$>`)
- Exécution de commandes via le `PATH` ou un chemin absolu
- Gestion des erreurs (`command not found`, erreurs système, etc.)
- Récupération et propagation correcte du code de retour (`$?`)
- Gestion des signaux (`Ctrl+C`, etc.)
- Copie et gestion de l’environnement d’origine

### 🧩 Built-ins (internes)
- `cd` : changement de répertoire
- `env` : affichage de l’environnement
- `setenv` : ajout/modification de variable d’environnement
- `unsetenv` : suppression de variable d’environnement (sans wildcard `*`)
- `exit` : quitter le shell proprement

### ➕ Fonctionnalités avancées
- `;` : exécution séquentielle de plusieurs commandes
- `|` : pipes entre commandes
- Redirections :
  - `>` : redirection de la sortie
  - `>>` : redirection avec ajout
  - `<` : redirection de l'entrée
  - `<<` : heredoc
- Gestion des priorités entre ces opérations

## 📁 Structure du projet

```
.
├── src
├── include
├── bonus
├── tests
├── Makefile
└── README.md
```

## ⚙️ Fonctions système autorisées

```c
malloc, free, exit, opendir, readdir, closedir, getcwd, chdir,
fork, stat, lstat, fstat, open, close, getline, strtok, strtok_r,
read, write, execve, access, isatty, wait, waitpid, wait3, wait4,
signal, kill, getpid, strerror, perror, strsignal, pipe, dup, dup2
```

## 🧪 Exemples d’utilisation

```bash
$> ls -l ; echo "done"
$> echo hello | wc -c
$> cat << EOF
> Bonjour
> EOF
```

## 🧱 Objectifs pédagogiques

- Approfondir la compréhension du fonctionnement d’un shell UNIX
- Manipuler les processus et la communication inter-processus
- Gérer les redirections, les erreurs, et les signaux
- Renforcer la maîtrise du langage C et des appels système
