#include "FIRFilter.h"

static float FIR_IMPULSE_RESPONSE[FIR_FILTER_LENGTH] = {};

void FIRFilter_Init(FIRFilter *fir){


	//clear the filter buffer
	for(int i = 0; i < FIR_FILTER_LENGTH; i++){

		fir->buf[i] = 0.0f;

	}

	//Reset Buffer Index
	fir->bufIndex = 0;


	//Clear filter output
	fir->out = 0.0f;

}
