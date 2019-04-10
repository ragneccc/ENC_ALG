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
	float outMAX;
	float outMIN;
}_ENC_Location_PID_Struct;

/*
	函数名 :_MC8F_Increment_PID;
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

