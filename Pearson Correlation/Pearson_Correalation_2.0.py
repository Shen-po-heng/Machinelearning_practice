# -*- coding: utf-8 -*-
"""
Created on Sun Aug 16 00:53:17 2020
@author: shenpaul
"""
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error, r2_score
#Set up, it could be changed with scenario
target='next_activity' #target data name
threshold=0.03 # to choose those data whose correlation coefficient lower than threshold
testdata_per=0.4 #the percentage for test data
path='result/result_u00.pkl'
#Load data
def Loaddata(path):
    print("Loading... data")
    DF = pd.read_pickle(path, compression='xz') #Read dataset
    DF.replace([np.inf, -np.inf], np.nan, inplace=True) #replace infinity and nan value with mean value
    DF.fillna(DF.mean(), inplace=True) 
    return DF
#pearson selection
def Pearson_Sele(testDF):
    #pearson selection
    df = pd.DataFrame(data= testDF) # use dataframe, because of the use of building pearson method
    corr = df.corr(method ='pearson')[target]#Pearson correlation coefficient
    # print(corr)#print out the result of the corrleation after pearson correaltion 
    feat_labels = corr.index #here, already filter out first time some data in which with text message
    abs_corr = abs(corr).sort_values(ascending=True,)[1:]# absolute for positive values
    print(abs_corr,"\n")
    relevant_features = abs_corr[abs_corr> threshold]#filter out those correalation coefficient is lower than 0.08
    return (feat_labels,relevant_features)
#arrange the data into X(data set) and Y(target set)
def arrangeXY(DF,features,target):
    X=DF[features[0]]
    Y=DF[target]
    for i in range(1,len(features)):
        print(features[i])
        X_Old=X;
        X_New=testDF[features[i]];
        #joint data frame 
        X = pd.concat([X_Old,X_New], axis=1, sort=False)   
    X=X.drop([target],axis=1)#delete target set in data set
    print("\ndata set:",X)
    print(X.columns)
    return (X,Y)
def Randomforest(X,Y,testdata_per):
    # Split the data into 40% test and 60% training
    X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=testdata_per, random_state=0)
    clf = RandomForestRegressor(n_estimators=100, max_depth=20,random_state=0, n_jobs=-1)
    print("\nTraining...Regressor")
    # Train ......
    clf.fit(X_train, Y_train)
    print("\nprediction")
    Y_pred = clf.predict(X_test)
    print("R2 score : %.2f" % r2_score(Y_test,Y_pred))
    print("Mean squared error: %.2f" % mean_squared_error(Y_test,Y_pred))
#Main
testDF=Loaddata(path) #loading data
(feat_labels,relevant_features)=Pearson_Sele(testDF)# doing pearson and select the features
print("relevant_features:",relevant_features.index)
#arrange the data for the convenience of division of test set and training set
print("\nspilt original data to training set and test set")
(X,Y)=arrangeXY(testDF,feat_labels,target)
Randomforest(X,Y,testdata_per)

print("\nChange... set") #use the features after filtered out
print("\nspilt limited data to training set and test set")
(X_limited,Y)=arrangeXY(testDF,relevant_features.index,target)              
Randomforest(X_limited,Y,testdata_per)