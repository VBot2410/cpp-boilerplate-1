/*
 * PID.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: Pranav Dhulipala
 */

/* --Includes-- */
#include "PID.h"
#include <stdexcept>

/**

 * @brief Constructor used to initialize all the private members

 * @param kp - is of type double used to initialize the private member Kp

 * @param kd - is of type double used to initialize the private member Kd

 * @param ki - is of type double used to initialize the private member Ki

 * @param t - is of type double used to initialize the private member dt

 * @returns nothing
 */

/* Throws an error if kp,kd,ki are less than zero*/
/* Throws an error t is less than or equal to zero*/

PID::PID(double kp, double kd, double ki, double t) {
  if (kp < 0 || kd < 0 || ki < 0 || t <= 0)
    throw std::domain_error(
        "Kp,Ki,Kd Cannot be Negative and t cannot be less than or equal to zero");
  else {
    Kp = kp;
    Kd = kd;
    Ki = ki;
    dt = t;
    error = 0;
    previousError = 0;
    errorSum = 0;
    errorRateOfChange = 0;
  }
}

/**

 * @brief computes controller output based on the values of Kp,Kd,Ki,dt

 * @param setPoint - is of type double used to input the maximum velocity

 * @param velocity - is of type double used to input

 * @returns the value of the controller output

 */

double PID::compute(double setPoint, double velocity) {
  error = setPoint - velocity;
  errorSum = errorSum + (error * dt);
  errorRateOfChange = (error - previousError) / dt;
  previousError = error;
  return ((Kp * error) + (Ki * errorSum) + (Kd * errorRateOfChange));
}

/* Destructor*/

PID::~PID() {
}
