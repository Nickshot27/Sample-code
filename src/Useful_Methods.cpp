#include "Useful_Methods.h"

int8_t sign(int value)
{
	if (value == 0)
		return 0;
	if (value < 0)
		return -1;
	return 1;
}

void togglePin(uint8_t pin)
{
	digitalWrite(pin, !digitalRead(pin));
}

void parseString(String string_in, char* delimiter, float output_array[])
{
	char str[sizeof(string_in) * 8]; //Create an array to store the input string
	string_in.toCharArray(str, (sizeof(str) * 8)); //Convert the input data to CharArray
	char* pch; //create buffer
	pch = strtok(str, delimiter); //begin parsing the values
	uint8_t i = 0;
	while (pch != NULL)
	{
		output_array[i] = atof(pch);
		pch = strtok(NULL, delimiter);
		i++;
	}
}

void parseString(String string_in, char* delimiter, int32_t output_array[])
{
	char str[sizeof(string_in) * 8]; //Create an array to store the input string
	string_in.toCharArray(str, (sizeof(str) * 8)); //Convert the input data to CharArray
	char* pch; //create buffer
	pch = strtok(str, delimiter); //begin parsing the values
	uint8_t i = 0;
	while (pch != NULL)
	{
		output_array[i] = atof(pch);
		pch = strtok(NULL, delimiter);
		i++;
	}
}

String buildString(float* data_to_string, uint8_t number_of_elements, char* delimiter)
{
	String payload = "";
	uint8_t i;
	for (i = 0; i < number_of_elements; i++)
	{
		payload += String(data_to_string[i],3);
		payload += delimiter;
	}
	payload.setCharAt(payload.length() - 1, '\r');
	return payload;
}

float getMean(float data[], uint8_t size)
{
	uint8_t i;
	float mean = 0;
	for (i = 0; i < size; i++)
		mean = mean + data[i];
	mean = mean / size;
	return mean;
}

float getVariance(float data[], uint8_t size)
{
	uint8_t i;
	float variance = 0;
	float mean = getMean(data, size);
	for (i = 0; i < size; i++)
		variance = variance + pow(mean - data[i], 2);
	return variance / size;
}




