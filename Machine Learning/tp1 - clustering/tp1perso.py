#-*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs, make_circles, make_s_curve, make_moons, load_boston, load_iris, load_diabetes, load_digits, load_wine, load_breast_cancer, load_linnerud
from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score

#Algorithme du KMeans - 4 itérations
def iter_kmeans(X):
    for n_iter in range(1, 5):
        #max_iter = n_iter, comme ça l'algorithme s'affiche, étape par étape
        clust = KMeans(n_clusters=4, max_iter=n_iter, init='random', random_state=101)
        #Perform clustering
        clust.fit(X)

        #Partage de la fenêtre affichant les graphes en 2*2
        plt.subplot(2, 2, n_iter)

        #Création de la dispersion de points
        plt.scatter(X[:,0], X[:,1], c=clust.labels_, edgecolors='none', alpha = 0.6)
        #Visualisation des centres de classe
        #(première colonne des centres : n_clusters, deuxième colonne des centres: n_features)
        plt.scatter(clust.cluster_centers_[:,0], clust.cluster_centers_[:,1], marker='x', color='r', s=100, linewidth=4)

        #Affiche l'étiquette de chaque point
        label = clust.labels_
        plt.title("iteration %s, inertie: %0.2f, score: %0.3f" %(n_iter, clust.inertia_, silhouette_score(X,label)))

    plt.show()

def demo_deft():
    #On testera différents jeux de données en faisant varier les paramètres de la dispersion des points

    centers = [[1, 1], [1, -1], [-1, -1], [-1, 1]]
#MOONS
    for clust_std in range(1,11):
        X, y = make_moons(n_samples = 300, shuffle=False, noise=0.1, random_state=0)
        clust = KMeans(n_clusters=2, max_iter=4, init='random') #, random_state=50)
        #Perform clustering
        clust.fit(X)

        #Partage de la fenêtre affichant les graphes en 2*2
        plt.subplot(5, 2, clust_std)

        #Création de la dispersion de points
        plt.scatter(X[:,0], X[:,1], c=clust.labels_, edgecolors='none', alpha = 0.6)
        #Visualisation des centres de classe
        #(première colonne des centres : n_clusters, deuxième colonne des centres: n_features)
        plt.scatter(clust.cluster_centers_[:,0], clust.cluster_centers_[:,1], marker='x', color='r', s=100, linewidth=4)

        #Affiche l'étiquette de chaque point
        label = clust.labels_
        plt.title("inertie: %0.2f, score: %0.3f" %(clust.inertia_, silhouette_score(X,label)))

#S_CURVES

    for clust_std in range(1,11):
            X, y = make_s_curve(n_samples = 250, noise=0.5, random_state=None)
            clust = KMeans(n_clusters=2, max_iter=4, init='random') #, random_state=50)
            #Perform clustering
            clust.fit(X)

            #Partage de la fenêtre affichant les graphes en 2*2
            plt.subplot(5, 2, clust_std)

            #Création de la dispersion de points
            plt.scatter(X[:,0], X[:,1], c=clust.labels_, edgecolors='none', alpha = 0.6)
            #Visualisation des centres de classe
            #(première colonne des centres : n_clusters, deuxième colonne des centres: n_features)
            plt.scatter(clust.cluster_centers_[:,0], clust.cluster_centers_[:,1], marker='x', color='r', s=100, linewidth=4)

            #Affiche l'étiquette de chaque point
            label = clust.labels_
            plt.title("inertie: %0.2f, score: %0.3f" %(clust.inertia_, silhouette_score(X,label)))


#CIRCLES

    for clust_std in range(1,11):
            X, y = make_circles(n_samples = 100, shuffle=True, noise=0.05, factor = 0.51) #, random_state = 101)
            clust = KMeans(n_clusters=2, max_iter=4, init='random') #, random_state=50)
            #Perform clustering
            clust.fit(X)

            #Partage de la fenêtre affichant les graphes en 2*2
            plt.subplot(5, 2, clust_std)

            #Création de la dispersion de points
            plt.scatter(X[:,0], X[:,1], c=clust.labels_, edgecolors='none', alpha = 0.6)
            #Visualisation des centres de classe
            #(première colonne des centres : n_clusters, deuxième colonne des centres: n_features)
            plt.scatter(clust.cluster_centers_[:,0], clust.cluster_centers_[:,1], marker='x', color='r', s=100, linewidth=4)

            #Affiche l'étiquette de chaque point
            label = clust.labels_
            plt.title("inertie: %0.2f, score: %0.3f" %(clust.inertia_, silhouette_score(X,label)))


#BLOBS
            
    for clust_std in range(1,11):
        X, y = make_blobs(n_samples = 100, n_features = 2, centers = centers, cluster_std = clust_std) #, random_state = 101)
        clust = KMeans(n_clusters=4, max_iter=4, init='random') #, random_state=50)
        #Perform clustering
        clust.fit(X)

        #Partage de la fenêtre affichant les graphes en 2*2
        plt.subplot(5, 2, clust_std)

        #Création de la dispersion de points
        plt.scatter(X[:,0], X[:,1], c=clust.labels_, edgecolors='none', alpha = 0.6)
        #Visualisation des centres de classe
        #(première colonne des centres : n_clusters, deuxième colonne des centres: n_features)
        plt.scatter(clust.cluster_centers_[:,0], clust.cluster_centers_[:,1], marker='x', color='r', s=100, linewidth=4)

        #Affiche l'étiquette de chaque point
        label = clust.labels_
        plt.title("inertie: %0.2f, score: %0.3f" %(clust.inertia_, silhouette_score(X,label)))

    plt.show()
    #Place aux tests de l'algorithme des K-means en faisant varier les arguments:

def class_dig(nb_cluster):
    dataDig = load_digits(n_class=nb_cluster)
    data = dataDig.data
    reduce_date = 
    plt.figure(figsize=[10,10])
    clust = KMeans(n_clusters = nb_cluster, max_iter = 4, init='random')
    
    #Classement et apprentissage
    clust.fit(data)
    
    #Création de la dispersion de points
    plt.plot(data[:,0], data[:,1], 'k.', markersize = 2)
    #Visualisation des centres de classe
    #(première colonne des centres : n_clusters, deuxième colonne des centres: n_features)
    plt.scatter(clust.cluster_centers_[:,0], clust.cluster_centers_[:,1], marker='x', color='r', s=100, linewidth=4)

    #Affiche l'étiquette de chaque point
    #plt.title("score: %0.3f" %silhouette_score(data,clust.labels_))
    plt.show()

for nb_clust in range(1,11):
    class_dig(nb_clust)

#Protocole de test

#Construction du jeu de données
centers = [[1, 1], [1, -1], [-1, -1], [-1, 1]]

#Chargement d'un jeu de données
X, y = make_blobs(n_samples = 100, n_features = 2, centers = centers, cluster_std = 0.5, random_state = 101)

#Crée la dispersion de points
plt.scatter(X[:,0], X[:,1], c=y, edgecolors='none', alpha = 0.9)
plt.title("Données initiales")
plt.show()

###Lancement de l'algorithme des K-means sur un jeu de données simple
##iter_kmeans(X)

#Différents types de données mettant en défaut cet algorithme:
demo_deft()
