#include "__FILE__.h"


/*MC8@�봴8¥*************�ⲿ����*****/

/*MC8@�봴8¥*************�ṩ�ӿ�*****/

/*MC8@�봴8¥*************�ڲ�����*****/

typedef struct 
{
	float Kp;
	float Ki;
	float Kd;
	float I_add;
	float I_add_min;
	float I_add_max;
	float D_last;
}_ENC_Increment_PID_Struct;

/*
	������ :_MC8F_Increment_PID;
*/
float _ENC_Increment_PID(void *ENC_PID,int error)
{
	float P_num,I_num,D_num;
	if (ENC_PID.Kp != 0)
	{
		P_num = ENC_PID.Kp*error;
	}
	if (ENC_PID.Ki != 0)
	{
		I_num = ENC_PID.Ki*I_add;
		ENC_PID.Ki*I_add += error;
	}
	if (ENC_PID.Kd != 0)
	{
		D_num = ENC_PID.Kd*(error - ENC_PID.D_last);
		ENC_PID.D_last = error;
	}
	return P_num + I_num + D_num;
}


