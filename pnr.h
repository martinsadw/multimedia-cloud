#ifndef _PNR_H_
#define _PNR_H_

#include "specification.h"

#define REQUEST 1
#define RESPONSE 2
#define ACK 3
#define NACK 4

// Tipo de estrutura incoerente ou pré-requisito não atendido
#define SPECIFICATION_NOT_SUPPORTED 1
// MEC não tem recursos suficientes para fornecer
#define INSUFFICIENT_RESOURCE 2

int request_create(char *buffer, uint8_t type_msg, short int id_app, char *spec, char *option);

int response_create(char *buffer, uint8_t type_msg, char *spec);

int ack_create(char *buffer, uint8_t type_msg);

int nack_create(char *buffer, uint8_t error);

int encapsulation(char *buffer, int flag, HWSpecification *hwspec, char *option);

int request_remove(char *buffer, short int *id_app, char *spec, char *option);

int response_remove(char *buffer, char *spec);

//int ack_remove(char *buffer);

int nack_remove(char *buffer);

int decapsulation(char *buffer, HWSpecification *hwspec, char *option);

#endif
