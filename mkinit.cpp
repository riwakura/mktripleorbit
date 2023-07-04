#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<random>
using namespace std;

const double PI = acos(-1);
#define G 0.00449830997959438

//乱数生成
random_device seed_gen;
mt19937 engine(seed_gen());

constexpr size_t bits = numeric_limits<float>::digits;    
//float rn_1 = generate_canonical<float,bits>(engine);
float rn_2 = generate_canonical<float,bits>(engine);
float rn_3 = generate_canonical<float,bits>(engine);
float rn_4 = generate_canonical<float,bits>(engine);
float rn_5 = generate_canonical<float,bits>(engine);
float rn_6 = generate_canonical<float,bits>(engine);
float rn_7 = generate_canonical<float,bits>(engine);



//コマンドライン引数
double Q; //Q parameter
double cosI; //cosI 
double eccin;

//m1,m2:inner
//m3:outer
double const m1 = 1.0;
double const m2 = 1.0;
double const m3 = 1.0;

//inner
double semiin = 0.000005; //とりあえず5e-6にしておく
double incin = 0; //innerのinclination 
double OMGin = 2*PI*rn_2;
double omgin = 2*PI*rn_3;
double eccain = 2*PI*rn_4;

//outer
double const eccout = 0.5; //固定
double incout; //outerのinclination デフォルトではこれが系のinclination
double OMGout = 2*PI*rn_5;
double omgout = 2*PI*rn_6;
double eccaout = 2*PI*rn_7;



int main(int argc, char* argv[]){

    //引数 Q,cosI,eccinの順でいれる
    //シェルでやりやすいように少しずらしてる
    Q = atof(argv[1]);
    cosI = atof(argv[2]);
    eccin = atof(argv[3]);

    incout = acos(cosI);

    //innerのperiapsis distanceとQからsemioutの計算
    double semiout = (semiin*Q)/(1-eccout);

    //outerのPeriod
    double P = 2*PI*pow(pow(semiout,3),0.5)/pow(G*(m1+m2),0.5);

    //ファイルに初期条件を入力
/*
    ofstream outputfile("initelement.dat");
    outputfile << "0 0 " << m1+m2 << " " << m3 << " " << semiout << " " << eccout << " " << incout << " " << OMGout << " " << omgout << " " << eccaout <<"\n"
    "1 0 "<< m1 << " " << m2 << " " << semiin << " " << eccin << " " <<  incin << " " << OMGin << " " << omgin << " " << eccain << " " << "\t";
    outputfile.close();
*/

    //標準出力に初期条件を出力
    cout << " outer " << m1+m2 << " " << m3 << " " << semiout << " " << eccout << " " << incout << " " << OMGout << " " << omgout << " " << eccaout << endl;
    cout << " inner " << m1 << " " << m2 << " " << semiin << " " << eccin << " " <<  incin << " " << OMGin << " " << omgin << " " << eccain << endl;

    //周期は別のファイルに保存
/*
    ofstream outputfile("period.dat");
    outputfile << P << "\t";
    outputfile.close();
*/

    return 0;
}