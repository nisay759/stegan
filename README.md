# Stegan #

## Présentation ##

Stegan est une application qui fait de la stéganographie sur des images au format PGM. A partir d'un fichier texte et d'une image au format PGM, l'application cache dans cette dernière toute les informations relatives au fichier texte et qui permettront de le reconstituer dans le futur (et ce de façon totalement transparente). L'application est aussi en mesure de reconstituer, à partir de l'image générée auparavant, le fichier texte originale.

## Compilation ##

Pour compiler l'application, placez-vous à la racine du répertoire, puis tapez dans votre terminal:
	
```
	make all
```

Cette commande compilera les fichiers source du programme et placera l'exécutable dans le dossier "binary". L'exécutable porte le nom de "stegan"

Pour compiler le programme de test, tapez la commande:

```
	make tests
```


Une fois la compilation terminée, vous pouvez supprimer les fichiers objets inutiles (placés dans le dossier object) en tapant la commande:


```
	make clean
```

## Documentation ##

* Pour générer les fichiers de documentation, tapez la commande:


```
	make docu
```


Vous trouverez à la racine du répertoire un lien symbolique "documentation.html" que vous pouvez ouvrir avec votre navigateur pour accéder à la documentation

## Nettoyage ##

* Pour supprimer les fichiers de documentation, les fichiers objets ainsi que les fichiers binaires, tapez:


```
	make mrproper
```


Cette commande supprimera tout les fichiers générés par la commande make et gardera que les fichiers sources du programme.

## Troubleshooting  

* Si vous rencontrez des problèmes avec les commandes précédents, assurez-vous que vous avez les bons paquets installés sur votre machine (à adapter selon votre distribution):

-> Si vous êtes sous Debian ou Ubuntu:

```
	sudo apt-get update
	sudo apt-get install build-essential
	sudo apt-get install doxygen
	sudo apt-get install graphviz
	sudo apt-get install libgtk-3-dev
```


-> Assurez-vous d'avoir la version 3.8 ou supérieure de GTK

## Utilisation

1. Lancez l'application "stegan" dans le répertoire binary.
2. Remplissez les champs demandés
3. Cliquez sur Enfouir ou Extraire selon l'opération à laquelle vous voulez procéder.

-> Les dossiers "pgm" et "texte" contiennent respectivement une image au format PGM et un fichier au format HTML que vous pouvez utilisez pour tester l'application.

## Structure du répertoire

* sources:	Dossier contenant les fichiers sources .c
* headers:	Dossier contenant les fichiers d'en-tête .h
* object:	Dossier contenant les fichiers objet .o issus de la compilation
* pgm:		Dossier contenant une image au format PGM pour tester l'application
* texte:	Dossier contenant un fichier au format HTML pour tester l'application
* test:		Dossier contenant les programmes de test issus de la compilation
* binary:	Dossier contenant les programmes principaux issus de la compilation
* doc:		Dossier contenant les différents fichiers relatifs à la documentation du projet
* GUI:		Dossier contenant le fichier XML définissant la structure de l'interface graphique de l'application
