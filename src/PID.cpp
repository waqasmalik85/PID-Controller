#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  // initialising errors
  p_error = 0;
  i_error = 0;
  d_error = 0;
  // previous cte
  prev_cte = 0;
}

void PID::UpdateError(double cte) {
  //proportional error
  p_error = cte;

  //differential error
  d_error = cte - prev_cte;

  //integral error
  i_error = i_error + cte;

  //updating previous error
  prev_cte = cte;

}

double PID::TotalError() {
  return -Kp*p_error - Ki*i_error - Kd*d_error;
}

