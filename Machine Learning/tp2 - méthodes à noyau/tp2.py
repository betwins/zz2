import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_moons
from sklearn.svm import SVC,SVR
from sklearn.model_selection import ShuffleSplit
from sklearn.svm.libsvm import decision_function

# Choisir plusieurs modèles et sélectionner celui avec le plus grand score en validation croisée

#Image loading
def imLoading():
    uspsXapp = np.load('USPS/uspsXapp.npy')
    uspsYapp = np.load('USPS/uspsYapp.npy')
    nimg = 56
    im = uspsXapp[:,nimg]
    lab = uspsYapp[nimg]-1
    plt.imshow(np.reshape(im,(16,16)))
    plt.title('Training: %i' %lab) #affiche l'entier lab
    plt.show(block=False)

def plot_results(X,y,clf):
    axes = [-1.5,2.5,-1,1.5]
    plt.plot(X[:,0][y==0],X[:,1][y==0],"bs")
    plt.plot(X[:,0][y==1],X[:,1][y==1],"g^")
    x0s=np.linspace(axes[0], axes[1],100)
    x1s=np.linspace(axes[2], axes[3],100)
    x0, x1=np.meshgrid(x0s, x1s)
    X=np.c_[x0.ravel(), x1.ravel()]
    y_pred=clf.predict(X).reshape(x0.shape)
    y_decision=clf.decision_function(X).reshape(x0.shape)
    plt.contourf(x0,x1,y_pred, cmap=plt.cm.brg, alpha=0.2)
    plt.contourf(x0,x1,y_pred, cmap=plt.cm.brg, alpha=0.1)


##X, y = make_moons(n_samples=10, shuffle=True, noise=None, random_state=None)
###Noyau Gaussien
##gamma1, gamma2=0.1, 5
##c1, c2=0.001,1000
##hyperparams=(gamma1,c1),(gamma1,c2),(gamma2,c1),(gamma2,c2)
##i=1
##plt.figure(figsize=(12,8))
##plt.suptitle("SCM noyau Gaussien")
##for gamma, C in hyperparams:
##    rbf=SVC(kernel="rbf", gamma=gamma, C=C).fit(X,y)
##    plt.subplot(2,2,i)
##    plot_results(X,y,rbf)
##    plt.title("sigma="+str(gamma)+", C="+str(C), fontsize=14)
##    i=i+1
##
uspsXapp = np.load('USPS/uspsXapp.npy')
uspsYapp = np.load('USPS/uspsYapp.npy')
nimg = 56
im = uspsXapp[:,nimg]
lab = uspsYapp[nimg]-1
##plt.imshow(np.reshape(im,(16,16)))
##plt.title('Training: %i' %lab) #affiche l'entier lab
##plt.show(block=False)
[x1,x2]=np.meshgrid(range(16),range(16))
#stockage des valeurs de chaque pixel
trainvecT = np.transpose(np.concatenate((np.reshape(x1,(1,16*16)),np.reshape(x2,(1,16*16))),axis=0))
trainlabT = im


#Découpage de la base avec ShuffleSplit
##n_splits = 4 # si on veut tester 4 images en même temps
##prop = 0.6 # proportion de points pris en test
##lpo=ShuffleSplit(n_splits=n_splits,test_size=prop)
##i=1
##for train_index, test_index in lpo.split(trainvecT):
##    nimg = np.random.randint(2000, size=1)
##    trainlabT = uspsXapp[:,nimg]
##    lab=uspsYapp[nimg]-1
##
##    plt.subplot(n_splits,3,i)
##    i+=1
##    plt.imshow(np.reshape(trainlabT,(16,16)))
##    plt.title('Training: %i' %lab)
##
##    Xtrain, Xtest = trainvecT[train_index], trainvecT[test_index]
##    Ytrain, Ytest = trainlabT[train_index], trainlabT[test_index]


#Training + image dégradée + reconstruction
prop = 0.7
n_splits = 4
plt.Figure(figsize=[3*n_splits,6])
lpo = ShuffleSplit(n_splits=n_splits,test_size=prop)
i = 1
for train_index, test_index in lpo.split(trainvecT): #lpo.split() returns indices to split data into training and test set
    nimg = np.random.randint(2000, size=1)
    trainlabT = uspsXapp[:,nimg]
    lab = uspsYapp[nimg]-1

    plt.subplot(n_splits,3,i)
    i += 1
    plt.imshow(np.reshape(trainlabT,(16,16)))
    plt.title('Training: %i' %lab)

    Xtrain, Xtest = trainvecT[train_index], trainvecT[test_index]
    Ytrain, Ytest = trainlabT[train_index], trainlabT[test_index]

    imgReconstruite = trainlabT*0.0
    imgDegradee = trainlabT*0.0-1.0
    imgDegradee[train_index] = Ytrain

    plt.subplot(n_splits,3,i)
    i += 1
    plt.imshow(np.reshape(imgDegradee,(16,16)))

#Ravel permet de fusionner en un seul tableau les vecteurs contenus dans un tableau
    rbf = SVR(kernel='rbf', gamma=0.1, C=1).fit(Xtrain, np.ravel(Ytrain)) 
    imgReconstruite = rbf.predict(trainvecT)
    plt.subplot(n_splits,3,i)
    i += 1
    plt.imshow(np.reshape(imgReconstruite,(16,16)))
    #SVC != SVR il s'attend à différentes valeurs +1 ou -1 alors que l'autre entre +1 et -1
#clf=SVR(kernel="rbf", gamma=0.1, C=1) #gamma = 1/epsilon #pas SVC !!
#clf.fit(trainvecT, trainlabT)
#clf.decision_function(trainlabT)
#clf.predict(trainlabT)
plt.show(block=False)


