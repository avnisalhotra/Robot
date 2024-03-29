// this is the dance file 


#include "sumovore.h"
#include "motor_control.h"

void follow_simple_curves(void);
void spin_left(void);
void turn_left(void);
void straight_fwd(void);
void turn_right(void);
void spin_right(void);
void straight_back(void);
void spin_wide_left(void);
void test_program(void);

void motor_control(void)
{
     // very simple motor control
     switch(SeeLine.B)
     {
        case 0b00100u:
        case 0b00010u:
        case 0b01000u:
        case 0b00001u:
        case 0b10000u:
                       //no breaks all above readings end up here
                       follow_simple_curves();
                       break;
        case 0b00000u:
                        motors_brake_all();
                       break;
        default:       break;
      } 
}

void follow_simple_curves(void)
{
     if ( SeeLine.b.Center ) straight_fwd();
     else if (SeeLine.b.Left) spin_left();
     else if (SeeLine.b.CntLeft) turn_left();
     else if (SeeLine.b.CntRight) turn_right();
    else if (SeeLine.b.Right) spin_right();
}

void spin_left(void)
{
  set_motor_speed(left, rev_fast, 0); 
  set_motor_speed(right, fast, 0); 
}

void turn_left(void)
{
  set_motor_speed(left, stop, 0); 
  set_motor_speed(right, fast, 0); 
}
void straight_fwd(void)
{
  set_motor_speed(left, fast, 0); 
  set_motor_speed(right, fast, 0); 
}
void spin_right(void)
{
  set_motor_speed(left, fast, 0); 
  set_motor_speed(right, rev_fast, 0); 
}
void turn_right(void)
{
  set_motor_speed(left, fast, 0); 
  set_motor_speed(right, stop, 0); 
}
void straight_back(void)
{
  set_motor_speed(left,rev_fast, 0); 
  set_motor_speed(right,rev_fast, 0);
}
void spin_wide_left(void)
{
  set_motor_speed(left, slow, 0); 
  set_motor_speed(right, fast, 0);
}
void test_program(void)
{
    int i;
    while(1)
    {
    set_motor_speed(left, fast, 0); 
  	set_motor_speed(right, fast, 0); 
    for(i=0; i<244; i++)
    {
        _delay(65535);
    }
    set_motor_speed(left, medium, 0); 
  	set_motor_speed(right, medium, 0);
    for(i=0; i<244; i++)
    {
        _delay(65535);
    }
    set_motor_speed(left, slow, 0); 
  	set_motor_speed(right, slow, 0);
    for(i=0; i<244; i++)
    {
        _delay(65535);
    }
    set_motor_speed(left, stop, 0); 
  	set_motor_speed(right, stop, 0);
    for(i=0; i<244; i++)
    {
        _delay(65535);
    }
    set_motor_speed(left, rev_slow, 0); 
  	set_motor_speed(right, rev_slow, 0);
    for(i=0; i<244; i++)
    {
        _delay(65535);
    }
    set_motor_speed(left, rev_medium, 0); 
  	set_motor_speed(right,rev_medium, 0);
    for(i=0; i<244; i++)
    {
        _delay(65535);
    }
    set_motor_speed(left, rev_fast, 0); 
  	set_motor_speed(right, rev_fast, 0);
    for(i=0; i<244; i++)
    {
        _delay(65535);
    }
    }

//***************************************************************
	// ROBOT DANCES		    										*
	//***************************************************************
	//turn_left();		//Spin around one wheel

	//spin_left();		//Spin at one place

	//set_motor_speed(left, slow, 0); 
  	//set_motor_speed(right, fast, 0);	//Spin in larger circles
	//***************************************************************
