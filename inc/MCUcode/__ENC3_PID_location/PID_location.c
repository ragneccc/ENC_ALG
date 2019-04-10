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
	float outMAX;
	float outMIN;
}_ENC_Location_PID_Struct;

/*
	������ :_MC8F_Increment_PID;
*/
float _ENC_Location_PID(void *ENC_PID, int error)
{
	if (ENC_PID.Kp != 0)
	{
		ENC_PID.Output += ENC_PID.Kp*(error-ENC_PID.Error_last);
	}
	if (ENC_PID.Ki != 0)
	{
		ENC_PID.Output += ENC_PID.Kp*error;
	}
	if (ENC_PID.Kd != 0)
	{
		ENC_PID.Output += ENC_PID.Kd*(error - 2*ENC_PID.Error_last + ENC_PID.Error_last_last);
	}
	ENC_PID.Error_last_last = ENC_PID.Error_last;
	ENC_PID.Error_last = error;
	if(ENC_PID.Output>ENC_PID.outMAX)ENC_PID.Output=ENC_PID.outMAX;
	if(ENC_PID.Output<ENC_PID.outMIN)ENC_PID.Output=ENC_PID.outMIN;
	return ENC_PID.Output;
}

