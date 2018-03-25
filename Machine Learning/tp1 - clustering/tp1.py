#!/usr/bin/env python
#-*- coding: utf-8 -*-

from sklearn.datasets import make_blobs,make_circles,make_s_curve,load_digits
from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score
import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

def construction():
    #Construction d'un jeu de données de test
    centers = [[1, 1], [1, -1], [-1, -1], [-1, 1]]
    #X,y = make_circles(n_samples=100, shuffle=True, noise=0.1, random_state=None)
    X,y = make_blobs(n_samples=1000, centers=centers, cluster_std=0.5, random_state=101)
    plt.scatter(X[:,0], X[:,1], c=y, edgecolors='none', alpha=0.9)
    #Certains arguments peuvent être non insérés
    plt.title("Données initiales")
    # plt.show(block=False) si on veut afficher plusieurs figures les
    # unes à la suite des autres pour ne pas que le programme s'arrête
    plt.show()

# Jeu de données réel
def jeu_reel():
    X,y = load_digits(return_X_y=True)
    plt.scatter(X[:,0], X[:,1], c='r', edgecolors='none', alpha=0.9)
    plt.title("Données initiales")
    plt.show()

def iter_kmeans():
    # 4 itérations du K-means avec visualisation cellules de Voronoi, classif et centres
    for n_iter in range(1, 5):
        cls = KMeans(n_clusters=4, max_iter=n_iter, n_init=1, init='random', random_state=101)
        cls.fit(X)

        # Division de l'écran affichant les graphes en 2*2
        plt.subplot(2, 2, n_iter)

        # Paramètre la dispersion de points
        plt.scatter(X[:,0], X[:,1], c=cls.labels_, edgecolors='none', alpha=0.6)
        
        #Visualisation des centres de classe
        plt.scatter(cls.cluster_centers_[:,0], cls.cluster_centers_[:,1], marker='x', color='r', s=100, linewidth=4)

        label=cls.labels_
        plt.title("iteration=%s, inertie=%s, coefficient silhouette: %0.3f" %(silhouette_score(X,label), n_iter, int(cls.inertia_)))
        
    plt.show()
        # Cellules de Voronoï résultat
        # xx, yy = np.mshgrid(np.arange(-3, 3, 0.01), np.aranghe(-3, 3, 0.01))
        # Z = cls.predict(np.c_[xx.ravel(), yy.ravel()],xx.reshape())

def digits():
    dig = load_digits(n_class=10)
    X = dig.data
    y = dig.target
    print(X.shape)
    s=[]
    for n_iter in range(5,30):
        kmeans_model=KMeans(n_clusters=n_iter, random_state=1)
        fitter=kmeans_model.fit(X)
        s.append(silhouette_score(X,kmeans_model.labels_,metric='euclidean'))
    plt.plot(s,alpha=0.7)
    plt.show(block=False)

construction()
iter_kmeans()
#digits()

