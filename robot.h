#ifndef ROBOT
#define ROBOT

#include <string>
#include<eigen3/Eigen/Dense>


class kuka
{
  public:
    //Variables
    std::string reference;
    float a1,a2,a3,a4,a5,a6,a7,a8;

    //Metodos

    kuka(std::string version="");

    Eigen::Matrix4f dh(float q1,float q2,float q3,float q4,float q5,float q6,float q7,float q8);

};


#endif // ROBOT

