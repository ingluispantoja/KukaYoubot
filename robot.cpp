#include "robot.h"
#include<iostream>
#include <eigen3/Eigen/Dense>

//Variables matriciales y vectoriales
Eigen::Matrix4f G;
Eigen::Matrix4f gt;
Eigen::RowVectorXd alpha(9);//Declarando vector de alpha(Rx)
Eigen::RowVectorXd a(9);    //Declarando vector de a (Tx)
Eigen::RowVectorXd theta(9);//Declarando vector de theta(Rz)
Eigen::RowVectorXd d(9);//Declarando vector de theta(Tx)

//Variables de longitud
int l1,l2,l3,l4,l5;

//Variables numéricas
float pi=3.14159125;


kuka::kuka(std::string version)
{
    reference=version;

}

Eigen::Matrix4f kuka::dh(float q1,float q2,float q3,float q4,float q5,float q6,float q7,float q8)
{

    l1=l2=l3=l4=l5=1;

    //Vectores de los parametros DH

    theta<< 0  ,  -pi/2  , -pi/2 ,  q3 ,q4-pi/2 ,q5-pi/2 ,q6 ,q7+pi/2 ,q8;
         d<< 0  ,    q1   ,   q2  ,  l1  , l2     ,  0     ,0    ,0    ,l5;
         a<< 0   ,   0    ,   0   ,  0   ,  0      , l3    ,l4   ,0     ,0;
     alpha<<-pi/2, -pi/2  ,-pi/2  ,  0  , -pi/2    , 0     ,0   ,pi/2   ,0;

     //MUltriplicación de las matrices homogeneas de transformación

     for (int i=0;i<=8;i++)
      {
          gt<<cos(theta(i)),-sin(theta(i))*cos(alpha(i)), sin(theta(i))*sin(alpha(i)),a(i)*cos(theta(i)),
              sin(theta(i)), cos(theta(i))*cos(alpha(i)),-cos(theta(i))*sin(alpha(i)),a(i)*sin(theta(i)),
                     0     ,  sin(alpha(i))             ,      cos(alpha(i))         ,    d(i)          ,
                     0     ,            0               ,            0               ,      1           ;

         if (i==0)
         {
             G<<1,0,0,0,
                0,1,0,0,
                0,0,1,0,
                0,0,0,1;
         }

          G=G*gt;

      }

        return G;


}
