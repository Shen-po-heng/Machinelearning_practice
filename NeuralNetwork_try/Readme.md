# Neural Network try

1. I use the Sigmoid function as the activation function
2.StartShowANDEndShow.h is only used as a link for the user to check if there is a TrainData before use
3. CalculateMainPart.h is marked with annotations, which is the core part of the program calculation
4. Use main function to execute the file properly
※I have storage for WeightValue and Threshold, which can also be used as a check when errors occur

The main variables in the program are all commented and marked, and the names of the variables are also considered naming, except that the counted variables are not marked.

※Train Data: I put two sets of variables, one set is 5; the first 3 are learning data, and the last 2 are teaching data
※ Observation of the execution result: From the slowly correcting of the Error, it can be found that the Error is gradually smaller

Experience and review: Due to the time factor, it is too late to use the C language to play the GUI graph to see the error trend. It is a pity that the graph is relatively clear at a glance.
This is the first time I have learned CNN and reviewed the c style of play. In two weeks, I felt quite pressured and not easy.
It took a lot of time to understand it, but it was very rewarding.
If there is time, I also hope to use a larger TrainData to complete the results


Reference:
1. C Standard Library Reference Tutorial: https://www.tutorialspoint.com/c_standard_library/index.htm
2. Basic Neural Network Tutorial : C++ Implementation and Source Code :
https://takinginitiative.wordpress.com/2008/04/23/basic-neural-network-tutorial-c-implementation-and-source-code/
3. 神經網路BP演算法(C程式):http://fecbob.pixnet.net/blog/post/38133227-%E7%A5%9E%E7%B6%93%E7%B6%B2%E8%B7%AFbp%E6%BC%94%E7%AE%97%E6%B3%95(c%E7%A8%8B%E5%BC%8F)%E3%80%90%E8%BD%89%E3%80%91
4. 程式人雜誌 -- 2014 年 4 月號 (開放公益出版品) 類神經網路轉譯成 C++ (作者：張藝瀚): http://programmermagazine.github.io/201404/htm/focus4.html
5. 征服C語言程式設計 
