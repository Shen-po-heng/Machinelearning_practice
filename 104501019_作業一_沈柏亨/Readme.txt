ReadMe
作業一:Neural Network實作
學號:104501019
姓名:沈柏亨
E-mail: a069501a@gmail.com
1.我是用Sigmoid函數做激活函數
2.StartShowANDEndShow.h 只作為讓User在使用前能先檢查有無放好TrainData的連結
3.CalculateMainPart.h 都皆有做註解標記，為此程式計算的核心部分
4.用main function 即可好好執行檔案
※對於WeightValue和Threshold，我都有儲存,亦可作為出錯時的檢查

程式中的主要變數皆註解標示，對於變數名稱也皆有考慮的命名，除了計數的變數沒標記之外

※Train Data：我放了兩組變數，一組是5個；前3個是learning Data,後2個是Teaching Data
※執行結果觀察：從Error的慢慢修正，前後比對可以發現，Error漸漸變小

心得與檢討：由於時間因素，來不及以C語言打GUI的圖去看Error的趨勢，很可惜，畢竟圖比較能一目了然。
這是第一次學CNN和複習c的打法，兩周時間，覺得頗感壓力也很不容易。
光前面要了解，就花了不少時間，但很有收穫。
如果還有時間，也很希望用更大的TrainData完成結果


參考資料:
1. C Standard Library Reference Tutorial: https://www.tutorialspoint.com/c_standard_library/index.htm
2. Basic Neural Network Tutorial : C++ Implementation and Source Code :
https://takinginitiative.wordpress.com/2008/04/23/basic-neural-network-tutorial-c-implementation-and-source-code/
3. 神經網路BP演算法(C程式):http://fecbob.pixnet.net/blog/post/38133227-%E7%A5%9E%E7%B6%93%E7%B6%B2%E8%B7%AFbp%E6%BC%94%E7%AE%97%E6%B3%95(c%E7%A8%8B%E5%BC%8F)%E3%80%90%E8%BD%89%E3%80%91
4. 程式人雜誌 -- 2014 年 4 月號 (開放公益出版品) 類神經網路轉譯成 C++ (作者：張藝瀚): http://programmermagazine.github.io/201404/htm/focus4.html
5. 征服C語言程式設計 