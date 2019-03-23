#include "__FILE__.h"


/*MC8@秒创8楼*************外部引用*****/

/*MC8@秒创8楼*************提供接口*****/

/*MC8@秒创8楼*************内部函数*****/

struct {
	float Kp;
	float Ki;
	float Kd;
	float I_add;
	float I_add_min;
	float I_add_max;
	float D_last;
}_MC8V_Increment_PID_Struct;

/*
	函数名 :_MC8F_Increment_PID;
*/
float _MC8F_Increment_PID(void *MC8_PID,int error)
{
	float P_num,I_num,D_num;
	if (MC8_PID.Kp != 0)
	{
		P_num= MC8_PID.Kp*error;
	}
	if (MC8_PID.Ki != 0)
	{
		I_num = MC8_PID.Ki*I_add;
		MC8_PID.Ki*I_add += error;
	}
	if (MC8_PID.Kd != 0)
	{
		MC8_PID.Kd*(error - MC8_PID.D_last);
		MC8_PID.D_last = error;
	}
	return P_num + I_num + D_num;
}


