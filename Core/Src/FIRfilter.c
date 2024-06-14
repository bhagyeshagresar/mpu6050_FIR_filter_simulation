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


float FIRFilter_Update(FIRFilter *fir, float inp){

	//Store the latest sample in a buffer
	fir->buf[fir->bufIndex] = inp;

	//Increment the buffer index and wrap around if necessary
	fir->bufIndex++;

	if(fir->bufIndex == FIR_FILTER_LENGTH){
		fir->bufIndex = 0;
	}

	//Compute new output sample(via Convolution)
	fir->out = 0.0f;

	uint8_t sumIndex = fir->bufIndex;

	for(uint8_t i = 0; i < FIR_FILTER_LENGTH; i++){

		//decrement index and wrap if necessary
		if(sumIndex > 0){
			sumIndex--;
		}
		else{

			sumIndex = FIR_FILTER_LENGTH - 1;
		}

		//Multiple impulse response with shifted input sample and add to output
		fir->out += FIR_IMPULSE_RESPONSE[i] * fir->buf[sumIndex];

	}

	return fir->out;



}
