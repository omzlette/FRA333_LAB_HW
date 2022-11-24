#include <Xicro_sandevistan_imu_ID_2.h>
#include <Arduino_LSM6DS3.h>

Xicro xicro;

float ax, ay, az;  
float gx, gy, gz;  

float angular_velocity[3]={0};
float linear_acceleration[3]={0};

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  xicro.begin(&Serial);
  IMU.begin();
  //Set timer
  TCB0.CTRLB = TCB_CNTMODE_INT_gc; 

  TCB0.CCMP  = 2500;
  TCB0.INTCTRL = TCB_CAPT_bm; 
  TCB0.CTRLA = TCB_CLKSEL_CLKTCA_gc | TCB_ENABLE_bm;
//end of set timer
}

void read_imu_Sendros2()
{
  if(IMU.readAcceleration(gx, gy, gz) && IMU.readGyroscope(ax, ay, az))
  {
      angular_velocity[0]=ax;
      angular_velocity[1]=ay;
      angular_velocity[2]=az;
      linear_acceleration[0]=gx*(9.80665);
      linear_acceleration[1]=gy*(9.80665);
      linear_acceleration[2]=gz*(-9.80665);

      xicro.publish_sandevistan_IMU(linear_acceleration, angular_velocity);
                                       
  }

}
void loop() {
//  Serial.println(ax);
  // put your main code here, to run repeatedly:
  xicro.Spin_node();
}

ISR(TCB0_INT_vect)
{
  read_imu_Sendros2();
  TCB0.INTFLAGS = TCB_CAPT_bm; 
}
