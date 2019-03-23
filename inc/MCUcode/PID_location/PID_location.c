#include "__FILE__.h"


/*MC8@秒创8楼*************外部引用*****/

/*MC8@秒创8楼*************提供接口*****/

/*MC8@秒创8楼*************内部函数*****/

struct {
	float Kp;
	float Ki;
	float Kd;
	float Output;
	float Error_last;
	float Error_last_last;
}_MC8V_Location_PID_Struct;

/*
	函数名 :_MC8F_Increment_PID;
*/
float _MC8F_Location_PID(void *MC8_PID, int error)
{
	if (MC8_PID.Kp != 0)
	{
		MC8_PID.Output += MC8_PID.Kp*(error-MC8_PID.Error_last);
	}
	if (MC8_PID.Ki != 0)
	{
		MC8_PID.Output += MC8_PID.Kp*error;
	}
	if (MC8_PID.Kd != 0)
	{
		MC8_PID.Output += MC8_PID.Kd*(error - 2*MC8_PID.Error_last + MC8_PID.Error_last_last);
	}
	MC8_PID.Error_last_last = MC8_PID.Error_last;
	MC8_PID.Error_last = error;
	return MC8_PID.Output;
}

