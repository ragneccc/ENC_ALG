#include "__FILE__.h"


/*MC8@�봴8¥*************�ⲿ����*****/

/*MC8@�봴8¥*************�ṩ�ӿ�*****/

/*MC8@�봴8¥*************�ڲ�����*****/

struct {
	float Kp;
	float Ki;
	float Kd;
	float Output;
	float Error_last;
	float Error_last_last;
}_MC8V_Location_PID_Struct;

/*
	������ :_MC8F_Increment_PID;
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

